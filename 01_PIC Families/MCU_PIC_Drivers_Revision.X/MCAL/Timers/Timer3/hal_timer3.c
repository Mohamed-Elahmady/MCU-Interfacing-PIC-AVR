/* 
 * File:   hal_timer3.c
 * Author: mohammedel-ahmady
 *
 * Created on August 31, 2025, 9:05 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_timer3.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 timer3_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_timer3))
static timer3_handler timer3_handler_function = NULL;
#endif

static Std_ReturnType timer3_set_disable(const timer3_cfg *timer3);
static Std_ReturnType timer3_set_enable(const timer3_cfg *timer3);
static Std_ReturnType timer3_set_mode(const timer3_cfg *timer3);
static Std_ReturnType timer3_set_prescaler(const timer3_cfg *timer3);
static Std_ReturnType timer3_set_rw_register_size(const timer3_cfg *timer3);

#if ((interrupt_feature_enable) == (int_interrupt_timer3))
static Std_ReturnType timer3_configure_interrupt(const timer3_cfg *timer3);
#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType timer3_init(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable timer 3
        Retval = timer3_set_disable(timer3);
        // 2. Set timer 3 mode
        Retval = timer3_set_mode(timer3);
        // 3. Set timer 3 pre-scaler
        Retval = timer3_set_prescaler(timer3);
        // 4. Set timer 3 rw register mode
        Retval = timer3_set_rw_register_size(timer3);
        // 5. Initialize timer 3 register with pre-loaded value
        TMR3H = (uint8)((timer3->preloaded_value) >> 8);
        TMR3L = (uint8)(timer3->preloaded_value);
        timer3_preloaded_value = timer3->preloaded_value;
        // 6. Configure Timer 3 Interrupt if needed
#if ((interrupt_feature_enable) == (int_interrupt_timer3))
        Retval = timer3_configure_interrupt(timer3);
#endif
        // 7. Enable timer 3
        Retval = timer3_set_enable(timer3);
    }
    return Retval;
}

Std_ReturnType timer3_deinit(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable timer 3
        Retval = timer3_set_disable(timer3);
#if ((interrupt_feature_enable) == (int_interrupt_timer3))
        // 2. Disable timer 3 interrupt
        intenral_interrupt_timer3_disable();
        // 3. clear timer 3 flag
        intenral_interrupt_timer3_clear_flag();
#endif
    }
    return Retval;
}

Std_ReturnType timer3_write_data(const timer3_cfg *timer3, uint16 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        TMR3H = (uint8)((data) >> 8);
        TMR3L = (uint8)(data);
    }
    return Retval;
}

Std_ReturnType timer3_read_data(const timer3_cfg *timer3, uint16 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        uint8 tmr3_high = 0, tmr3_low = 0;
        
        tmr3_high = TMR3H;
        tmr3_low = TMR3L;
        
        *data = (uint16)((tmr3_high << 8) | tmr3_low);
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer3))

void tmr3_isr(void){
    // 1. Clear timer 3 flag
    intenral_interrupt_timer3_clear_flag();
    // 2. Code
    TMR3H = (uint8)((timer3_preloaded_value) >> 8);
    TMR3L = (uint8)(timer3_preloaded_value);
    //3. Callback function
    if(timer3_handler_function){
        timer3_handler_function();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType timer3_set_disable(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        timer3_module_disable();
    }
    return Retval;
}

static Std_ReturnType timer3_set_enable(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        timer3_module_enable();
    }
    return Retval;
}

static Std_ReturnType timer3_set_mode(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer3->mode){
            case timer3_timer_mode:
                // 1. Set timer 3 timer mode
                timer3_internal_osc_timer_mode();
                break;
            case timer3_counter_mode:
                // 1. Set timer 3 counter mode
                timer3_internal_osc_counter_mode();
                
                // 2. Initialize input osc pin
                gpio_pin_cfg t13cki_pin = {.port = gpio_portC, .pin = gpio_pin0, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&t13cki_pin);
                
                // 3. Enable Or Disable timer 1Oscillator
                if(timer3->osc == timer1_oscillator_enable){
                    timer1_oscillator_timer_mode_enable();
                }
                else{
                    timer1_oscillator_timer_mode_disable();
                }
                
                // 3. Enable Or Disable Synchronization
                if(timer3->sync == timer3_counter_synchronous_mode){
                    timer3_synchronous_counter_mode();
                }
                else{
                    timer3_asynchronous_counter_mode();
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType timer3_set_prescaler(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        timer3_select_prescaler(timer3->prescaler);
    }
    return Retval;
}

static Std_ReturnType timer3_set_rw_register_size(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer3->rw_mode){
            case timer3_rw_8bit_mode:
                timer3_read_write_8bit_mode();
                break;
            case timer3_rw_16bit_mode:
                timer3_read_write_16bit_mode();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer3))

static Std_ReturnType timer3_configure_interrupt(const timer3_cfg *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        intenral_interrupt_timer3_enable();
        intenral_interrupt_timer3_clear_flag();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        interrupt_priority_bit_enable();
        global_interrupt_high_enable();
        global_interrupt_low_enable();
        if(timer3->priority == interrupt_high_priority){
            intenral_interrupt_timer3_high_priority();
        }
        else if(timer3->priority == interrupt_low_priority){
            intenral_interrupt_timer3_low_priority();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
        interrupt_priority_bit_disable();
        global_interrupt_enable();
        peripheral_interrupt_enable();
#endif
        timer3_handler_function = timer3->timer3_interrupt;
    }
    return Retval;
}

#endif