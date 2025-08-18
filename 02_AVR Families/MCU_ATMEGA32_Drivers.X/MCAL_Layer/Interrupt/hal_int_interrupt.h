/* 
 * File:   hal_int_interrupt.h
 * Author: mohammedel-ahmady
 *
 * Created on August 3, 2025, 6:15 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INT_INTERRUPT_H
#define	HAL_INT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "hal_interrupt_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

// Internal Interrupts

// 1. For ADC Interrupt
#define Internal_Interrupt_ADC_Clear_Flag()                 Clear_Bit(ADCSRA, ADIF)

#define Internal_Interrupt_ADC_Disable()                    Clear_Bit(ADCSRA, ADIE)
#define Internal_Interrupt_ADC_Enable()                     Set_Bit(ADCSRA, ADIE)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/


#endif	/* HAL_INT_INTERRUPT_H */

