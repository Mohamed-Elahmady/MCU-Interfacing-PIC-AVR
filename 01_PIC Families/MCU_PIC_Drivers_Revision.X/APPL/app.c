/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

void t2_app_isr(void);

gpio_led led1 = {.pin.port = gpio_portD, .pin.pin = gpio_pin0, .pin.direction = gpio_output, 
                 .pin.logic = gpio_low, .con = led_source, .state = led_off};

volatile uint8 tim2_flag = 0;

timer2_cfg tim2_timer = {
    .timer2_interrupt = t2_app_isr,
    .priority = interrupt_low_priority,
    .prescaler = timer2_prescaler_div_1,
    .postscaler = timer2_postscaler_div_16,
    .preloaded_value = 0xF9
};


int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    gpio_led_init(&led1);
    timer2_init(&tim2_timer);
    while(1){
        if(tim2_flag == 150){
            gpio_led_turn_toggle(&led1);
            tim2_flag = 0;
        }
    }
    return (EXIT_SUCCESS);
}

void t2_app_isr(void){
    tim2_flag++;
}