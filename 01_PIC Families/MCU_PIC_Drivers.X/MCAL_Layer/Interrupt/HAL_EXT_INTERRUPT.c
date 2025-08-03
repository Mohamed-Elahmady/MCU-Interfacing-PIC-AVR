/* 
 * File:   HAL_EXT_INTERRUPT.c
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:03 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_EXT_INTERRUPT.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

// ISR Pointer to functions

static INTERRUPT_HANDLER INT0_INTERRUPT_HANDLER = NULL;
static INTERRUPT_HANDLER INT1_INTERRUPT_HANDLER = NULL;
static INTERRUPT_HANDLER INT2_INTERRUPT_HANDLER = NULL;

static INTERRUPT_HANDLER RB4_INTERRUPT_HANDLER_CHANGE_HIGH = NULL;
static INTERRUPT_HANDLER RB5_INTERRUPT_HANDLER_CHANGE_HIGH = NULL;
static INTERRUPT_HANDLER RB6_INTERRUPT_HANDLER_CHANGE_HIGH = NULL;
static INTERRUPT_HANDLER RB7_INTERRUPT_HANDLER_CHANGE_HIGH = NULL;

static INTERRUPT_HANDLER RB4_INTERRUPT_HANDLER_CHANGE_LOW = NULL;
static INTERRUPT_HANDLER RB5_INTERRUPT_HANDLER_CHANGE_LOW = NULL;
static INTERRUPT_HANDLER RB6_INTERRUPT_HANDLER_CHANGE_LOW = NULL;
static INTERRUPT_HANDLER RB7_INTERRUPT_HANDLER_CHANGE_LOW = NULL;

// helper Functions for INTX pins

static Std_ReturnType INTERRUPT_INTX_PIN_INIT(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INTERRUPT_INTX_CLEAR_FLAG(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INTERRUPT_INTX_DISABLE(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INTERRUPT_INTX_ENABLE(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INTERRUPT_INTX_PRIORTIY_INIT(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INTERRUPT_INTX_EDGE_INIT(const INTERRUPT_INTX *int_pin);

static Std_ReturnType INTX_SET_HANDLER(const INTERRUPT_INTX *int_pin);
static Std_ReturnType INT0_SET_HANDLER(void (* INTERRUPT_HANDLER)(void));
static Std_ReturnType INT1_SET_HANDLER(void (* INTERRUPT_HANDLER)(void));
static Std_ReturnType INT2_SET_HANDLER(void (* INTERRUPT_HANDLER)(void));

// helper Functions for RBX pins

static Std_ReturnType INTERRUPT_RBX_PIN_INIT(const INTERRUPT_RBX *int_pin);
static Std_ReturnType INTERRUPT_RBX_CLEAR_FLAG(const INTERRUPT_RBX *int_pin);
static Std_ReturnType INTERRUPT_RBX_DISABLE(const INTERRUPT_RBX *int_pin);
static Std_ReturnType INTERRUPT_RBX_ENABLE(const INTERRUPT_RBX *int_pin);
static Std_ReturnType INTERRUPT_RBX_PRIORTIY_INIT(const INTERRUPT_RBX *int_pin);

static Std_ReturnType RBX_SET_HANDLER(const INTERRUPT_RBX *int_pin);
static Std_ReturnType RB4_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW);
static Std_ReturnType RB5_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW);
static Std_ReturnType RB6_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW);
static Std_ReturnType RB7_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType EXTERNAL_INTERRUPT_INTX_INIT(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Interrupt before initialization 
        Retval = INTERRUPT_INTX_DISABLE(int_pin);
        // 2. Clear Interrupt flag
        Retval = INTERRUPT_INTX_CLEAR_FLAG(int_pin);
        // 3. Configure Interrupt Edge
        Retval = INTERRUPT_INTX_EDGE_INIT(int_pin);
        // 4. Configure Interrupt Priority if needed
        #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        Retval = INTERRUPT_INTX_PRIORTIY_INIT(int_pin);
        #endif
        // 5. Configure Interrupt Pin Initialization
        Retval = INTERRUPT_INTX_PIN_INIT(int_pin);
        // 6. Configure Interrupt Call back function
        Retval = INTX_SET_HANDLER(int_pin);
        // 7. Enable INTX interrupt
        Retval = INTERRUPT_INTX_ENABLE(int_pin);
    }
    return Retval;
}

Std_ReturnType EXTERNAL_INTERRUPT_INTX_DEINIT(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        Retval = INTERRUPT_INTX_DISABLE(int_pin);
    }
    return Retval;
}

void INT0_ISR(void){
    // You must Clear Flag First
    EXT_INTERRUPT_INT0_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(INT0_INTERRUPT_HANDLER){
        INT0_INTERRUPT_HANDLER();
    }
}

void INT1_ISR(void){
    // You must Clear Flag First
    EXT_INTERRUPT_INT1_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(INT1_INTERRUPT_HANDLER){
        INT1_INTERRUPT_HANDLER();
    }
}

void INT2_ISR(void){
    // You must Clear Flag First
    EXT_INTERRUPT_INT2_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(INT2_INTERRUPT_HANDLER){
        INT2_INTERRUPT_HANDLER();
    }
}

Std_ReturnType EXTERNAL_INTERRUPT_RBX_INIT(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Interrupt before initialization 
        Retval = INTERRUPT_RBX_DISABLE(int_pin);
        // 2. Clear Interrupt flag
        Retval = INTERRUPT_RBX_CLEAR_FLAG(int_pin);
        // 3. Configure Interrupt Priority if needed
        #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        Retval = INTERRUPT_RBX_PRIORTIY_INIT(int_pin);
        #endif
        // 4. Configure Interrupt Pin Initialization
        Retval = INTERRUPT_RBX_PIN_INIT(int_pin);
        // 5. Configure Interrupt Call back function
        Retval = RBX_SET_HANDLER(int_pin);
        // 6. Enable RBX interrupt
        Retval = INTERRUPT_RBX_ENABLE(int_pin);
    }
    return Retval;
}

Std_ReturnType EXTERNAL_INTERRUPT_RBX_DEINIT(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        Retval = INTERRUPT_RBX_DISABLE (int_pin);
    }
    return Retval;
}

void RB4_ISR(uint8 change){
    // You must Clear Flag First
    EXT_INTERRUPT_RBX_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(change == CHANGE_HIGH){
        if(RB4_INTERRUPT_HANDLER_CHANGE_HIGH){
            RB4_INTERRUPT_HANDLER_CHANGE_HIGH();
        }
    }
    else if(change == CHANGE_LOW){
        if(RB4_INTERRUPT_HANDLER_CHANGE_LOW){
            RB4_INTERRUPT_HANDLER_CHANGE_LOW();
        }
    }
}

void RB5_ISR(uint8 change){
    // You must Clear Flag First
    EXT_INTERRUPT_RBX_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(change == CHANGE_HIGH){
        if(RB5_INTERRUPT_HANDLER_CHANGE_HIGH){
            RB5_INTERRUPT_HANDLER_CHANGE_HIGH();
        }
    }
    else if(change == CHANGE_LOW){
        if(RB5_INTERRUPT_HANDLER_CHANGE_LOW){
            RB5_INTERRUPT_HANDLER_CHANGE_LOW();
        }
    }
}

void RB6_ISR(uint8 change){
    // You must Clear Flag First
    EXT_INTERRUPT_RBX_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(change == CHANGE_HIGH){
        if(RB6_INTERRUPT_HANDLER_CHANGE_HIGH){
            RB6_INTERRUPT_HANDLER_CHANGE_HIGH();
        }
    }
    else if(change == CHANGE_LOW){
        if(RB6_INTERRUPT_HANDLER_CHANGE_LOW){
            RB6_INTERRUPT_HANDLER_CHANGE_LOW();
        }
    }
}

void RB7_ISR(uint8 change){
    // You must Clear Flag First
    EXT_INTERRUPT_RBX_CLEAR_FLAG();
    // Code
    
    // Call Back Function
    if(change == CHANGE_HIGH){
        if(RB7_INTERRUPT_HANDLER_CHANGE_HIGH){
            RB7_INTERRUPT_HANDLER_CHANGE_HIGH();
        }
    }
    else if(change == CHANGE_LOW){
        if(RB7_INTERRUPT_HANDLER_CHANGE_LOW){
            RB7_INTERRUPT_HANDLER_CHANGE_LOW();
        }
    }
}

/******************* Section 4:  Helper Functions Definitions *******************/

// helper Functions for INTX pins

static Std_ReturnType INTERRUPT_INTX_PIN_INIT(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INIT(&(int_pin->pin));
    }
    return Retval;
}

static Std_ReturnType INTERRUPT_INTX_CLEAR_FLAG(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch (int_pin->source){
            case INTERRUPT_INT0:
                EXT_INTERRUPT_INT0_CLEAR_FLAG();
                break;
            case INTERRUPT_INT1:
                EXT_INTERRUPT_INT1_CLEAR_FLAG();
                break;
            case INTERRUPT_INT2:
                EXT_INTERRUPT_INT2_CLEAR_FLAG();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType INTERRUPT_INTX_DISABLE(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch (int_pin->source){
            case INTERRUPT_INT0:
                EXT_INTERRUPT_INT0_DISABLE();
                break;
            case INTERRUPT_INT1:
                EXT_INTERRUPT_INT1_DISABLE();
                break;
            case INTERRUPT_INT2:
                EXT_INTERRUPT_INT2_DISABLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType INTERRUPT_INTX_ENABLE(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch (int_pin->source){
            case INTERRUPT_INT0:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                EXT_INTERRUPT_INT0_ENABLE();
                break;
            case INTERRUPT_INT1:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                EXT_INTERRUPT_INT1_ENABLE();
                break;
            case INTERRUPT_INT2:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                EXT_INTERRUPT_INT2_ENABLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

static Std_ReturnType INTERRUPT_INTX_PRIORTIY_INIT(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch (int_pin->source){
            case INTERRUPT_INT0:
                if(INTERRUPT_HIGH_PRIORITY != int_pin->priority){
                    Retval = E_NOT_OK;
                }
                break;
            case INTERRUPT_INT1:
                if(INTERRUPT_HIGH_PRIORITY == int_pin->priority){
                    EXT_INTERRUPT_INT1_HIGH_PRIORITY();
                }
                else if(INTERRUPT_LOW_PRIORITY == int_pin->priority){
                    EXT_INTERRUPT_INT1_LOW_PRIORITY();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case INTERRUPT_INT2:
                if(INTERRUPT_HIGH_PRIORITY == int_pin->priority){
                    EXT_INTERRUPT_INT2_HIGH_PRIORITY();
                }
                else if(INTERRUPT_LOW_PRIORITY == int_pin->priority){
                    EXT_INTERRUPT_INT2_LOW_PRIORITY();
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

#endif

static Std_ReturnType INTERRUPT_INTX_EDGE_INIT(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch (int_pin->source){
            case INTERRUPT_INT0:
                if(INTERRUPT_RISING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT0_RISING_EDGE();
                }
                else if(INTERRUPT_FALLING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT0_FALLING_EDGE();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case INTERRUPT_INT1:
                if(INTERRUPT_RISING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT1_RISING_EDGE();
                }
                else if(INTERRUPT_FALLING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT1_FALLING_EDGE();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case INTERRUPT_INT2:
                if(INTERRUPT_RISING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT2_RISING_EDGE();
                }
                else if(INTERRUPT_FALLING_EDGE == int_pin->edge){
                    EXT_INTERRUPT_INT2_FALLING_EDGE();
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

static Std_ReturnType INTX_SET_HANDLER(const INTERRUPT_INTX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch(int_pin->source){
            case INTERRUPT_INT0:
                Retval = INT0_SET_HANDLER(int_pin->INTERRUPT_ISR);
                break;
            case INTERRUPT_INT1:
                Retval = INT1_SET_HANDLER(int_pin->INTERRUPT_ISR);
                break;
            case INTERRUPT_INT2:
                Retval = INT2_SET_HANDLER(int_pin->INTERRUPT_ISR);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType INT0_SET_HANDLER(void (* INTERRUPT_HANDLER)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER){
        Retval = E_NOT_OK;
    }
    else{
        INT0_INTERRUPT_HANDLER = INTERRUPT_HANDLER;
    }
    return Retval;
}

static Std_ReturnType INT1_SET_HANDLER(void (* INTERRUPT_HANDLER)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER){
        Retval = E_NOT_OK;
    }
    else{
        INT1_INTERRUPT_HANDLER = INTERRUPT_HANDLER;
    }
    return Retval;
}

static Std_ReturnType INT2_SET_HANDLER(void (* INTERRUPT_HANDLER)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER){
        Retval = E_NOT_OK;
    }
    else{
        INT2_INTERRUPT_HANDLER = INTERRUPT_HANDLER;
    }
    return Retval;
}

// helper Functions for RBX pins

static Std_ReturnType INTERRUPT_RBX_PIN_INIT(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INIT(&(int_pin->pin));
    }
    return Retval;
}

static Std_ReturnType INTERRUPT_RBX_CLEAR_FLAG(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        EXT_INTERRUPT_RBX_CLEAR_FLAG();
    }
    return Retval;
}

static Std_ReturnType INTERRUPT_RBX_DISABLE(const INTERRUPT_RBX *int_pin) {
    Std_ReturnType Retval = E_OK;
    if (NULL == int_pin) {
        Retval = E_NOT_OK;
    }
    else {
        switch (int_pin->source) {
            case INTERRUPT_RB4:
                DISABLE_EXT_INTERRUPT_IOC_ON_RB4();
                break;
            case INTERRUPT_RB5:
                DISABLE_EXT_INTERRUPT_IOC_ON_RB5();
                break;
            case INTERRUPT_RB6:
                DISABLE_EXT_INTERRUPT_IOC_ON_RB6();
                break;
            case INTERRUPT_RB7:
                DISABLE_EXT_INTERRUPT_IOC_ON_RB7();
                break;
            default:
                Retval = E_NOT_OK;
                break;
        }

        if ((IOCBbits.IOCB4 == INTERRUPT_DISABLE) && (IOCBbits.IOCB5 == INTERRUPT_DISABLE) 
           && (IOCBbits.IOCB6 == INTERRUPT_DISABLE) && (IOCBbits.IOCB7 == INTERRUPT_DISABLE)) {
            EXT_INTERRUPT_RBX_DISABLE();
        }

    }
    return Retval;
}

static Std_ReturnType INTERRUPT_RBX_ENABLE(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch(int_pin->source){
            case INTERRUPT_RB4:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                ENABLE_EXT_INTERRUPT_IOC_ON_RB4();
                EXT_INTERRUPT_RBX_ENABLE();
                break;
            case INTERRUPT_RB5:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                ENABLE_EXT_INTERRUPT_IOC_ON_RB5();
                EXT_INTERRUPT_RBX_ENABLE();
                break;
            case INTERRUPT_RB6:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                ENABLE_EXT_INTERRUPT_IOC_ON_RB6();
                EXT_INTERRUPT_RBX_ENABLE();
                break;
            case INTERRUPT_RB7:
                #if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_ENABLE();
                GLOBAL_INTERRUPT_LOW_ENABLE();
                GLOBAL_INTERRUPT_HIGH_ENABLE();
                #elif((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
                INTERRUPT_PRIORITY_BIT_DISABLE();
                PERIPHERAL_INTERRUPT_ENABLE();
                GLOBAL_INTERRUPT_ENABLE();
                #endif
                ENABLE_EXT_INTERRUPT_IOC_ON_RB7();
                EXT_INTERRUPT_RBX_ENABLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

static Std_ReturnType INTERRUPT_RBX_PRIORTIY_INIT(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch(int_pin->priority){
            case INTERRUPT_HIGH_PRIORITY:
                EXT_INTERRUPT_RBX_HIGH_PRIORITY();
                break;
            case INTERRUPT_LOW_PRIORITY:
                EXT_INTERRUPT_RBX_LOW_PRIORITY();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#endif

static Std_ReturnType RBX_SET_HANDLER(const INTERRUPT_RBX *int_pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == int_pin){
        Retval = E_NOT_OK;
    }
    else{
        switch(int_pin->source){
            case INTERRUPT_RB4:
                Retval = RB4_SET_HANDLER(int_pin->INTERRUPT_ISR_CHANGE_HIGH, int_pin->INTERRUPT_ISR_CHANGE_LOW);
                break;
            case INTERRUPT_RB5:
                Retval = RB5_SET_HANDLER(int_pin->INTERRUPT_ISR_CHANGE_HIGH, int_pin->INTERRUPT_ISR_CHANGE_LOW);
                break;
            case INTERRUPT_RB6:
                Retval = RB6_SET_HANDLER(int_pin->INTERRUPT_ISR_CHANGE_HIGH, int_pin->INTERRUPT_ISR_CHANGE_LOW);
                break;
            case INTERRUPT_RB7:
                Retval = RB7_SET_HANDLER(int_pin->INTERRUPT_ISR_CHANGE_HIGH, int_pin->INTERRUPT_ISR_CHANGE_LOW);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType RB4_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER_HIGH || NULL == INTERRUPT_HANDLER_LOW){
        Retval = E_NOT_OK;
    }
    else{
        RB4_INTERRUPT_HANDLER_CHANGE_HIGH = INTERRUPT_HANDLER_HIGH;
        RB4_INTERRUPT_HANDLER_CHANGE_LOW  = INTERRUPT_HANDLER_LOW;
    }
    return Retval;
}

static Std_ReturnType RB5_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER_HIGH || NULL == INTERRUPT_HANDLER_LOW){
        Retval = E_NOT_OK;
    }
    else{
        RB5_INTERRUPT_HANDLER_CHANGE_HIGH = INTERRUPT_HANDLER_HIGH;
        RB5_INTERRUPT_HANDLER_CHANGE_LOW  = INTERRUPT_HANDLER_LOW;
    }
    return Retval;
}

static Std_ReturnType RB6_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER_HIGH || NULL == INTERRUPT_HANDLER_LOW){
        Retval = E_NOT_OK;
    }
    else{
        RB6_INTERRUPT_HANDLER_CHANGE_HIGH = INTERRUPT_HANDLER_HIGH;
        RB6_INTERRUPT_HANDLER_CHANGE_LOW  = INTERRUPT_HANDLER_LOW;
    }
    return Retval;
}

static Std_ReturnType RB7_SET_HANDLER(INTERRUPT_HANDLER INTERRUPT_HANDLER_HIGH, INTERRUPT_HANDLER INTERRUPT_HANDLER_LOW){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTERRUPT_HANDLER_HIGH || NULL == INTERRUPT_HANDLER_LOW){
        Retval = E_NOT_OK;
    }
    else{
        RB7_INTERRUPT_HANDLER_CHANGE_HIGH = INTERRUPT_HANDLER_HIGH;
        RB7_INTERRUPT_HANDLER_CHANGE_LOW  = INTERRUPT_HANDLER_LOW;
    }
    return Retval;
}