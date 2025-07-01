/* 
 * File:   HAL_GPIO.c
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:30 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_GPIO.h"

/******************* Section 1 :  Variables Definitions *******************/

volatile uint8 *TRIS_REGs[REGs_NO] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 *PORT_REGs[REGs_NO] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 *LAT_REGs[REGs_NO]  = {&LATA, &LATB, &LATC, &LATD, &LATE};

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to assign a direction for the pin "INPUT/OUTPUT"  @ref : GPIO_DIRECTION
 * @param pin       : Pointer to pin configurations @  : GPIO_PIN_CFG
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_DIRECTION_INIT(const GPIO_PIN_CFG *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO){
        Retval = E_NOT_OK;
    }
    else{
        switch(pin->DIRECTION){
            case GPIO_OUTPUT:
                CLEAR_BIT(*TRIS_REGs[pin->PORT], pin->PIN);
                break;
            case GPIO_INPUT:
               SET_BIT(*TRIS_REGs[pin->PORT], pin->PIN);
                break; 
            default : Retval = E_NOT_OK;
        }
    }
    return (Retval);
}

#endif

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to return the direction for the pin "INPUT/OUTPUT"  @ref : GPIO_DIRECTION
 * @param pin       : Pointer to pin configurations @ref : GPIO_PIN_CFG 
 * @param direction : Pointer that return the direction status register
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_GET_DIRECTION_STATUS(const GPIO_PIN_CFG *pin, GPIO_DIRECTION *direction){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO || NULL == direction){
        Retval = E_NOT_OK;
    }
    else{
        *direction = READ_BIT(*TRIS_REGs[pin->PORT], pin->PIN);
    }
    return (Retval);
}

#endif

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to assign a logic for the pin "LOW/HIGH"  @ref : GPIO_LOGIC
 * @param pin       : Pointer to pin configurations @ref : GPIO_PIN_CFG 
 * @param logic     : Variable that will be assign to latch register
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_WRITE_LOGIC(const GPIO_PIN_CFG *pin, GPIO_LOGIC logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO){
        Retval = E_NOT_OK;
    }
    else{
        switch (logic){
            case GPIO_LOW:
                CLEAR_BIT(*LAT_REGs[pin->PORT], pin->PIN);
                break;
            case GPIO_HIGH:
                SET_BIT(*LAT_REGs[pin->PORT], pin->PIN);                
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return (Retval);
}

#endif

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to return the logic for the pin "LOW/HIGH"  @ref : GPIO_LOGIC
 * @param pin       : Pointer to pin configurations @ref : GPIO_PIN_CFG 
 * @param logic     : Pointer that return the logic status register
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_READ_LOGIC(const GPIO_PIN_CFG *pin, GPIO_LOGIC *logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        *logic = READ_BIT(*PORT_REGs[pin->PORT], pin->PIN);
    }
    return (Retval);
}

#endif

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to toggle the logic for the pin "LOW/HIGH"  @ref : GPIO_LOGIC
 * @param pin       : Pointer to pin configurations @ref : GPIO_PIN_CFG 
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_TOGGLE_LOGIC(const GPIO_PIN_CFG *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO){
        Retval = E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*LAT_REGs[pin->PORT], pin->PIN);
    }
    return (Retval);
}

#endif

#if ((GPIO_PIN_CFG_ENABLE) == (GPIO_PIN_CFG_T))

/**
 * @brief           : This function to assign a (direction / logic) for the pin ("INPUT/OUTPUT" / "LOW/HIGH")  @ref : GPIO_DIRECTION / GPIO_LOGIC
 * @param pin       : Pointer to pin configurations @ref : GPIO_PIN_CFG 
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PIN_INIT(const GPIO_PIN_CFG *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->PIN >= PIN_NO){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INIT(pin);
        Retval = GPIO_PIN_WRITE_LOGIC(pin, pin->LOGIC);
    }
    return (Retval);
}

#endif


#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to assign a direction for the PORT
 * @param port      : The port index that u will assign its direction
 * @param direction : The direction that u will assign for the port
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_DIRECTION_INIT(const GPIO_PORT port, uint8 direction){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO){
        Retval = E_NOT_OK;
    }
    else{
        *TRIS_REGs[port] = direction;
    }
    return (Retval);
}

#endif

#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to return a direction for the PORT
 * @param port      : The port index that u will return its direction
 * @param direction : Pointer that return the direction status register
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_GET_DIRECTION_STATUS(const GPIO_PORT port, uint8 *direction){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO || NULL == direction){
        Retval = E_NOT_OK;
    }
    else{
        *direction = *TRIS_REGs[port];
    }
    return (Retval);
}

#endif

#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to assign a logic for the PORT
 * @param port      : The port index that u will assign its logic
 * @param logic     : The Logic that u will assign for the port
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_WRITE_LOGIC(const GPIO_PORT port, uint8 logic){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO){
        Retval = E_NOT_OK;
    }
    else{
        *LAT_REGs[port] = logic;
    }
    return (Retval);
}

#endif

#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to return a logic for the PORT
 * @param port      : The port index that u will return its logic
 * @param logic     : Pointer that return the logic status register
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_READ_LOGIC(const GPIO_PORT port, uint8 *logic){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        *logic = *PORT_REGs[port];
    }
    return (Retval);
}

#endif

#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to toggle a logic for the PORT
 * @param port      : The port index that u will toggle its logic
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_TOGGLE_LOGIC(const GPIO_PORT port){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO){
        Retval = E_NOT_OK;
    }
    else{
        *LAT_REGs[port] ^= PORT_MASK;
    }
    return (Retval);
}

#endif

#if ((GPIO_PORT_CFG_ENABLE) == (GPIO_PORT_CFG_T))

/**
 * @brief           : This function to assign a direction / logic for the PORT
 * @param port      : The port index that u will assign its direction / logic
 * @param direction : The direction that u will assign for the port
 * @param logic     : The Logic that u will assign for the port
 * @return          : Status of the function
 *      (E_OK)      : The function done Successfully
 *      (E_NOT_OK)  : The function has issue to perform the action
 */

Std_ReturnType GPIO_PORT_INIT(const GPIO_PORT port, uint8 direction, uint8 logic){
    Std_ReturnType Retval = E_OK;
    if(port >= PORT_NO){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PORT_DIRECTION_INIT(port, direction);
        Retval = GPIO_PORT_WRITE_LOGIC(port, logic);
    }
    return (Retval);
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/


