/* 
 * File:   ecual_btn.c
 * Author: mohammedel-ahmady
 *
 * Created on July 3, 2025, 5:00 PM
 */

/******************* Section 0 : Includes *******************/

#include "ecual_btn.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_btn_cfg_enable) == (gpio_btn_cfg))

Std_ReturnType gpio_btn_init(const gpio_btn *btn){
    Std_ReturnType Retval = E_OK;
    if(NULL == btn){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_direction_init(&(btn->pin));
    }
    return Retval;
}

Std_ReturnType gpio_btn_read_status(const gpio_btn *btn, btn_state *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == btn || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic = gpio_low;
        Retval = gpio_pin_read_logic(&(btn->pin), &logic);
        switch (btn->connection){
            case btn_active_low:
                if(logic == gpio_high){
                    *state = btn_released;
                }
                else if(logic == gpio_low){
                    *state = btn_pressed;
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case btn_active_high:
                if(logic == gpio_high){
                    *state = btn_pressed;
                }
                else if(logic == gpio_low){
                    *state = btn_released;
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


