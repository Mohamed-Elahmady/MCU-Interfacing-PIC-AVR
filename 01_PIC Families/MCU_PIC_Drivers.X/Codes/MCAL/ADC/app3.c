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
//    .ADC_INTERRUPT = ADC_APP_ISR,
//    .priority = INTERRUPT_HIGH_PRIORITY,
//    .channel = ADC_CHANNEL_AN0,
//    .tad = ADC_ACQ_12TAD,
//    .clk = ADC_CONVERSION_CLOCK_FOSC_DIV_16,
//    .vref = ADC_INTERNAL_VOLTAGE_REFERENCE,
//    .format = ADC_RESULT_FORMAT_RIGHT
//};
//
//uint16 result1, result2, result3, result4;
//uint8 data1[6], data2[6], data3[6], data4[6];
//
//volatile uint8 adc_req = 0;
//
//int main() {
//    application_init();
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "ADC Test", LCD_ROW1, 7);
//    __delay_ms(2000);
//    Ret = GPIO_LCD_4BIT_SEND_COMMAND(&lcd1, CHR_LCD_CLEAR_SCREEN);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "POT1 : ", LCD_ROW1, 1);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "POT2 : ", LCD_ROW2, 1);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "POT3 : ", LCD_ROW3, 1);
//    Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, "POT4 : ", LCD_ROW4, 1);
//
//    while (1) {
//        if (adc_req == 0) {
//            Ret = ADC_START_CONVERSION_INTERRUPT(&adc1, ADC_CHANNEL_AN0);
//        } else if (adc_req == 1) {
//            Ret = ADC_START_CONVERSION_INTERRUPT(&adc1, ADC_CHANNEL_AN1);
//        } else if (adc_req == 2) {
//            Ret = ADC_START_CONVERSION_INTERRUPT(&adc1, ADC_CHANNEL_AN2);
//        } else if (adc_req == 3) {
//            Ret = ADC_START_CONVERSION_INTERRUPT(&adc1, ADC_CHANNEL_AN3);
//        } else {
//        }
//
//        Ret = convert_uint16_to_string(result1, data1);
//        Ret = convert_uint16_to_string(result2, data2);
//        Ret = convert_uint16_to_string(result3, data3);
//        Ret = convert_uint16_to_string(result4, data4);
//
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data1, LCD_ROW1, 8);
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data2, LCD_ROW2, 8);
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data3, LCD_ROW3, 8);
//        Ret = GPIO_LCD_4BIT_SEND_STRING_POS(&lcd1, data4, LCD_ROW4, 8);
//        
////        __delay_ms(100);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    Ret = ADC_INIT(&adc1);
//}
//
//void ADC_APP_ISR(void) {
//    if (adc_req == 0) {
//        Ret = ADC_GET_CONVERSION_RESULT(&adc1, &result1);
//        adc_req = 1;
//    } else if (adc_req == 1) {
//        Ret = ADC_GET_CONVERSION_RESULT(&adc1, &result2);
//        adc_req = 2;
//    } else if (adc_req == 2) {
//        Ret = ADC_GET_CONVERSION_RESULT(&adc1, &result3);
//        adc_req = 3;
//    } else if (adc_req == 3) {
//        Ret = ADC_GET_CONVERSION_RESULT(&adc1, &result4);
//        adc_req = 0;
//    } else {
//    }
//
//}