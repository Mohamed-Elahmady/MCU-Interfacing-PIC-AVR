/* 
 * File:   ecual_relay.c
 * Author: mohammedel-ahmady
 *
 * Created on July 5, 2025, 12:12 PM
 */

/******************* Section 0 : Includes *******************/

#include "ecual_relay.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_relay_cfg_enable) == (gpio_relay_cfg))

Std_ReturnType gpio_relay_init(const gpio_relay *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_init(&(relay->pin));
    }
    return Retval;
}

Std_ReturnType gpio_relay_read_logic(const gpio_relay *relay, relay_state *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic = gpio_low;
        Retval = gpio_pin_read_logic(&(relay->pin), &logic);
        if(logic == gpio_high){
            *state = relay_on;
        }
        else if(logic == gpio_low){
            *state = relay_off;
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

Std_ReturnType gpio_relay_turn_off(const gpio_relay *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic = gpio_low;
        Retval = gpio_pin_write_logic(&(relay->pin), logic);
    }
    return Retval;
}

Std_ReturnType gpio_relay_turn_on(const gpio_relay *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic = gpio_high;
        Retval = gpio_pin_write_logic(&(relay->pin), logic);
    }
    return Retval;
}

Std_ReturnType gpio_relay_turn_toggle(const gpio_relay *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_toggle_logic(&(relay->pin));
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/


