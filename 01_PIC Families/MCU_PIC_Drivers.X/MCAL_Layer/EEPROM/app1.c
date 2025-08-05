///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//void program1(void);
//void program2(void);
//void INT0_APP_ISR(void);
//
//Std_ReturnType Ret = E_OK;
//
//GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//GPIO_LED led2 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN1, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};
//
//INTERRUPT_INTX int0_ob = {.INTERRUPT_ISR = INT0_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN0, .pin.DIRECTION = GPIO_INPUT,
//                          .source = INTERRUPT_INT0, .priority = INTERRUPT_HIGH_PRIORITY,.edge = INTERRUPT_RISING_EDGE};
//
//volatile uint8 counter = 0x00;
//BTN_STATE state;
//
//int main() {
//    application_init();
//    Ret = EEPROM_READ_1BYTE(0x3FF, &counter);
//    while (1) {
//        if(counter == 1){
//            program1();
//        }
//        else if(counter == 2){
//            program2();
//        }
//        else{
//            Ret = GPIO_LED_TURN_OFF(&led1);
//            Ret = GPIO_LED_TURN_OFF(&led2);
//        }        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = GPIO_LED_INIT(&led1);
//    Ret = GPIO_LED_INIT(&led2);
//    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int0_ob);
//}
//
//void INT0_APP_ISR(void){
//    counter++;
//    if(counter > 2){
//        counter = 0;
//    }
//    Ret = EEPROM_WRITE_1BYTE(0x3FF, counter);
//}
//
//void program1(void){
//    Ret = GPIO_LED_TURN_ON(&led1);
//    __delay_ms(500);
//    Ret = GPIO_LED_TURN_OFF(&led1);
//    __delay_ms(500);
//}
//
//void program2(void){
//    Ret = GPIO_LED_TURN_ON(&led2);
//    __delay_ms(500);
//    Ret = GPIO_LED_TURN_OFF(&led2);
//    __delay_ms(500);
//}
