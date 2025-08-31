/* 
 * File:   hal_timer3.h
 * Author: mohammedel-ahmady
 *
 * Created on August 31, 2025, 9:05 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER3_H
#define	HAL_TIMER3_H

/******************* Section 1 : Includes *******************/

#include "../../mcu_cfg.h"
#include "../../GPIO/hal_gpio.h"
#include "../../INTERRUPT/hal_int_interrupt.h"
#include "../Timer1/hal_timer1.h"
#include "hal_timer3_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define timer3_module_disable()                         clear_bit(T3CON, _T3CON_TMR3ON_POSITION)
#define timer3_module_enable()                          set_bit(T3CON, _T3CON_TMR3ON_POSITION)

#define timer3_internal_osc_timer_mode()                clear_bit(T3CON,_T3CON_TMR3CS_POSITION )
#define timer3_internal_osc_counter_mode()              set_bit(T3CON,_T3CON_TMR3CS_POSITION )

#define timer3_synchronous_counter_mode()               clear_bit(T3CON, _T3CON_T3SYNC_POSITION)
#define timer3_asynchronous_counter_mode()              set_bit(T3CON, _T3CON_T3SYNC_POSITION)

#define timer3_select_prescaler(__PRESCALER)            (T3CONbits.T3CKPS = __PRESCALER)

#define timer3_read_write_8bit_mode()                   clear_bit(T3CON, _T3CON_RD16_POSITION)
#define timer3_read_write_16bit_mode()                  set_bit(T3CON, _T3CON_RD16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* timer3_handler)(void);

typedef enum{
    timer3_prescaler_div_1 = (uint8)0x00,
    timer3_prescaler_div_2,
    timer3_prescaler_div_4,
    timer3_prescaler_div_8
}timer3_prescaler_select;

typedef enum{
    timer3_timer_mode = (uint8)0x00,
    timer3_counter_mode
}timer3_mode;

typedef enum{
    timer3_counter_synchronous_mode = (uint8)0x00,
    timer3_counter_asynchronous_mode
}timer3_synchronization;

typedef enum{
    timer3_rw_8bit_mode = (uint8)0x00,
    timer3_rw_16bit_mode
}timer3_rw_mode;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_timer3))
    timer3_handler          timer3_interrupt;
    interrupt_priority              priority;
#endif
    uint16                   preloaded_value;
    timer3_prescaler_select        prescaler;
    timer3_mode                         mode;
    timer3_synchronization              sync;
    timer3_rw_mode                   rw_mode;
    timer1_oscillator                    osc;
}timer3_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType timer3_init(const timer3_cfg *timer3);
Std_ReturnType timer3_deinit(const timer3_cfg *timer3);
Std_ReturnType timer3_write_data(const timer3_cfg *timer3, uint16 data);
Std_ReturnType timer3_read_data(const timer3_cfg *timer3, uint16 *data);

#endif	/* HAL_TIMER3_H */

