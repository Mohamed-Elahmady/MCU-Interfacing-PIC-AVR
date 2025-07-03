/* 
 * File:   ECUAL_BTN.h
 * Author: mohammedel-ahmady
 *
 * Created on July 2, 2025, 5:18 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_BTN_H
#define	ECUAL_BTN_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_BTN_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    BTN_RELEASED    = (uint8)0x00,
    BTN_PRESSED     = (uint8)0x01
}BTN_STATE;

typedef enum{
    BTN_ACTIVE_LOW  = (uint8)0x00,
    BTN_ACTIVE_HIGH = (uint8)0x01
}BTN_CON;

typedef struct{
    GPIO_PIN_CFG    pin;
    BTN_STATE     state;
    BTN_CON connection;
}GPIO_BTN;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_BTN_INIT(const GPIO_BTN *btn);
Std_ReturnType GPIO_BTN_READ_STATE(const GPIO_BTN *btn, BTN_STATE *state);


#endif	/* ECUAL_BTN_H */