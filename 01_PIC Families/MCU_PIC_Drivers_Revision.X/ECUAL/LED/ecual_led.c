/* 
 * File:   ecual_led.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:32 AM
 */

/******************* Section 0 : Includes *******************/

#include "ecual_led.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_led_cfg_enable) == (gpio_led_cfg))

Std_ReturnType gpio_led_init(const gpio_led *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_init(&(led->pin));
    }
    return Retval;
}

Std_ReturnType gpio_led_read_logic(const gpio_led *led, led_logic *logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == led || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_read_logic(&(led->pin), logic);
    }
    return Retval;
}

Std_ReturnType gpio_led_turn_off(const gpio_led *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        led_logic logic;
        switch(led->con){
            case led_sink:
                logic = led_on;   // sink mode: pull high to turn off
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            case led_source:
                logic = led_off;  // source mode: pull low to turn off
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType gpio_led_turn_on(const gpio_led *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        led_logic logic;
        switch(led->con){
            case led_sink:
                logic = led_off;  // sink mode: pull low to turn on
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            case led_source:
                logic = led_on;   // source mode: pull high to turn on
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType gpio_led_turn_toggle(const gpio_led *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_toggle_logic(&(led->pin));
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/


