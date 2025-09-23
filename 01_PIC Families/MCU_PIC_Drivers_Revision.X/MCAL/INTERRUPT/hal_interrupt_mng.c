/* 
 * File:   hal_interrupt_mng.c
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:15 PM
 */

/******************* Section 0 : Includes *******************/

#include "hal_interrupt_mng.h"

/******************* Section 1 :  Variables Definitions *******************/

static uint8 rb4_flag = 0x01;
static uint8 rb5_flag = 0x01;
static uint8 rb6_flag = 0x01;
static uint8 rb7_flag = 0x01;

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

void __interrupt() interrupt_manager_high(void) {
    // FOR EXT INTX
    
    if ((INTCONbits.INT0IF == interrupt_occur) && (INTCONbits.INT0IE == interrupt_enable)) {
        int0_isr();
    }
    else { /* Nothing*/ }
    
    // for ADC internal interrupt
    if ((PIR1bits.ADIF == interrupt_occur) && (PIE1bits.ADIE == interrupt_enable)) {
        adc_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 0 internal interrupt
    if ((INTCONbits.T0IF == interrupt_occur) && (INTCONbits.TMR0IE == interrupt_enable)) {
        tmr0_isr();
    }
    else { /* Nothing*/ }

    if ((INTCON3bits.INT2IF == interrupt_occur) && (INTCON3bits.INT2IE == interrupt_enable)) {
        int2_isr();
    }
    else { /* Nothing*/ }
    
}

void __interrupt(low_priority) interrupt_manager_low(void) {
    // FOR EXT INTX
    
    if ((INTCON3bits.INT1IF == interrupt_occur) && (INTCON3bits.INT1IE == interrupt_enable)) {
        int1_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 1 internal interrupt
    if ((PIR1bits.TMR1IF == interrupt_occur) && (PIE1bits.TMR1IE == interrupt_enable)) {
        tmr1_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 2 internal interrupt
    if ((PIR1bits.TMR2IF == interrupt_occur) && (PIE1bits.TMR2IE == interrupt_enable)) {
        tmr2_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 3 internal interrupt
    if ((PIR2bits.TMR3IF == interrupt_occur) && (PIE2bits.TMR3IE == interrupt_enable)) {
        tmr3_isr();
    }
    else { /* Nothing*/ }
    
    // FOR EXT RBX
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB4 == interrupt_enable) && (PORTBbits.RB4 == gpio_high) && (rb4_flag == 0x01)){
        rb4_flag = 0x00;
        rb4_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB4 == interrupt_enable) && (PORTBbits.RB4 == gpio_low) && (rb4_flag == 0x00)){
        rb4_flag = 0x01;
        rb4_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB5 == interrupt_enable) && (PORTBbits.RB5 == gpio_high) && (rb5_flag == 0x01)){
        rb5_flag = 0x00;
        rb5_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB5 == interrupt_enable) && (PORTBbits.RB5 == gpio_low) && (rb5_flag == 0x00)){
        rb5_flag = 0x01;
        rb5_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB6 == interrupt_enable) && (PORTBbits.RB6 == gpio_high) && (rb6_flag == 0x01)){
        rb6_flag = 0x00;
        rb6_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB6 == interrupt_enable) && (PORTBbits.RB6 == gpio_low) && (rb6_flag == 0x00)){
        rb6_flag = 0x01;
        rb6_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB7 == interrupt_enable) && (PORTBbits.RB7 == gpio_high) && (rb7_flag == 0x01)){
        rb7_flag = 0x00;
        rb7_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB7 == interrupt_enable) && (PORTBbits.RB7 == gpio_low) && (rb7_flag == 0x00)){
        rb7_flag = 0x01;
        rb7_isr(change_low);
    }
    else { /* Nothing*/ }
    
}

#elif ((interrupt_feature_disable) == (interrupt_priority_levels))

void __interrupt() interrupt_manager(void) {
    
    if ((INTCONbits.INT0IF == interrupt_occur) && (INTCONbits.INT0IE == interrupt_enable)) {
        int0_isr();
    }
    else { /* Nothing*/ }
    
    // for CCP1 internal interrupt
    if ((PIR1bits.CCP1IF == interrupt_occur) && (PIE1bits.CCP1IE == interrupt_enable)) {
        ccp1_isr();
    }
    else { /* Nothing*/ }
    
    // for Eusart tx internal interrupt
    if ((PIR1bits.TXIF == interrupt_occur) && (PIE1bits.TXIE == interrupt_enable)) {
        eusart_tx_isr();
    }
    else { /* Nothing*/ }
    
    // for Eusart rx internal interrupt
    if ((PIR1bits.RCIF == interrupt_occur) && (PIE1bits.RCIE == interrupt_enable)) {
        eusart_rx_isr();
    }
    else { /* Nothing*/ }
    
    // for CCP2 internal interrupt
    if ((PIR2bits.CCP2IF == interrupt_occur) && (PIE2bits.CCP2IE == interrupt_enable)) {
        ccp2_isr();
    }
    else { /* Nothing*/ }
    
    // for ADC internal interrupt
    if ((PIR1bits.ADIF == interrupt_occur) && (PIE1bits.ADIE == interrupt_enable)) {
        adc_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 0 internal interrupt
    if ((INTCONbits.TMR0IF == interrupt_occur) && (INTCONbits.TMR0IE == interrupt_enable)) {
        tmr0_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 1 internal interrupt
    if ((PIR1bits.TMR1IF == interrupt_occur) && (PIE1bits.TMR1IE == interrupt_enable)) {
        tmr1_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 2 internal interrupt
    if ((PIR1bits.TMR2IF == interrupt_occur) && (PIE1bits.TMR2IE == interrupt_enable)) {
        tmr2_isr();
    }
    else { /* Nothing*/ }
    
    // for timer 3 internal interrupt
    if ((PIR2bits.TMR3IF == interrupt_occur) && (PIE2bits.TMR3IE == interrupt_enable)) {
        tmr3_isr();
    }
    else { /* Nothing*/ }

    if ((INTCON3bits.INT1IF == interrupt_occur) && (INTCON3bits.INT1IE == interrupt_enable)) {
        int1_isr();
    }
    else { /* Nothing*/ }

    if ((INTCON3bits.INT2IF == interrupt_occur) && (INTCON3bits.INT2IE == interrupt_enable)) {
        int2_isr();
    }
    else { /* Nothing*/ }
    
    // FOR EXT RBX
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB4 == interrupt_enable) && (PORTBbits.RB4 == gpio_high) && (rb4_flag == 0x01)){
        rb4_flag = 0x00;
        rb4_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB4 == interrupt_enable) && (PORTBbits.RB4 == gpio_low) && (rb4_flag == 0x00)){
        rb4_flag = 0x01;
        rb4_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB5 == interrupt_enable) && (PORTBbits.RB5 == gpio_high) && (rb5_flag == 0x01)){
        rb5_flag = 0x00;
        rb5_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB5 == interrupt_enable) && (PORTBbits.RB5 == gpio_low) && (rb5_flag == 0x00)){
        rb5_flag = 0x01;
        rb5_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB6 == interrupt_enable) && (PORTBbits.RB6 == gpio_high) && (rb6_flag == 0x01)){
        rb6_flag = 0x00;
        rb6_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB6 == interrupt_enable) && (PORTBbits.RB6 == gpio_low) && (rb6_flag == 0x00)){
        rb6_flag = 0x01;
        rb6_isr(change_low);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB7 == interrupt_enable) && (PORTBbits.RB7 == gpio_high) && (rb7_flag == 0x01)){
        rb7_flag = 0x00;
        rb7_isr(change_high);
    }
    else { /* Nothing*/ }
    
    if((INTCONbits.RBIF == interrupt_occur) && (INTCONbits.RBIE == interrupt_enable)
            && (IOCBbits.IOCB7 == interrupt_enable) && (PORTBbits.RB7 == gpio_low) && (rb7_flag == 0x00)){
        rb7_flag = 0x01;
        rb7_isr(change_low);
    }
    else { /* Nothing*/ }
}

#endif





/******************* Section 4:  Helper Functions Definitions *******************/


