/* 
 * File:   ecual_led.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:32 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_LED_H
#define	ECUAL_LED_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_led_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    led_off = (uint8)0x00,
    led_on  = (uint8)0x01
}led_logic;

typedef enum{
    led_sink   = (uint8)0x00,
    led_source = (uint8)0x01
}led_con;

typedef struct{
    gpio_pin_cfg pin  ;
    led_logic    state;
    led_con      con  ;
}gpio_led;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_led_init(const gpio_led *led);
Std_ReturnType gpio_led_read_logic(const gpio_led *led, led_logic *logic);
Std_ReturnType gpio_led_turn_off(const gpio_led *led);
Std_ReturnType gpio_led_turn_on(const gpio_led *led);
Std_ReturnType gpio_led_turn_toggle(const gpio_led *led);



#endif	/* ECUAL_LED_H */

