/* 
 * File:   ECUAL_DC_MOTOR.h
 * Author: mohammedel-ahmady
 *
 * Created on July 6, 2025, 9:41 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_DC_MOTOR_H
#define	ECUAL_DC_MOTOR_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_DC_MOTOR_CFG.h"

/******************* Section 2 : Macros Declarations *******************/

#define MOTOR_PINS          (uint8)0x02

/******************* Section 3 : Macros Functions Declarations *******************/

typedef enum{
    MOTOR_BRAKE                     = (uint8)0x00,
    MOTOR_CLOCKWISE                 = (uint8)0x01,
    MOTOR_COUNTER_CLOCKWISE         = (uint8)0x02
}MOTOR_STATE;

typedef struct{
    GPIO_PIN_CFG INs[2];
}DC_MOTOR;

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

Std_ReturnType GPIO_DC_MOTOR_INIT(const DC_MOTOR *motor);
Std_ReturnType GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(const DC_MOTOR *motor, MOTOR_STATE *state);
Std_ReturnType GPIO_DC_MOTOR_BRAKE(const DC_MOTOR *motor);
Std_ReturnType GPIO_DC_MOTOR_ROTATE_CLOCKWISE(const DC_MOTOR *motor);
Std_ReturnType GPIO_DC_MOTOR_ROTATE_COUNTER_CLOCKWISE(const DC_MOTOR *motor);
Std_ReturnType GPIO_DC_MOTOR_ROTATE_TOGGLE(const DC_MOTOR *motor);

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/


#endif	/* ECUAL_DC_MOTOR_H */

