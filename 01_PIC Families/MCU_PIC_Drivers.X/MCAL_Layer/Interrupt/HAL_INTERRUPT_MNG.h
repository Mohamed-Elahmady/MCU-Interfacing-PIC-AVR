/* 
 * File:   HAL_INTERRUPT_MNG.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:05 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_MNG_H
#define	HAL_INTERRUPT_MNG_H

/******************* Section 1 : Includes *******************/

#include "HAL_INTERRUPT_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

// For External Interrupts 
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 change);
void RB5_ISR(uint8 change);
void RB6_ISR(uint8 change);
void RB7_ISR(uint8 change);
// For Internal Interrupts
void ADC_ISR(void);
void TMR0_ISR(void);
void TMR1_ISR(void);
void TMR2_ISR(void);

#endif	/* HAL_INTERRUPT_MNG_H */

