/* 
 * File:   hal_ccp.h
 * Author: mohammedel-ahmady
 *
 * Created on September 11, 2025, 10:58 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_CCP_H
#define	HAL_CCP_H


/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "hal_ccp_cfg.h"
#include "../GPIO/hal_gpio.h"
#include "../INTERRUPT/hal_int_interrupt.h"

/******************* Section 2 : Macros Declarations *******************/

#define ccp_pwm_timer2_prescaler_1                              (uint8)0x01
#define ccp_pwm_timer2_prescaler_4                              (uint8)0x04
#define ccp_pwm_timer2_prescaler_16                             (uint8)0x10

#define ccp_pwm_timer2_prescaler_1                              (uint8)0x01
#define ccp_pwm_timer2_prescaler_2                              (uint8)0x02
#define ccp_pwm_timer2_prescaler_3                              (uint8)0x03
#define ccp_pwm_timer2_prescaler_4                              (uint8)0x04
#define ccp_pwm_timer2_prescaler_5                              (uint8)0x05
#define ccp_pwm_timer2_prescaler_6                              (uint8)0x06
#define ccp_pwm_timer2_prescaler_7                              (uint8)0x07
#define ccp_pwm_timer2_prescaler_8                              (uint8)0x08
#define ccp_pwm_timer2_prescaler_9                              (uint8)0x09
#define ccp_pwm_timer2_prescaler_10                             (uint8)0x0A
#define ccp_pwm_timer2_prescaler_11                             (uint8)0x0B
#define ccp_pwm_timer2_prescaler_12                             (uint8)0x0C
#define ccp_pwm_timer2_prescaler_13                             (uint8)0x0D
#define ccp_pwm_timer2_prescaler_14                             (uint8)0x0E
#define ccp_pwm_timer2_prescaler_15                             (uint8)0x0F
#define ccp_pwm_timer2_prescaler_16                             (uint8)0x10

/******************* Section 3 : Macros Functions Declarations *******************/

#define ccp1_ccp2_timer1_set_cfg()                                  (T3CON &= ~((1 << _T3CON_T3CCP1_POSITION) | (1 << _T3CON_T3CCP2_POSITION)))
#define ccp1_timer1_ccp2_timer3_set_cfg()                           (T3CON = (T3CON | (1 << _T3CON_T3CCP1_POSITION)) & ~(1 << _T3CON_T3CCP2_POSITION))
#define ccp1_ccp2_timer3_set_cfg()                                  (T3CON = (T3CON & ~(1 << _T3CON_T3CCP1_POSITION)) | (1 << _T3CON_T3CCP2_POSITION))

#define ccp1_set_configurations(__config)                          (CCP1CONbits.CCP1M = __config)
#define ccp2_set_configurations(__config)                          (CCP2CONbits.CCP2M = __config)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* ccp_handler)(void);

typedef enum{
    ccp_source_ccp1 = (uint8)0x00,
    ccp_source_ccp2
}ccp_source;

typedef enum{
    ccp_capture_mode = (uint8)0x00,
    ccp_compare_mode,
    ccp_pwm_mode
}ccp_mode;

typedef enum{
    ccp_cfg_module_disable = (uint8)0x00, // 0000
    ccp_cfg_capture_1_falling_edge = (uint8)0x04, // 0100
    ccp_cfg_capture_1_rising_edge, // 0101
    ccp_cfg_capture_4_rising_edge, // 0110
    ccp_cfg_capture_16_rising_edge, // 0111
    ccp_cfg_compare_clear_logic, // 1000
    ccp_cfg_compare_set_logic, // 1001
    ccp_cfg_compare_toggle_logic = (uint8)0x02, // 0010
    ccp_cfg_compare_gen_interrupt = (uint8)0x0A, // 1010
    ccp_cfg_compare_trigger_special_event, // 1011
    ccp_cfg_pwm_mode // 11xx
}ccp_mode_configurations;

#if ((ccp_cfg_pwm_mode_selected) != (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) != (ccp2_cfg_mode_selected))

typedef enum{
    ccp1_ccp2_timer1 = (uint8)0x00,
    ccp1_timer1_ccp2_timer3,
    ccp1_ccp2_timer3
}ccp_capture_compare_timer;

typedef enum{
    ccp_capture_not_ready = (uint8)0x00,
    ccp_capture_ready
}ccp_capture_status;

typedef enum{
    ccp_compare_not_ready = (uint8)0x00,
    ccp_compare_ready
}ccp_compare_status;

#endif 

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_ccp1) || (interrupt_feature_enable) == (int_interrupt_ccp2))
    ccp_handler             ccp_interrupt;
    interrupt_priority           priority;
#endif
    ccp_source                    ccp_src;
    ccp_mode                     ccp_mode;
    ccp_mode_configurations       ccp_cfg;
    
#if ((ccp_cfg_pwm_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) == (ccp2_cfg_mode_selected))
    uint32                       pwm_freq;
    uint8                pwm_prescaler :2;
    uint8               pwm_postscaler :5;
#endif
#if ((ccp_cfg_pwm_mode_selected) != (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) != (ccp2_cfg_mode_selected))
    ccp_capture_compare_timer   ccp_timer;
#endif
    
}ccp_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType ccp_init(const ccp_cfg *ccp);
Std_ReturnType ccp_deinit(const ccp_cfg *ccp);

#if ((ccp_cfg_capture_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_capture_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_is_capture_ready(const ccp_cfg *ccp, ccp_capture_status *state);
Std_ReturnType ccp_get_capture_value(const ccp_cfg *ccp, uint16 *value);

#endif

#if ((ccp_cfg_compare_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_compare_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_is_compare_completed(const ccp_cfg *ccp, ccp_compare_status *state);
Std_ReturnType ccp_set_compare_value(const ccp_cfg *ccp, uint16 value);

#endif

#if ((ccp_cfg_pwm_mode_selected) == (ccp1_cfg_mode_selected) || (ccp_cfg_pwm_mode_selected) == (ccp2_cfg_mode_selected))

Std_ReturnType ccp_pwm_start(const ccp_cfg *ccp);
Std_ReturnType ccp_pwm_stop(const ccp_cfg *ccp);
Std_ReturnType ccp_set_pwm_duty_cycle(const ccp_cfg *ccp, uint8 duty);

#endif

#endif	/* HAL_CCP_H */

