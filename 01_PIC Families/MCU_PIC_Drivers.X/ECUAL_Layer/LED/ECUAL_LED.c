/* 
 * File:   ECUAL_LED.c
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:28 AM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_LED.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((LED_CFG_ENABLE) == (LED_CFG))

/**
 * @brief           : initialize the assigned pin to be output and turn led (OFF/ON)
 * @param led       : pointer to the led module configurations
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_LED_INIT(const GPIO_LED *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_INIT(&(led->pin));
    }
    return Retval;
}

#endif

#if ((LED_CFG_ENABLE) == (LED_CFG))

/**
 * @brief           : return the logic of the led using LED_LOGIC *pointer
 * @param led       : pointer to the led module configurations
 * @param logic     : pointer return the led_logic status (OFF/ON)
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_LED_READ_LOGIC(const GPIO_LED *led, LED_LOGIC *logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == led || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_READ_LOGIC(&(led->pin), logic);
    }
    return Retval;
}

#endif

#if ((LED_CFG_ENABLE) == (LED_CFG))

/**
 * @brief           : Turn the led off
 * @param led       : pointer to the led module configurations
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_LED_TURN_OFF(const GPIO_LED *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC log = GPIO_LOW;
        Retval = GPIO_PIN_WRITE_LOGIC(&(led->pin), log);
    }
    return Retval;

}

#endif

#if ((LED_CFG_ENABLE) == (LED_CFG))

/**
 * @brief           : Turn the led on
 * @param led       : pointer to the led module configurations
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_LED_TURN_ON(const GPIO_LED *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC log = GPIO_HIGH;
        Retval = GPIO_PIN_WRITE_LOGIC(&(led->pin), log);
    }
    return Retval;

}

#endif

#if ((LED_CFG_ENABLE) == (LED_CFG))

/**
 * @brief           : Toggle the led logic
 * @param led       : pointer to the led module configurations
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_LED_TURN_TOGGLE(const GPIO_LED *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_TOGGLE_LOGIC(&(led->pin));
    }
    return Retval;

}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/