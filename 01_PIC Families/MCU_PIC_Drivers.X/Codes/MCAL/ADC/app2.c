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
//void ADC_APP_ISR(void);
//
//ADC_CFG adc1 = {
//    .ADC_INTERRUPT = ADC_APP_ISR,
//    .priority      = INTERRUPT_HIGH_PRIORITY,
//    .channel       = ADC_CHANNEL_AN0,
//    .tad           = ADC_ACQ_12TAD,
//    .clk           = ADC_CONVERSION_CLOCK_FOSC_DIV_16, 
//    .vref          = ADC_INTERNAL_VOLTAGE_REFERENCE ,
//    .format        = ADC_RESULT_FORMAT_RIGHT
//};
//
//uint16 result1;
//volatile uint8 adc_flag;
//
//int main() {
//    application_init();
//    
//    while (1) {
//        Ret = ADC_START_CONVERSION_FROM_CHANNEL_INTERRUPT (&adc1, ADC_CHANNEL_AN0);
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//     Ret = ADC_INIT(&adc1);
//}
//
//void ADC_APP_ISR(void){
//    adc_flag++;
//    Ret = ADC_GET_CONVERSION_RESULT(&adc1, &result1);
//}