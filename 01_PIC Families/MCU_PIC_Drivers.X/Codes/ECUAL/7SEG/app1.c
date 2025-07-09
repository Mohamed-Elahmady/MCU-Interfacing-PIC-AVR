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
//uint8 Com_anode[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
//uint8 Com_cathode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//
//uint8 counter1,counter2 = 0;
//uint8 tens,ones = 0;
//Std_ReturnType Ret;
//
//int main() {
//    application_init();
//    while (1) {
//        //APP1
//        __delay_ms(100);
//        Ret = GPIO_PORT_WRITE_LOGIC(pc, Com_anode[counter1]);
//        Ret = GPIO_PORT_WRITE_LOGIC(pd, Com_cathode[counter2]);
//        counter1++;
//        if(counter1 >= 10){
//            counter1 = 0;
//            counter2++;
//        }
//        if(counter2 >= 10){
//            counter2 = 0;
//        }
//        
//        for(tens = 0; tens < 10; tens++){
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, Com_cathode[tens]);
//            for(ones = 0; ones < 10; ones++){
//                Ret = GPIO_PORT_WRITE_LOGIC(pc, Com_anode[ones]);
//                __delay_ms(250);
//            }
//        }
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    Ret = GPIO_PORT_INIT(pc, 0x00, 0xFF);
//    Ret = GPIO_PORT_INIT(pd, 0x00, 0x00);
//}