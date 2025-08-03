/* 
 * File:   HAL_INTERRUPT_CFG.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:08 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INTERRUPT_CFG_H
#define	HAL_INTERRUPT_CFG_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_INTERRUPT_GEN_CFG.h"
#include "../GPIO/HAL_GPIO.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

// For Flag Bit
#define INTERRUPT_NOT_OCCUR                 0x00
#define INTERRUPT_OCCUR                     0x01
// For Enable Bit
#define INTERRUPT_DISABLE                   0x00
#define INTERRUPT_ENABLE                    0x01
// For Priority Bit
#define INTERRUPT_PRIORITY_DISABLE          0x00
#define INTERRUPT_PRIORITY_ENABLE           0x01
// For RBX CHANGES
#define CHANGE_LOW                  (uint8)0x00
#define CHANGE_HIGH                 (uint8)0x01

/******************* Section 3 : Macros Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

// For Priority Bit

// This Macro for Enable all priority levels
#define INTERRUPT_PRIORITY_BIT_ENABLE()                     (RCONbits.IPEN = (uint8)0x01)

// For Enable Bits

// This Macro for Disable all interrupts high priority & low priority
#define GLOBAL_INTERRUPT_HIGH_DISABLE()                     (INTCONbits.GIEH = (uint8)0x00)
// This Macro for Enable all high priority interrupts
#define GLOBAL_INTERRUPT_HIGH_ENABLE()                      (INTCONbits.GIEH = (uint8)0x01)

// This Macro for Disable all low priority interrupts
#define GLOBAL_INTERRUPT_LOW_DISABLE()                      (INTCONbits.GIEL = (uint8)0x00)
// This Macro for Enable all low priority interrupts
#define GLOBAL_INTERRUPT_LOW_ENABLE()                       (INTCONbits.GIEL = (uint8)0x01)

#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))

// For Priority Bit

// This Macro for Disable all priority levels
#define INTERRUPT_PRIORITY_BIT_DISABLE()                    (RCONbits.IPEN = (uint8)0x00)

// For Enable Bits

// This Macro for Disable all global interrupts
#define GLOBAL_INTERRUPT_DISABLE()                          (INTCONbits.GIE = (uint8)0x00)
// This Macro for Enable all global interrupts
#define GLOBAL_INTERRUPT_ENABLE()                           (INTCONbits.GIE = (uint8)0x01)

// This Macro for Disable all peripheral interrupts like "ADC, I2C, SPI, UART,...."
#define PERIPHERAL_INTERRUPT_DISABLE()                      (INTCONbits.PEIE = (uint8)0x00)
// This Macro for Enable all peripheral interrupts like "ADC, I2C, SPI, UART,...."
#define PERIPHERAL_INTERRUPT_ENABLE()                       (INTCONbits.PEIE = (uint8)0x01)


#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum {
    INTERRUPT_LOW_PRIORITY     = (uint8)0x00,
    INTERRUPT_HIGH_PRIORITY    = (uint8)0x01
}INTERRUPT_PRIORITY;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/



#endif	/* HAL_INTERRUPT_CFG_H */

