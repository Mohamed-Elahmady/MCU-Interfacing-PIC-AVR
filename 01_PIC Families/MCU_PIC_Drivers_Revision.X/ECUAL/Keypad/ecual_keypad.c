/* 
 * File:   ecual_keypad.c
 * Author: mohammedel-ahmady
 *
 * Created on July 13, 2025, 1:27 PM
 */

/******************* Section 0 : Includes *******************/

#include "ecual_keypad.h"

/******************* Section 1 :  Variables Definitions *******************/

#if ((keypad_small_calc) == (keypad_type))

const uint8 keypad_btns[keypad_row][keypad_col] = {{'7','8','9','/'},
                                                          {'4','5','6','*'},
                                                          {'1','2','3','-'},
                                                          {'C','0','=','+'}};

#elif ((keypad_phone) == (keypad_type))

const uint8 keypad_btns[keypad_row][keypad_col] = {{'1','2','3'},
                                                          {'4','5','6'},
                                                          {'7','8','9'},
                                                          {'*','0','#'}};

#elif ((keypad_calculator) == (keypad_type))

const uint8 keypad_btns[keypad_row][keypad_col] = {{'C','7','8','9','*','/'},
                                                          {'±','4','5','6','-','R'},
                                                          {'%','1','2','3','+','N'},
                                                          {'?','0','.','=','+','P'}};

#endif

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_keypad_cfg_enable) == (gpio_keypad_cfg))

Std_ReturnType gpio_keypad_init(const gpio_keypad *keypad){
    Std_ReturnType Retval = E_OK;
    if(NULL == keypad){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = zero_init; i < keypad_row; i++){
            Retval = gpio_pin_init(&(keypad->row_pins[i]));
        }
        
        for(uint8 j = zero_init; j < keypad_col; j++){
            Retval = gpio_pin_direction_init(&(keypad->col_pins[j]));
        }
    }
    return Retval;
}

Std_ReturnType gpio_keypad_read_data(const gpio_keypad *keypad, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == keypad || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic deactive = gpio_low;
        gpio_logic active = gpio_high;
        gpio_logic read;
        for(uint8 i = zero_init; i < keypad_row; i++){
            for(uint8 j = zero_init; j < keypad_row; j++){
                Retval = gpio_pin_write_logic(&keypad->row_pins[j], deactive);
            }
            
            Retval = gpio_pin_write_logic(&keypad->row_pins[i], active);
            
            for(uint8 k = zero_init; k < keypad_col; k++){
                Retval = gpio_pin_read_logic(&keypad->col_pins[k], &read);
                
                if(gpio_high == read){
                    *data = keypad_btns[i][k];
                    break;
                }
            }
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/