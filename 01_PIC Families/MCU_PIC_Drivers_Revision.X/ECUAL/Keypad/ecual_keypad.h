/* 
 * File:   ecual_keypad.h
 * Author: mohammedel-ahmady
 *
 * Created on July 13, 2025, 1:27 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_KEYPAD_H
#define	ECUAL_KEYPAD_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_keypad_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define zero_init           (uint8)0x00

#if ((keypad_small_calc) == (keypad_type))

#define keypad_row          (uint8)0x04
#define keypad_col          (uint8)0x04

extern const uint8 keypad_btns[keypad_row][keypad_col];

#elif ((keypad_phone) == (keypad_type))

#define keypad_row          (uint8)0x04
#define keypad_col          (uint8)0x03

extern const uint8 keypad_btns[keypad_row][keypad_col];

#elif ((keypad_calculator) == (keypad_type))

#define keypad_row          (uint8)0x04
#define keypad_col          (uint8)0x06

extern const uint8 keypad_btns[keypad_row][keypad_col];

#endif

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef struct{
    gpio_pin_cfg row_pins[keypad_row];
    gpio_pin_cfg col_pins[keypad_col];
}gpio_keypad;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_keypad_init(const gpio_keypad *keypad);
Std_ReturnType gpio_keypad_read_data(const gpio_keypad *keypad, uint8 *data);

#endif	/* ECUAL_KEYPAD_H */

