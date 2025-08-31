/* 
 * File:   hal_interrupt_gen_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:16 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_GEN_CFG_H
#define	HAL_INTERRUPT_GEN_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define interrupt_feature_disable                   0x00
#define interrupt_feature_enable                    0x01

//#define interrupt_priority_levels                   (interrupt_feature_enable)

// for external interrupts

#define ext_interrupt_intx                          (interrupt_feature_enable)
#define ext_interrupt_rbx                           (interrupt_feature_enable)

// for internal interrupts
#define int_interrupt_adc                           (interrupt_feature_enable)
#define int_interrupt_timer0                        (interrupt_feature_enable)
#define int_interrupt_timer1                        (interrupt_feature_enable)
#define int_interrupt_timer2                        (interrupt_feature_enable)
#define int_interrupt_timer3                        (interrupt_feature_enable)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/




#endif	/* HAL_INTERRUPT_GEN_CFG_H */

