/* 
 * File:   HAL_TIMER0.h
 * Author: mohammedel-ahmady
 *
 * Created on August 18, 2025, 7:16 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_TIMER0_CFG.h"
#include "../../GPIO/HAL_GPIO.h"
#include "../../Interrupt/HAL_INT_INTERRUPT.h"
#include "../../mcal_std_types.h"
#include "../../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define TIMER0_PRESCALER_DISABLE()                          SET_BIT(T0CON, _T0CON_PSA_POSITION)
#define TIMER0_PRESCALER_ENABLE()                           CLEAR_BIT(T0CON, _T0CON_PSA_POSITION)

#define TIMER0_COUNTER_MODE_RISING_EDGE()                   CLEAR_BIT(T0CON, _T0CON_T0SE_POSITION)
#define TIMER0_COUNTER_MODE_FALLING_EDGE()                  SET_BIT(T0CON, _T0CON_T0SE_POSITION)

#define TIMER0_INTERNAL_OSCILLATOR_TIMER_MODE()             CLEAR_BIT(T0CON, _T0CON_T0CS_POSITION)
#define TIMER0_EXTERNAL_OSCILLATOR_COUNTER_MODE()           SET_BIT(T0CON, _T0CON_T0CS_POSITION)

#define TIMER0_RESOLUTION_16BIT_MODE()                      CLEAR_BIT(T0CON, _T0CON_T08BIT_POSITION)
#define TIMER0_RESOLUTION_8BIT_MODE()                       SET_BIT(T0CON, _T0CON_T08BIT_POSITION)

#define TIMER0_MODULE_DISABLE()                             CLEAR_BIT(T0CON, _T0CON_TMR0ON_POSITION)
#define TIMER0_MODULE_ENABLE()                              SET_BIT(T0CON, _T0CON_TMR0ON_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* TIMER0_HANDLER)(void);

typedef enum{
    TIMER0_PRESCALER_DIV_2 = (uint8) 0x00,
    TIMER0_PRESCALER_DIV_4,
    TIMER0_PRESCALER_DIV_8,
    TIMER0_PRESCALER_DIV_16,
    TIMER0_PRESCALER_DIV_32,
    TIMER0_PRESCALER_DIV_64,
    TIMER0_PRESCALER_DIV_128,
    TIMER0_PRESCALAER_DIV_256
}TIMER0_PRESCALER_SELECT;

typedef enum{
    TIMER0_PRESCALER_CFG_DISABLE = (uint8)0x00,
    TIMER0_PRESCALER_CFG_ENABLE
}TIMER0_PRESCALER_CFG;

typedef enum{
    TIMER0_FALLING_EDGE = (uint8) 0x00,
    TIMER0_RISING_EDGE
}TIMER0_COUNTER_EDGE;

typedef enum{
    TIMER0_TIMER_MODE = (uint8)0x00,
    TIMER0_COUNTER_MODE
}TIMER0_MODE;

typedef enum{
    TIMER0_16BIT_RESOLUTION = (uint8) 0x00,
    TIMER0_8BIT_RESOLUTION
}TIMER0_RESOLUTION;

typedef struct{
#if((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
    TIMER0_HANDLER   TIMER0_INTERRUPT;
    INTERRUPT_PRIORITY       priority;
#endif
    uint16       TIMER0_PRELOAD_VALUE;
    TIMER0_PRESCALER_SELECT pre_value;
    TIMER0_PRESCALER_CFG    prescalar;
    TIMER0_RESOLUTION      resolution;
    TIMER0_MODE                  mode;
    TIMER0_COUNTER_EDGE          edge;
}TIMER0_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType TIMER0_INIT(const TIMER0_CFG *timer0);
Std_ReturnType TIMER0_DEINIT(const TIMER0_CFG *timer0);
Std_ReturnType TIMER0_WRITE_DATA(const TIMER0_CFG *timer0, uint16 data);
Std_ReturnType TIMER0_READ_DATA(const TIMER0_CFG *timer0, uint16 *data);


#endif	/* HAL_TIMER0_H */

