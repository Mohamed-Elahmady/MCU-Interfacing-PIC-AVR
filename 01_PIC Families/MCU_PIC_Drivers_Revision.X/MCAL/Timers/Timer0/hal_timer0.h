/* 
 * File:   hal_timer0.h
 * Author: mohammedel-ahmady
 *
 * Created on August 19, 2025, 6:27 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/******************* Section 1 : Includes *******************/

#include "../../mcu_cfg.h"
#include "hal_timer0_cfg.h"
#include "../../GPIO/hal_gpio.h"
#include "../../INTERRUPT/hal_int_interrupt.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define timer0_prescaler_disable()                          set_bit(T0CON, _T0CON_PSA_POSITION)
#define timer0_prescaler_enable()                           clear_bit(T0CON, _T0CON_PSA_POSITION)

#define timer0_counter_mode_rising_edge()                   clear_bit(T0CON, _T0CON_T0SE_POSITION)
#define timer0_counter_mode_falling_edge()                  set_bit(T0CON, _T0CON_T0SE_POSITION)

#define timer0_internal_oscillator_timer_mode()             clear_bit(T0CON, _T0CON_T0CS_POSITION)
#define timer0_external_oscillator_counter_mode()           set_bit(T0CON, _T0CON_T0CS_POSITION)

#define timer0_16bit_resolution()                           clear_bit(T0CON, _T0CON_T08BIT_POSITION)
#define timer0_8bit_resolution()                            set_bit(T0CON, _T0CON_T08BIT_POSITION)

#define timer0_module_disable()                             clear_bit(T0CON, _T0CON_TMR0ON_POSITION)
#define timer0_module_enable()                              set_bit(T0CON, _T0CON_TMR0ON_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* timer0_handler)(void);

typedef enum{
    timer0_prescaler_div_2 = (uint8)0x00,
    timer0_prescaler_div_4,
    timer0_prescaler_div_8,
    timer0_prescaler_div_16,
    timer0_prescaler_div_32,
    timer0_prescaler_div_64,
    timer0_prescaler_div_128,
    timer0_prescaler_div_256
}timer0_prescaler_select;

typedef enum{
    timer0_prescaler_cfg_disable = (uint8)0x00,
    timer0_prescaler_cfg_enable
}timer0_prescaler_cfg;

typedef enum{
    timer0_timer_mode = (uint8)0x00,
    timer0_counter_mode
}timer0_mode;

typedef enum{
    timer0_counter_falling_edge = (uint8)0x00,
    timer0_counter_rising_edge
}timer0_counter_edge;

typedef enum{
    timer0_8bit_register_size = (uint8)0x00,
    timer0_16bit_register_size
}timer0_resolution;

typedef struct{
#if((interrupt_feature_enable) == (int_interrupt_timer0))
    timer0_handler           timer0_interrupt;
    interrupt_priority               priority;
#endif
    uint16             timer0_preloaded_value;
    timer0_prescaler_select             value;
    timer0_prescaler_cfg            prescalar;
    timer0_mode                          mode;
    timer0_counter_edge                  edge;
    timer0_resolution              resolution;
}timer0_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType timer0_init(const timer0_cfg *timer0);
Std_ReturnType timer0_deinit(const timer0_cfg *timer0);
Std_ReturnType timer0_write_data(const timer0_cfg *timer0, uint16 data);
Std_ReturnType timer0_read_data(const timer0_cfg *timer0, uint16 *data);



#endif	/* HAL_TIMER0_H */

