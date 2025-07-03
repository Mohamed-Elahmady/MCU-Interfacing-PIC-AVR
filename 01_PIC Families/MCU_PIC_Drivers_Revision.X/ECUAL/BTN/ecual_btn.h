/* 
 * File:   ecual_btn.h
 * Author: mohammedel-ahmady
 *
 * Created on July 3, 2025, 5:00 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_BTN_H
#define	ECUAL_BTN_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_btn_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

typedef enum{
    btn_released  = (uint8)0x00,
    btn_pressed   = (uint8)0x01
}btn_state;

typedef enum{
    btn_active_low  = (uint8)0x00,
    btn_active_high = (uint8)0x01
}btn_con;

typedef struct{
    gpio_pin_cfg   pin;
    btn_con connection;
    btn_state    state;
}gpio_btn;

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

Std_ReturnType gpio_btn_init(const gpio_btn *btn);
Std_ReturnType gpio_btn_read_status(const gpio_btn *btn, btn_state *state);

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/



#endif	/* ECUAL_BTN_H */

