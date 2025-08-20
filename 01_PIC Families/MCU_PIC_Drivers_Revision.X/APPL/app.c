/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

void t0_app_isr(void);

gpio_led led1 = {.pin.port = gpio_portC, .pin.pin = gpio_pin0, .pin.direction = gpio_output, 
                 .pin.logic = gpio_low, .con = led_source, .state = led_off};

//timer0_cfg t0_timer = {
//    .timer0_interrupt = t0_app_isr,
//    .priority = interrupt_high_priority,
//    .mode = timer0_timer_mode,
//    .resolution = timer0_16bit_register_size,
//    .prescalar = timer0_prescaler_cfg_enable,
//    .value = timer0_prescaler_div_8,
//    .timer0_preloaded_value = 0x3CB0
//};

timer0_cfg t0_counter = {
    .timer0_interrupt = t0_app_isr,
    .priority = interrupt_high_priority,
    .mode = timer0_counter_mode,
    .edge = timer0_counter_falling_edge,
    .resolution = timer0_16bit_register_size,
    .prescalar = timer0_prescaler_cfg_disable,
    .timer0_preloaded_value = 0x0009
};

uint16 indicator = 0;

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    timer0_init(&t0_counter);
    gpio_led_init(&led1);
    while(1){
        timer0_read_data(&t0_counter, &indicator);
    }
    return (EXIT_SUCCESS);
}

void t0_app_isr(void){
//    gpio_led_turn_toggle(&led1);
}