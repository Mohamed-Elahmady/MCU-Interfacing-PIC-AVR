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
        Retval = gpio_pin_direction_init(&(led->pin));
        gpio_logic logic;
        switch(led->con){
            case led_sink:
                if(led->state == led_off){
                    logic = gpio_high;
                }
                else if(led->state == led_on){
                    logic = gpio_low;
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case led_source:
                if(led->state == led_off){
                    logic = gpio_low;
                }
                else if(led->state == led_on){
                    logic = gpio_high;
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
        Retval = gpio_pin_write_logic(&(led->pin), logic);
    }
    return Retval;
}

Std_ReturnType gpio_led_read_logic(const gpio_led *led, led_logic *logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == led || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic status;
        Retval = gpio_pin_read_logic(&(led->pin), &status);
        switch(led->con){
            case led_sink:
                if(status == gpio_high){
                    *logic = led_off;
                }
                else if(status == gpio_low){
                    *logic = led_on;
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case led_source:
                if(status == gpio_high){
                    *logic = led_on;
                }
                else if(status == gpio_low){
                    *logic = led_off;
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

Std_ReturnType gpio_led_turn_off(const gpio_led *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic;
        switch(led->con){
            case led_sink:
                logic = gpio_high;   // sink mode: pull high to turn off
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            case led_source:
                logic = gpio_low;  // source mode: pull low to turn off
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
        gpio_logic logic;
        switch(led->con){
            case led_sink:
                logic = gpio_low;  // sink mode: pull low to turn on
                Retval = gpio_pin_write_logic(&(led->pin), logic);
                break;
            case led_source:
                logic = gpio_high;   // source mode: pull high to turn on
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


