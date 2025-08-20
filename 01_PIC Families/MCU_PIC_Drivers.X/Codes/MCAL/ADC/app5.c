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
//void ADC_APP_ISR(void);
//
//ADC_CFG adc1 = {
//    .ADC_INTERRUPT = NULL,
//    .priority = INTERRUPT_HIGH_PRIORITY,
//    .channel = ADC_CHANNEL_AN0,
//    .tad = ADC_ACQ_12TAD,
//    .clk = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
//    .vref = ADC_INTERNAL_VOLTAGE_REFERENCE,
//    .format = ADC_RESULT_FORMAT_RIGHT
//};
//
//uint16 result1, result2;
//uint16 temp1, temp2;
//uint8 data1[6], data2[6];
//
//volatile uint8 adc_req = 0;
//
//int main() {
//    application_init();
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "LM35 Test", LCD_ROW1, 7);
//    __delay_ms(2000);
////    Ret = GPIO_LCD_4BIT_SEND_COMMAND(&lcd1, CHR_LCD_CLEAR_SCREEN);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Temp1 : ", LCD_ROW2, 1);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "Temp2 : ", LCD_ROW3, 1);
//
//    while (1) {
//        
//        Ret = ADC_GET_CONVERSION_BLOCKING(&adc1, ADC_CHANNEL_AN0, &result1);
//        Ret = ADC_GET_CONVERSION_BLOCKING(&adc1, ADC_CHANNEL_AN1, &result2);
//        
//        temp1 = result1 * 4.88f;
//        temp1 /= 10;
//        
//        temp2 = result2 * 4.88f;
//        temp2 /= 10;
//        
//        Ret = convert_uint16_to_string(temp1, data1);
//        Ret = convert_uint16_to_string(temp2, data2);
//
//
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data1, LCD_ROW2, 9);
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data2, LCD_ROW3, 9 );
//        
//        if(temp1 > 50 && temp2 < 30){
//            Ret = GPIO_DC_MOTOR_ROTATE_CLOCKWISE(&motor1);
//            Ret = GPIO_DC_MOTOR_ROTATE_CLOCKWISE(&motor2);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M1-ON ", LCD_ROW2, 13);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M2-ON ", LCD_ROW3, 13);
//        }
//        else if(temp1 < 80 && temp2 > 50){
//            Ret = GPIO_DC_MOTOR_ROTATE_CLOCKWISE(&motor1);
//            Ret = GPIO_DC_MOTOR_BRAKE(&motor2);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M1-ON ", LCD_ROW2, 13);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M2-OFF", LCD_ROW3, 13);
//        }
//        else{
//            Ret = GPIO_DC_MOTOR_BRAKE(&motor1);
//            Ret = GPIO_DC_MOTOR_BRAKE(&motor2);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M1-OFF", LCD_ROW2, 13);
//            Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "M2-OFF", LCD_ROW3, 13);
//        }
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = ADC_INIT(&adc1);
//}