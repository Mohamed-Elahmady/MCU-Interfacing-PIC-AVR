/* 
 * File:   interrupts.c
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#include "interrupts.h"

/******************* Section 1 : Static Variables *******************/

static ISR_Callback_t MSSP_InterruptHandler = 0;
static ISR_Callback_t BusCollisionHandler = 0;

/******************* Section 2 : Function Definitions *******************/

void INTERRUPT_Init(void)
{
    // Enable global & peripheral interrupts
    INTCONbits.PEIE = 1;
    INTCONbits.GIE  = 1;
}

void INTERRUPT_SetMSSPHandler(ISR_Callback_t callback)
{
    MSSP_InterruptHandler = callback;
}

void INTERRUPT_SetBusCollisionHandler(ISR_Callback_t callback)
{
    BusCollisionHandler = callback;
}

/******************* Section 3 : Global Interrupt Handler *******************/
void __interrupt() INTERRUPT_Handler(void)
{
    // MSSP interrupt
    if (PIR1bits.SSPIF && PIE1bits.SSPIE)
    {
        PIR1bits.SSPIF = 0;
        if (MSSP_InterruptHandler)
            MSSP_InterruptHandler();
    }

    // Bus collision interrupt
    if (PIR2bits.BCLIF && PIE2bits.BCLIE)
    {
        PIR2bits.BCLIF = 0;
        if (BusCollisionHandler)
            BusCollisionHandler();
    }
}