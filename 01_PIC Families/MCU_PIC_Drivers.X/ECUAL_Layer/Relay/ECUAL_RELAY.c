/* 
 * File:   ECUAL_RELAY.c
 * Author: mohammedel-ahmady
 *
 * Created on July 4, 2025, 7:21 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_RELAY.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((GPIO_RELAY_CFG_ENABLE) == (GPIO_RELAY_CFG) )

/**
 * @brief           : Initialize the relay pin as output based on its configuration
 * @param relay     : Pointer to the relay configuration @ref GPIO_RELAY
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action (e.g., NULL pointer)
 */

Std_ReturnType GPIO_RELAY_INIT(const GPIO_RELAY *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_INIT(&(relay->pin));
    }
    return Retval;
}

#endif

#if ((GPIO_RELAY_CFG_ENABLE) == (GPIO_RELAY_CFG) )

/**
 * @brief           : Read the current state of the relay pin (ON/OFF)
 * @param relay     : Pointer to the relay configuration @ref GPIO_RELAY
 * @param state     : Pointer to variable to store the relay state @ref RELAY_STATE
 * @return          : Status of the function
 *      (E_OK)      : Logic read successfully
 *      (E_NOT_OK)  : Function failed due to NULL pointers or read error
 */

Std_ReturnType GPIO_RELAY_READ_LOGIC(const GPIO_RELAY *relay, RELAY_STATE *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic = GPIO_LOW;
        Retval = GPIO_PIN_READ_LOGIC(&(relay->pin), &logic);
        
        if(logic == GPIO_HIGH){
            *state = RELAY_ON;
        }
        else if (logic == GPIO_LOW){
            *state = RELAY_OFF;
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#endif

#if ((GPIO_RELAY_CFG_ENABLE) == (GPIO_RELAY_CFG) )

/**
 * @brief           : Set the relay pin logic to LOW (turn relay OFF)
 * @param relay     : Pointer to the relay configuration @ref GPIO_RELAY
 * @return          : Status of the function
 *      (E_OK)      : Relay turned OFF successfully
 *      (E_NOT_OK)  : Function failed due to NULL pointer or write error
 */

Std_ReturnType GPIO_RELAY_TURN_OFF(const GPIO_RELAY *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic = GPIO_LOW;
        Retval = GPIO_PIN_WRITE_LOGIC(&(relay->pin), logic);
    }
    return Retval;
}

#endif 

#if ((GPIO_RELAY_CFG_ENABLE) == (GPIO_RELAY_CFG) )

/**
 * @brief           : Set the relay pin logic to HIGH (turn relay ON)
 * @param relay     : Pointer to the relay configuration @ref GPIO_RELAY
 * @return          : Status of the function
 *      (E_OK)      : Relay turned ON successfully
 *      (E_NOT_OK)  : Function failed due to NULL pointer or write error
 */

Std_ReturnType GPIO_RELAY_TURN_ON(const GPIO_RELAY *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic = GPIO_HIGH;
        Retval = GPIO_PIN_WRITE_LOGIC(&(relay->pin), logic);
    }
    return Retval;
}

#endif

#if ((GPIO_RELAY_CFG_ENABLE) == (GPIO_RELAY_CFG) )

/**
 * @brief           : Toggle the current logic state of the relay pin (HIGH <-> LOW)
 * @param relay     : Pointer to the relay configuration @ref GPIO_RELAY
 * @return          : Status of the function
 *      (E_OK)      : Relay toggled successfully
 *      (E_NOT_OK)  : Function failed due to NULL pointer or toggle error
 */

Std_ReturnType GPIO_RELAY_TURN_TOGGLE(const GPIO_RELAY *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_TOGGLE_LOGIC (&(relay->pin));
    }
    return Retval;
}

#endif
/******************* Section 2 :  Helper Functions Definitions *******************/
