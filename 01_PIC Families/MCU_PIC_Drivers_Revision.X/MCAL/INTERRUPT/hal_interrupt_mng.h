/* 
 * File:   hal_interrupt_mng.h
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:15 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_MNG_H
#define	HAL_INTERRUPT_MNG_H

/******************* Section 1 : Includes *******************/

#include "hal_interrupt_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

// for external interrupts
void int0_isr(void);
void int1_isr(void);
void int2_isr(void);
void rb4_isr(uint8 change);
void rb5_isr(uint8 change);
void rb6_isr(uint8 change);
void rb7_isr(uint8 change);

// for internal interrupts
void adc_isr(void);
void tmr0_isr(void);
void tmr1_isr(void);

#endif	/* HAL_INTERRUPT_MNG_H */

