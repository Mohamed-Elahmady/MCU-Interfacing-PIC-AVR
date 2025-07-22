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
//uint8 counter = 00;
//uint8 counter_str[4];
//
//int main() {
//    application_init();
//    GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "Counter : ", 1, 1);
//    while (1) {
//
//        convert_byte_to_string(counter, counter_str);
//        GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, counter_str, 1, 11);
//        counter++;
//        __delay_ms(200);
//        if(counter == 255){
//            counter = 0;
//            GPIO_LCD_8BIT_SEND_STRING_POS(&lcd2, "    ", 1, 11);
//        }
//    }
//        
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//}
