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
//Std_ReturnType Ret;
//
//uint8 Secs = 45, Mins = 59, Hrs = 23;
//uint8 Secs_bcd, Mins_bcd, Hrs_bcd;
//
//int main() {
//    application_init();
//    while (1) {
//        //APP4
//        for(uint8 i = 0; i < 33; i++){
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0x7F);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Secs%10);
//            __delay_ms(5);
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0xBF);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Secs/10);
//            __delay_ms(5);
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0xEF);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Mins%10);
//            __delay_ms(5);
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0xF7);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Mins/10);
//            __delay_ms(5);
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0xFD);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Hrs%10);
//            __delay_ms(5);
//            Ret = GPIO_PORT_WRITE_LOGIC(pd, 0xFE);
//            Ret = GPIO_PORT_WRITE_LOGIC(pc, Hrs/10);
//            __delay_ms(5);
//        }
//        __delay_ms(10);
//        
//        Secs++;
//        if(Secs >= 60){
//            Secs = 0;
//            Mins++;
//        }
//        if(Mins >= 60){
//            Mins = 0;
//            Hrs++;
//        }
//        if(Hrs >= 24){
//            Secs = 0;
//            Mins = 0;
//            Hrs = 0;
//        }        
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    Ret = GPIO_PORT_INIT(pc, 0x00, 0x05);
//    Ret = GPIO_PORT_INIT(pd, 0x24, 0x00);
//}