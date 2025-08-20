/* 
 * File:   hal_timer0.c
 * Author: mohammedel-ahmady
 *
 * Created on August 19, 2025, 6:27 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_timer0.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if((interrupt_feature_enable) == (int_interrupt_timer0))
timer0_handler timer0_handler_function = NULL;
#endif

static Std_ReturnType timer0_set_disable(const timer0_cfg *timer0);
static Std_ReturnType timer0_set_resolution(const timer0_cfg *timer0);
static Std_ReturnType timer0_set_mode(const timer0_cfg *timer0);
static Std_ReturnType timer0_set_prescaler(const timer0_cfg *timer0);
#if((interrupt_feature_enable) == (int_interrupt_timer0))
static Std_ReturnType timer0_configure_interrupt(const timer0_cfg *timer0);
#endif
static Std_ReturnType timer0_set_enable(const timer0_cfg *timer0);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType timer0_init(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 0
        Retval = timer0_set_disable(timer0);
        // 2. Set Timer 0 Resolution
        Retval = timer0_set_resolution(timer0);
        // 3. Set Timer 0 Mode & edge if needed
        Retval = timer0_set_mode(timer0);
        // 4. Set Timer 0 Prescaler
        Retval = timer0_set_prescaler(timer0);
        // 5. Configure Timer 0 Interrupt if needed
#if((interrupt_feature_enable) == (int_interrupt_timer0))
        Retval = timer0_configure_interrupt(timer0);
#endif
        // 6. Initialize Timer0 Registers with preloaded value
        TMR0H = (uint8)((timer0->timer0_preloaded_value) >> 8);
        TMR0L = (uint8)(timer0->timer0_preloaded_value);
        preloaded_value = timer0->timer0_preloaded_value;
        // 7. Enable Timer 0
        Retval = timer0_set_enable(timer0);
    }
    return Retval;
}

Std_ReturnType timer0_deinit(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 0
        Retval = timer0_set_disable(timer0);
#if((interrupt_feature_enable) == (int_interrupt_timer0))
        // 2. Disable Timer 0 Interrupt
        intenral_interrupt_timer0_disable();
        // 3. Clear Timer 0 Interrupt Flag
        intenral_interrupt_timer0_clear_flag();
#endif
    }
    return Retval;
}

Std_ReturnType timer0_write_data(const timer0_cfg *timer0, uint16 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        TMR0H = (uint8)((data) >> 8);
        TMR0L = (uint8)(data);
    }
    return Retval;
}

Std_ReturnType timer0_read_data(const timer0_cfg *timer0, uint16 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        uint8 tmr_high = 0, tmr_low = 0;
        tmr_high = TMR0H;
        tmr_low = TMR0L;
        
        *data = (uint16)((tmr_high << 8) | tmr_low);
    }
    return Retval;
}

void tmr0_isr(void){
    // 1. Clear Timer 0 Interrupt Flag
    intenral_interrupt_timer0_clear_flag();
    // 2. Code
    TMR0H = (uint8)((preloaded_value) >> 8);
    TMR0L = (uint8)(preloaded_value);
    // 3. Call back function
    if(timer0_handler_function){
        timer0_handler_function();
    }
}

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType timer0_set_disable(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        timer0_module_disable();
    }
    return Retval;
}

static Std_ReturnType timer0_set_resolution(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer0->resolution){
            case timer0_8bit_register_size:
                timer0_8bit_resolution();
                break;
            case timer0_16bit_register_size:
                timer0_16bit_resolution();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType timer0_set_mode(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer0->mode){
            case timer0_timer_mode:
                timer0_internal_oscillator_timer_mode();
                break;
            case timer0_counter_mode:
                timer0_external_oscillator_counter_mode();
                gpio_pin_cfg t0cki_pin = {.port = gpio_portA, .pin = gpio_pin4, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&t0cki_pin);
                if(timer0->edge == timer0_counter_rising_edge){
                    timer0_counter_mode_rising_edge();
                }
                else if(timer0->edge == timer0_counter_falling_edge){
                    timer0_counter_mode_falling_edge();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType timer0_set_prescaler(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer0->prescalar){
            case timer0_prescaler_cfg_disable:
                timer0_prescaler_disable();
                break;
            case timer0_prescaler_cfg_enable:
                timer0_prescaler_enable();
                T0CONbits.T0PS = timer0->value;
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if((interrupt_feature_enable) == (int_interrupt_timer0))

static Std_ReturnType timer0_configure_interrupt(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        intenral_interrupt_timer0_clear_flag();
        intenral_interrupt_timer0_enable();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        interrupt_priority_bit_enable();
        global_interrupt_high_enable();
        global_interrupt_low_enable();
        if(timer0->priority == interrupt_high_priority){
            intenral_interrupt_timer0_high_priority();
        }
        else if(timer0->priority == interrupt_low_priority){
            intenral_interrupt_timer0_low_priority();
        }
        else{
            Retval = E_NOT_OK;
        }
#else
        interrupt_priority_bit_disable();
        global_interrupt_enable();
        peripheral_interrupt_enable();
#endif
      timer0_handler_function = timer0->timer0_interrupt;
    }
    return Retval;
}

#endif

static Std_ReturnType timer0_set_enable(const timer0_cfg *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval = E_NOT_OK;
    }
    else{
        timer0_module_enable();
    }
    return Retval;
}
