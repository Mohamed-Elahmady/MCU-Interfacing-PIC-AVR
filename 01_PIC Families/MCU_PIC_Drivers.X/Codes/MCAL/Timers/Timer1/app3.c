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
//void timer0_timer_init(void);
//void timer1_timer_init(void);
//
//TIMER0_CFG t0_freq_counter;
//TIMER1_CFG t1_timer;
//
//volatile uint8 t_500ms = 0;
//uint16 freq = 0;
//
//int main() {
//    application_init();
//    while (1) {
//        if(t_500ms == 2){
//            TIMER0_READ_DATA(&t0_freq_counter, &freq);
//            TIMER0_WRITE_DATA(&t0_freq_counter, 0x0000);
//            t_500ms = 0;
//        }
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    timer0_timer_init();
//    timer1_timer_init();
//}
//
//void timer0_timer_init(void){
//    t0_freq_counter.TIMER0_INTERRUPT = NULL;
//    t0_freq_counter.priority = INTERRUPT_HIGH_PRIORITY;
//    t0_freq_counter.resolution = TIMER0_16BIT_RESOLUTION;
//    t0_freq_counter.mode = TIMER0_COUNTER_MODE;
//    t0_freq_counter.edge = TIMER0_RISING_EDGE;
//    t0_freq_counter.prescalar = TIMER0_PRESCALER_CFG_DISABLE;
//    t0_freq_counter.TIMER0_PRELOAD_VALUE = 0x0000;
//    TIMER0_INIT(&t0_freq_counter);
//}
//
//void timer1_timer_init(void){
//    t1_timer.TIMER1_INTERRUPT = timer1_app_isr;
//    t1_timer.priority = INTERRUPT_LOW_PRIORITY;
//    t1_timer.mode = TIMER1_TIMER_MODE;
//    t1_timer.prescaler = TIMER1_PRESCALER_DIV_8;
//    t1_timer.rw_reg = TIMER1_16BIT_RW_MODE;
//    t1_timer.preloaded_value = 0x0BDC;
//    TIMER1_INIT(&t1_timer);
//}
//
//void timer1_app_isr(void){
//    t_500ms++;
//}