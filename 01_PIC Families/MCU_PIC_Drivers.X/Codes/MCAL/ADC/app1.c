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
//ADC_CFG adc1 = {
//    .ADC_INTERRUPT = NULL,
//    .priority      = INTERRUPT_HIGH_PRIORITY,
//    .channel       = ADC_CHANNEL_AN0,
//    .tad           = ADC_ACQ_12TAD,
//    .clk           = ADC_CONVERSION_CLOCK_FOSC_DIV_16, 
//    .vref          = ADC_INTERNAL_VOLTAGE_REFERENCE ,
//    .format        = ADC_RESULT_FORMAT_RIGHT
//};
//
//uint16 result1,result2,result3,result4;
//volatile uint8 adc_flag;
//
//int main() {
//    application_init();
//    
//    while (1) {
//        Ret = ADC_GET_CONVERSION_RESULT_FROM_CHANNEL_BLOCKING (&adc1, ADC_CHANNEL_AN0, &result1);
//        Ret = ADC_GET_CONVERSION_RESULT_FROM_CHANNEL_BLOCKING (&adc1, ADC_CHANNEL_AN1, &result2);
//        Ret = ADC_GET_CONVERSION_RESULT_FROM_CHANNEL_BLOCKING (&adc1, ADC_CHANNEL_AN2, &result3);
//        Ret = ADC_GET_CONVERSION_RESULT_FROM_CHANNEL_BLOCKING (&adc1, ADC_CHANNEL_AN3, &result4);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//     Ret = ADC_INIT(&adc1);
//}