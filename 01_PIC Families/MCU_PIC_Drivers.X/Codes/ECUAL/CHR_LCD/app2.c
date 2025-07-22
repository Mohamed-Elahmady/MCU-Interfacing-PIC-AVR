///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//void welcome_message(void);
//void Loading_message(void);
//
//Std_ReturnType Ret = E_OK;
//
//
//int main() {
//    application_init();
////    GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "Loading...", 1,1);
////    GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Embedded Diploma", 2,1);
//    GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "Counter : ", 1, 1);
//    while (1) {
////        for(uint8 i = 1; i <= 8; i++){    
////            GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Hello, World!", 1,i);
////            __delay_ms(250);
////            GPIO_LCD_4BIT_SEND_CHARACTER_POS(&lcd1, ' ', 1, i);
////        }
////        GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "                             ", 1,1);
////        for(uint8 i = 8; i >= 1; i--){
////            GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Hello, World!", 1,i);
////            __delay_ms(250);
////            GPIO_LCD_4BIT_SEND_CHARACTER_POS(&lcd1, ' ', 1, i+strlen("Hello, World!")-1);
////        }
////        GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "                             ", 1,1);
//        //welcome_message();
////        Loading_message();
//        
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//}
//
//void welcome_message(void){
//
//    for(uint8 i = 1; i <= 2; i++){    
//        GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Hello, All", 1, 5);
//        GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Embedded Diploma", 2, 3);
//        __delay_ms(500);
//        GPIO_LCD_4BIT_SEND_COMMAND(&lcd1, 0x01);
//        __delay_ms(100);
//    }
//}
//
//void Loading_message(void){
//    GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "Loading", 1,1);
//    for(uint8 i = strlen("Loading...")-2; i <= strlen("Loading...")+3 ; i++){
//        GPIO_LCD_8BIT_SEND_CHARACTER_POS(&lcd2, '.', 1, i);
//        __delay_ms(350);    
//    }
//    GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "         ", 1,strlen("Loading...")-1);
//}