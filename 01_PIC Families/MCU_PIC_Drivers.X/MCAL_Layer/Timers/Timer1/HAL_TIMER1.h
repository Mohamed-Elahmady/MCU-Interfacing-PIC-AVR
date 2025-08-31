/* 
 * File:   HAL_TIMER1.h
 * Author: mohammedel-ahmady
 *
 * Created on August 21, 2025, 6:36 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_TIMER1_CFG.h"
#include "../../GPIO/HAL_GPIO.h"
#include "../../Interrupt/HAL_INT_INTERRUPT.h"
#include "../../mcal_std_types.h"
#include "../../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define TIMER1_MODULE_DISABLE()                             CLEAR_BIT(T1CON, _T1CON_TMR1ON_POSITION)
#define TIMER1_MODULE_ENABLE()                              SET_BIT(T1CON, _T1CON_TMR1ON_POSITION)

#define TIMER1_INTERNAL_TIMER_MODE()                        CLEAR_BIT(T1CON, _T1CON_TMR1CS_POSITION)
// External Oscillator Enable Counter Mode in only Rising Edge
#define TIMER1_EXTERNAL_COUNTER_MODE()                      SET_BIT(T1CON, _T1CON_TMR1CS_POSITION)

#define TIMER1_SYNCHRONOUS_COUNTER_MODE()                    CLEAR_BIT(T1CON, _T1CON_T1SYNC_POSITION)
#define TIMER1_ASYNCHRONOUS_COUNTER_MODE()                   SET_BIT(T1CON, _T1CON_T1SYNC_POSITION)

#define TIMER1_OSCILLATOR_DISABLE()                         CLEAR_BIT(T1CON, _T1CON_T1OSCEN_POSITION)
#define TIMER1_OSCILLATOR_ENABLE()                          SET_BIT(T1CON, _T1CON_T1OSCEN_POSITION)

#define TIMER1_PRESCALER_SELECT(__PRESCALER)                 (T1CONbits.T1CKPS = __PRESCALER)

#define TIMER1_READ_CLOCK_STATUS()                          READ_BIT(T1CON, _T1CON_T1RUN_POSITION)

#define TIMER1_8BIT_READ_WRITE_MODE()                       CLEAR_BIT(T1CON, _T1CON_T1RD16_POSITION)
#define TIMER1_16BIT_READ_WRITE_MODE()                      SET_BIT(T1CON, _T1CON_T1RD16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* TIMER1_HANDLER)(void);

typedef enum{
    TIMER1_PRESCALER_DIV_1 = (uint8)0x00,
    TIMER1_PRESCALER_DIV_2,
    TIMER1_PRESCALER_DIV_4,
    TIMER1_PRESCALER_DIV_8
}TIMER1_PRESCALER;

typedef enum{
    TIMER1_TIMER_MODE = (uint8)0x00,
    TIMER1_COUNTER_MODE
}TIMER1_MODE;

typedef enum{
    TIMER1_SYNCHRONOUS_COUNTER = (uint8)0x00,
    TIMER1_ASYNCHRONOUS_COUNTER
}TIMER1_SYNCHRONIZATION;

typedef enum{
    TIMER1_OSCILLATOR_DISABLE = (uint8)0x00,
    TIMER1_OSCILLATOR_ENABLE
}TIMER1_OSCILLATOR;

typedef enum{
    TIMER1_8BIT_RW_MODE = (uint8)0x00,
    TIMER1_16BIT_RW_MODE
}TIMER1_RW_MODE;

typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))
    TIMER1_HANDLER       TIMER1_INTERRUPT;
    INTERRUPT_PRIORITY           priority;
#endif
    uint16                preloaded_value;
    TIMER1_MODE                      mode;
    TIMER1_SYNCHRONIZATION           sync;
    TIMER1_OSCILLATOR                 osc;
    TIMER1_PRESCALER            prescaler;
    TIMER1_RW_MODE                 rw_reg;
}TIMER1_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType TIMER1_INIT(const TIMER1_CFG *timer1);
Std_ReturnType TIMER1_DEINIT(const TIMER1_CFG *timer1);
Std_ReturnType TIMER1_WRITE_DATA(const TIMER1_CFG *timer1, uint16 data);
Std_ReturnType TIMER1_READ_DATA(const TIMER1_CFG *timer1, uint16 *data);

#endif	/* HAL_TIMER1_H */

