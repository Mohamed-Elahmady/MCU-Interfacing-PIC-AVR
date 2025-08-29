/* 
 * File:   hal_timer2.h
 * Author: mohammedel-ahmady
 *
 * Created on August 27, 2025, 11:00 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER2_H
#define	HAL_TIMER2_H

/******************* Section 1 : Includes *******************/

#include "hal_timer2_cfg.h"
#include "../../mcu_cfg.h"
#include "../../GPIO/hal_gpio.h"
#include "../../INTERRUPT/hal_int_interrupt.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define timer2_module_disable()                          clear_bit(T2CON, _T2CON_TMR2ON_POSITION)
#define timer2_module_enable()                           set_bit(T2CON, _T2CON_TMR2ON_POSITION)

#define timer2_prescaler_select(__prescaler)             (T2CONbits.T2CKPS = __prescaler)
#define timer2_postscaler_select(__postscaler)           (T2CONbits.T2OUTPS = __postscaler)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* timer2_handler)(void);

typedef enum{
    timer2_prescaler_div_1 = (uint8)0x00,
    timer2_prescaler_div_4,
    timer2_prescaler_div_16
}timer2_prescaler_select;

typedef enum{
    timer2_postscaler_div_1 = (uint8)0x00,
    timer2_postscaler_div_2,
    timer2_postscaler_div_3,
    timer2_postscaler_div_4,
    timer2_postscaler_div_5,
    timer2_postscaler_div_6,
    timer2_postscaler_div_7,
    timer2_postscaler_div_8,
    timer2_postscaler_div_9,
    timer2_postscaler_div_10,
    timer2_postscaler_div_11,
    timer2_postscaler_div_12,
    timer2_postscaler_div_13,
    timer2_postscaler_div_14,
    timer2_postscaler_div_15,
    timer2_postscaler_div_16
}timer2_postscaler_select;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_timer2))
    timer2_handler       timer2_interrupt;
    interrupt_priority           priority;
#endif
    uint8                 preloaded_value;
    timer2_prescaler_select     prescaler;
    timer2_postscaler_select   postscaler;
}timer2_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType timer2_init(const timer2_cfg *timer2);
Std_ReturnType timer2_deinit(const timer2_cfg *timer2);
Std_ReturnType timer2_write_data(const timer2_cfg *timer2, uint8 data);
Std_ReturnType timer2_read_data(const timer2_cfg *timer2, uint8 *data);

#endif	/* HAL_TIMER2_H */

