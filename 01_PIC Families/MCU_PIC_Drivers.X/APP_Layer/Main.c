/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

Std_ReturnType Ret = E_OK;
TIMER1_CFG t1_timer;

void ccp_capture_isr(void);

void tim1_isr(void);

CCP_CFG ccp1_com = {
//    .ccp_interrupt = ccp_capture_isr,
//    .priority = INTERRUPT_HIGH_PRIORITY,
    .ccp_src = CCP1_SOURCE,
    .ccp_mode = CCP_COMPARE_MODE,
    .ccp_cfg = CCP_CFG_COMPARE_MODE_SET_LOGIC,
    .ccp_timer = CCP1_CCP2_TIMER1
};

void timer1_timer_init(void){
    t1_timer.TIMER1_INTERRUPT = NULL;
    t1_timer.priority = INTERRUPT_LOW_PRIORITY;
    t1_timer.mode = TIMER1_TIMER_MODE;
    t1_timer.prescaler = TIMER1_PRESCALER_DIV_1;
    t1_timer.rw_reg = TIMER1_16BIT_RW_MODE;
    t1_timer.preloaded_value = 0x0000;
    TIMER1_INIT(&t1_timer);
}

uint8 flag = 0;

int main() {
    CCP_WRITE_COMPARE_SET_VALUE(&ccp1_com, 12500);
    application_init();

    while (1) {
        
    }
    return (EXIT_SUCCESS);
}

void application_init(void) {
    ECUAL_LAYER_INIT();
    CCP_INIT(&ccp1_com);
    timer1_timer_init();
    
    
}

void ccp_capture_isr(void){
    flag++;
    if(flag == 0){
        CCP_WRITE_COMPARE_SET_VALUE(&ccp1_com, 12500);
        CCP1_SET_MODE_CONFIGURATION(CCP_CFG_COMPARE_MODE_SET_LOGIC);
    }
    else if(flag == 1){
        CCP_WRITE_COMPARE_SET_VALUE(&ccp1_com, 37500);
        CCP1_SET_MODE_CONFIGURATION(CCP_CFG_COMPARE_MODE_CLEAR_LOGIC);
        flag = 0;
    }
    TIMER1_WRITE_DATA(&t1_timer, 0x0000);
}