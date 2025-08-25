/* 
 * File:   hal_timer1.h
 * Author: mohammedel-ahmady
 *
 * Created on August 24, 2025, 7:19 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER1_H
#define	HAL_TIMER1_H

/******************* Section 1 : Includes *******************/

#include "../../mcu_cfg.h"
#include "hal_timer1_cfg.h"
#include "../../GPIO/hal_gpio.h"
#include "../../INTERRUPT/hal_int_interrupt.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define timer1_module_disable()                             clear_bit(T1CON, _T1CON_TMR1ON_POSITION)
#define timer1_module_enable()                              set_bit(T1CON, _T1CON_TMR1ON_POSITION)

#define timer1_internal_osc_timer_mode()                    clear_bit(T1CON, _T1CON_TMR1CS_POSITION)
// External Oscillator Enable Counter Mode in only Rising Edge
#define timer1_external_osc_counter_mode()                  set_bit(T1CON, _T1CON_TMR1CS_POSITION)

#define timer1_synchronous_clock_counter_mode()             clear_bit(T1CON, _T1CON_T1SYNC_POSITION)
#define timer1_asynchronous_clock_counter_mode()            set_bit(T1CON, _T1CON_T1SYNC_POSITION)

#define timer1_oscillator_timer_mode_disable()              clear_bit(T1CON, _T1CON_T1OSCEN_POSITION)
#define timer1_oscillator_timer_mode_enable()               set_bit(T1CON, _T1CON_T1OSCEN_POSITION)

#define timer1_select_prescaler(__PRESCALER)                (T1CONbits.T1CKPS = __PRESCALER)

#define timer1_oscillator_read_status()                     read_bit(T1CON, _T1CON_T1RUN_POSITION)

#define timer1_read_write_8bit_mode()                       clear_bit(T1CON, _T1CON_RD16_POSITION)
#define timer1_read_write_16bit_mode()                      set_bit(T1CON, _T1CON_RD16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* timer1_handler)(void);

typedef enum{
    timer1_prescaler_div_1 = (uint8)0x00,
    timer1_prescaler_div_2,
    timer1_prescaler_div_4,
    timer1_prescaler_div_8
}timer1_prescaler_select;

typedef enum{
    timer1_timer_mode = (uint8)0x00,
    timer1_counter_mode 
}timer1_mode;

typedef enum{
    timer1_counter_synchronous_mode = (uint8)0x00,
    timer1_counter_asynchronous_mode
}timer1_synchronization;

typedef enum{
    timer1_oscillator_disable = (uint8)0x00,
    timer1_oscillator_enable 
}timer1_oscillator;

typedef enum{
    timer1_8bit_rw_mode = (uint8)0x00,
    timer1_16bit_rw_mode
}timer1_rw_mode;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_timer1))
    timer1_handler   timer1_interrupt;
    interrupt_priority       priority;
#endif
    uint16            preloaded_value;
    timer1_prescaler_select prescaler;
    timer1_mode                  mode;
    timer1_oscillator             osc;
    timer1_synchronization       sync;
    timer1_rw_mode            rw_mode;
}timer1_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType timer1_init(const timer1_cfg *timer1);
Std_ReturnType timer1_deinit(const timer1_cfg *timer1);
Std_ReturnType timer1_write_data(const timer1_cfg *timer1, uint16 data);
Std_ReturnType timer1_read_data(const timer1_cfg *timer1, uint16 *data);

#endif	/* HAL_TIMER1_H */

