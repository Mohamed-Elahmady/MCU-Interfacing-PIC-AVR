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

void int0_isr(void);
void int1_isr(void);
void int2_isr(void);
void rb4_isr(uint8 change);
void rb5_isr(uint8 change);
void rb6_isr(uint8 change);
void rb7_isr(uint8 change);



#endif	/* HAL_INTERRUPT_MNG_H */

