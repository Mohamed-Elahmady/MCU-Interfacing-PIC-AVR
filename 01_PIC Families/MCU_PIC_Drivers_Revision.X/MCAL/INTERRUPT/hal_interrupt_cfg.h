/* 
 * File:   hal_interrupt_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:15 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_CFG_H
#define	HAL_INTERRUPT_CFG_H

/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "../GPIO/hal_gpio.h"
#include "hal_interrupt_gen_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

// flag bit
#define interrupt_not_occur                      (uint8)0x00
#define interrupt_occur                          (uint8)0x01

// enable bit

#define interrupt_disable                        (uint8)0x00
#define interrupt_enable                         (uint8)0x01

// priority bit

#define interrupt_priority_disable               (uint8)0x00
#define interrupt_priority_enable                (uint8)0x01

// RBX Change

#define change_low                               (uint8)0x00
#define change_high                              (uint8)0x01


/******************* Section 3 : Macros Functions Declarations *******************/

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define interrupt_priority_bit_enable()                 (RCONbits.IPEN = (uint8)0x01)

#define global_interrupt_high_disable()                 (INTCONbits.GIEH = (uint8)0x00)
#define global_interrupt_high_enable()                  (INTCONbits.GIEH = (uint8)0x01)

#define global_interrupt_low_disable()                  (INTCONbits.GIEL = (uint8)0x00)
#define global_interrupt_low_enable()                   (INTCONbits.GIEL = (uint8)0x01)

#elif((interrupt_feature_disable) == (interrupt_priority_levels))

#define interrupt_priority_bit_disable()                (RCONbits.IPEN = (uint8)0x00)

#define global_interrupt_disable()                      (INTCONbits.GIE = (uint8)0x00)
#define global_interrupt_enable()                       (INTCONbits.GIE = (uint8)0x01)

#define peripheral_interrupt_disable()                  (INTCONbits.PEIE = (uint8)0x00)
#define peripheral_interrupt_enable()                   (INTCONbits.PEIE = (uint8)0x01)

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    interrupt_low_priority  = (uint8)0x00,
    interrupt_high_priority = (uint8)0x01
}interrupt_priority;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/




#endif	/* HAL_INTERRUPT_CFG_H */

