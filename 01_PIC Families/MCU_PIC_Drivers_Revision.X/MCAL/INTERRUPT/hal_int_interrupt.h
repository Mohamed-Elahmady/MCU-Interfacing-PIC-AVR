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
#if ((interrupt_feature_enable) == (int_interrupt_adc))

#define intenral_interrupt_adc_clear_flag()                      clear_bit(PIR1, _PIR1_ADIF_POSITION)

#define intenral_interrupt_adc_disable()                          clear_bit(PIE1, _PIE1_ADIE_POSITION)
#define intenral_interrupt_adc_enable()                           set_bit(PIE1, _PIE1_ADIE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_adc_low_priority()                     clear_bit(IPR1, _IPR1_ADIP_POSITION)
#define intenral_interrupt_adc_high_priority()                    set_bit(IPR1, _IPR1_ADIP_POSITION)

#endif

#endif

// Timer0 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_timer0))

#define intenral_interrupt_timer0_clear_flag()                    clear_bit(INTCON, _INTCON_TMR0IF_POSITION)

#define intenral_interrupt_timer0_disable()                       clear_bit(INTCON, _INTCON_TMR0IE_POSITION)
#define intenral_interrupt_timer0_enable()                        set_bit(INTCON, _INTCON_TMR0IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_timer0_low_priority()                  clear_bit(INTCON2, _INTCON2_TMR0IP_POSITION)
#define intenral_interrupt_timer0_high_priority()                 set_bit(INTCON2, _INTCON2_TMR0IP_POSITION)

#endif

#endif

// Timer1 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_timer1))

#define intenral_interrupt_timer1_clear_flag()                    clear_bit(PIR1, _PIR1_TMR1IF_POSITION)

#define intenral_interrupt_timer1_disable()                       clear_bit(PIE1, _PIE1_TMR1IE_POSITION)
#define intenral_interrupt_timer1_enable()                        set_bit(PIE1, _PIE1_TMR1IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_timer1_low_priority()                  clear_bit(IPR1, _IPR1_TMR1IP_POSITION)
#define intenral_interrupt_timer1_high_priority()                 set_bit(IPR1, _IPR1_TMR1IP_POSITION)

#endif

#endif

// Timer2 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_timer2))

#define intenral_interrupt_timer2_clear_flag()                    clear_bit(PIR1, _PIR1_TMR2IF_POSITION)

#define intenral_interrupt_timer2_disable()                       clear_bit(PIE1, _PIE1_TMR2IE_POSITION)
#define intenral_interrupt_timer2_enable()                        set_bit(PIE1, _PIE1_TMR2IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_timer2_low_priority()                  clear_bit(IPR1, _IPR1_TMR2IP_POSITION)
#define intenral_interrupt_timer2_high_priority()                 set_bit(IPR1, _IPR1_TMR2IP_POSITION)

#endif

#endif

// Timer3 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_timer3))

#define intenral_interrupt_timer3_clear_flag()                    clear_bit(PIR2, _PIR2_TMR3IF_POSITION)

#define intenral_interrupt_timer3_disable()                       clear_bit(PIE2, _PIE2_TMR3IE_POSITION)
#define intenral_interrupt_timer3_enable()                        set_bit(PIE2, _PIE2_TMR3IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_timer3_low_priority()                  clear_bit(IPR2, _IPR2_TMR3IP_POSITION)
#define intenral_interrupt_timer3_high_priority()                 set_bit(IPR2, _IPR2_TMR3IP_POSITION)

#endif

#endif

// CCP1 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_ccp1))

#define intenral_interrupt_ccp1_clear_flag()                    clear_bit(PIR1, _PIR1_CCP1IF_POSITION)

#define intenral_interrupt_ccp1_disable()                       clear_bit(PIE1, _PIE1_CCP1IE_POSITION)
#define intenral_interrupt_ccp1_enable()                        set_bit(PIE1, _PIE1_CCP1IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_ccp1_low_priority()                  clear_bit(IPR1, _IPR1_CCP1IP_POSITION)
#define intenral_interrupt_ccp1_high_priority()                 set_bit(IPR1, _IPR1_CCP1IP_POSITION)

#endif

#endif

// CCP2 internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_ccp2))

#define intenral_interrupt_ccp2_clear_flag()                    clear_bit(PIR2, _PIR2_CCP2IF_POSITION)

#define intenral_interrupt_ccp2_disable()                       clear_bit(PIE2, _PIE2_CCP2IE_POSITION)
#define intenral_interrupt_ccp2_enable()                        set_bit(PIE2, _PIE2_CCP2IE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_ccp2_low_priority()                  clear_bit(IPR2, _IPR2_CCP2IP_POSITION)
#define intenral_interrupt_ccp2_high_priority()                 set_bit(IPR2, _IPR2_CCP2IP_POSITION)

#endif

#endif

// EUSART TX internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_eusart))

#define intenral_interrupt_eusart_tx_clear_flag()                    clear_bit(PIR1, _PIR1_TXIF_POSITION)

#define intenral_interrupt_eusart_tx_disable()                       clear_bit(PIE1, _PIE1_TXIE_POSITION)
#define intenral_interrupt_eusart_tx_enable()                        set_bit(PIE1, _PIE1_TXIE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_eusart_tx_low_priority()                  clear_bit(IPR1, _IPR1_TXIP_POSITION)
#define intenral_interrupt_eusart_tx_high_priority()                 set_bit(IPR1, _IPR1_TXIP_POSITION)

#endif

#endif

// EUSART RX internal interrupt Configurations
#if ((interrupt_feature_enable) == (int_interrupt_eusart))

#define intenral_interrupt_eusart_rx_clear_flag()                    clear_bit(PIR1, _PIR1_RCIF_POSITION)

#define intenral_interrupt_eusart_rx_disable()                       clear_bit(PIE1, _PIE1_RCIE_POSITION)
#define intenral_interrupt_eusart_rx_enable()                        set_bit(PIE1, _PIE1_RCIE_POSITION)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define intenral_interrupt_eusart_rx_low_priority()                  clear_bit(IPR1, _IPR1_RCIP_POSITION)
#define intenral_interrupt_eusart_rx_high_priority()                 set_bit(IPR1, _IPR1_RCIP_POSITION)

#endif

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/




#endif	/* HAL_INT_INTERRUPT_H */

