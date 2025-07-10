/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

#define _XTAL_FREQ 8000000UL

gpio_segment seg1 = {
    .pins[0].port = gpio_portC, 
    .pins[0].pin = gpio_pin0,
    .pins[0].direction = gpio_output, 
    .pins[0].logic = gpio_low,
    
    .pins[1].port = gpio_portC, 
    .pins[1].pin = gpio_pin1,
    .pins[1].direction = gpio_output, 
    .pins[1].logic = gpio_low,
    
    .pins[2].port = gpio_portC, 
    .pins[2].pin = gpio_pin2,
    .pins[2].direction = gpio_output, 
    .pins[2].logic = gpio_low,
    
    .pins[3].port = gpio_portC, 
    .pins[3].pin = gpio_pin3,
    .pins[3].direction = gpio_output, 
    .pins[3].logic = gpio_low,
    
    .connection = segment_common_anode
};

gpio_pin_cfg pin1 = {
    .port = gpio_portD,
    .pin = gpio_pin0,
    .direction = gpio_output,
    .logic = gpio_low
};

gpio_pin_cfg pin2 = {
    .port = gpio_portD,
    .pin = gpio_pin1,
    .direction = gpio_output,
    .logic = gpio_low
};

uint8 number = 0;
uint8 var;

int main() {
    Std_ReturnType ret = E_NOT_OK;
    ret = gpio_segment_init(&seg1);
    ret = gpio_pin_init(&pin1);
    ret = gpio_pin_init(&pin2);
    while (1) {
        for(uint8 i = 0; i < 50; i++){
            ret = gpio_pin_write_logic(&pin2, gpio_high);
            ret = gpio_segment_write_number(&seg1, number%10);
            __delay_ms(10);
            ret = gpio_pin_write_logic(&pin2, gpio_low);
            ret = gpio_pin_write_logic(&pin1, gpio_high);
            ret = gpio_segment_write_number(&seg1, number/10);
            __delay_ms(10);
            ret = gpio_pin_write_logic(&pin1, gpio_low);
        }
        number++;
        if(number >= 100){
            number = 0;
        }
    }

    return (EXIT_SUCCESS);
}