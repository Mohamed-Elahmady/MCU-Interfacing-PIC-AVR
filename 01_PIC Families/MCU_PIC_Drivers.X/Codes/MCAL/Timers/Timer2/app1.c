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
//void t2_app_isr(void);
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTD, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//TIMER2_CFG tim2 = {
//    .TIMER2_INTERRUPT = t2_app_isr,
//    .priority = INTERRUPT_LOW_PRIORITY,
//    .prescaler = TIMER2_PRESCALER_DIV_1,
//    .postscaler = TIMER2_POSTSCALER_DIV_16 ,
//    .preloaded_value = 0xF9,
//};
//
//volatile uint32 tm2_flag = 0;
//
//int main() {
//    application_init();
//    while (1) {
//        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    GPIO_LED_INIT(&led1);
//    TIMER2_INIT(&tim2);
//}
//
//void t2_app_isr(void) {
//    tm2_flag++;
//    GPIO_LED_TURN_TOGGLE(&led1);
//}