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

#define EXT_INTERRUPT_INT0_CLEAR_FLAG()                    CLEAR_BIT(INTCON, _INTCON_INT0IF_POSITION)

#define EXT_INTERRUPT_INT0_DISABLE()                       CLEAR_BIT(INTCON, _INTCON_INT0IE_POSITION)
#define EXT_INTERRUPT_INT0_ENABLE()                        SET_BIT(INTCON, _INTCON_INT0IE_POSITION)

#define EXT_INTERRUPT_INT0_FALLING_EDGE()                  CLEAR_BIT(INTCON2, _INTCON2_INTEDG0_POSITION)
#define EXT_INTERRUPT_INT0_RISING_EDGE()                   SET_BIT(INTCON2, _INTCON2_INTEDG0_POSITION)

// for INT1 PIN

#define EXT_INTERRUPT_INT1_CLEAR_FLAG()                    CLEAR_BIT(INTCON3, _INTCON3_INT1IF_POSITION)

#define EXT_INTERRUPT_INT1_DISABLE()                       CLEAR_BIT(INTCON3, _INTCON3_INT1IE_POSITION)
#define EXT_INTERRUPT_INT1_ENABLE()                        SET_BIT(INTCON3, _INTCON3_INT1IE_POSITION)

#define EXT_INTERRUPT_INT1_FALLING_EDGE()                  CLEAR_BIT(INTCON2, _INTCON2_INTEDG1_POSITION)
#define EXT_INTERRUPT_INT1_RISING_EDGE()                   SET_BIT(INTCON2, _INTCON2_INTEDG1_POSITION)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))


#define EXT_INTERRUPT_INT1_LOW_PRIORITY()                  CLEAR_BIT(INTCON3, _INTCON3_INT1IP_POSITION)
#define EXT_INTERRUPT_INT1_HIGH_PRIORITY()                 SET_BIT(INTCON3, _INTCON3_INT1IP_POSITION)

#endif
// for INT2 PIN

#define EXT_INTERRUPT_INT2_CLEAR_FLAG()                    CLEAR_BIT(INTCON3, _INTCON3_INT2IF_POSITION)

#define EXT_INTERRUPT_INT2_DISABLE()                       CLEAR_BIT(INTCON3, _INTCON3_INT2IE_POSITION)
#define EXT_INTERRUPT_INT2_ENABLE()                        SET_BIT(INTCON3, _INTCON3_INT2IE_POSITION)

#define EXT_INTERRUPT_INT2_FALLING_EDGE()                  CLEAR_BIT(INTCON2, _INTCON2_INTEDG2_POSITION)
#define EXT_INTERRUPT_INT2_RISING_EDGE()                   SET_BIT(INTCON2, _INTCON2_INTEDG2_POSITION)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define EXT_INTERRUPT_INT2_LOW_PRIORITY()                  CLEAR_BIT(INTCON3, _INTCON3_INT2IP_POSITION)
#define EXT_INTERRUPT_INT2_HIGH_PRIORITY()                 SET_BIT(INTCON3, _INTCON3_INT2IP_POSITION)

#endif

#endif

#if ((INTERRUPT_FEATURE_ENABLE) == (EXTERNAL_INTERRUPT_IOC_ENABLE))

// for external interrupt on change RBX <RB4-RB7>

#define EXT_INTERRUPT_RBX_CLEAR_FLAG()                     CLEAR_BIT(INTCON, _INTCON_RBIF_POSITION)

#define EXT_INTERRUPT_RBX_DISABLE()                        CLEAR_BIT(INTCON, _INTCON_RBIE_POSITION)
#define EXT_INTERRUPT_RBX_ENABLE()                         SET_BIT(INTCON, _INTCON_RBIE_POSITION)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB4()                 CLEAR_BIT(IOCB, _IOCB_IOCB4_POSITION)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB4()                  SET_BIT(IOCB, _IOCB_IOCB4_POSITION)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB5()                 CLEAR_BIT(IOCB, _IOCB_IOCB5_POSITION)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB5()                  SET_BIT(IOCB, _IOCB_IOCB5_POSITION)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB6()                 CLEAR_BIT(IOCB, _IOCB_IOCB6_POSITION)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB6()                  SET_BIT(IOCB, _IOCB_IOCB6_POSITION)

#define DISABLE_EXT_INTERRUPT_IOC_ON_RB7()                 CLEAR_BIT(IOCB, _IOCB_IOCB7_POSITION)
#define ENABLE_EXT_INTERRUPT_IOC_ON_RB7()                  SET_BIT(IOCB, _IOCB_IOCB7_POSITION)

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define EXT_INTERRUPT_RBX_LOW_PRIORITY()                   CLEAR_BIT(INTCON2, _INTCON2_RBIP_POSITION)
#define EXT_INTERRUPT_RBX_HIGH_PRIORITY()                  SET_BIT(INTCON2, _INTCON2_RBIP_POSITION)

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

