/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

void t3_app_isr(void);

gpio_led led1 = {.pin.port = gpio_portD, .pin.pin = gpio_pin0, .pin.direction = gpio_output, 
                 .pin.logic = gpio_low, .con = led_source, .state = led_off};

volatile uint8 tim3_flag = 0;

timer3_cfg tim3_timer ={
    .timer3_interrupt = t3_app_isr,
    .priority = interrupt_low_priority,
    .mode = timer3_counter_mode,
    .sync = timer3_counter_synchronous_mode,
    .rw_mode = timer3_rw_16bit_mode,
    .prescaler = timer3_prescaler_div_1,
    .preloaded_value = 0x0000 
};


int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    gpio_led_init(&led1);
    timer3_init(&tim3_timer);
    while(1){
        timer3_read_data(&tim3_timer, &tim3_flag);
    }
    return (EXIT_SUCCESS);
}

void t3_app_isr(void){
    gpio_led_turn_toggle(&led1);
}