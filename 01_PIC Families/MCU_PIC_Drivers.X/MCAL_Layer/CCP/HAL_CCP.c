 /* 
 * File:   HAL_CCP.c
 * Author: mohammedel-ahmady
 *
 * Created on September 3, 2025, 3:22 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_CCP.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))

static CCP_HANDLER CCP1_HANDLER_FUNCTION = NULL;
static CCP_HANDLER CCP2_HANDLER_FUNCTION = NULL;

#endif

static Std_ReturnType CCP_SET_DISABLE(const CCP_CFG *ccp);
static Std_ReturnType CCP_PIN_INIT(const CCP_CFG *ccp);
static Std_ReturnType CCP_SET_MODE(const CCP_CFG *ccp);
static Std_ReturnType CCP_SET_CAPTURE_COMPARE_TIMER(const CCP_CFG *ccp);

#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))

static Std_ReturnType CCP_CONFIGURE_INTERRUPT(const CCP_CFG *ccp);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType CCP_INIT(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable CCP Module
        Retval = CCP_SET_DISABLE(ccp);
        
        // 2. CCP Set Mode & Mode CFG
        Retval = CCP_SET_MODE(ccp);
       
        // 3. CCP PIN INIT
        Retval = CCP_PIN_INIT(ccp);
        
        // 4. CCP Module Configure Interrupt if needed
#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
        Retval = CCP_CONFIGURE_INTERRUPT(ccp);
#endif
    }
    return Retval;
}

Std_ReturnType CCP_DEINIT(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable CCP Module
        Retval = CCP_SET_DISABLE(ccp);
        // 2. Disable CCP Interrupt & Clear Flag
#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
        if(ccp->ccp_src == CCP1_SOURCE){
            INT_INTERRUPT_CCP1_DISABLE();
            INT_INTERRUPT_CCP1_CLEAR_FLAG();
        }
        else if(ccp->ccp_src == CCP2_SOURCE){
            INT_INTERRUPT_CCP2_DISABLE();
            INT_INTERRUPT_CCP2_CLEAR_FLAG();
        }
        else{
            Retval = E_NOT_OK;
        }
#endif
    }
    return Retval;
}

#if ((CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))

Std_ReturnType CCP_IS_CAPTURE_READY(const CCP_CFG *ccp, CCP_CAPTURE_STATUS *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                if(READ_BIT(PIR1, _PIR1_CCP1IF_POSITION)){
                    *state = CCP_CAPTURE_READY;
#if((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
                    INT_INTERRUPT_CCP1_CLEAR_FLAG();
#endif
                }
                else{
                    *state = CCP_CAPTURE_NOT_READY;
                }
                break;
            case CCP2_SOURCE:
                if(READ_BIT(PIR2, _PIR2_CCP2IF_POSITION)){
                    *state = CCP_CAPTURE_READY;
#if((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
                    INT_INTERRUPT_CCP2_CLEAR_FLAG();
#endif
                }
                else{
                    *state = CCP_CAPTURE_NOT_READY;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType CCP_READ_CAPTURE_VALUE(const CCP_CFG *ccp, uint16 *value){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == value){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                *value = (uint16)CCPR1;
                break;
            case CCP2_SOURCE:
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

#if ((CCP_CFG_COMPARE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_COMPARE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))

Std_ReturnType CCP_IS_COMPARE_COMPLETED(const CCP_CFG *ccp, CCP_COMPARE_STATUS *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                if(READ_BIT(PIR1, _PIR1_CCP1IF_POSITION)){
                    *state = CCP_COMPARE_READY;
#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE))
                    INT_INTERRUPT_CCP1_CLEAR_FLAG();
#endif
                }
                else{
                    *state = CCP_COMPARE_NOT_READY;
                }
                break;
            case CCP2_SOURCE:
                if(READ_BIT(PIR2, _PIR2_CCP2IF_POSITION)){
                    *state = CCP_COMPARE_READY;
#if((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
                    INT_INTERRUPT_CCP2_CLEAR_FLAG();
#endif
                }
                else{
                    *state = CCP_COMPARE_NOT_READY;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType CCP_WRITE_COMPARE_SET_VALUE(const CCP_CFG *ccp, uint16 value){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp || NULL == value){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
               CCPR1 = (uint16)value;
               break;
            case CCP2_SOURCE:
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

#if ((CCP_CFG_PWM_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))

Std_ReturnType CCP_START_PWM(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                if(ccp->ccp_mode == CCP_PWM_MODE){
                    Retval = CCP_PIN_INIT(ccp);
                    CCP1_SET_MODE_CONFIGURATION(CCP_CFG_PWM);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case CCP2_SOURCE:
                if(ccp->ccp_mode == CCP_PWM_MODE){
                    Retval = CCP_PIN_INIT(ccp);
                    CCP2_SET_MODE_CONFIGURATION(CCP_CFG_PWM);
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

Std_ReturnType CCP_STOP_PWM(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                if(ccp->ccp_mode == CCP_PWM_MODE){
                    CCP1_SET_MODE_CONFIGURATION(CCP_CFG_MODULE_DISABLE);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case CCP2_SOURCE:
                if(ccp->ccp_mode == CCP_PWM_MODE){
                    CCP2_SET_MODE_CONFIGURATION(CCP_CFG_MODULE_DISABLE);
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

Std_ReturnType CCP_SET_DUTY_CYCLE(const CCP_CFG *ccp, uint8 duty){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        uint16 duty_cycle_temp = (uint16)(4.0 * (PR2 + 1) * (duty / 100.0));
        switch(ccp->ccp_src){
            case CCP1_SOURCE:
                CCP1CONbits.DC1B = (uint8)(duty_cycle_temp & 0x0003);
                CCPR1L = (uint8)(duty_cycle_temp >> 2);
                break;
            case CCP2_SOURCE:
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

#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE))

void CCP1_ISR(void){
    // 1. Clear CCP Module Flag
    INT_INTERRUPT_CCP1_CLEAR_FLAG();
    // 2. Code
    // 3. Call back Function
    if(CCP1_HANDLER_FUNCTION){
        CCP1_HANDLER_FUNCTION();
    }
}

#endif 

#if((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))

void CCP2_ISR(void){
    // 1. Clear CCP Module Flag
    INT_INTERRUPT_CCP2_CLEAR_FLAG();
    // 2. Code
    // 3. Call back Function
    if(CCP2_HANDLER_FUNCTION){
        CCP2_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType CCP_SET_DISABLE(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        if(ccp->ccp_src == CCP1_SOURCE){
            CCP1_SET_MODE_CONFIGURATION(CCP_CFG_MODULE_DISABLE);
        }
        else if(ccp->ccp_src == CCP2_SOURCE){
            CCP2_SET_MODE_CONFIGURATION(CCP_CFG_MODULE_DISABLE);
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

static Std_ReturnType CCP_PIN_INIT(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{        
        switch(ccp->ccp_mode){
            case CCP_CAPTURE_MODE:
                if(ccp->ccp_src == CCP1_SOURCE){
                    GPIO_PIN_CFG ccp1_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN2, .DIRECTION = GPIO_INPUT};
                    Retval = GPIO_PIN_DIRECTION_INIT(&ccp1_pin);
                }
                else if(ccp->ccp_src == CCP2_SOURCE){
                    GPIO_PIN_CFG ccp2_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN1, .DIRECTION = GPIO_INPUT};
                    Retval = GPIO_PIN_DIRECTION_INIT(&ccp2_pin);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case CCP_COMPARE_MODE:
                if(ccp->ccp_src == CCP1_SOURCE){
                    GPIO_PIN_CFG ccp1_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN2, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
                    Retval = GPIO_PIN_INIT(&ccp1_pin);
                }
                else if(ccp->ccp_src == CCP2_SOURCE){
                    GPIO_PIN_CFG ccp2_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN1, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
                    Retval = GPIO_PIN_INIT(&ccp2_pin);
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case CCP_PWM_MODE:
                if(ccp->ccp_src == CCP1_SOURCE){
                    GPIO_PIN_CFG ccp1_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN2, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
                    Retval = GPIO_PIN_INIT(&ccp1_pin);
                }
                else if(ccp->ccp_src == CCP2_SOURCE){
                    GPIO_PIN_CFG ccp2_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN1, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
                    Retval = GPIO_PIN_INIT(&ccp2_pin);
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

#if ((CCP_CFG_PWM_MODE_SELECTED) != (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) != (CCP2_CFG_SELECTED_MODE))

static Std_ReturnType CCP_SET_CAPTURE_COMPARE_TIMER(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        if(ccp->ccp_timer == CCP1_CCP2_TIMER1){
            CCP_TIMER1_CCP1_CCP2();
        }
        else if(ccp->ccp_timer == CCP1_TIMER1_CCP2_TIMER3){
            CCP_TIMER1_CCP1_TIMER3_CCP2();
        }
        else if(ccp->ccp_timer == CCP1_CCP2_TIMER3){
            CCP_TIMER3_CCP1_CCP2();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#endif

static Std_ReturnType CCP_SET_MODE(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        switch (ccp->ccp_mode){
            // 1. Set CCP Mode
            case CCP_CAPTURE_MODE:
                // 2. Set CCP Mode Configuration
                if(ccp->ccp_cfg == CCP_CFG_CAPTURE_MODE_1_FALLING_EDGE || ccp->ccp_cfg == CCP_CFG_CAPTURE_MODE_1_RISING_EDGE ||
                   ccp->ccp_cfg == CCP_CFG_CAPTURE_MODE_4_RISING_EDGE || ccp->ccp_cfg == CCP_CFG_CAPTURE_MODE_16_RISING_EDGE){
                    // 3. Set CCP Source
                    if(ccp->ccp_src == CCP1_SOURCE){
                        CCP1_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == CCP2_SOURCE){
                        CCP2_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                }
                else{
                    Retval = E_NOT_OK;
                }
                // 4. Set CCP Timer
                Retval = CCP_SET_CAPTURE_COMPARE_TIMER(ccp);
                break;
            case CCP_COMPARE_MODE:
                // 2. Set CCP Mode Configuration
                if(ccp->ccp_cfg == CCP_CFG_COMPARE_MODE_SET_LOGIC || ccp->ccp_cfg == CCP_CFG_COMPARE_MODE_CLEAR_LOGIC ||
                   ccp->ccp_cfg == CCP_CFG_COMPARE_MODE_TOGGLE_LOGIC || ccp->ccp_cfg == CCP_CFG_COMPARE_MODE_GEN_SW_INTERRUPT ||
                   ccp->ccp_cfg == CCP_CFG_COMPARE_MODE_GEN_EVENT){
                    // 3. Set CCP Source
                    if(ccp->ccp_src == CCP1_SOURCE){
                        CCP1_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == CCP2_SOURCE){
                        CCP2_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                }
                else{
                    Retval = E_NOT_OK;
                }
                // 4. Set CCP Timer
                Retval = CCP_SET_CAPTURE_COMPARE_TIMER(ccp);
                break;
            case CCP_PWM_MODE:
                // 2. Set CCP Mode Configuration
                if(ccp->ccp_cfg == CCP_CFG_PWM){
#if ((CCP_CFG_PWM_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))
                    if(ccp->ccp_src == CCP1_SOURCE){
                        // 3. Set CCP Source
                        CCP1_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else if(ccp->ccp_src == CCP2_SOURCE){
                        CCP2_SET_MODE_CONFIGURATION(ccp->ccp_cfg);
                    }
                    else{
                        Retval = E_NOT_OK;
                    }
                    // 4. PWM frequency init
                     PR2 = (uint8)((_XTAL_FREQ/ ((ccp->pwm_freq) * (ccp->pwm_prescaler) * (ccp->pwm_postscaler) * 4.0)) - 1);
#endif
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
        Retval = CCP_PIN_INIT(ccp);
    }
    return Retval;
}

#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))

static Std_ReturnType CCP_CONFIGURE_INTERRUPT(const CCP_CFG *ccp){
    Std_ReturnType Retval = E_OK;
    if(NULL == ccp){
        Retval = E_NOT_OK;
    }
    else{
        if(ccp->ccp_src == CCP1_SOURCE){
            // 1. Enable CCP1 Interrupt
            INT_INTERRUPT_CCP1_ENABLE();
            // 2. Clear CCP1 Flag
            INT_INTERRUPT_CCP1_CLEAR_FLAG();
            // 3. Set CCP1 Priority
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
            INTERRUPT_PRIORITY_BIT_ENABLE();
            GLOBAL_INTERRUPT_HIGH_ENABLE();
            GLOBAL_INTERRUPT_LOW_ENABLE();
            if(ccp->priority == INTERRUPT_HIGH_PRIORITY){
                INT_INTERRUPT_CCP1_HIGH_PRIORITY();
            }
            else if(ccp->priority == INTERRUPT_LOW_PRIORITY){
                INT_INTERRUPT_CCP1_LOW_PRIORITY();
            }
            else{
                Retval = E_NOT_OK;
            }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
            INTERRUPT_PRIORITY_BIT_DISABLE();
            GLOBAL_INTERRUPT_ENABLE();
            PERIPHERAL_INTERRUPT_ENABLE();
#endif
            // 4. Assign Call Back Function
            CCP1_HANDLER_FUNCTION = ccp->ccp_interrupt;
        }
        else if(ccp->ccp_src == CCP2_SOURCE){
            // 1. Enable CCP2 Interrupt
            INT_INTERRUPT_CCP2_ENABLE();
            // 2. Clear CCP2 Flag
            INT_INTERRUPT_CCP2_CLEAR_FLAG();
            // 3. Set CCP1 Priority
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
            INTERRUPT_PRIORITY_BIT_ENABLE();
            GLOBAL_INTERRUPT_HIGH_ENABLE();
            GLOBAL_INTERRUPT_LOW_ENABLE();
            if(ccp->priority == INTERRUPT_HIGH_PRIORITY){
                INT_INTERRUPT_CCP2_HIGH_PRIORITY();
            }
            else if(ccp->priority == INTERRUPT_LOW_PRIORITY){
                INT_INTERRUPT_CCP2_LOW_PRIORITY();
            }
            else{
                Retval = E_NOT_OK;
            }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
            INTERRUPT_PRIORITY_BIT_DISABLE();
            GLOBAL_INTERRUPT_ENABLE();
            PERIPHERAL_INTERRUPT_ENABLE();
#endif
            // 4. Assign Call Back Function
            CCP2_HANDLER_FUNCTION = ccp->ccp_interrupt;
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#endif