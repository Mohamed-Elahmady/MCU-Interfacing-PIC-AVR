/* 
 * File:   HAL_TIMER2.h
 * Author: mohammedel-ahmady
 *
 * Created on August 26, 2025, 9:16 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_TIMER2_CFG.h"
#include "../../GPIO/HAL_GPIO.h"
#include "../../Interrupt/HAL_INT_INTERRUPT.h"
#include "../../mcal_std_types.h"
#include "../../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define TIMER2_MODULE_DISABLE()                             CLEAR_BIT(T2CON, _T2CON_TMR2ON_POSITION)
#define TIMER2_MODULE_ENABLE()                              SET_BIT(T2CON, _T2CON_TMR2ON_POSITION)

#define TIMER2_SELECT_PRESCALER(__PRESCALER)                (T2CONbits.T2CKPS = __PRESCALER)
#define TIMER2_SELECT_POSTSCALER(__POSTSCALER)              (T2CONbits.T2OUTPS = __POSTSCALER)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void(*TIMER2_HANDLER)(void);

typedef enum{
    TIMER2_PRESCALER_DIV_1 = (uint8)0x00,
    TIMER2_PRESCALER_DIV_4,
    TIMER2_PRESCALER_DIV_16
}TIMER2_PRESCALER_SELECT;

typedef enum{
    TIMER2_POSTSCALER_DIV_1 = (uint8)0x00,
    TIMER2_POSTSCALER_DIV_2,
    TIMER2_POSTSCALER_DIV_3,
    TIMER2_POSTSCALER_DIV_4,
    TIMER2_POSTSCALER_DIV_5,
    TIMER2_POSTSCALER_DIV_6,
    TIMER2_POSTSCALER_DIV_7,
    TIMER2_POSTSCALER_DIV_8,
    TIMER2_POSTSCALER_DIV_9,
    TIMER2_POSTSCALER_DIV_10,
    TIMER2_POSTSCALER_DIV_11,
    TIMER2_POSTSCALER_DIV_12,
    TIMER2_POSTSCALER_DIV_13,
    TIMER2_POSTSCALER_DIV_14,
    TIMER2_POSTSCALER_DIV_15,
    TIMER2_POSTSCALER_DIV_16
}TIMER2_POSTSCALER_SELECT;


typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))
    TIMER2_HANDLER          TIMER2_INTERRUPT;
    INTERRUPT_PRIORITY              priority;
#endif
    uint8                    preloaded_value;
    TIMER2_PRESCALER_SELECT        prescaler;
    TIMER2_POSTSCALER_SELECT      postscaler;
}TIMER2_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType TIMER2_INIT(const TIMER2_CFG *timer2);
Std_ReturnType TIMER2_DEINIT(const TIMER2_CFG *timer2);
Std_ReturnType TIMER2_WRITE_DATA(const TIMER2_CFG *timer2, uint8 data);
Std_ReturnType TIMER2_READ_DATA(const TIMER2_CFG *timer2, uint8 *data);


#endif	/* HAL_TIMER2_H */

