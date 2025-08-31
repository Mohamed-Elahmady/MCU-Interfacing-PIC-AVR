/* 
 * File:   HAL_TIMER3.h
 * Author: mohammedel-ahmady
 *
 * Created on August 30, 2025, 2:07 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "../../mcal_std_types.h"
#include "HAL_TIMER3_CFG.h"
#include "../../GPIO/HAL_GPIO.h"
#include "../../Interrupt/HAL_INT_INTERRUPT.h"
#include "../Timer1/HAL_TIMER1.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define TIMER3_MODULE_DISABLE()                     CLEAR_BIT(T3CON, _T3CON_TMR3ON_POSITION)
#define TIMER3_MODULE_ENABLE()                      SET_BIT(T3CON, _T3CON_TMR3ON_POSITION)

#define TIMER3_INTERNAL_TIMER_MODE()                CLEAR_BIT(T3CON, _T3CON_TMR3CS_POSITION)
// External Oscillator Enable Counter Mode in only start from the second Rising Edge
#define TIMER3_EXTERNAL_COUNTER_MODE()              SET_BIT(T3CON, _T3CON_TMR3CS_POSITION)

#define TIMER3_SYNCHRONOUS_COUNTER_MODE()           CLEAR_BIT(T3CON, _T3CON_NOT_T3SYNC_POSITION)
#define TIMER3_ASYNCHRONOUS_COUNTER_MODE()          SET_BIT(T3CON, _T3CON_NOT_T3SYNC_POSITION)

#define TIMER3_PRESCALER_SELECT(__PRESCALER)                 (T3CONbits.T3CKPS = __PRESCALER)

#define TIMER3_8BIT_READ_WRITE_MODE()               CLEAR_BIT(T3CON, _T3CON_RD16_POSITION)
#define TIMER3_16BIT_READ_WRITE_MODE()              SET_BIT(T3CON, _T3CON_RD16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* TIMER3_HANDLER)(void);

typedef enum{
    TIMER3_PRESCALER_DIV_1 = (uint8)0x00,
    TIMER3_PRESCALER_DIV_2,
    TIMER3_PRESCALER_DIV_4,
    TIMER3_PRESCALER_DIV_8
}TIMER3_PRESCALER;

typedef enum{
    TIMER3_TIMER_MODE = (uint8)0X00,
    TIMER3_COUNTER_MODE
}TIMER3_MODE;

typedef enum{
    TIMER3_SYNCHRONOUS_COUNTER = (uint8)0x00,
    TIMER3_ASYNCHRONOUS_COUNTER
}TIMER3_SYNCHRONIZATION;

typedef enum{
    TIMER3_8BIT_RW_MODE = (uint8)0x00,
    TIMER3_16BIT_RW_MODE
}TIMER3_RW_MODE;

typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
    TIMER3_HANDLER      TIMER3_INTERRUPT;
    INTERRUPT_PRIORITY          priority;
#endif
    uint16               preloaded_value;
    TIMER3_PRESCALER           prescaler;
    TIMER1_OSCILLATOR                osc;
    TIMER3_MODE                     mode;
    TIMER3_SYNCHRONIZATION          sync;
    TIMER3_RW_MODE                rw_reg;
}TIMER3_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType TIMER3_INIT(const TIMER3_CFG *timer3);
Std_ReturnType TIMER3_DEINIT(const TIMER3_CFG *timer3);
Std_ReturnType TIMER3_WRITE_DATA(const TIMER3_CFG *timer3, uint16 data);
Std_ReturnType TIMER3_READ_DATA(const TIMER3_CFG *timer3, uint16 *data);

#endif	/* HAL_TIMER3_H */

