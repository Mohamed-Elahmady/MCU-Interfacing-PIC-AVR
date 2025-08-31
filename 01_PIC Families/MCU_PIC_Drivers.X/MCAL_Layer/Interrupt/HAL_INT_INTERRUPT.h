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

// Timer0 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))

// Timer0 Flag bit
#define INT_INTERRUPT_TIMER0_CLEAR_FLAG()                     CLEAR_BIT(INTCON, _INTCON_TMR0IF_POSITION)

// Timer0 Enable Bit
#define INT_INTERRUPT_TIMER0_DISABLE()                        CLEAR_BIT(INTCON, _INTCON_TMR0IE_POSITION)
#define INT_INTERRUPT_TIMER0_ENABLE()                         SET_BIT(INTCON, _INTCON_TMR0IE_POSITION)

// Timer0 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER0_LOW_PRIORITY()                   CLEAR_BIT(INTCON2, _INTCON2_TMR0IP_POSITION)
#define INT_INTERRUPT_TIMER0_HIGH_PRIORITY()                  SET_BIT(INTCON2, _INTCON2_TMR0IP_POSITION)

#endif

#endif

// Timer1 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

// Timer1 Flag bit
#define INT_INTERRUPT_TIMER1_CLEAR_FLAG()                     CLEAR_BIT(PIR1, _PIR1_TMR1IF_POSITION)

// Timer1 Enable Bit
#define INT_INTERRUPT_TIMER1_DISABLE()                        CLEAR_BIT(PIE1, _PIE1_TMR1IE_POSITION)
#define INT_INTERRUPT_TIMER1_ENABLE()                         SET_BIT(PIE1, _PIE1_TMR1IE_POSITION)

// Timer1 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER1_LOW_PRIORITY()                   CLEAR_BIT(IPR1, _IPR1_TMR1IP_POSITION)
#define INT_INTERRUPT_TIMER1_HIGH_PRIORITY()                  SET_BIT(IPR1, _IPR1_TMR1IP_POSITION)

#endif

#endif

// Timer2 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))

// Timer2 Flag bit
#define INT_INTERRUPT_TIMER2_CLEAR_FLAG()                     CLEAR_BIT(PIR1, _PIR1_TMR2IF_POSITION)

// Timer2 Enable Bit
#define INT_INTERRUPT_TIMER2_DISABLE()                        CLEAR_BIT(PIE1, _PIE1_TMR2IE_POSITION)
#define INT_INTERRUPT_TIMER2_ENABLE()                         SET_BIT(PIE1, _PIE1_TMR2IE_POSITION)

// Timer2 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER2_LOW_PRIORITY()                   CLEAR_BIT(IPR1, _IPR1_TMR2IP_POSITION)
#define INT_INTERRUPT_TIMER2_HIGH_PRIORITY()                  SET_BIT(IPR1, _IPR1_TMR2IP_POSITION)

#endif

#endif

// Timer3 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))

// Timer3 Flag bit
#define INT_INTERRUPT_TIMER3_CLEAR_FLAG()                     CLEAR_BIT(PIR2, _PIR2_TMR3IF_POSITION)

// Timer3 Enable Bit
#define INT_INTERRUPT_TIMER3_DISABLE()                        CLEAR_BIT(PIE2, _PIE2_TMR3IE_POSITION)
#define INT_INTERRUPT_TIMER3_ENABLE()                         SET_BIT(PIE2, _PIE2_TMR3IE_POSITION)

// Timer3 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER3_LOW_PRIORITY()                   CLEAR_BIT(IPR2, _IPR2_TMR3IP_POSITION)
#define INT_INTERRUPT_TIMER3_HIGH_PRIORITY()                  SET_BIT(IPR2, _IPR2_TMR3IP_POSITION)

#endif

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/



#endif	/* HAL_INT_INTERRUPT_H */

