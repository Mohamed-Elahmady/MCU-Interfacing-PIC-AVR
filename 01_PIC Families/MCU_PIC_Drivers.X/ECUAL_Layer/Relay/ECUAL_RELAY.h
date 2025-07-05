/* 
 * File:   ECUAL_RELAY.h
 * Author: mohammedel-ahmady
 *
 * Created on July 4, 2025, 7:21 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_RELAY_H
#define	ECUAL_RELAY_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_RELAY_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    RELAY_OFF   = (uint8)0x00,
    RELAY_ON    = (uint8)0x01
}RELAY_STATE;

typedef struct{
    GPIO_PIN_CFG pin;
}GPIO_RELAY;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_RELAY_INIT(const GPIO_RELAY *relay);
Std_ReturnType GPIO_RELAY_READ_LOGIC(const GPIO_RELAY *relay, RELAY_STATE *state);
Std_ReturnType GPIO_RELAY_TURN_OFF(const GPIO_RELAY *relay);
Std_ReturnType GPIO_RELAY_TURN_ON(const GPIO_RELAY *relay);
Std_ReturnType GPIO_RELAY_TURN_TOGGLE(const GPIO_RELAY *relay);


#endif	/* ECUAL_RELAY_H */

