/* 
 * File:   ecual_dc_motor.c
 * Author: mohammedel-ahmady
 *
 * Created on July 7, 2025, 5:07 PM
 */

/******************* Section 0 : Includes *******************/

#include "ecual_dc_motor.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((dc_motor_cfg_enable) == (dc_motor_cfg))

Std_ReturnType gpio_dc_motor_init(const dc_motor *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < motor_pins; i++){
            Retval = gpio_pin_init(&(motor->ins[i]));
        }
    }
    return Retval;
}

Std_ReturnType gpio_dc_motor_read_state(const dc_motor *motor, motor_state *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic[motor_pins];
        for(uint8 i = 0; i < motor_pins; i++){
            Retval = gpio_pin_read_logic(&(motor->ins[i]), &logic[i]);
        }
        
        if(logic[0] == gpio_high && logic[1] == gpio_low){
            *state = motor_clock_wise;
        }
        else if(logic[0] == gpio_low && logic[1] == gpio_high){
            *state = motor_counter_clock_wise;
        }
        else{
            *state = motor_brake;
        }
    }
    return Retval;
}

Std_ReturnType gpio_dc_motor_brake(const dc_motor *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic[motor_pins] = {gpio_low, gpio_low};
        for(uint8 i = 0; i < motor_pins; i++){
            Retval = gpio_pin_write_logic(&(motor->ins[i]), logic[i]);
        }
    }
    return Retval;
}

Std_ReturnType gpio_dc_motor_rotate_clock_wise(const dc_motor *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic[motor_pins] = {gpio_high, gpio_low};
        for(uint8 i = 0; i < motor_pins; i++){
            Retval = gpio_pin_write_logic(&(motor->ins[i]), logic[i]);
        }
    }
    return Retval;
}

Std_ReturnType gpio_dc_motor_rotate_counter_clock_wise(const dc_motor *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        gpio_logic logic[motor_pins] = {gpio_low, gpio_high};
        for(uint8 i = 0; i < motor_pins; i++){
            Retval = gpio_pin_write_logic(&(motor->ins[i]), logic[i]);
        }
    }
    return Retval;
}

Std_ReturnType gpio_dc_motor_toggle_rotation_direction(const dc_motor *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        motor_state state;
        Retval = gpio_dc_motor_read_state(motor, &state);
        if(state == motor_clock_wise){
            Retval = gpio_dc_motor_rotate_counter_clock_wise(motor);
        }
        else{
            Retval = gpio_dc_motor_rotate_clock_wise(motor);
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/

