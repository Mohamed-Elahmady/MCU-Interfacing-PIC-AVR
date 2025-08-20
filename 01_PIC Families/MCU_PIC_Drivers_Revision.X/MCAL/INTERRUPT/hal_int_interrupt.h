/* 
 * File:   hal_int_interrupt.h
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:14 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INT_INTERRUPT_H
#define	HAL_INT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "hal_interrupt_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

// ADC internal interrupt Configurations

#define intenral_interrupt_adc_clear_flag()                      clear_bit(PIR1, _PIR1_ADIF_POSITION)

#define intenral_interrupt_adc_disable()                          clear_bit(PIE1, _PIE1_ADIE_POSITION)
#define intenral_interrupt_adc_enable()                           set_bit(PIE1, _PIE1_ADIE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_adc_low_priority()                     clear_bit(IPR1, _IPR1_ADIP_POSITION)
#define intenral_interrupt_adc_high_priority()                    set_bit(IPR1, _IPR1_ADIP_POSITION)

#endif

// Timer0 internal interrupt Configurations

#define intenral_interrupt_timer0_clear_flag()                    clear_bit(INTCON, _INTCON_TMR0IF_POSITION)

#define intenral_interrupt_timer0_disable()                       clear_bit(INTCON, _INTCON_TMR0IE_POSITION)
#define intenral_interrupt_timer0_enable()                        set_bit(INTCON, _INTCON_TMR0IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_timer0_low_priority()                  clear_bit(INTCON2, _INTCON2_TMR0IP_POSITION)
#define intenral_interrupt_timer0_high_priority()                 set_bit(INTCON2, _INTCON2_TMR0IP_POSITION)

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/




#endif	/* HAL_INT_INTERRUPT_H */

