/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

#define _XTAL_FREQ                       8000000UL

DC_MOTOR motor1 = {
    .INs[0].PORT = GPIO_PORTC,
    .INs[0].PIN  = GPIO_PIN0,
    .INs[0].DIRECTION = GPIO_OUTPUT,
    .INs[0].LOGIC = GPIO_LOW,
    .INs[1].PORT = GPIO_PORTC,
    .INs[1].PIN  = GPIO_PIN1,
    .INs[1].DIRECTION = GPIO_OUTPUT,
    .INs[1].LOGIC = GPIO_LOW,
};

DC_MOTOR motor2 = {
    .INs[0].PORT = GPIO_PORTC,
    .INs[0].PIN  = GPIO_PIN2,
    .INs[0].DIRECTION = GPIO_OUTPUT,
    .INs[0].LOGIC = GPIO_LOW,
    .INs[1].PORT = GPIO_PORTC,
    .INs[1].PIN  = GPIO_PIN3,
    .INs[1].DIRECTION = GPIO_OUTPUT,
    .INs[1].LOGIC = GPIO_LOW,
};

Std_ReturnType Ret = E_OK;

MOTOR_STATE st1,st2;

int main() {
    application_init();
    while (1) {
        Ret = GPIO_DC_MOTOR_ROTATE_CLOCKWISE(&motor1);
        Ret = GPIO_DC_MOTOR_ROTATE_COUNTER_CLOCKWISE(&motor2);
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor1, &st1); // st1 = 1
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor2, &st2); // st2 = 2
        __delay_ms(2000);
        
        Ret = GPIO_DC_MOTOR_ROTATE_TOGGLE(&motor1);
        Ret = GPIO_DC_MOTOR_ROTATE_TOGGLE(&motor2);
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor1, &st1); // st1 = 2
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor2, &st2); // st2 = 1
        __delay_ms(2000);
        
        Ret = GPIO_DC_MOTOR_BRAKE(&motor1);
        Ret = GPIO_DC_MOTOR_BRAKE(&motor2);
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor1, &st1); // st1 = 0
        Ret = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(&motor2, &st2); // st2 = 0
        __delay_ms(2000);
    }

    return (EXIT_SUCCESS);
}

void application_init(void) {
    Ret = GPIO_DC_MOTOR_INIT(&motor1);
    Ret = GPIO_DC_MOTOR_INIT(&motor2);
}