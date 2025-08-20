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
//GPIO_LED led2 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN1, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
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
//volatile uint16 pb_counter = 0;
//
//int main() {
//    application_init();
//    
//    while (1) {
//        Ret = TIMER0_READ_DATA(&timer0_counter, &pb_counter);
//        if(pb_counter % 5 == 0 && pb_counter != 0){
//            GPIO_LED_TURN_ON(&led1);
//        }
//        else{
//            GPIO_LED_TURN_OFF(&led1);
//        }
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    TIMER0_INIT(&timer0_counter);
//    GPIO_LED_INIT(&led1);
//    GPIO_LED_INIT(&led2);
//}
//
//void tmr0_app_handler(void){
//    
//}