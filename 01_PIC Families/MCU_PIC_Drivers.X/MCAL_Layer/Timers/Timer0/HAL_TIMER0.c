/* 
 * File:   HAL_TIMER0.c
 * Author: mohammedel-ahmady
 *
 * Created on August 18, 2025, 7:16 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_TIMER0.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint16 TIMER0_PRELOADED = 0;

/******************* Section 2 :  Helper Functions Declarations *******************/

#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
static TIMER0_HANDLER TIMER0_HANDLER_FUNCTION = NULL;
#endif

static Std_ReturnType TIMER0_SET_DISABLE(const TIMER0_CFG *timer0);
static Std_ReturnType TIMER0_SET_RESOLUTION(const TIMER0_CFG *timer0);
static Std_ReturnType TIMER0_SET_MODE(const TIMER0_CFG *timer0);
static Std_ReturnType TIMER0_SET_COUNTER_EDGE(const TIMER0_CFG *timer0);
static Std_ReturnType TIMER0_SET_PRESCALAR(const TIMER0_CFG *timer0);

#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
static Std_ReturnType TIMER0_CONFIGURE_INTERRUPT(const TIMER0_CFG *timer0);
#endif

static Std_ReturnType TIMER0_SET_ENABLE(const TIMER0_CFG *timer0);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

/**
 * @brief           : Initialize Timer0 peripheral with the given configuration
 * @param timer0    : Pointer to TIMER0_CFG structure contains configuration parameters
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or configuration issue
 */

Std_ReturnType TIMER0_INIT(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        // 1. Disable Timer 0
        Retval = TIMER0_SET_DISABLE(timer0);
        // 2. Set Timer 0 Resolution
        Retval = TIMER0_SET_RESOLUTION(timer0);
        // 3. Set Timer 0 Mode
        Retval = TIMER0_SET_MODE(timer0);
        // 4. Select mode edge if needed "counter mode"
        Retval = TIMER0_SET_COUNTER_EDGE(timer0);
        // 5. Set Prescaler if needed
        Retval = TIMER0_SET_PRESCALAR(timer0);
        // 6. initialize Timer Registers values " TMR0L = 0, TMR0H = 0"
        TMR0H = (uint8)((timer0->TIMER0_PRELOAD_VALUE) >> 8);
        TMR0L = (uint8)(timer0->TIMER0_PRELOAD_VALUE);
        TIMER0_PRELOADED = timer0->TIMER0_PRELOAD_VALUE;
        // 7. configure interrupt
#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
        Retval = TIMER0_CONFIGURE_INTERRUPT(timer0);
#endif
        // 8. Enable Timer 0
        Retval = TIMER0_SET_ENABLE(timer0);
    }
    return Retval;
}

/**
 * @brief           : De-initialize Timer0 peripheral (disable and clear flags)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */
Std_ReturnType TIMER0_DEINIT(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        // 1. Disable Timer 0
        Retval = TIMER0_SET_DISABLE(timer0);
#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
        // 2. Disable Timer 0 Interrupt
        INT_INTERRUPT_TIMER0_DISABLE();
        // 3. Clear Timer 0 Interrupt Flag
        INT_INTERRUPT_TIMER0_CLEAR_FLAG();
#endif
    }
    return Retval;
}

/**
 * @brief           : Write a 16-bit preload value into Timer0 registers
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @param data      : 16-bit value to be written into TMR0H:TMR0L
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

Std_ReturnType TIMER0_WRITE_DATA(const TIMER0_CFG *timer0, uint16 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        TMR0H = (uint8)(data >> 8);
        TMR0L = (uint8)(data);
    }
    return Retval;
}

/**
 * @brief           : Read the current 16-bit value from Timer0 registers
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @param data      : Pointer to store the 16-bit timer value
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

Std_ReturnType TIMER0_READ_DATA(const TIMER0_CFG *timer0, uint16 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0 || NULL == data){
        Retval= E_NOT_OK;
    }
    else{
        uint8 tmr0_high = 0, tmr0_low = 0;;
        tmr0_high = TMR0H;
        tmr0_low = TMR0L;
        *data = (uint16)((tmr0_high << 8) | tmr0_low);
    }
    return Retval;
}

#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))

/**
 * @brief           : Disable Timer0 module
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

void TMR0_ISR(void){
    // 1. Clear Timer 0 Flag
    INT_INTERRUPT_TIMER0_CLEAR_FLAG();
    // 2. Code
    TMR0H = (uint8)(TIMER0_PRELOADED >> 8);
    TMR0L = (uint8)(TIMER0_PRELOADED);
    // 3. Call back function
    if(TIMER0_HANDLER_FUNCTION){
        TIMER0_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

/**
 * @brief           : Disable Timer0 module
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER0_SET_DISABLE(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        TIMER0_MODULE_DISABLE();
    }
    return Retval;
}

/**
 * @brief           : Configure Timer0 resolution (8-bit or 16-bit)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or invalid resolution
 */

static Std_ReturnType TIMER0_SET_RESOLUTION(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        switch(timer0->resolution){
            case TIMER0_8BIT_RESOLUTION:
                TIMER0_RESOLUTION_8BIT_MODE();
                break;
            case TIMER0_16BIT_RESOLUTION:
                TIMER0_RESOLUTION_16BIT_MODE();
                break;
            default :
                Retval= E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/**
 * @brief           : Configure Timer0 mode (Timer mode / Counter mode)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or invalid mode
 */

static Std_ReturnType TIMER0_SET_MODE(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        switch(timer0->mode){
            case TIMER0_TIMER_MODE:{
                TIMER0_INTERNAL_OSCILLATOR_TIMER_MODE();
                break;
            }
            case TIMER0_COUNTER_MODE:{
                TIMER0_EXTERNAL_OSCILLATOR_COUNTER_MODE();
                GPIO_PIN_CFG T0CKI_pin = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN4, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&T0CKI_pin);
                break;
            }
            default :
                Retval= E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/**
 * @brief           : Configure Timer0 counter edge selection (Rising/Falling)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or wrong mode
 */

static Std_ReturnType TIMER0_SET_COUNTER_EDGE(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        if(timer0->mode == TIMER0_TIMER_MODE){
            /* Nothing*/
        }
        else if(timer0->mode == TIMER0_COUNTER_MODE){
            switch(timer0->edge){
            case TIMER0_RISING_EDGE:
                TIMER0_COUNTER_MODE_RISING_EDGE();
                break;
            case TIMER0_FALLING_EDGE:
                TIMER0_COUNTER_MODE_FALLING_EDGE();
                break;
            default :
                Retval= E_NOT_OK;
                break;
            }
        }
        else{
            Retval= E_NOT_OK;
        }
    }
    return Retval;
}

/**
 * @brief           : Configure Timer0 prescaler (enable/disable and set value)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or invalid configuration
 */

static Std_ReturnType TIMER0_SET_PRESCALAR(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        if(timer0->prescalar == TIMER0_PRESCALER_CFG_DISABLE){
            TIMER0_PRESCALER_DISABLE();
        }
        else if(timer0->prescalar == TIMER0_PRESCALER_CFG_ENABLE){
            TIMER0_PRESCALER_ENABLE();
            T0CONbits.T0PS = timer0->pre_value;
        }
        else{
            Retval= E_NOT_OK;
        }
    }
    return Retval;
}

#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))

/**
 * @brief           : Configure Timer0 interrupt (enable, clear flag, set priority, assign handler)
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer or priority issue
 */

static Std_ReturnType TIMER0_CONFIGURE_INTERRUPT(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        INT_INTERRUPT_TIMER0_ENABLE();
        INT_INTERRUPT_TIMER0_CLEAR_FLAG();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        if(timer0->priority == INTERRUPT_HIGH_PRIORITY)
        {
            INT_INTERRUPT_TIMER0_HIGH_PRIORITY();
        }
        else if(timer0->priority == INTERRUPT_LOW_PRIORITY)
        {
            INT_INTERRUPT_TIMER0_LOW_PRIORITY();
        }
        else {
            Retval= E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        TIMER0_HANDLER_FUNCTION = timer0->TIMER0_INTERRUPT;
    }
    return Retval;
}

#endif


/**
 * @brief           : Enable Timer0 module
 * @param timer0    : Pointer to TIMER0_CFG structure
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : Invalid pointer
 */

static Std_ReturnType TIMER0_SET_ENABLE(const TIMER0_CFG *timer0){
    Std_ReturnType Retval = E_OK;
    if(NULL == timer0){
        Retval= E_NOT_OK;
    }
    else{
        TIMER0_MODULE_ENABLE();
    }
    return Retval;
}