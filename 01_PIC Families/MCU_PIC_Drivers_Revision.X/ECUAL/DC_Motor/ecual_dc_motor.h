/* 
 * File:   ecual_dc_motor.h
 * Author: mohammedel-ahmady
 *
 * Created on July 7, 2025, 5:07 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_DC_MOTOR_H
#define	ECUAL_DC_MOTOR_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_dc_motor_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define motor_pins                  (uint8)2

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    motor_brake              = (uint8)0x00,
    motor_clock_wise         = (uint8)0x01,
    motor_counter_clock_wise = (uint8)0x02
}motor_state;

typedef struct{
    gpio_pin_cfg ins[motor_pins];
}dc_motor;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_dc_motor_init(const dc_motor *motor);
Std_ReturnType gpio_dc_motor_read_state(const dc_motor *motor, motor_state *state);
Std_ReturnType gpio_dc_motor_brake(const dc_motor *motor);
Std_ReturnType gpio_dc_motor_rotate_clock_wise(const dc_motor *motor);
Std_ReturnType gpio_dc_motor_rotate_counter_clock_wise(const dc_motor *motor);
Std_ReturnType gpio_dc_motor_toggle_rotation_direction(const dc_motor *motor);




#endif	/* ECUAL_DC_MOTOR_H */

