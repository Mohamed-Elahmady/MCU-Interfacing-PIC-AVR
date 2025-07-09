///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//#define _XTAL_FREQ                       8000000UL
//
//GPIO_PORT pc = GPIO_PORTC, pd = GPIO_PORTD;
//
//uint8 counter1,counter2 = 0;
//uint8 tens,ones = 0;
//
//Std_ReturnType Ret;
//
//int main() {
//    application_init();
//    while (1) {
            //APP2
////        __delay_ms(250);
////        counter1++;
////
////        if(counter1 >= 10){
////            counter1 = 0;
////            counter2++;
////        }
////        if(counter2 >= 10){
////            counter1 = 0;
////            counter2 = 0;
////        }
////        
////        Ret = GPIO_PORT_WRITE_LOGIC(pc, counter1);
////        Ret = GPIO_PORT_WRITE_LOGIC(pd, counter2);
//        
//        for(tens = 0; tens < 10; tens++){
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, tens);
//            for(ones = 0; ones < 10; ones++){
//                Ret = GPIO_PORT_WRITE_LOGIC(pc, ones);
//                __delay_ms(100);
//            }
//        }
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    Ret = GPIO_PORT_INIT(pc, 0x00, 0x00);
//    Ret = GPIO_PORT_INIT(pd, 0x00, 0x00);
//}
