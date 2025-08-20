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
//void tmr0_app_handler(void);
//
//TIMER0_CFG timer0_counter = {
//    .TIMER0_INTERRUPT = tmr0_app_handler,
//    .priority = INTERRUPT_HIGH_PRIORITY,
//    .prescalar = TIMER0_PRESCALER_CFG_DISABLE,
//    .mode = TIMER0_COUNTER_MODE,
//    .edge = TIMER0_RISING_EDGE,
//    .resolution = TIMER0_16BIT_RESOLUTION,
//    .TIMER0_PRELOAD_VALUE = 0x0000
//};
//
//volatile uint16 freq = 0;
//
//int main() {
//    application_init();
//    
//    while (1) {
//        Ret = TIMER0_READ_DATA(&timer0_counter, &freq);
//        Ret = TIMER0_WRITE_DATA(&timer0_counter, 0x0000);
//        __delay_ms(1000);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    TIMER0_INIT(&timer0_counter);
//}
//
//void tmr0_app_handler(void){
//    
//}