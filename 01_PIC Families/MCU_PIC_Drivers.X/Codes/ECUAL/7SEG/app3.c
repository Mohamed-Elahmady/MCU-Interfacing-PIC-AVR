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
//GPIO_PORT pc = GPIO_PORTC;
//
//uint8 counter1,counter2 = 0;
//uint8 tens,ones = 0;
//uint8 var = 0,var_bcd = 0;
//
//Std_ReturnType Ret;
//
//int main() {
//    application_init();
//    while (1) {
//        //APP3
//        
////        var_bcd = (((var / 10) << 4) | (var % 10));
////        Ret = GPIO_PORT_WRITE_LOGIC(pc, var_bcd);
////        __delay_ms(100);
////        var++;
////        if(var >= 100){
////            var = 0;
////        }
//        
////        __delay_ms(100);
////        counter1++;
////        if(counter1 >= 10){
////            counter1 = 0;
////            counter2 += 0x10;
////        }
////        if(counter2 >= 0xA0){
////            counter1 = 0;
////            counter2 = 0;
////        }
////        Ret = GPIO_PORT_WRITE_LOGIC(pc, (counter2+counter1));
//        
////        for(tens = 0; tens < 10; tens++){
////            for(ones = 0; ones < 10; ones++){
////                var_bcd = ((tens << 4) | ones);
////                Ret = GPIO_PORT_WRITE_LOGIC(pc, var_bcd);
////                __delay_ms(250);
////            }
////        }
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    Ret = GPIO_PORT_INIT(pc, 0x00, 0x00);
//}