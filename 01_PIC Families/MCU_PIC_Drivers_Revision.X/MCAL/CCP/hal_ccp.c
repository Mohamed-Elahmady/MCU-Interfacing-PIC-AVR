/* 
 * File:   hal_ccp.c
 * Author: mohammedel-ahmady
 *
 * Created on September 11, 2025, 10:58 PM
 */

/******************* Section 0 : Includes *******************/

#include "hal_ccp.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))

static ccp_handler ccp1_handler_function = NULL;
static ccp_handler ccp2_handler_function = NULL;

#endif

static Std_ReturnType ccp_module_disable(const ccp_cfg *ccp);
static Std_ReturnType ccp_set_mode(const ccp_cfg *ccp);
static Std_ReturnType ccp_select_capture_compare_timer(const ccp_cfg *ccp);
static Std_ReturnType ccp_pin_init(const ccp_cfg *ccp);

#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))

static Std_ReturnType ccp_configure_interrupt(const ccp_cfg *ccp);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType ccp_init(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        // 1. set CCP module disable
        Retval = ccp_module_disable(ccp);
        // 2. set CCP mode & mode configurations & timer selected
        Retval = ccp_set_mode(ccp);
        // 3. CCP pin initialization
        Retval = ccp_pin_init(ccp);
        // 4. CCP configure interrupt if needed
#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))
        Retval = ccp_configure_interrupt(ccp);
#endif
    }
    return Retval;
}

Std_ReturnType ccp_deinit(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        // 1. set CCP module disable
        Retval = ccp_module_disable(ccp);
        // 2. Disable CCP Interrupt & clear flag
#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                intenral_interrupt_ccp1_disable();
                intenral_interrupt_ccp1_clear_flag();
                break;
            case ccp_source_ccp2:
                intenral_interrupt_ccp2_disable();
                intenral_interrupt_ccp2_clear_flag();
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
#endif
    }
    return Retval;
}

#if ((ccp_cfg_capture_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_capture_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_is_capture_ready(const ccp_cfg *ccp, ccp_capture_status *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                if(read_bit(PIR1, _PIR1_CCP1IF_POSITION)){
                    *state = ccp_capture_ready;
                    intenral_interrupt_ccp1_clear_flag();
                }
                else{
                    *state = ccp_capture_not_ready;
                }
                break;
            case ccp_source_ccp2:
                if(read_bit(PIR2, _PIR2_CCP2IF_POSITION)){
                    *state = ccp_capture_ready;
                    intenral_interrupt_ccp2_clear_flag();
                }
                else{
                    *state = ccp_capture_not_ready;
                }
                break;
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType ccp_get_capture_value(const ccp_cfg *ccp, uint16 *value){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == value){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                *value = (uint16)CCPR1;
                break;
            case ccp_source_ccp2:
                *value = (uint16)CCPR2;
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

#if ((ccp_cfg_compare_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_compare_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_is_compare_completed(const ccp_cfg *ccp, ccp_compare_status *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                if(read_bit(PIR1, _PIR1_CCP1IF_POSITION)){
                    *state = ccp_compare_ready;
                    intenral_interrupt_ccp1_clear_flag();
                }
                else{
                    *state = ccp_compare_not_ready;
                }
                break;
            case ccp_source_ccp2:
                if(read_bit(PIR2, _PIR2_CCP2IF_POSITION)){
                    *state = ccp_compare_ready;
                    intenral_interrupt_ccp2_clear_flag();
                }
                else{
                    *state = ccp_compare_not_ready;
                }
                break;
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType ccp_set_compare_value(const ccp_cfg *ccp, uint16 value){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                CCPR1 = (uint16)value;
                break;
            case ccp_source_ccp2:
                CCPR2 = (uint16)value;
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

#if ((ccp_cfg_pwm_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_pwm_start(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                if(ccp->ccp_mode == ccp_pwm_mode){
                    Retval = ccp_pin_init(ccp);
                    ccp1_set_configurations(ccp_cfg_pwm_mode);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case ccp_source_ccp2:
                if(ccp->ccp_mode == ccp_pwm_mode){
                    Retval = ccp_pin_init(ccp);
                    ccp2_set_configurations(ccp_cfg_pwm_mode);
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

Std_ReturnType ccp_pwm_stop(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                if(ccp->ccp_mode == ccp_pwm_mode){
                    ccp1_set_configurations(ccp_cfg_module_disable);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case ccp_source_ccp2:
                if(ccp->ccp_mode == ccp_pwm_mode){
                    ccp2_set_configurations(ccp_cfg_module_disable);
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

Std_ReturnType ccp_set_pwm_duty_cycle(const ccp_cfg *ccp, uint8 duty){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        uint16 duty_cycle_temp = (uint16)((4.0 * (PR2 + 1)) * (duty / 100.0));
        
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                CCP1CONbits.DC1B = (uint8)(duty_cycle_temp & 0x0003);
                CCPR1L = (uint8)(duty_cycle_temp >> 2);
                break;
            case ccp_source_ccp2:
                CCP2CONbits.DC2B = (uint8)(duty_cycle_temp & 0x0003);
                CCPR2L = (uint8)(duty_cycle_temp >> 2);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

void ccp1_isr(void){
    // 1. CCP1 module clear flag
    intenral_interrupt_ccp1_clear_flag();
    // 2. code
    // 3. callback function
    if(ccp1_handler_function){
        ccp1_handler_function();
    }
}

void ccp2_isr(void){
    // 1. CCP2 module clear flag
    intenral_interrupt_ccp2_clear_flag();
    // 2. code
    // 3. callback function
    if(ccp2_handler_function){
        ccp2_handler_function();
    }
}

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType ccp_module_disable(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                ccp1_set_configurations(ccp_cfg_module_disable);
                break;
            case ccp_source_ccp2:
                ccp2_set_configurations(ccp_cfg_module_disable);
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((ccp_cfg_pwm_mode_selected) != (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) != (ccp2_cfg_mode_selected))

static Std_ReturnType ccp_select_capture_compare_timer(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        if(ccp->ccp_timer == ccp1_ccp2_timer1){
            ccp1_ccp2_timer1_set_cfg();
        }
        else if(ccp->ccp_timer == ccp1_timer1_ccp2_timer3){
            ccp1_timer1_ccp2_timer3_set_cfg();
        }
        else if(ccp->ccp_timer == ccp1_ccp2_timer3){
            ccp1_ccp2_timer3_set_cfg();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#endif

static Std_ReturnType ccp_set_mode(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_mode){
            case ccp_capture_mode:
                if(ccp->ccp_cfg == ccp_cfg_capture_1_falling_edge || ccp->ccp_cfg == ccp_cfg_capture_1_rising_edge || 
                   ccp->ccp_cfg == ccp_cfg_capture_4_rising_edge || ccp->ccp_cfg == ccp_cfg_capture_16_rising_edge){
                    if(ccp->ccp_src == ccp_source_ccp1){
                        ccp1_set_configurations(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == ccp_source_ccp2){
                        ccp2_set_configurations(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                }
                else{
                    Retval = E_NOT_OK;
                }
                Retval = ccp_select_capture_compare_timer(ccp);
                break;
            case ccp_compare_mode:
                if(ccp->ccp_cfg == ccp_cfg_compare_clear_logic || ccp->ccp_cfg == ccp_cfg_compare_set_logic || 
                   ccp->ccp_cfg == ccp_cfg_compare_toggle_logic || ccp->ccp_cfg == ccp_cfg_compare_gen_interrupt || 
                   ccp->ccp_cfg == ccp_cfg_compare_trigger_special_event){
                    if(ccp->ccp_src == ccp_source_ccp1){
                        ccp1_set_configurations(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == ccp_source_ccp2){
                        ccp2_set_configurations(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                }
                else{
                    Retval = E_NOT_OK;
                }
                Retval = ccp_select_capture_compare_timer(ccp);
                break;
            case ccp_pwm_mode:
                if(ccp->ccp_cfg == ccp_cfg_pwm_mode){
#if ((ccp_cfg_pwm_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) == (ccp2_cfg_mode_selected))
                    if(ccp->ccp_src == ccp_source_ccp1){
                        ccp1_set_configurations(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == ccp_source_ccp2){
                        ccp2_set_configurations(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                    
                    PR2 = (uint8)((_XTAL_FREQ / (4.0 * (ccp->pwm_freq) * (ccp->pwm_prescaler) * (ccp->pwm_postscaler))) - 1);
                }
#endif
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

static Std_ReturnType ccp_pin_init(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_mode){
            case ccp_capture_mode:
                if(ccp->ccp_src == ccp_source_ccp1){
                    gpio_pin_cfg ccp1_pin = {.port = gpio_portC, .pin = gpio_pin2, .direction = gpio_input};
                    Retval = gpio_pin_direction_init(&ccp1_pin);
                }
                else if(ccp->ccp_src == ccp_source_ccp2){
                    gpio_pin_cfg ccp2_pin = {.port = gpio_portC, .pin = gpio_pin1, .direction = gpio_input};
                    Retval = gpio_pin_direction_init(&ccp2_pin);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case ccp_compare_mode:
                if(ccp->ccp_src == ccp_source_ccp1){
                    gpio_pin_cfg ccp1_pin = {.port = gpio_portC, .pin = gpio_pin2, .direction = gpio_output, .logic = gpio_low};
                    Retval = gpio_pin_init(&ccp1_pin);
                }
                else if(ccp->ccp_src == ccp_source_ccp2){
                    gpio_pin_cfg ccp2_pin = {.port = gpio_portC, .pin = gpio_pin2, .direction = gpio_output, .logic = gpio_low};
                    Retval = gpio_pin_init(&ccp2_pin);
                }
                else{
                    Retval = E_NOT_OK;
                }
                    break;
            case ccp_pwm_mode:
                if(ccp->ccp_src == ccp_source_ccp1){
                    gpio_pin_cfg ccp1_pin = {.port = gpio_portC, .pin = gpio_pin2, .direction = gpio_output, .logic = gpio_low};
                    Retval = gpio_pin_init(&ccp1_pin);
                }
                else if(ccp->ccp_src == ccp_source_ccp2){
                    gpio_pin_cfg ccp2_pin = {.port = gpio_portC, .pin = gpio_pin2, .direction = gpio_output, .logic = gpio_low};
                    Retval = gpio_pin_init(&ccp2_pin);
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

#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))

static Std_ReturnType ccp_configure_interrupt(const ccp_cfg *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case ccp_source_ccp1:
                intenral_interrupt_ccp1_enable();
                intenral_interrupt_ccp1_clear_flag();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
                if(ccp->priority == interrupt_high_priority){
                    intenral_interrupt_ccp1_high_priority();
                }
                else if(ccp->priority == interrupt_low_priority){
                    intenral_interrupt_ccp1_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                ccp1_handler_function = ccp->ccp_interrupt;
                break;
            case ccp_source_ccp2:
                intenral_interrupt_ccp2_enable();
                intenral_interrupt_ccp2_clear_flag();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
                interrupt_priority_bit_enable();
                global_interrupt_high_enable();
                global_interrupt_low_enable();
                if(ccp->priority == interrupt_high_priority){
                    intenral_interrupt_ccp2_high_priority();
                }
                else if(ccp->priority == interrupt_low_priority){
                    intenral_interrupt_ccp2_low_priority();
                }
                else{
                    Retval = E_NOT_OK;
                }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels))
                interrupt_priority_bit_disable();
                global_interrupt_enable();
                peripheral_interrupt_enable();
#endif
                ccp2_handler_function = ccp->ccp_interrupt;
                    break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif