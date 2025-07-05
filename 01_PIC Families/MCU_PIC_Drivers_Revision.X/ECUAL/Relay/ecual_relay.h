/* 
 * File:   ecual_relay.h
 * Author: mohammedel-ahmady
 *
 * Created on July 5, 2025, 12:12 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_RELAY_H
#define	ECUAL_RELAY_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_relay_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    relay_off   = (uint8)0x00,
    relay_on    = (uint8)0x01
}relay_state;

typedef struct{
    gpio_pin_cfg pin;
}gpio_relay;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_relay_init(const gpio_relay *relay);
Std_ReturnType gpio_relay_read_logic(const gpio_relay *relay, relay_state *state);
Std_ReturnType gpio_relay_turn_off(const gpio_relay *relay);
Std_ReturnType gpio_relay_turn_on(const gpio_relay *relay);
Std_ReturnType gpio_relay_turn_toggle(const gpio_relay *relay);

#endif	/* ECUAL_RELAY_H */

