/* 
 * File:   ECUAL_LED.h
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:28 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_LED_H
#define	ECUAL_LED_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_LED_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    LED_OFF =   (uint8)0x00,     
    LED_ON  =   (uint8)0x01
}LED_LOGIC;

typedef struct{
    GPIO_PIN_CFG pin;
}GPIO_LED;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_LED_INIT(const GPIO_LED *led);
Std_ReturnType GPIO_LED_READ_LOGIC(const GPIO_LED *led, LED_LOGIC *logic);
Std_ReturnType GPIO_LED_TURN_OFF(const GPIO_LED *led);
Std_ReturnType GPIO_LED_TURN_ON(const GPIO_LED *led);
Std_ReturnType GPIO_LED_TURN_TOGGLE(const GPIO_LED *led);


#endif	/* ECUAL_LED_H */

