/* 
 * File:   HAL_TIMER1.c
 * Author: mohammedel-ahmady
 *
 * Created on August 21, 2025, 6:36 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_TIMER1.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 timer1_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

TIMER1_HANDLER TIMER1_HANDLER_FUNCTION = NULL;

#endif

static Std_ReturnType TIMER1_SET_DISABLE(const TIMER1_CFG *timer1);
static Std_ReturnType TIMER1_SET_ENABLE(const TIMER1_CFG *timer1);
static Std_ReturnType TIMER1_SET_MODE(const TIMER1_CFG *timer1);
static Std_ReturnType TIMER1_SET_PRESCALER(const TIMER1_CFG *timer1);
static Std_ReturnType TIMER1_SET_RW_MODE(const TIMER1_CFG *timer1);

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

static Std_ReturnType TIMER1_CONFIGURE_INTERRUPT(const TIMER1_CFG *timer1);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

/**
 * @brief           : Initialize Timer1 module with provided configuration
 * @param timer1    : Pointer to Timer1 configuration structure @ref TIMER1_CFG
 * @return          : Status of the function
 *      (E_OK)      : Timer1 initialized successfully
 *      (E_NOT_OK)  : Invalid pointer or configuration error
 */

Std_ReturnType TIMER1_INIT(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 1
        Retval = TIMER1_SET_DISABLE(timer1);
        // 2. Set Timer 1 Mode
        Retval = TIMER1_SET_MODE(timer1);
        // 3. Set Timer 1 Prescaller
        Retval = TIMER1_SET_PRESCALER(timer1);
        // 4. Set Timer 1 Read/Write Mode
        Retval = TIMER1_SET_RW_MODE(timer1);
        // 5. init Timer 1 with preloaded value
        TMR1H = (uint8)((timer1->preloaded_value) >> 8);
        TMR1L = (uint8)(timer1->preloaded_value);
        timer1_preloaded_value = timer1->preloaded_value;
        // 6. Configure Timer 1 Interrupt if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))
        Retval = TIMER1_CONFIGURE_INTERRUPT(timer1);
#endif
        // 7. Enable Timer 1
        Retval = TIMER1_SET_ENABLE(timer1);
    }
    return Retval;
}

/**
 * @brief           : De-initialize Timer1 (disable module and interrupt)
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Timer1 deinitialized successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

Std_ReturnType TIMER1_DEINIT(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 1
        Retval = TIMER1_SET_DISABLE(timer1);
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))
        // 2. Disable Timer 1 Interrupt
        INT_INTERRUPT_TIMER1_DISABLE();
        // 3. Clear Timer 1 Flag
        INT_INTERRUPT_TIMER1_CLEAR_FLAG();
#endif        
    }
    return Retval;
}

/**
 * @brief           : Write a new value to Timer1 counter register
 * @param timer1    : Pointer to Timer1 configuration structure
 * @param data      : Value to be written (16-bit)
 * @return          : Status of the function
 *      (E_OK)      : Value written successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

Std_ReturnType TIMER1_WRITE_DATA(const TIMER1_CFG *timer1, uint16 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        TMR1H = (uint8)((data) >> 8);
        TMR1L = (uint8)(data);
    }
    return Retval;
}

/**
 * @brief           : Read the current value from Timer1 counter register
 * @param timer1    : Pointer to Timer1 configuration structure
 * @param data      : Pointer to store the read value (16-bit)
 * @return          : Status of the function
 *      (E_OK)      : Value read successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

Std_ReturnType TIMER1_READ_DATA(const TIMER1_CFG *timer1, uint16 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        uint8 tmr1_high = 0, tmr1_low = 0;
        
        tmr1_high = TMR1H;
        tmr1_low = TMR1L;
        
        *data = (uint16)((tmr1_high << 8) | tmr1_low);
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

/**
 * @brief           : Timer1 Overflow Interrupt Service Routine
 * @note            : Reloads preloaded value and executes callback if registered
 */

void TMR1_ISR(void){
    // 1. clear timer 1 flag
    INT_INTERRUPT_TIMER1_CLEAR_FLAG();
    // 2. code
    TMR1H = (uint8)((timer1_preloaded_value) >> 8);
    TMR1L = (uint8)(timer1_preloaded_value);
    // 3. call back function
    if(TIMER1_HANDLER_FUNCTION){
       TIMER1_HANDLER_FUNCTION(); 
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

/**
 * @brief           : Disable Timer1 module
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Timer1 disabled successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER1_SET_DISABLE(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        TIMER1_MODULE_DISABLE();
    }
    return Retval;
}

/**
 * @brief           : Enable Timer1 module
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Timer1 enabled successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER1_SET_ENABLE(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        TIMER1_MODULE_ENABLE();
    }
    return Retval;
}

/**
 * @brief           : Configure Timer1 mode (Timer or Counter)
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Mode set successfully
 *      (E_NOT_OK)  : Invalid pointer or mode
 */

static Std_ReturnType TIMER1_SET_MODE(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer1->mode){
            case TIMER1_TIMER_MODE:
                // 1. Set Timer1 as timer mode
                TIMER1_INTERNAL_TIMER_MODE();
                // 2. Set Timer1 Oscillator
                if(timer1->osc == TIMER1_OSCILLATOR_ENABLE){
                    TIMER1_OSCILLATOR_ENABLE();
                }
                else{
                    TIMER1_OSCILLATOR_DISABLE();
                }
                break;
            case TIMER1_COUNTER_MODE:
                // 1. Set Timer1 as counter mode
                TIMER1_EXTERNAL_COUNTER_MODE();
                // 2. Initialize Pin as input
                GPIO_PIN_CFG T13CKI_Pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN0, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&T13CKI_Pin);
                // 3. set synchronous or asynchronous
                if(timer1->sync == TIMER1_SYNCHRONCE_COUNTER){
                    TIMER1_SYNCHRONCE_COUNTER_MODE();
                }
                else{
                    TIMER1_ASYNCHRONCE_COUNTER_MODE();
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/**
 * @brief           : Configure Timer1 prescaler value
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Prescaler set successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER1_SET_PRESCALER(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        TIMER1_PRESCALER_SELECT(timer1->prescaler);
    }
    return Retval;
}

/**
 * @brief           : Configure Timer1 read/write mode (8-bit or 16-bit)
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Mode set successfully
 *      (E_NOT_OK)  : Invalid pointer or mode
 */

static Std_ReturnType TIMER1_SET_RW_MODE(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer1->rw_reg){
            case TIMER1_8BIT_RW_MODE:
                TIMER1_8BIT_READ_WRITE_MODE();
                break;
            case TIMER1_16BIT_RW_MODE:
                TIMER1_16BIT_READ_WRITE_MODE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

/**
 * @brief           : Configure Timer1 interrupt settings and callback function
 * @param timer1    : Pointer to Timer1 configuration structure
 * @return          : Status of the function
 *      (E_OK)      : Interrupt configured successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER1_CONFIGURE_INTERRUPT(const TIMER1_CFG *timer1){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer1){
        Retval = E_NOT_OK;
    }
    else{
        INT_INTERRUPT_TIMER1_ENABLE();
        INT_INTERRUPT_TIMER1_CLEAR_FLAG();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        
        if(timer1->priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_TIMER1_HIGH_PRIORITY();
        }
        else if(timer1->priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_TIMER1_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        TIMER1_HANDLER_FUNCTION = timer1->TIMER1_INTERRUPT;
    }
    return Retval;
}

#endif