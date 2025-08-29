/* 
 * File:   hal_timer2.c
 * Author: mohammedel-ahmady
 *
 * Created on August 27, 2025, 11:00 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_timer2.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint8 timer2_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_timer2))
static timer2_handler timer2_handler_function = NULL;
#endif

static Std_ReturnType timer2_set_disable(const timer2_cfg *timer2);
static Std_ReturnType timer2_set_enable(const timer2_cfg *timer2);
static Std_ReturnType timer2_set_prescaler(const timer2_cfg *timer2);
static Std_ReturnType timer2_set_postscaler(const timer2_cfg *timer2);

#if ((interrupt_feature_enable) == (int_interrupt_timer2))
static Std_ReturnType timer2_configure_interrupt(const timer2_cfg *timer2);
#endif
/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType timer2_init(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 2
        Retval = timer2_set_disable(timer2);
        // 2. Set Timer 2 Pre-scaler
        Retval = timer2_set_prescaler(timer2);
        // 3. Set Timer 2 Post-scaler
        Retval = timer2_set_postscaler(timer2);
        // 4. Initialize Timer 2 registers data
        TMR2 = timer2->preloaded_value;
        timer2_preloaded_value = timer2->preloaded_value;
        // 5. Configure Timer 2 interrupt if needed
#if ((interrupt_feature_enable) == (int_interrupt_timer2))
        Retval = timer2_configure_interrupt(timer2);
#endif
        // 6. Enable Timer 2
        Retval = timer2_set_enable(timer2);
    }
    return Retval;
}

Std_ReturnType timer2_deinit(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 2
        Retval = timer2_set_disable(timer2);
#if ((interrupt_feature_enable) == (int_interrupt_timer2))
        // 2. Disable Timer 2 interrupt
        intenral_interrupt_timer2_disable();
        // 3. Clear Timer 2 flag
        intenral_interrupt_timer2_clear_flag();
#endif
    }
    return Retval;
}

Std_ReturnType timer2_write_data(const timer2_cfg *timer2, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TMR2 = data;
    }
    return Retval;
}

Std_ReturnType timer2_read_data(const timer2_cfg *timer2, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        *data = TMR2;
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer2))

void tmr2_isr(void){
    // 1. Clear Timer 2 flag
    intenral_interrupt_timer2_clear_flag();
    // 2. Code
    TMR2 = timer2_preloaded_value;
    // 3. Call Back Function
    if(timer2_handler_function){
        timer2_handler_function();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

Std_ReturnType timer2_set_disable(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        timer2_module_disable();
    }
    return Retval;
}

Std_ReturnType timer2_set_enable(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        timer2_module_enable();
    }
    return Retval;
}

Std_ReturnType timer2_set_prescaler(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        timer2_prescaler_select(timer2->prescaler);
    }
    return Retval;
}

Std_ReturnType timer2_set_postscaler(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        timer2_postscaler_select(timer2->postscaler);
    }
    return Retval;
}

#if ((interrupt_feature_enable) == (int_interrupt_timer2))

Std_ReturnType timer2_configure_interrupt(const timer2_cfg *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Enable Timer 2 interrupt
        intenral_interrupt_timer2_enable();
        // 2. Clear Timer 2 flag
        intenral_interrupt_timer2_clear_flag();
        // 3. Set Timer 2 priority
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        interrupt_priority_bit_enable();
        global_interrupt_high_enable();
        global_interrupt_low_enable();
        
        if(timer2->priority == interrupt_high_priority){
            intenral_interrupt_timer2_high_priority();
        }
        else if(timer2->priority == interrupt_low_priority){
            intenral_interrupt_timer2_low_priority();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif((interrupt_feature_disable) == (interrupt_priority_levels))
        interrupt_priority_bit_disable();
        global_interrupt_enable();
        peripheral_interrupt_enable();
#endif
        timer2_handler_function = timer2->timer2_interrupt;
    }
    return Retval;
}

#endif