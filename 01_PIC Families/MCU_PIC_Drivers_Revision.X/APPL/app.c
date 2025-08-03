/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

void int0_app_isr(void);
void int1_app_isr(void);
void int2_app_isr(void);
void rb4_app_isr_high(void);
void rb4_app_isr_low(void);
void rb5_app_isr_high(void);
void rb5_app_isr_low(void);
void rb6_app_isr_high(void);
void rb6_app_isr_low(void);
void rb7_app_isr_high(void);
void rb7_app_isr_low(void);

gpio_led led1 = {.pin.port = gpio_portC, .pin.pin = gpio_pin0, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led2 = {.pin.port = gpio_portC, .pin.pin = gpio_pin1, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led3 = {.pin.port = gpio_portC, .pin.pin = gpio_pin2, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led4 = {.pin.port = gpio_portC, .pin.pin = gpio_pin3, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led5 = {.pin.port = gpio_portC, .pin.pin = gpio_pin4, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led6 = {.pin.port = gpio_portC, .pin.pin = gpio_pin5, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led7 = {.pin.port = gpio_portC, .pin.pin = gpio_pin6, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};
gpio_led led8 = {.pin.port = gpio_portC, .pin.pin = gpio_pin7, .pin.direction = gpio_output, .pin.logic = gpio_low, .con =led_source, .state = led_off};

interrupt_intx int0_ob = {.intx_isr = int0_app_isr,.pin.port = gpio_portB, .pin.pin  = gpio_pin0, .pin.direction = gpio_input,
                          .src = interrupt_int0, .edg = interrupt_rising_edge, .priority = interrupt_high_priority};

interrupt_intx int1_ob = {.intx_isr = int1_app_isr, .pin.port = gpio_portB, .pin.pin  = gpio_pin1, .pin.direction = gpio_input,
                          .src = interrupt_int1, .edg = interrupt_falling_edge, .priority = interrupt_low_priority};

interrupt_intx int2_ob = {.intx_isr = int2_app_isr, .pin.port = gpio_portB, .pin.pin  = gpio_pin2, .pin.direction = gpio_input,
                          .src = interrupt_int2, .edg = interrupt_rising_edge, .priority = interrupt_high_priority};

interrupt_rbx rb4_ob = {.rbx_isr_high = rb4_app_isr_high, .rbx_isr_low = rb4_app_isr_low, .pin.port = gpio_portB, .pin.pin = gpio_pin4,
                        .pin.direction = gpio_input, .src = interrupt_rb4, .edg = interrupt_on_change, .priority = interrupt_low_priority};

interrupt_rbx rb5_ob = {.rbx_isr_high = rb5_app_isr_high, .rbx_isr_low = rb5_app_isr_low, .pin.port = gpio_portB, .pin.pin = gpio_pin5,
                        .pin.direction = gpio_input, .src = interrupt_rb5, .edg = interrupt_on_change, .priority = interrupt_low_priority};

interrupt_rbx rb6_ob = {.rbx_isr_high = rb6_app_isr_high, .rbx_isr_low = rb6_app_isr_low, .pin.port = gpio_portB, .pin.pin = gpio_pin6,
                        .pin.direction = gpio_input, .src = interrupt_rb6, .edg = interrupt_on_change, .priority = interrupt_low_priority};

interrupt_rbx rb7_ob = {.rbx_isr_high = rb7_app_isr_high, .rbx_isr_low = rb7_app_isr_low, .pin.port = gpio_portB, .pin.pin = gpio_pin7,
                        .pin.direction = gpio_input, .src = interrupt_rb7, .edg = interrupt_on_change, .priority = interrupt_low_priority};

int main() {
    Std_ReturnType ret = E_NOT_OK;
    ret = external_interrupt_intx_init(&int0_ob);
    ret = external_interrupt_intx_init(&int1_ob);
    ret = external_interrupt_intx_init(&int2_ob);
    ret = external_interrupt_rbx_init(&rb4_ob);
    ret = external_interrupt_rbx_init(&rb5_ob);
    ret = external_interrupt_rbx_init(&rb6_ob);
    ret = external_interrupt_rbx_init(&rb7_ob);
    
    ret = gpio_led_init(&led1);
    ret = gpio_led_init(&led2);
    ret = gpio_led_init(&led3);
    ret = gpio_led_init(&led4);
    ret = gpio_led_init(&led5);
    ret = gpio_led_init(&led6);
    ret = gpio_led_init(&led7);
    ret = gpio_led_init(&led8);
    
    while (1) {
        
    }

    return (EXIT_SUCCESS);
}


void int0_app_isr(void){
    gpio_led_turn_toggle(&led1);
}

void int1_app_isr(void){
    gpio_led_turn_toggle(&led2);
}

void int2_app_isr(void){
    gpio_led_turn_toggle(&led3);
}

void rb4_app_isr_high(void){
    gpio_led_turn_on(&led5);
}

void rb4_app_isr_low(void){
    gpio_led_turn_on(&led6);
}

void rb5_app_isr_high(void){
    gpio_led_turn_off(&led5);
}

void rb5_app_isr_low(void){
    gpio_led_turn_off(&led6);
}
void rb6_app_isr_high(void){
    gpio_led_turn_on(&led7);
}

void rb6_app_isr_low(void){
    gpio_led_turn_on(&led8);
}

void rb7_app_isr_high(void){
    gpio_led_turn_off(&led7);
}

void rb7_app_isr_low(void){
    gpio_led_turn_off(&led8);
}