///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//Std_ReturnType Ret = E_OK;
//
//void timer1_app_isr(void);
//void timer1_timer_init(void);
//void timer1_counter_init(void);
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTD, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//TIMER1_CFG t1_timer;
//TIMER1_CFG t1_count;
//
//uint8 flag = 0;
//
//int main() {
//    application_init();
//    TIMER1_WRITE_DATA(&t1_count, 0x0000);
//    while (1) {
//         TIMER1_READ_DATA(&t1_count, &flag);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    timer1_counter_init();
//    GPIO_LED_INIT(&led1);
//}
//
//void timer1_timer_init(void){
//    t1_timer.TIMER1_INTERRUPT = timer1_app_isr;
//    t1_timer.priority = INTERRUPT_LOW_PRIORITY;
//    t1_timer.mode = TIMER1_TIMER_MODE;
//    t1_timer.prescaler = TIMER1_PRESCALER_DIV_8;
//    t1_timer.rw_reg = TIMER1_16BIT_RW_MODE;
//    t1_timer.preloaded_value = 0x3CB0;
//    TIMER1_INIT(&t1_timer);
//}
//
//void timer1_counter_init(void){
//    t1_count.TIMER1_INTERRUPT = timer1_app_isr;
//    t1_count.priority = INTERRUPT_LOW_PRIORITY;
//    t1_count.mode = TIMER1_COUNTER_MODE;
//    t1_count.sync = TIMER1_ASYNCHRONCE_COUNTER;
//    t1_count.prescaler = TIMER1_PRESCALER_DIV_1;
//    t1_count.rw_reg = TIMER1_16BIT_RW_MODE;
//    t1_count.preloaded_value = 0x0000;
//    TIMER1_INIT(&t1_count);
//}
//
//void timer1_app_isr(void){
//    GPIO_LED_TURN_TOGGLE(&led1); 
//}