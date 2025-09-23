/* 
 * File:   hal_eusart.c
 * Author: mohammedel-ahmady
 *
 * Created on September 21, 2025, 12:46 AM
 */


/******************* Section 0 : Includes *******************/

#include "hal_eusart.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_eusart))

static eusart_handler tx_handler_function = NULL;
static eusart_handler rx_handler_function = NULL;
static eusart_handler framing_handler_function = NULL;
static eusart_handler overrun_handler_function = NULL;

#endif

static Std_ReturnType eusart_set_disable(const eusart_cfg *eusart);
static Std_ReturnType eusart_set_enable(const eusart_cfg *eusart);
static Std_ReturnType eusart_set_baud_rate_configurations(const eusart_cfg *eusart);
static Std_ReturnType eusart_tx_init(const eusart_cfg *eusart);
static Std_ReturnType eusart_rx_init(const eusart_cfg *eusart);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType eusart_init(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Eusart Module
        Retval = eusart_set_disable(eusart);
        // 2. Set Baud Rate Configurations
        Retval = eusart_set_baud_rate_configurations(eusart);
        // 3. Init TX Configurations
        Retval = eusart_tx_init(eusart);
        // 4. Init RX Configurations
        Retval = eusart_rx_init(eusart);
        // 5. Enable Eusart Module
        Retval = eusart_set_enable(eusart);
    }
    return Retval;
}

Std_ReturnType eusart_deinit(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        eusart_module_disable();
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
        intenral_interrupt_eusart_tx_disable();
        intenral_interrupt_eusart_rx_disable();
#endif
    }
    return Retval;
}

Std_ReturnType eusart_async_tx_write_byte_non_blocking(const eusart_cfg *eusart, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(eusart_async_tx_read_shift_register()){
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
            intenral_interrupt_eusart_tx_enable();
#endif
            TXREG = data;
        }
        else{ /* Nothing */ }
    }
    return Retval;
}

Std_ReturnType eusart_async_tx_write_string_non_blocking(const eusart_cfg *eusart, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            while(!eusart_async_tx_read_shift_register());
            Retval = eusart_async_tx_write_byte_non_blocking(eusart, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType eusart_async_tx_write_byte_blocking(const eusart_cfg *eusart, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        while(!eusart_async_tx_read_shift_register());
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
        intenral_interrupt_eusart_tx_enable();
#endif
        TXREG = data;
    }
    return Retval;
}

Std_ReturnType eusart_async_tx_write_string_blocking(const eusart_cfg *eusart, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = eusart_async_tx_write_byte_blocking(eusart, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType eusart_async_rx_reset(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        eusart_async_rx_disable();
        eusart_async_rx_enable();
    }
    return Retval;
}

Std_ReturnType eusart_async_rx_read_byte_non_blocking(const eusart_cfg *eusart, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        if(eusart_async_rx_read_shift_register()){
            *data = RCREG;
        }
        else{ /* Nothing */ }
    }
    return Retval;
}

Std_ReturnType eusart_async_rx_read_byte_blocking(const eusart_cfg *eusart, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        while(!eusart_async_rx_read_shift_register());
        *data = RCREG;
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_eusart))

void eusart_tx_isr(){
    // 1. Don't clear flag, flag cleared by hardware in uart
    // 2. code
    intenral_interrupt_eusart_tx_disable();
    // 3. call back function
    if(tx_handler_function){
        tx_handler_function();
    }
}

void eusart_rx_isr(){
    // 1. Don't clear flag, flag cleared by hardware in uart
    // 2. code
    // 3. call back function
    if(rx_handler_function){
        rx_handler_function();
    }
    if(framing_handler_function){
        framing_handler_function();
    }
    if(overrun_handler_function){
        overrun_handler_function();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

Std_ReturnType eusart_set_disable(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        eusart_module_disable();
    }
    return Retval;
}

Std_ReturnType eusart_set_enable(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        eusart_module_enable();
    }
    return Retval;
}

Std_ReturnType eusart_set_baud_rate_configurations(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        float32 baud_rate_temp = 0;
        switch(eusart->baud_rate_cfg){
            case eusart_async_8bit_low_speed:
                eusart_asynchronous_mode();
                eusart_baud_rate_8bit();
                eusart_async_baud_rate_low_speed();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 64.0)) - 1);
                break;
            case eusart_async_8bit_high_speed:
                eusart_asynchronous_mode();
                eusart_baud_rate_8bit();
                eusart_async_baud_rate_high_speed();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 16.0)) - 1);
                break;
            case eusart_async_16bit_low_speed:
                eusart_asynchronous_mode();
                eusart_baud_rate_16bit();
                eusart_async_baud_rate_low_speed();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 16.0)) - 1);
                break;
            case eusart_async_16bit_high_speed:
                eusart_asynchronous_mode();
                eusart_baud_rate_16bit();
                eusart_async_baud_rate_high_speed();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 4.0)) - 1);
                break;
            case eusart_sync_8bit:
                eusart_synchronous_mode();
                eusart_baud_rate_8bit();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 4.0)) - 1);
                break;
            case eusart_sync_16bit:
                eusart_synchronous_mode();
                eusart_baud_rate_16bit();
                
                baud_rate_temp = (float32)(((_XTAL_FREQ) / ((eusart->baud_rate) * 4.0)) - 1);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
        SPBRG = (uint8)((uint32)baud_rate_temp);
        SPBRGH = (uint8)((uint32)(baud_rate_temp) >> 8);
    }
    return Retval;
}

Std_ReturnType eusart_tx_init(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(eusart->tx_transmitter.tx_state == eusart_tx_enable_state){
            // 1. Disable tx pin
            eusart_async_tx_disable();
            // 2. tx initialize as input functionality
            gpio_pin_cfg tx_pin = {.port = gpio_portC, .pin = gpio_pin6, .direction = gpio_input};
            Retval = gpio_pin_direction_init(&tx_pin);
            
            // 3. set tx register size "8bit or 9bit"
            if(eusart->tx_transmitter.tx_9bit_state == eusart_tx_9bit_enable_state){
                eusart_async_tx_9bit_enable();
            }
            else if(eusart->tx_transmitter.tx_9bit_state == eusart_tx_9bit_disable_state){
                eusart_async_tx_9bit_disable();
            }
            else{
                Retval = E_NOT_OK;
            }
            
            // 4. Set tx interrupt configuration if needed
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
            if(eusart->tx_transmitter.tx_int_state == eusart_tx_interrupt_enable_state){
                intenral_interrupt_eusart_tx_enable();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
                if(eusart->tx_transmitter.tx_priority == interrupt_high_priority){
                    intenral_interrupt_eusart_tx_high_priority();
                }
                else if(eusart->tx_transmitter.tx_priority == interrupt_low_priority){
                    intenral_interrupt_eusart_tx_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                // 5. Assign tx call back function
                tx_handler_function = eusart->tx_transmitter.tx_interrupt;
            }
            else if(eusart->tx_transmitter.tx_int_state == eusart_tx_interrupt_disable_state){
                intenral_interrupt_eusart_tx_disable();
            }
            else{
                Retval = E_NOT_OK;
            }
#endif
            // 6. Enable tx pin
            eusart_async_tx_enable();
        }
        else if(eusart->tx_transmitter.tx_state == eusart_tx_disable_state){
            eusart_async_tx_disable();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

Std_ReturnType eusart_rx_init(const eusart_cfg *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(eusart->rx_reciver.rx_state == eusart_rx_enable_state){
            // 1. Disable rx pin
            eusart_async_rx_disable();
            // 2. rx initialize as input functionality
            gpio_pin_cfg rx_pin = {.port = gpio_portC, .pin = gpio_pin7, .direction = gpio_input};
            Retval = gpio_pin_direction_init(&rx_pin);
            
            // 3. set rx register size "8bit or 9bit"
            if(eusart->rx_reciver.rx_9bit_state == eusart_rx_9bit_enable_state){
                eusart_async_rx_9bit_enable();
            }
            else if(eusart->rx_reciver.rx_9bit_state == eusart_rx_9bit_disable_state){
                eusart_async_rx_9bit_disable();
            }
            else{
                Retval = E_NOT_OK;
            }
            
            // 4. Set rx interrupt configuration if needed
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
            if(eusart->rx_reciver.rx_int_state == eusart_rx_interrupt_enable_state){
                intenral_interrupt_eusart_rx_enable();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
                if(eusart->rx_reciver.rx_priority == interrupt_high_priority){
                    intenral_interrupt_eusart_rx_high_priority();
                }
                else if(eusart->rx_reciver.rx_priority == interrupt_low_priority){
                    intenral_interrupt_eusart_rx_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                // 5. Assign rx call back function
                rx_handler_function = eusart->rx_reciver.rx_interrupt;
                framing_handler_function = eusart->rx_reciver.framing_interrupt;
                overrun_handler_function = eusart->rx_reciver.ovverun_interrupt;
            }
            else if(eusart->rx_reciver.rx_int_state == eusart_rx_interrupt_disable_state){
                intenral_interrupt_eusart_rx_disable();
            }
            else{
                Retval = E_NOT_OK;
            }
#endif
            // 6. Enable rx pin
            eusart_async_rx_enable();
        }
        else if(eusart->rx_reciver.rx_state == eusart_rx_disable_state){
            eusart_async_rx_disable();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}