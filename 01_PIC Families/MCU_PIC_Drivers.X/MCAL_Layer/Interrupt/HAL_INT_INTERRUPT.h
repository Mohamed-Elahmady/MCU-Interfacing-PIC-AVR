/* 
 * File:   HAL_INT_INTERRUPT.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:03 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INT_INTERRUPT_H
#define	HAL_INT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "HAL_INTERRUPT_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

// Analog to Digital Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))

// ADC Flag bit
#define INT_INTERRUPT_ADC_CLEAR_FLAG()                        CLEAR_BIT(PIR1, _PIR1_ADIF_POSITION)

// ADC Enable Bit
#define INT_INTERRUPT_ADC_DISABLE()                           CLEAR_BIT(PIE1, _PIE1_ADIE_POSITION)
#define INT_INTERRUPT_ADC_ENABLE()                            SET_BIT(PIE1, _PIE1_ADIE_POSITION)

// ADC Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_ADC_LOW_PRIORITY()                      CLEAR_BIT(IPR1, _IPR1_ADIP_POSITION)
#define INT_INTERRUPT_ADC_HIGH_PRIORITY()                     SET_BIT(IPR1, _IPR1_ADIP_POSITION)

#endif

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/



#endif	/* HAL_INT_INTERRUPT_H */

