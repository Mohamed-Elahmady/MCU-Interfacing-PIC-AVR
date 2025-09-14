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
//TIMER1_CFG t1_timer;
//
//void ccp_capture_isr(void);
//
//void tim1_isr(void);
//
//CCP_CFG ccp1_cap = {
//    .ccp_interrupt = ccp_capture_isr,
//    .priority = INTERRUPT_HIGH_PRIORITY,
//    .ccp_src = CCP1_SOURCE,
//    .ccp_mode = CCP_CAPTURE_MODE,
//    .ccp_cfg = CCP_CFG_CAPTURE_MODE_1_RISING_EDGE,
//    .ccp_timer = CCP1_CCP2_TIMER1
//};
//
//void timer1_timer_init(void){
//    t1_timer.TIMER1_INTERRUPT = tim1_isr;
//    t1_timer.priority = INTERRUPT_LOW_PRIORITY;
//    t1_timer.mode = TIMER1_TIMER_MODE;
//    t1_timer.prescaler = TIMER1_PRESCALER_DIV_1;
//    t1_timer.rw_reg = TIMER1_8BIT_RW_MODE;
//    t1_timer.preloaded_value = 0x0000;
//    TIMER1_INIT(&t1_timer);
//}
//
//volatile uint8 flagy = 0;
//volatile uint16 flagy2 = 0;
//
//volatile uint16 T1_TOV = 0;
//
//uint32 time_period_us = 0;
//uint16 capture_time = 0;
//
//uint32 freqy = 0;
//
//int main() {
//    application_init();
//
//    while (1) {
//        if(flagy2 == 2){
//            
//            time_period_us = (T1_TOV * 65536) + capture_time;
//            freqy = (uint32)(1 / (time_period_us / 1000000.0));
//            flagy2 = 0;
//            
//        }
//        
//    }
//    return (EXIT_SUCCESS);
//}
//
//void application_init(void) {
//    ECUAL_LAYER_INIT();
//    CCP_INIT(&ccp1_cap);
//    timer1_timer_init();
//    
//    
//}
//
//void ccp_capture_isr(void){
//    flagy++;
//    flagy2++;
//    if(flagy == 1){
//         TIMER1_WRITE_DATA(&t1_timer, 0x0000);
//    }
//    else if(flagy == 2){
//        CCP_READ_CAPTURE_VALUE(&ccp1_cap, &capture_time);
//        flagy = 0;
//        T1_TOV = 0;
//    }
//     
//    
//}
//
//void tim1_isr(void){
//    T1_TOV++;
//}