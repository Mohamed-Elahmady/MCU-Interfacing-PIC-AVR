/* 
 * File:   HAL_TIMER3.c
 * Author: mohammedel-ahmady
 *
 * Created on August 30, 2025, 2:07 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_TIMER3.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 timer3_preloaded_value = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
static TIMER3_HANDLER TIMER3_HANDLER_FUNCTION = NULL;
#endif

static Std_ReturnType TIMER3_SET_DISABLE(const TIMER3_CFG *timer3);
static Std_ReturnType TIMER3_SET_ENABLE(const TIMER3_CFG *timer3);
static Std_ReturnType TIMER3_SET_MODE(const TIMER3_CFG *timer3);
static Std_ReturnType TIMER3_SET_PRESCALER(const TIMER3_CFG *timer3);
static Std_ReturnType TIMER3_SET_RW_MODE(const TIMER3_CFG *timer3);

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))

static Std_ReturnType TIMER3_CONFIGURE_INTERRUPT(const TIMER3_CFG *timer3);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

/**
 * @brief           : This function initializes Timer3 module with user configurations
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType TIMER3_INIT(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 3
        Retval = TIMER3_SET_DISABLE(timer3);
        // 2. Set Timer 3 Mode
        Retval = TIMER3_SET_MODE(timer3);
        // 3. Set Timer 3 Prescaler
        Retval = TIMER3_SET_PRESCALER(timer3);
        // 4. Set Timer 3 R/W Register Size
        Retval = TIMER3_SET_RW_MODE(timer3);
        // 5. Initialize Timer 3 with pre-loaded value
        TMR3H = (uint8)((timer3->preloaded_value) >> 8);
        TMR3L = (uint8)((timer3->preloaded_value));
        timer3_preloaded_value = timer3->preloaded_value;
        // 6. Configure Timer 3 Interrupt
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
        Retval = TIMER3_CONFIGURE_INTERRUPT(timer3);
#endif
        // 7. Enable Timer 3
        Retval = TIMER3_SET_ENABLE(timer3);
    }
    return Retval;
}

/**
 * @brief           : This function de-initializes Timer3 module (disable & stop interrupt)
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType TIMER3_DEINIT(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable Timer 3
        Retval = TIMER3_SET_DISABLE(timer3);
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
        // 2. Disable Timer 3 Interrupt
        INT_INTERRUPT_TIMER3_DISABLE();
        // 3. Clear Timer 3 Flag
        INT_INTERRUPT_TIMER3_CLEAR_FLAG();
#endif  
    }
    return Retval;
}

/**
 * @brief           : This function writes a 16-bit data value into Timer3 register
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @param data      : 16-bit value to be written into TMR3 register
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType TIMER3_WRITE_DATA(const TIMER3_CFG *timer3, uint16 data){
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

/**
 * @brief           : This function reads a 16-bit data value from Timer3 register
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @param data      : Pointer to variable to store the read value
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType TIMER3_READ_DATA(const TIMER3_CFG *timer3, uint16 *data){
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

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))

/**
 * @brief           : Timer3 Interrupt Service Routine
 * @note            : Clears the interrupt flag, reloads pre-loaded value, and calls user ISR handler
 * @param void
 * @return void
 */

void TMR3_ISR(void){
    // 1. clear timer 3 flag
    INT_INTERRUPT_TIMER3_CLEAR_FLAG();
    // 2. code
    TMR3H = (uint8)((timer3_preloaded_value) >> 8);
    TMR3L = (uint8)(timer3_preloaded_value);
    // 3. call back function
    if(TIMER3_HANDLER_FUNCTION){
       TIMER3_HANDLER_FUNCTION(); 
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

/**
 * @brief           : This function disables Timer3 module
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_SET_DISABLE(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        TIMER3_MODULE_DISABLE();
    }
    return Retval;
}

/**
 * @brief           : This function enables Timer3 module
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_SET_ENABLE(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        TIMER3_MODULE_ENABLE();
    }
    return Retval;
}

/**
 * @brief           : This function sets Timer3 mode (Timer / Counter)
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_SET_MODE(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer3->mode){
            case TIMER3_TIMER_MODE:
                // 1. Set Timer3 as timer mode
                TIMER3_INTERNAL_TIMER_MODE();
                break;
            case TIMER3_COUNTER_MODE:
                // 1. Set Timer3 as counter mode
                TIMER3_EXTERNAL_COUNTER_MODE();
                
                // 2. Initialize Pin as input
                GPIO_PIN_CFG T13CKI_Pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN0, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&T13CKI_Pin);
                
                // 3. Set Timer1 Oscillator
                if(timer3->osc == TIMER1_OSCILLATOR_ENABLE){
                    TIMER1_OSCILLATOR_ENABLE();
                }
                else{
                    TIMER1_OSCILLATOR_DISABLE();
                }
                
                // 4. set synchronous or asynchronous
                if(timer3->sync == TIMER3_SYNCHRONOUS_COUNTER){
                    TIMER3_SYNCHRONOUS_COUNTER_MODE();
                }
                else{
                    TIMER3_ASYNCHRONOUS_COUNTER_MODE();
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
 * @brief           : This function configures Timer3 prescaler
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_SET_PRESCALER(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        TIMER3_PRESCALER_SELECT(timer3->prescaler);
    }
    return Retval;
}

/**
 * @brief           : This function configures Timer3 Read/Write mode (8-bit / 16-bit)
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_SET_RW_MODE(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        switch(timer3->rw_reg){
            case TIMER3_8BIT_RW_MODE:
                TIMER3_8BIT_READ_WRITE_MODE();
                break;
            case TIMER3_16BIT_RW_MODE:
                TIMER3_16BIT_READ_WRITE_MODE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))

/**
 * @brief           : This function configures Timer3 interrupt and set user ISR handler
 * @param timer3    : Pointer to Timer3 configurations @ref : TIMER3_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

static Std_ReturnType TIMER3_CONFIGURE_INTERRUPT(const TIMER3_CFG *timer3){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer3){
        Retval = E_NOT_OK;
    }
    else{
        INT_INTERRUPT_TIMER3_ENABLE();
        INT_INTERRUPT_TIMER3_CLEAR_FLAG();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        
        if(timer3->priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_TIMER3_HIGH_PRIORITY();
        }
        else if(timer3->priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_TIMER3_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        TIMER3_HANDLER_FUNCTION = timer3->TIMER3_INTERRUPT;
    }
    return Retval;
}

#endif