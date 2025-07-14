/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

gpio_led led1 = {
    .pin.port = gpio_portD,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_output,
    .pin.logic = gpio_low,
    .con = led_source,
    .state = led_off
};

gpio_keypad keypad1 = {
    .row_pins[0].port = gpio_portC,
    .row_pins[0].pin = gpio_pin0,
    .row_pins[0].direction = gpio_output,
    .row_pins[0].logic = gpio_low,

    .row_pins[1].port = gpio_portC,
    .row_pins[1].pin = gpio_pin1,
    .row_pins[1].direction = gpio_output,
    .row_pins[1].logic = gpio_low,

    .row_pins[2].port = gpio_portC,
    .row_pins[2].pin = gpio_pin2,
    .row_pins[2].direction = gpio_output,
    .row_pins[2].logic = gpio_low,

    .row_pins[3].port = gpio_portC,
    .row_pins[3].pin = gpio_pin3,
    .row_pins[3].direction = gpio_output,
    .row_pins[3].logic = gpio_low,

    .col_pins[0].port = gpio_portC,
    .col_pins[0].pin = gpio_pin4,
    .col_pins[0].direction = gpio_input,

    .col_pins[1].port = gpio_portC,
    .col_pins[1].pin = gpio_pin5,
    .col_pins[1].direction = gpio_input,

    .col_pins[2].port = gpio_portC,
    .col_pins[2].pin = gpio_pin6,
    .col_pins[2].direction = gpio_input,

    .col_pins[3].port = gpio_portC,
    .col_pins[3].pin = gpio_pin7,
    .col_pins[3].direction = gpio_input
};

uint8 data13 = 0;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    ret = gpio_keypad_init(&keypad1);
    ret = gpio_led_init(&led1);
    
    while (1) {
        ret = gpio_keypad_read_data(&keypad1, &data13);
        if(data13 == '4'){
            ret = gpio_led_turn_on(&led1);
        }
        else if(data13 == 'C'){
            ret = gpio_led_turn_off(&led1);
        }
    }

    return (EXIT_SUCCESS);
}