/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

#define _XTAL_FREQ 16000000

gpio_led led1 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_output,
    .con = led_source,
    .state = led_off
};

gpio_led led2 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin1,
    .pin.direction = gpio_output,
    .con = led_source,
    .state = led_off
};

gpio_btn btn1 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin2,
    .pin.direction = gpio_input,
    .pin.logic = gpio_low,
    .connection = btn_active_high,
    .state = btn_released
};

gpio_btn btn2 = {
    .pin.port = gpio_portD,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_input,
    .pin.logic = gpio_high,
    .connection = btn_active_low,
    .state = btn_released
};

btn_state st1 = btn_released,st2 = btn_released;
int main() {
    Std_ReturnType ret = E_NOT_OK;

    ret = gpio_led_init(&led1);
    ret = gpio_led_init(&led2);
    ret = gpio_btn_init(&btn1);
    ret = gpio_btn_init(&btn2);
    
    while (1) {
//        ret = gpio_btn_read_status(&btn1, &st1);
//        if(st1 == btn_pressed){
//            ret = gpio_led_turn_on(&led1);
//        }
//        else{
//            ret = gpio_led_turn_off(&led1);
//        }
        
        ret = gpio_btn_read_status(&btn2, &st2);
        if(st2 == btn_pressed){
            ret = gpio_led_turn_on(&led2);
        }
        else{
            ret = gpio_led_turn_off(&led2);
        }
    }

    return (EXIT_SUCCESS);
}