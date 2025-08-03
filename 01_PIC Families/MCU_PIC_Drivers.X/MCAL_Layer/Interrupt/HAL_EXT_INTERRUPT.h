/* 
 * File:   HAL_EXT_INTERRUPT.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:03 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EXT_INTERRUPT_H
#define	HAL_EXT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "HAL_INTERRUPT_CFG.h"

/******************* Section 2 : Macros Declarations *******************/

#define CHANGE_LOW                  (uint8)0x00
#define CHANGE_HIGH                 (uint8)0x01

/******************* Section 3 : Macros Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (EXTERNAL_INTERRUPT_INTX_ENABLE))

// for INT0 PIN "HIGH Priority by default"

#define EXT_INTERRUPT_INT0_CLEAR_FLAG()                    (INTCONbits.INT0IF = (uint8)0x00)

#define EXT_INTERRUPT_INT0_DISABLE()                       (INTCONbits.INT0IE = (uint8)0x00)
#define EXT_INTERRUPT_INT0_ENABLE()                        (INTCONbits.INT0IE = (uint8)0x01)

#define EXT_INTERRUPT_INT0_FALLING_EDGE()                  (INTCON2bits.INTEDG0 = (uint8)0x00)
#define EXT_INTERRUPT_INT0_RISING_EDGE()                   (INTCON2bits.INTEDG0 = (uint8)0x01)

// for INT1 PIN

#define EXT_INTERRUPT_INT1_CLEAR_FLAG()                    (INTCON3bits.INT1IF = (uint8)0x00)

#define EXT_INTERRUPT_INT1_DISABLE()                       (INTCON3bits.INT1IE = (uint8)0x00)
#define EXT_INTERRUPT_INT1_ENABLE()                        (INTCON3bits.INT1IE = (uint8)0x01)

#define EXT_INTERRUPT_INT1_FALLING_EDGE()                  (INTCON2bits.INTEDG1 = (uint8)0x00)
#define EXT_INTERRUPT_INT1_RISING_EDGE()                   (INTCON2bits.INTEDG1 = (uint8)0x01)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))


#define EXT_INTERRUPT_INT1_LOW_PRIORITY()                  (INTCON3bits.INT1IP = (uint8)0x00)
#define EXT_INTERRUPT_INT1_HIGH_PRIORITY()                 (INTCON3bits.INT1IP = (uint8)0x01)

#endif
// for INT2 PIN

#define EXT_INTERRUPT_INT2_CLEAR_FLAG()                    (INTCON3bits.INT2IF = (uint8)0x00)

#define EXT_INTERRUPT_INT2_DISABLE()                       (INTCON3bits.INT2IE = (uint8)0x00)
#define EXT_INTERRUPT_INT2_ENABLE()                        (INTCON3bits.INT2IE = (uint8)0x01)

#define EXT_INTERRUPT_INT2_FALLING_EDGE()                  (INTCON2bits.INTEDG2 = (uint8)0x00)
#define EXT_INTERRUPT_INT2_RISING_EDGE()                   (INTCON2bits.INTEDG2 = (uint8)0x01)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define EXT_INTERRUPT_INT2_LOW_PRIORITY()                  (INTCON3bits.INT2IP = (uint8)0x00)
#define EXT_INTERRUPT_INT2_HIGH_PRIORITY()                 (INTCON3bits.INT2IP = (uint8)0x01)

#endif

#endif

#if ((INTERRUPT_FEATURE_ENABLE) == (EXTERNAL_INTERRUPT_IOC_ENABLE))

// for external interrupt on change RBX <RB4-RB7>

#define EXT_INTERRUPT_RBX_CLEAR_FLAG()                     (INTCONbits.RBIF = (uint8)0x00)

#define EXT_INTERRUPT_RBX_DISABLE()                        (INTCONbits.RBIE = (uint8)0x00)
#define EXT_INTERRUPT_RBX_ENABLE()                         (INTCONbits.RBIE = (uint8)0x01)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB4()                 (IOCBbits.IOCB4 = (uint8)0x00)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB4()                  (IOCBbits.IOCB4 = (uint8)0x01)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB5()                 (IOCBbits.IOCB5 = (uint8)0x00)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB5()                  (IOCBbits.IOCB5 = (uint8)0x01)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB6()                 (IOCBbits.IOCB6 = (uint8)0x00)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB6()                  (IOCBbits.IOCB6 = (uint8)0x01)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB7()                 (IOCBbits.IOCB7 = (uint8)0x00)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB7()                  (IOCBbits.IOCB7 = (uint8)0x01)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define EXT_INTERRUPT_RBX_LOW_PRIORITY()                   (INTCON2bits.RBIP = (uint8)0x00)
#define EXT_INTERRUPT_RBX_HIGH_PRIORITY()                  (INTCON2bits.RBIP = (uint8)0x01)

#endif

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* INTERRUPT_HANDLER)(void);

typedef enum{
    INTERRUPT_INT0             = (uint8)0x00,
    INTERRUPT_INT1             = (uint8)0x01,
    INTERRUPT_INT2             = (uint8)0x02
}INTERRUPT_INTX_SOURCE;

typedef enum{
    INTERRUPT_RB4              = (uint8)0x00,
    INTERRUPT_RB5              = (uint8)0x01,
    INTERRUPT_RB6              = (uint8)0x02,
    INTERRUPT_RB7              = (uint8)0x03
}INTERRUPT_RBX_SOURCE;

typedef enum{
    INTERRUPT_FALLING_EDGE     = (uint8)0x00,
    INTERRUPT_RISING_EDGE      = (uint8)0x01,
}INTERRUPT_INTX_EDGES;

typedef enum{
    INTERRUPT_ON_CHANGE        = (uint8)0x00  
}INTERRUPT_RBX_EDGES;

typedef struct{
    INTERRUPT_HANDLER INTERRUPT_ISR;
    GPIO_PIN_CFG             pin;
    INTERRUPT_INTX_SOURCE source;
    INTERRUPT_PRIORITY  priority;
    INTERRUPT_INTX_EDGES    edge;
}INTERRUPT_INTX;

typedef struct{
    INTERRUPT_HANDLER INTERRUPT_ISR_CHANGE_HIGH;
    INTERRUPT_HANDLER INTERRUPT_ISR_CHANGE_LOW;
    GPIO_PIN_CFG             pin;
    INTERRUPT_RBX_SOURCE  source;
    INTERRUPT_PRIORITY  priority;
    INTERRUPT_RBX_EDGES     edge; 
}INTERRUPT_RBX;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType EXTERNAL_INTERRUPT_INTX_INIT(const INTERRUPT_INTX *int_pin);
Std_ReturnType EXTERNAL_INTERRUPT_INTX_DEINIT(const INTERRUPT_INTX *int_pin);

Std_ReturnType EXTERNAL_INTERRUPT_RBX_INIT(const INTERRUPT_RBX *int_pin);
Std_ReturnType EXTERNAL_INTERRUPT_RBX_DEINIT(const INTERRUPT_RBX *int_pin);


#endif	/* HAL_EXT_INTERRUPT_H */

