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
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//TIMER0_CFG timer0_timer = {
//    .TIMER0_INTERRUPT = tmr0_app_handler,
//    .priority = INTERRUPT_HIGH_PRIORITY,
//    .prescalar = TIMER0_PRESCALER_CFG_ENABLE,
//    .pre_value = TIMER0_PRESCALER_DIV_4,
//    .mode = TIMER0_TIMER_MODE,
//    .resolution = TIMER0_16BIT_RESOLUTION,
//    .TIMER0_PRELOAD_VALUE = 3036
//};
//
//int main() {
//    application_init();
//    
//    while (1) {
//        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    TIMER0_INIT(&timer0_timer);
//    GPIO_LED_INIT(&led1);
//}
//
//void tmr0_app_handler(void){
//    GPIO_LED_TURN_TOGGLE(&led1);
//}