/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

#define _XTAL_FREQ 8000000UL

dc_motor motor1 = {
    .ins[0].port = gpio_portC,
    .ins[0].pin = gpio_pin0,
    .ins[0].direction = gpio_output,
    .ins[0].logic = gpio_low,
    
    .ins[1].port = gpio_portC,
    .ins[1].pin = gpio_pin1,
    .ins[1].direction = gpio_output,
    .ins[1].logic = gpio_low
};

dc_motor motor2 = {
    .ins[0].port = gpio_portC,
    .ins[0].pin = gpio_pin2,
    .ins[0].direction = gpio_output,
    .ins[0].logic = gpio_low,
    
    .ins[1].port = gpio_portC,
    .ins[1].pin = gpio_pin3,
    .ins[1].direction = gpio_output,
    .ins[1].logic = gpio_low
};

motor_state st1,st2;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    
    ret = gpio_dc_motor_init(&motor1);
    ret = gpio_dc_motor_init(&motor2);
    
    while (1) {
//        ret = gpio_dc_motor_brake(&motor1);
//        ret = gpio_dc_motor_brake(&motor2);
//        ret = gpio_dc_motor_read_state(&motor1, &st1);
//        ret = gpio_dc_motor_read_state(&motor2, &st2);
//        __delay_ms(3000);
        
        ret = gpio_dc_motor_rotate_clock_wise(&motor1);
        ret = gpio_dc_motor_rotate_clock_wise(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
        
        ret = gpio_dc_motor_brake(&motor1);
        ret = gpio_dc_motor_brake(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
        
        ret = gpio_dc_motor_rotate_counter_clock_wise(&motor1);
        ret = gpio_dc_motor_rotate_counter_clock_wise(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
        
        ret = gpio_dc_motor_brake(&motor1);
        ret = gpio_dc_motor_brake(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
        
        ret = gpio_dc_motor_rotate_clock_wise(&motor1);
        ret = gpio_dc_motor_rotate_counter_clock_wise(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
        
        ret = gpio_dc_motor_toggle_rotation_direction(&motor1);
        ret = gpio_dc_motor_toggle_rotation_direction(&motor2);
        ret = gpio_dc_motor_read_state(&motor1, &st1);
        ret = gpio_dc_motor_read_state(&motor2, &st2);
        __delay_ms(3000);
    }

    return (EXIT_SUCCESS);
}