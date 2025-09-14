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
//CCP_CFG ccp1_pwm = {
//    .ccp_src = CCP1_SOURCE,
//    .ccp_mode = CCP_PWM_MODE,
//    .ccp_cfg = CCP_CFG_PWM,
//    .pwm_freq = 10000,
//    .pwm_prescaler = CCP_PWM_TIMER2_PRESCALER_1,
//    .pwm_postscaler = CCP_PWM_TIMER2_POSTSCALER_1
//};
//
//CCP_CFG ccp2_pwm = {
//    .ccp_src = CCP2_SOURCE,
//    .ccp_mode = CCP_PWM_MODE,
//    .ccp_cfg = CCP_CFG_PWM,
//    .pwm_freq = 10000,
//    .pwm_prescaler = CCP_PWM_TIMER2_PRESCALER_1,
//    .pwm_postscaler = CCP_PWM_TIMER2_POSTSCALER_1
//};
//
//TIMER2_CFG tim2_timer = {
//    .prescaler = TIMER2_PRESCALER_DIV_1,
//    .postscaler = TIMER2_POSTSCALER_DIV_1,
//    .preloaded_value = 0x00
//};
//
//int main() {
//    application_init();
//    Ret = CCP_SET_DUTY_CYCLE(&ccp1_pwm, 30); // that means y make duty cycle 30%
//    Ret = CCP_SET_DUTY_CYCLE(&ccp2_pwm, 65); // that means y make duty cycle 65%
//    Ret = CCP_START_PWM(&ccp1_pwm);
//    while (1) {
////        for(uint8 i = 0; i <= 100; i++){
////            Ret = CCP_SET_DUTY_CYCLE(&ccp1_pwm, i);
////            __delay_ms(5);
////        }
//        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    TIMER2_INIT(&tim2_timer);
//    CCP_INIT(&ccp1_pwm);
//    CCP_INIT(&ccp2_pwm);
//    
//    
//}