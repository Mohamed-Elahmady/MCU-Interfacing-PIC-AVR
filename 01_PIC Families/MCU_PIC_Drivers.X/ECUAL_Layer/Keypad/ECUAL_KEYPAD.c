/* 
 * File:   ECUAL_KEYPAD.c
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 6:26 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_KEYPAD.h"

/******************* Section 1 :  Variables Definitions *******************/

#if ((KEYPAD_SMALL_CALC) == (KEYPAD_TYPE))

const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL] = {{'7','8','9','/'},
                                                   {'4','5','6','*'},
                                                   {'1','2','3','-'},
                                                   {'C','0','=','+'}};

#elif ((KEYPAD_PHONE) == (KEYPAD_TYPE))

const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL] = {{'1','2','3'},
                                                   {'4','5','6'},
                                                   {'7','8','9'},
                                                   {'*','0','#'}};

#elif ((KEYPAD_CALCULATOR) == (KEYPAD_TYPE))

const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL] = {{'C','7','8','9','*','/'},
                                                   {'±','4','5','6','-','R'},
                                                   {'%','1','2','3','+','N'},
                                                   {'?','0','.','=','+','P'}};

#endif

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((GPIO_KEYPAD_CFG_ENABLE) == (GPIO_KEYPAD_CFG))

/**
 * @brief           : Initialize the Keypad pins (rows as output, columns as input)
 * @param keypad    : Pointer to Keypad configuration structure @ref GPIO_KEYPAD
 * @return          : Status of the function
 *      (E_OK)      : The function executed successfully
 *      (E_NOT_OK)  : The function encountered an issue
 */

Std_ReturnType GPIO_KEYPAD_INIT(const GPIO_KEYPAD *keypad){
    Std_ReturnType Retval = E_OK;
    if(NULL == keypad){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = ZERO_INIT; i < KEYPAD_ROW; i++){
            Retval = GPIO_PIN_INIT(&(keypad->row_pins[i]));
        }

        for(uint8 j = ZERO_INIT; j < KEYPAD_COL; j++){
            Retval = GPIO_PIN_DIRECTION_INIT(&(keypad->col_pins[j]));
        }
    }
    return Retval;
}

#endif

#if ((GPIO_KEYPAD_CFG_ENABLE) == (GPIO_KEYPAD_CFG))

/**
 * @brief           : Scan the Keypad and read the pressed key if any
 * @param keypad    : Pointer to Keypad configuration structure @ref GPIO_KEYPAD
 * @param data      : Pointer to store the pressed key character
 * @return          : Status of the function
 *      (E_OK)      : Key read successfully (or no key pressed)
 *      (E_NOT_OK)  : Invalid pointer or error during read
 */

Std_ReturnType GPIO_KEYPAD_READ_DATA(const GPIO_KEYPAD *keypad, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == keypad || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC deactivation_pin = GPIO_LOW;
        GPIO_LOGIC activation_pin = GPIO_HIGH;
        GPIO_LOGIC read_pin;
        
        for(uint8 i = ZERO_INIT; i < KEYPAD_ROW; i++){
            for(uint8 j = ZERO_INIT; j < KEYPAD_ROW; j++){
                Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->row_pins[j]), deactivation_pin);
            }
            
            Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->row_pins[i]), activation_pin);
            __delay_ms(10);
            
            for(uint8 k = ZERO_INIT; k < KEYPAD_COL; k++){
                Retval = GPIO_PIN_READ_LOGIC(&(keypad->col_pins[k]), &read_pin);
                if(GPIO_HIGH == read_pin){
                    *data = KEYPAD_BTNS[i][k];
                    break;
                }
            }
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/