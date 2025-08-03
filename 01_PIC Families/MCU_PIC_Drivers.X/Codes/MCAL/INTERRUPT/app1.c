///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//void INT0_APP_ISR(void);
//void INT1_APP_ISR(void);
//void INT2_APP_ISR(void);
//
//Std_ReturnType Ret = E_OK;
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//GPIO_LED led2 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN1, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//GPIO_LED led3 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN2, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//
//
//
//INTERRUPT_INTX int0_ob = {.INTERRUPT_ISR = INT0_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN0, .pin.DIRECTION = GPIO_INPUT,
//                          .source = INTERRUPT_INT0, .priority = INTERRUPT_HIGH_PRIORITY,.edge = INTERRUPT_RISING_EDGE};
//
//INTERRUPT_INTX int1_ob = {.INTERRUPT_ISR = INT1_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN1, .pin.DIRECTION = GPIO_INPUT,
//                          .source = INTERRUPT_INT1, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_FALLING_EDGE};
//
//INTERRUPT_INTX int2_ob = {.INTERRUPT_ISR = INT2_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN2, .pin.DIRECTION = GPIO_INPUT,
//                          .source = INTERRUPT_INT2, .priority = INTERRUPT_HIGH_PRIORITY, .edge = INTERRUPT_RISING_EDGE};
//
//
//
//
//
//int main() {
//    application_init();
//    
//    while (1) {
//        
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int0_ob);
//    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int1_ob);
//    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int2_ob);
//
//    GPIO_LED_INIT(&led1);
//    GPIO_LED_INIT(&led2);
//    GPIO_LED_INIT(&led3);
//}
//
//void INT0_APP_ISR(void){
//    GPIO_LED_TURN_TOGGLE (&led1);
//}
//
//void INT1_APP_ISR(void){
//    GPIO_LED_TURN_TOGGLE (&led2);
//}
//
//void INT2_APP_ISR(void){
//    GPIO_LED_TURN_TOGGLE (&led3);
//}
