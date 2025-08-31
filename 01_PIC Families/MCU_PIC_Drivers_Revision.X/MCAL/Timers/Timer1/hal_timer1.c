/* 
 * File:   hal_timer1.c
 * Author: mohammedel-ahmady
 *
 * Created on August 24, 2025, 7:19 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_timer1.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 timer1_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_timer1))
static timer1_handler timer1_handler_function = NULL;
#endif

Std_ReturnType timer1_disable(const timer1_cfg *timer1);
Std_ReturnType timer1_enable(const timer1_cfg *timer1);
Std_ReturnType timer1_set_mode(const timer1_cfg *timer1);
Std_ReturnType timer1_set_prescaler(const timer1_cfg *timer1);
Std_ReturnType timer1_set_rw_register_size(const timer1_cfg *timer1);

#if ((interrupt_feature_enable) == (int_interrupt_timer1))

Std_ReturnType timer1_configure_interrupt(const timer1_cfg *timer1);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType timer1_init(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        // 1. disable timer 1
        Retval = timer1_disable(timer1);
        // 2. set timer 1 mode
        Retval = timer1_set_mode(timer1);
        // 3. set timer 1 prescaler
        Retval = timer1_set_prescaler(timer1);
        // 4. set timer 1 rw register size
        Retval = timer1_set_rw_register_size(timer1);
        // 5. initialize timer 1 with preloaded value
        TMR1H = (uint8)((timer1->preloaded_value) >> 8);
        TMR1L = (uint8)(timer1->preloaded_value);
        timer1_preloaded_value = timer1->preloaded_value;
        // 6. configure timer 1 interrupt if needed
#if ((interrupt_feature_enable) == (int_interrupt_timer1))
        Retval = timer1_configure_interrupt(timer1);
#endif
        // 7. enable timer 1
        Retval = timer1_enable(timer1);
    }
    return Retval;
}

Std_ReturnType timer1_deinit(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        // 1. disable timer 1
        Retval = timer1_disable(timer1);
#if ((interrupt_feature_enable) == (int_interrupt_timer1))
        // 2. Disable timer 1 interrupt
        intenral_interrupt_timer1_disable();
        // 3. clear timer 1 flag
        intenral_interrupt_timer1_clear_flag();
#endif
    }
    return Retval;
}

Std_ReturnType timer1_write_data(const timer1_cfg *timer1, uint16 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        TMR1H = (uint8)(data >> 8);
        TMR1L = (uint8)(data);
    }
    return Retval;
}

Std_ReturnType timer1_read_data(const timer1_cfg *timer1, uint16 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        uint8 tmr1_high = 0, tmr_low = 0;
        tmr1_high = TMR1H;
        tmr_low = TMR1L;
        
        *data = (uint16)((tmr1_high << 8) | tmr_low);
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer1))

void tmr1_isr(void){
    // 1. clear timer 1 flag
    intenral_interrupt_timer1_clear_flag();
    // 2. code
    TMR1H = (uint8)(timer1_preloaded_value >> 8);
    TMR1L = (uint8)(timer1_preloaded_value);
    // 3. call back function
    if(timer1_handler_function){
        timer1_handler_function();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

Std_ReturnType timer1_disable(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        timer1_module_disable();
    }
    return Retval;
}

Std_ReturnType timer1_enable(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        timer1_module_enable();
    }
    return Retval;
}

Std_ReturnType timer1_set_mode(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer1->mode){
            case timer1_timer_mode:{
                timer1_internal_osc_timer_mode();
                break;
            }
            case timer1_counter_mode:{
                timer1_external_osc_counter_mode();
                
                gpio_pin_cfg t13cki_pin = {.port = gpio_portC, .pin = gpio_pin0, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&t13cki_pin);
                
                if(timer1->osc == timer1_oscillator_enable){
                    timer1_oscillator_timer_mode_enable();
                }
                else if(timer1->osc == timer1_oscillator_disable){
                    timer1_oscillator_timer_mode_disable();
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                if(timer1->sync == timer1_counter_asynchronous_mode){
                    timer1_asynchronous_clock_counter_mode();
                }
                else if(timer1->sync == timer1_counter_synchronous_mode){
                    timer1_synchronous_clock_counter_mode();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            }
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType timer1_set_prescaler(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        timer1_select_prescaler(timer1->prescaler);
    }
    return Retval;
}

Std_ReturnType timer1_set_rw_register_size(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer1->rw_mode){
            case timer1_8bit_rw_mode:
                timer1_read_write_8bit_mode();
                break;
            case timer1_16bit_rw_mode:
                timer1_read_write_16bit_mode();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer1))

Std_ReturnType timer1_configure_interrupt(const timer1_cfg *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        // 1. enable timer1 interrupt
        intenral_interrupt_timer1_enable();
        // 2. clear timer 1 flag
        intenral_interrupt_timer1_clear_flag();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        // 1. Enable IPEN
        interrupt_priority_bit_enable();
        // 2. Enable GIEH
        global_interrupt_high_enable();
        // 3. Enable GIEL
        global_interrupt_low_enable();
        // 4. set timer 1 priority
        if(timer1->priority == interrupt_high_priority){
            intenral_interrupt_timer1_high_priority();
        }
        else if(timer1->priority == interrupt_high_priority){
            intenral_interrupt_timer1_low_priority();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
        // 1. Disable IPEN
        interrupt_priority_bit_disable();
        // 2. Enable GIE
        global_interrupt_enable();
        // 3. Enable PIE
        peripheral_interrupt_enable();
#endif
    timer1_handler_function = timer1->timer1_interrupt;
    }
    return Retval;
}

#endif