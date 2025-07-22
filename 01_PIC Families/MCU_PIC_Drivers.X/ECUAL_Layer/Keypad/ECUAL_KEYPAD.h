/* 
 * File:   ECUAL_KEYPAD.h
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 6:26 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_KEYPAD_H
#define	ECUAL_KEYPAD_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_KEYPAD_CFG.h"

/******************* Section 2 : Macros Declarations *******************/

#if ((KEYPAD_SMALL_CALC) == (KEYPAD_TYPE))

#define KEYPAD_ROW          (uint8)0x04
#define KEYPAD_COL          (uint8)0x04

extern const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL];

#elif ((KEYPAD_PHONE) == (KEYPAD_TYPE))

#define KEYPAD_ROW          (uint8)0x04
#define KEYPAD_COL          (uint8)0x03

extern const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL];

#elif ((KEYPAD_CALCULATOR) == (KEYPAD_TYPE))

#define KEYPAD_ROW          (uint8)0x04
#define KEYPAD_COL          (uint8)0x06

extern const uint8 KEYPAD_BTNS[KEYPAD_ROW][KEYPAD_COL];

#endif

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef struct{
    GPIO_PIN_CFG row_pins[KEYPAD_ROW];  // As an Output Pins
    GPIO_PIN_CFG col_pins[KEYPAD_COL];  // As an Input Pins
}GPIO_KEYPAD;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_KEYPAD_INIT(const GPIO_KEYPAD *keypad);
Std_ReturnType GPIO_KEYPAD_READ_DATA(const GPIO_KEYPAD *keypad, uint8 *data);

#endif	/* ECUAL_KEYPAD_H */

