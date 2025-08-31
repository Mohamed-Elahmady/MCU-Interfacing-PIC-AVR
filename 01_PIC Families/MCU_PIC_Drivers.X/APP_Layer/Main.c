/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

Std_ReturnType Ret = E_OK;

void t3_app_isr(void);

GPIO_LED led1 = {.pin.PORT = GPIO_PORTD, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

//TIMER3_CFG tim3_timer = {
//    .TIMER3_INTERRUPT = t3_app_isr,
//    .priority = INTERRUPT_LOW_PRIORITY,
//    .mode = TIMER3_TIMER_MODE,
//    .osc = TIMER1_OSCILLATOR_DISABLE,
//    .rw_reg = TIMER3_16BIT_RW_MODE,
//    .prescaler = TIMER3_PRESCALER_DIV_8,
//    .preloaded_value = 0X3CB0,
//};

TIMER3_CFG tim3_counter = {
    .TIMER3_INTERRUPT = t3_app_isr,
    .priority = INTERRUPT_LOW_PRIORITY,
    .mode = TIMER3_COUNTER_MODE,
    .osc = TIMER1_OSCILLATOR_DISABLE,
    .rw_reg = TIMER3_16BIT_RW_MODE,
    .prescaler = TIMER3_PRESCALER_DIV_1,
    .sync = TIMER3_SYNCHRONOUS_COUNTER,
    .preloaded_value = 0x0000,
};

volatile uint32 tim3_flag = 0;

int main() {
    application_init();
    while (1) {
        Ret = TIMER3_READ_DATA(&tim3_counter, &tim3_flag);
        if(tim3_flag%5 == 0 && tim3_flag != 0){
            GPIO_LED_TURN_ON(&led1);
        }
        else{
            GPIO_LED_TURN_OFF(&led1);
        }
        
    }
    return (EXIT_SUCCESS);
}

void application_init(void) {
    ECUAL_LAYER_INIT();
    GPIO_LED_INIT(&led1);
    TIMER3_INIT(&tim3_counter);
}

void t3_app_isr(void){
//    tim3_flag++;
//    GPIO_LED_TURN_TOGGLE(&led1);
}