///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//#define _XTAL_FREQ                       4000000
//
//GPIO_PIN_CFG pin1 ={
//    .PORT = GPIO_PORTC,
//    .PIN = GPIO_PIN0,
//    .DIRECTION = GPIO_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//
//GPIO_PIN_CFG pin2 ={
//    .PORT = GPIO_PORTC,
//    .PIN = GPIO_PIN1,
//    .DIRECTION = GPIO_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//
//GPIO_PIN_CFG pin3 ={
//    .PORT = GPIO_PORTC,
//    .PIN = GPIO_PIN2,
//    .DIRECTION = GPIO_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//
//GPIO_PIN_CFG pin4 ={
//    .PORT = GPIO_PORTD,
//    .PIN = GPIO_PIN0,
//    .DIRECTION = GPIO_INPUT,
//    .LOGIC = GPIO_LOW
//};
//
//Std_ReturnType Ret = E_OK;
//
//GPIO_LOGIC ll1;
//uint8 ll2;
//
//int main() { 
//    application_init();
//    while(1){ 
//        Ret = GPIO_PIN_TOGGLE_LOGIC(&pin1);
//        __delay_ms(1000);
//        Ret = GPIO_PIN_GET_DIRECTION_STATUS(&pin3, &ll1);
//        if(GPIO_OUTPUT == ll1){
//            Ret = GPIO_PIN_WRITE_LOGIC(&pin2, GPIO_HIGH);
//            __delay_ms(1000);
//            Ret = GPIO_PIN_WRITE_LOGIC(&pin2, GPIO_LOW);
//            __delay_ms(1000);
//        }
//        GPIO_PORT_INIT(GPIO_PORTC, 0xFF, 0xFF);
//         __delay_ms(1000);
//        GPIO_PORT_TOGGLE_LOGIC(GPIO_PORTC);
//        __delay_ms(1000);
//        GPIO_PORT_GET_DIRECTION_STATUS(GPIO_PORTC, &ll2);
//        if(ll2 = 0xFF){
//            GPIO_PORT_INIT(GPIO_PORTC, 0x00, 0x00);
//            GPIO_PORT_WRITE_LOGIC(GPIO_PORTC, 0x22);
//            __delay_ms(500);
//        }
//        Ret = GPIO_PIN_READ_LOGIC(&pin4, &ll1);
//        if(GPIO_HIGH == ll1){
//            Ret = GPIO_PIN_WRITE_LOGIC(&pin1, GPIO_HIGH);
//        }
//        else{
//            Ret = GPIO_PIN_WRITE_LOGIC(&pin1, GPIO_LOW);
//        }
//    }
//
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void){
//    Ret = GPIO_PIN_INIT(&pin1);     // Ret = E_OK
//    Ret = GPIO_PIN_INIT(&pin2 );    // Ret = E_OK
//    Ret = GPIO_PIN_INIT(&pin3);     // Ret = E_OK
//    Ret = GPIO_PIN_INIT(&pin4);     // Ret = E_OK
////    Ret = GPIO_PIN_INIT(NULL);      // Ret = E_NOT_OK
//}