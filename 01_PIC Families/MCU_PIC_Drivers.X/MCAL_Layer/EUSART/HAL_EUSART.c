/* 
 * File:   HAL_EUSART.c
 * Author: mohammedel-ahmady
 *
 * Created on September 18, 2025, 10:20 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_EUSART.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
static EUSART_HANDLER EUSART_TX_HANDLER_FUNCTION = NULL;
static EUSART_HANDLER EUSART_RX_HANDLER_FUNCTION = NULL;
static EUSART_HANDLER EUSART_FRAMING_HANDLER_FUNCTION = NULL;
static EUSART_HANDLER EUSART_OVERRUN_HANDLER_FUNCTION = NULL;
#endif

static Std_ReturnType EUSART_SET_DISABLE(const EUSART_CFG *eusart);
static Std_ReturnType EUSART_SET_ENABLE(const EUSART_CFG *eusart);
static Std_ReturnType EUSART_ASYNC_TX_INIT(const EUSART_CFG *eusart);
static Std_ReturnType EUSART_ASYNC_RX_INIT(const EUSART_CFG *eusart);
static Std_ReturnType EUSART_SET_BUAD_RATE_CONFIGURATIONS(const EUSART_CFG *eusart);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType EUSART_ASYNC_INIT(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable EUSART Module
        Retval = EUSART_SET_DISABLE(eusart);
        // 2. EUSART Set mode & speed & baud rate size & baud rate calculations
        Retval = EUSART_SET_BUAD_RATE_CONFIGURATIONS(eusart);
        // 3. EUSART Initialize pins
        Retval = EUSART_ASYNC_TX_INIT(eusart);
        Retval = EUSART_ASYNC_RX_INIT(eusart);
        // 4. Enable EUSART Module
        Retval = EUSART_SET_ENABLE(eusart);
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_DEINIT(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable EUSART Module
        Retval = EUSART_SET_DISABLE(eusart);
        // 2. Disable EUSART Transmission & Receiver Interrupts & Clear Flag if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
        INT_INTERRUPT_EUSART_TX_DISABLE();
        INT_INTERRUPT_EUSART_RX_DISABLE();
#endif
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(const EUSART_CFG *eusart, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(EUSART_TX_READ_TSR_STATE()){
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
            INT_INTERRUPT_EUSART_TX_ENABLE();
#endif
            TXREG = data;
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_TX_WRITE_STRING_NON_BLOCKING(const EUSART_CFG *eusart, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            while(!EUSART_TX_READ_TSR_STATE());
            Retval = EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(eusart, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_TX_WRITE_BYTE_BLOCKING(const EUSART_CFG *eusart, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        while(!EUSART_TX_READ_TSR_STATE());
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
        INT_INTERRUPT_EUSART_TX_ENABLE();
#endif
        TXREG = data;
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(const EUSART_CFG *eusart, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = EUSART_ASYNC_TX_WRITE_BYTE_BLOCKING(eusart, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_RX_RESTART(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        EUSART_ASYNC_RX_DISABLE();
        EUSART_ASYNC_RX_ENABLE();
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(const EUSART_CFG *eusart, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        if(EUSART_RX_READ_RSR_STATE()){
            *data = RCREG;
        }
        else{
            /* Nothing */
        }
    }
    return Retval;
}

Std_ReturnType EUSART_ASYNC_RX_READ_BYTE_BLOCKING(const EUSART_CFG *eusart, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        while(!EUSART_RX_READ_RSR_STATE());
        *data = RCREG;
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))

void EUSART_TX_ISR(void){
    // 1. Flag Cleared Automatically By Hardware
    // 2. Code
    // 3. Disable TX Interrupt
    INT_INTERRUPT_EUSART_TX_DISABLE();
    // 4. Callback Function
    if(EUSART_TX_HANDLER_FUNCTION){
        EUSART_TX_HANDLER_FUNCTION();
    }
    else {/* Nothing */}
}

void EUSART_RX_ISR(void){
    // 1. Flag Cleared Automatically By Hardware
    // 2. Code
    // 3. Disable TX Interrupt
    INT_INTERRUPT_EUSART_TX_DISABLE();
    // 4. Callback Function
    if(EUSART_RX_HANDLER_FUNCTION){
        EUSART_RX_HANDLER_FUNCTION();
    }
    else {/* Nothing */}
    if(EUSART_FRAMING_HANDLER_FUNCTION){
        EUSART_FRAMING_HANDLER_FUNCTION();
    }
    else {/* Nothing */}
    if(EUSART_OVERRUN_HANDLER_FUNCTION){
        EUSART_OVERRUN_HANDLER_FUNCTION();
    }
    else {/* Nothing */}
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType EUSART_SET_DISABLE(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        EUSART_MODULE_DISABLE();
    }
    return Retval;
}

static Std_ReturnType EUSART_SET_ENABLE(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        EUSART_MODULE_ENABLE();
    }
    return Retval;
}

static Std_ReturnType EUSART_ASYNC_TX_INIT(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(EUSART_ASYNC_TX_ENABLE_STATE == eusart->eusart_tx_mode.state){
            // 1. Disable TX Pin
            EUSART_ASYNC_TX_DISABLE();
            // 2. Initializer TX Pin as Input functionality
            GPIO_PIN_CFG TX_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN6, .DIRECTION = GPIO_INPUT};

            Retval = GPIO_PIN_DIRECTION_INIT(&TX_pin);
            
            // 3. Configure TX interrupt if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
            if(EUSART_ASYNC_TX_INTERRUPT_ENABLE_STATE == eusart->eusart_tx_mode.interrupt_state){
                INT_INTERRUPT_EUSART_TX_ENABLE();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                if(eusart->eusart_tx_mode.tx_priority == INTERRUPT_HIGH_PRIORITY){
                    INT_INTERRUPT_EUSART_TX_HIGH_PRIORITY();
                }
                else if(eusart->eusart_tx_mode.tx_priority == INTERRUPT_LOW_PRIORITY){
                    INT_INTERRUPT_EUSART_TX_LOW_PRIORITY();
                }
                else {
                    Retval = E_NOT_OK;
                }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                GLOBAL_INTERRUPT_ENABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
#endif
            // 4. Assign TX callback function
            EUSART_TX_HANDLER_FUNCTION = eusart->eusart_tx_mode.tx_interrupt;
            }
            else if(EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE == eusart->eusart_tx_mode.interrupt_state){
                INT_INTERRUPT_EUSART_TX_DISABLE();
            }
            else{
                Retval = E_NOT_OK;
            }
#endif
            // 5. Set Transmission 9Bit (Enable / Disable)
            if(eusart->eusart_tx_mode.tx_size == EUSART_ASYNC_TX_9BIT_SIZE_ENABLE){
                EUSART_ASYNC_TX_9BIT_ENABLE();
            }
            else if(eusart->eusart_tx_mode.tx_size == EUSART_ASYNC_TX_9BIT_SIZE_DISABLE){
                EUSART_ASYNC_TX_9BIT_DISABLE();
            }
            else{
                Retval = E_NOT_OK;
            }
            // 6. Enable TX Pin
            EUSART_ASYNC_TX_ENABLE();
        }
        else if(EUSART_ASYNC_TX_DISABLE_STATE == eusart->eusart_tx_mode.state){
            // Disable TX Pin
            EUSART_ASYNC_TX_DISABLE();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

static Std_ReturnType EUSART_ASYNC_RX_INIT(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        if(EUSART_ASYNC_RX_ENABLE_STATE == eusart->eusart_rx_mode.state){
            // 1. Disable RX Pin
            EUSART_ASYNC_RX_DISABLE();
            // 2. Initializer RX Pin as Input functionality
            GPIO_PIN_CFG RX_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN7, .DIRECTION = GPIO_INPUT};

            Retval = GPIO_PIN_DIRECTION_INIT(&RX_pin);
            
            // 3. Configure RX interrupt if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
            if(EUSART_ASYNC_RX_INTERRUPT_ENABLE_STATE == eusart->eusart_rx_mode.interrupt_state){
                INT_INTERRUPT_EUSART_RX_ENABLE();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                if(eusart->eusart_rx_mode.rx_priority == INTERRUPT_HIGH_PRIORITY){
                    INT_INTERRUPT_EUSART_RX_HIGH_PRIORITY();
                }
                else if(eusart->eusart_rx_mode.rx_priority == INTERRUPT_LOW_PRIORITY){
                    INT_INTERRUPT_EUSART_RX_LOW_PRIORITY();
                }
                else {
                    Retval = E_NOT_OK;
                }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                GLOBAL_INTERRUPT_ENABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
#endif
                // 4. Assign RX callback functions
                EUSART_RX_HANDLER_FUNCTION = eusart->eusart_rx_mode.rx_interrupt;
                EUSART_FRAMING_HANDLER_FUNCTION = eusart->eusart_rx_mode.farming_interrupt;
                EUSART_OVERRUN_HANDLER_FUNCTION = eusart->eusart_rx_mode.overrun_interrupt;
            }
            else if(EUSART_ASYNC_RX_INTERRUPT_DISABLE_STATE == eusart->eusart_rx_mode.interrupt_state){
                INT_INTERRUPT_EUSART_RX_DISABLE();
            }
            else{
                Retval = E_NOT_OK;
            }
    #endif
            // 5. Set Receiving 9Bit (Enable / Disable)
            if(eusart->eusart_rx_mode.rx_size == EUSART_ASYNC_RX_9BIT_SIZE_ENABLE){
                EUSART_ASYNC_RX_9BIT_ENABLE();
            }
            else if(eusart->eusart_rx_mode.rx_size == EUSART_ASYNC_RX_9BIT_SIZE_DISABLE){
                EUSART_ASYNC_RX_9BIT_DISABLE();
            }
            else{
                Retval = E_NOT_OK;
            }
            // 6. Enable RX Pin
            EUSART_ASYNC_RX_ENABLE();
        }
        else if(EUSART_ASYNC_RX_DISABLE_STATE == eusart->eusart_rx_mode.state){
            // Disable RX Pin
            EUSART_ASYNC_RX_DISABLE();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

static Std_ReturnType EUSART_SET_BUAD_RATE_CONFIGURATIONS(const EUSART_CFG *eusart){
    Std_ReturnType Retval = E_OK;
    if(NULL == eusart){
        Retval = E_NOT_OK;
    }
    else{
        float32 Buad_Rate_Temp = 0;
        switch(eusart->br_cfg){
            case EUSART_BR_ASYNC_8BIT_LOW_SPEED:
                EUSART_ASYNCHRONOUS_MODE();
                EUSART_BRG_8BIT();
                EUSART_ASYNC_LOW_SPEED_BAUD_RATE();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 64)) - 1);
                
                break;
            case EUSART_BR_ASYNC_8BIT_HIGH_SPEED:
                EUSART_ASYNCHRONOUS_MODE();
                EUSART_BRG_8BIT();
                EUSART_ASYNC_HIGH_SPEED_BAUD_RATE();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 16)) - 1);
                
                break;
            case EUSART_BR_ASYNC_16BIT_LOW_SPEED:
                EUSART_ASYNCHRONOUS_MODE();
                EUSART_BRG_16BIT();
                EUSART_ASYNC_LOW_SPEED_BAUD_RATE();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 16)) - 1);
                
                break;
            case EUSART_BR_ASYNC_16BIT_HIGH_SPEED:
                EUSART_ASYNCHRONOUS_MODE();
                EUSART_BRG_16BIT();
                EUSART_ASYNC_HIGH_SPEED_BAUD_RATE();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 4)) - 1);
                
                break;
            case EUSART_BR_SYNC_8BIT:
                EUSART_SYNCHRONOUS_MODE();
                EUSART_BRG_8BIT();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 4)) - 1);
                
                break;
            case EUSART_BR_SYNC_16BIT:
                EUSART_SYNCHRONOUS_MODE();
                EUSART_BRG_16BIT();
                
                Buad_Rate_Temp = ((float32)(_XTAL_FREQ/((eusart->baud_rate) * 4)) - 1);
                
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
        SPBRG = (uint8)((uint32)Buad_Rate_Temp);
        SPBRGH = (uint8)(((uint32)Buad_Rate_Temp) >> 8);
    }
    return Retval;
}
