/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

void t1_app_isr(void);

gpio_led led1 = {.pin.port = gpio_portD, .pin.pin = gpio_pin0, .pin.direction = gpio_output, 
                 .pin.logic = gpio_low, .con = led_source, .state = led_off};


//timer1_cfg t1_timer = {
//    .timer1_interrupt = t1_app_isr,
//    .priority = interrupt_low_priority,
//    .mode = timer1_timer_mode,
//    .osc = timer1_oscillator_disable,
//    .rw_mode = timer1_16bit_rw_mode,
//    .prescaler = timer1_prescaler_div_8,
//    .preloaded_value = 0x6D84
//};

timer1_cfg t1_counter = {
    .timer1_interrupt = t1_app_isr,
    .priority = interrupt_low_priority,
    .mode = timer1_counter_mode,
    .osc = timer1_oscillator_disable,
    .sync = timer1_counter_synchronous_mode,
    .rw_mode = timer1_16bit_rw_mode,
    .prescaler = timer1_prescaler_div_1,
    .preloaded_value = 0x0000
};

uint16 value = 0;

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    timer1_init(&t1_counter);
    gpio_led_init(&led1);
    while(1){
        ret = timer1_read_data(&t1_counter, &value);
        if(value % 5 == 0 && value != 0){
            gpio_led_turn_on(&led1);
        }
        else{
            gpio_led_turn_off(&led1);
        }
    }
    return (EXIT_SUCCESS);
}

void t1_app_isr(void){
//    gpio_led_turn_toggle(&led1);
}