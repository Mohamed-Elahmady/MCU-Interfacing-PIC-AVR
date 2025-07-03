/* 
 * File:   ECUAL_BTN.c
 * Author: mohammedel-ahmady
 *
 * Created on July 2, 2025, 5:18 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_BTN.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((BTN_CFG_ENABLE) == (BTN_CFG))

/**
 * @brief           : This function initializes the button by setting its associated GPIO pin direction
 *                    as input using the GPIO_PIN_DIRECTION_INIT function.
 * @param btn       : Pointer to the button configuration structure @ref GPIO_BTN
 * @return          : Status of the function
 *      (E_OK)      : The function executed successfully
 *      (E_NOT_OK)  : The function failed (e.g., NULL pointer passed)
 */

Std_ReturnType GPIO_BTN_INIT(const GPIO_BTN *btn){
    Std_ReturnType Retval = E_OK;
    if(NULL == btn){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INIT(&(btn->pin));
    }
    return Retval;
}

#endif

#if ((BTN_CFG_ENABLE) == (BTN_CFG))

/**
 * @brief           : This function reads the current logic state of the button (pressed/released)
 *                    by reading the logic level from its GPIO pin.
 * @param btn       : Pointer to the button configuration structure @ref GPIO_BTN
 * @param state     : Pointer to a variable where the button state will be stored @ref BTN_STATE
 * @return          : Status of the function
 *      (E_OK)      : The function executed successfully
 *      (E_NOT_OK)  : The function failed (e.g., NULL pointer passed)
 */

Std_ReturnType GPIO_BTN_READ_STATE(const GPIO_BTN *btn, BTN_STATE *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == btn || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic;
        Retval = GPIO_PIN_READ_LOGIC(&(btn->pin), &logic);
        switch (btn->connection){
            case BTN_ACTIVE_HIGH: // PULL_DOWN_RESISTOR
                if(GPIO_HIGH == logic){
                    *state = BTN_PRESSED;
                }
                else if(GPIO_LOW == logic){
                    *state = BTN_RELEASED;
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case BTN_ACTIVE_LOW: // PULL_UP_RESISTOR
                if(GPIO_HIGH == logic){
                    *state = BTN_RELEASED;
                }
                else if(GPIO_LOW == logic){
                    *state = BTN_PRESSED;
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

/******************* Section 2 :  Helper Functions Definitions *******************/
