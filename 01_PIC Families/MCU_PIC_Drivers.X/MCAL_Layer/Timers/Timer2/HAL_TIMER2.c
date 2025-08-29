/* 
 * File:   HAL_TIMER2.c
 * Author: mohammedel-ahmady
 *
 * Created on August 26, 2025, 9:16 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_TIMER2.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint8 timer2_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))

static TIMER2_HANDLER TIMER2_HANDLER_FUNCTION = NULL;

#endif

static Std_ReturnType TIMER2_SET_DISABLE(const TIMER2_CFG *timer2);
static Std_ReturnType TIMER2_SET_ENABLE(const TIMER2_CFG *timer2);
static Std_ReturnType TIMER2_SET_PRESCALER(const TIMER2_CFG *timer2);
static Std_ReturnType TIMER2_SET_POSTSCALER(const TIMER2_CFG *timer2);

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))

static Std_ReturnType TIMER2_CONFIGURE_INTERRUPT(const TIMER2_CFG *timer2);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

/**
 * @brief           : This function initializes Timer2 based on the provided configuration.
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed or configuration error
 */

Std_ReturnType TIMER2_INIT(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 2
        Retval = TIMER2_SET_DISABLE(timer2);
        // 2. Set Timer 2 Prescaler
        Retval = TIMER2_SET_PRESCALER(timer2);
        // 3. Set Timer 2 Postscaler
        Retval = TIMER2_SET_POSTSCALER(timer2);
        // 4. Initialize Timer 2 with Preloaded Value
        TMR2 = timer2->preloaded_value;
        timer2_preloaded_value = timer2->preloaded_value;
        // 5. Configure Timer 2 Interrupt if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))
        Retval = TIMER2_CONFIGURE_INTERRUPT(timer2);
#endif
        // 6. Enable Timer 2
        Retval = TIMER2_SET_ENABLE(timer2);
    }
    return Retval;
}

/**
 * @brief           : This function de-initializes Timer2 and disables its interrupt if enabled.
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_DEINIT(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 2
        Retval = TIMER2_SET_DISABLE(timer2);
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))
        // 2. Disable Timer 2 Interrupts
        INT_INTERRUPT_TIMER2_DISABLE();
        // 3. Clear Timer 2 Flag
        INT_INTERRUPT_TIMER2_CLEAR_FLAG();
#endif
    }
    return Retval;
}

/**
 * @brief           : This function writes a specific value into Timer2 register (TMR2).
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @param data      : The value to be written into TMR2 register
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_WRITE_DATA(const TIMER2_CFG *timer2, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TMR2 = data;
    }
    return Retval;
}

/**
 * @brief           : This function reads the current value from Timer2 register (TMR2).
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @param data      : Pointer to store the read value
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_READ_DATA(const TIMER2_CFG *timer2, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2 || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        *data = TMR2;
    }
    return Retval;
}

 #if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))


/**
 * @brief           : Timer2 Interrupt Service Routine (ISR). Clears the interrupt flag, reloads preloaded value, and executes callback.
 * @note            : This function should be linked to the interrupt vector.
 */

void TMR2_ISR(void){
    // 1. Clear Flag
    INT_INTERRUPT_TIMER2_CLEAR_FLAG();
    // 2. Code
    TMR2 = timer2_preloaded_value;
//    TMR2 = timer2_preloaded_value;
    // 3. Call back function
    if(TIMER2_HANDLER_FUNCTION){
        TIMER2_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

/**
 * @brief           : Disables Timer2 module.
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_SET_DISABLE(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TIMER2_MODULE_DISABLE();
    }
    return Retval;
}

/**
 * @brief           : Enables Timer2 module.
 * @param timer2    : Pointer to the Timer2 configuration structure. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_SET_ENABLE(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TIMER2_MODULE_ENABLE();
    }
    return Retval;
}

/**
 * @brief           : Configures the prescaler for Timer2.
 * @param timer2    : Pointer to the Timer2 configuration structure containing prescaler setting. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_SET_PRESCALER(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TIMER2_SELECT_PRESCALER(timer2->prescaler);
    }
    return Retval;
}

/**
 * @brief           : Configures the postscaler for Timer2.
 * @param timer2    : Pointer to the Timer2 configuration structure containing postscaler setting. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed
 */

Std_ReturnType TIMER2_SET_POSTSCALER(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        TIMER2_SELECT_POSTSCALER(timer2->postscaler);
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))

/**
 * @brief           : Configures and enables Timer2 interrupt based on the provided configuration.
 * @param timer2    : Pointer to the Timer2 configuration structure containing interrupt settings. @ref TIMER2_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : Null pointer passed or invalid priority
 */

Std_ReturnType TIMER2_CONFIGURE_INTERRUPT(const TIMER2_CFG *timer2){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer2){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Enable Timer 2 Interrupt
        INT_INTERRUPT_TIMER2_ENABLE();
        // 2. Clear Timer 2 Interrupt
        INT_INTERRUPT_TIMER2_CLEAR_FLAG();
        // 3. Set Timer 2 Interrupt Priority
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        if(timer2->priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_TIMER2_HIGH_PRIORITY();
        }
        else if(timer2->priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_TIMER2_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        TIMER2_HANDLER_FUNCTION = timer2->TIMER2_INTERRUPT;
    }
    return Retval;
}

#endif