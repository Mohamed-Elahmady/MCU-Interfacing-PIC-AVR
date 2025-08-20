/* 
 * File:   HAL_INTERRUPT_GEN_CFG.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 6:41 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_GEN_CFG_H
#define	HAL_INTERRUPT_GEN_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define INTERRUPT_FEATURE_DISABLE                 0x00
#define INTERRUPT_FEATURE_ENABLE                  0x01

#define INTERRUPT_PRIORITY_LEVELS                 (INTERRUPT_FEATURE_ENABLE)

// For EXT Interrupts
#define EXTERNAL_INTERRUPT_INTX_ENABLE            (INTERRUPT_FEATURE_ENABLE)
#define EXTERNAL_INTERRUPT_IOC_ENABLE             (INTERRUPT_FEATURE_ENABLE)

// For ADC Internal Interrupts
#define ADC_INTERRUPT_FEATURE                     (INTERRUPT_FEATURE_ENABLE)
// For Timer0 Internal Interrupts
#define TIMER0_INTERRUPT_FEATURE                  (INTERRUPT_FEATURE_ENABLE)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* HAL_INTERRUPT_GEN_CFG_H */

