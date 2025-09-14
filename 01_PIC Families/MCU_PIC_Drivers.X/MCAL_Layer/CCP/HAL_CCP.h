/* 
 * File:   HAL_CCP.h
 * Author: mohammedel-ahmady
 *
 * Created on September 3, 2025, 3:22 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_CCP_H
#define	HAL_CCP_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_CCP_CFG.h"
#include "../mcal_std_types.h"
#include "../GPIO/HAL_GPIO.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../Timers/Timer2/HAL_TIMER2.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define CCP_PWM_TIMER2_PRESCALER_1                    (uint8)0x01
#define CCP_PWM_TIMER2_PRESCALER_4                    (uint8)0x04
#define CCP_PWM_TIMER2_PRESCALER_16                   (uint8)0x10

#define CCP_PWM_TIMER2_POSTSCALER_1                   (uint8)0x01
#define CCP_PWM_TIMER2_POSTSCALER_2                   (uint8)0x02
#define CCP_PWM_TIMER2_POSTSCALER_3                   (uint8)0x03
#define CCP_PWM_TIMER2_POSTSCALER_4                   (uint8)0x04
#define CCP_PWM_TIMER2_POSTSCALER_5                   (uint8)0x05
#define CCP_PWM_TIMER2_POSTSCALER_6                   (uint8)0x06
#define CCP_PWM_TIMER2_POSTSCALER_7                   (uint8)0x07
#define CCP_PWM_TIMER2_POSTSCALER_8                   (uint8)0x08
#define CCP_PWM_TIMER2_POSTSCALER_9                   (uint8)0x09
#define CCP_PWM_TIMER2_POSTSCALER_10                  (uint8)0x0A
#define CCP_PWM_TIMER2_POSTSCALER_11                  (uint8)0x0B
#define CCP_PWM_TIMER2_POSTSCALER_12                  (uint8)0x0C
#define CCP_PWM_TIMER2_POSTSCALER_13                  (uint8)0x0D
#define CCP_PWM_TIMER2_POSTSCALER_14                  (uint8)0x0E
#define CCP_PWM_TIMER2_POSTSCALER_15                  (uint8)0x0F
#define CCP_PWM_TIMER2_POSTSCALER_16                  (uint8)0x10

/******************* Section 3 : Macros Functions Declarations *******************/

#define CCP_TIMER1_CCP1_CCP2()                                          (T3CON &= ~(uint8)((1 << _T3CON_T3CCP1_POSITION) | (1 << _T3CON_T3CCP2_POSITION)))
#define CCP_TIMER1_CCP1_TIMER3_CCP2()                                   (T3CON = (T3CON | (1 << _T3CON_T3CCP1_POSITION)) & ~(1 << _T3CON_T3CCP2_POSITION))
#define CCP_TIMER3_CCP1_CCP2()                                          (T3CON = (T3CON & ~(uint8)(1 << _T3CON_T3CCP1_POSITION)) | (1 << _T3CON_T3CCP2_POSITION))

#define CCP1_SET_MODE_CONFIGURATION(__CONFIG)                           (CCP1CONbits.CCP1M = __CONFIG)
#define CCP2_SET_MODE_CONFIGURATION(__CONFIG)                           (CCP2CONbits.CCP2M = __CONFIG)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* CCP_HANDLER)(void);

typedef enum{
    CCP_CAPTURE_MODE = (uint8) 0x00,
    CCP_COMPARE_MODE,
    CCP_PWM_MODE
}CCP_MODE;

typedef enum{
    CCP1_SOURCE = (uint8)0x00,
    CCP2_SOURCE
}CCP_SOURCE;

typedef enum{
    CCP_CFG_MODULE_DISABLE                    = (uint8)0x00,
    CCP_CFG_CAPTURE_MODE_1_FALLING_EDGE       = (uint8)0x04,
    CCP_CFG_CAPTURE_MODE_1_RISING_EDGE,
    CCP_CFG_CAPTURE_MODE_4_RISING_EDGE,
    CCP_CFG_CAPTURE_MODE_16_RISING_EDGE,
    CCP_CFG_COMPARE_MODE_CLEAR_LOGIC          = (uint8)0x08,
    CCP_CFG_COMPARE_MODE_SET_LOGIC,
    CCP_CFG_COMPARE_MODE_TOGGLE_LOGIC         = (uint8)0x02,
    CCP_CFG_COMPARE_MODE_GEN_SW_INTERRUPT     = (uint8)0x0A,
    CCP_CFG_COMPARE_MODE_GEN_EVENT,
    CCP_CFG_PWM
}CCP_MODE_CONFIGURATION;

#if ((CCP_CFG_PWM_MODE_SELECTED) != (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) != (CCP2_CFG_SELECTED_MODE))

typedef enum{
    CCP1_CCP2_TIMER1 = (uint8)0x00,
    CCP1_TIMER1_CCP2_TIMER3 = (uint8)0x01,
    CCP1_CCP2_TIMER3 = (uint8)0x02
}CCP_CAPTURE_COMPARE_TIMER;

#endif

#if ((CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE)  || (CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))

typedef enum{
    CCP_CAPTURE_NOT_READY = (uint8)0x00,
    CCP_CAPTURE_READY
}CCP_CAPTURE_STATUS;

#endif

#if ((CCP_CFG_COMPARE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_COMPARE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))

typedef enum{
    CCP_COMPARE_NOT_READY = (uint8)0x00,
    CCP_COMPARE_READY
}CCP_COMPARE_STATUS;

#endif

typedef union{
    struct{
        uint8 CCPR_LOW   ;
        uint8 CCPR_HIGH  ;
    };
    uint16    CCPR_16BIT ;
}CCP_REGISTER_SIZE;

typedef struct {
#if((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE) || (INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
    CCP_HANDLER                ccp_interrupt;
    INTERRUPT_PRIORITY              priority;
#endif
    
    CCP_MODE                        ccp_mode;   
    CCP_MODE_CONFIGURATION           ccp_cfg;
    CCP_SOURCE                       ccp_src;
    
#if ((CCP_CFG_PWM_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))
    uint32                          pwm_freq;
    uint8                   pwm_prescaler :2;
    uint8                   pwm_postscaler :5;
#endif
#if ((CCP_CFG_PWM_MODE_SELECTED) != (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) != (CCP2_CFG_SELECTED_MODE))
    CCP_CAPTURE_COMPARE_TIMER      ccp_timer;
#endif

}CCP_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType CCP_INIT(const CCP_CFG *ccp);
Std_ReturnType CCP_DEINIT(const CCP_CFG *ccp);

#if ((CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_CAPTURE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))
Std_ReturnType CCP_IS_CAPTURE_READY(const CCP_CFG *ccp, CCP_CAPTURE_STATUS *state);
Std_ReturnType CCP_READ_CAPTURE_VALUE(const CCP_CFG *ccp, uint16 *value);
#endif

#if ((CCP_CFG_COMPARE_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_COMPARE_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))
Std_ReturnType CCP_IS_COMPARE_COMPLETED(const CCP_CFG *ccp, CCP_COMPARE_STATUS *state);
Std_ReturnType CCP_WRITE_COMPARE_SET_VALUE(const CCP_CFG *ccp, uint16 value);
#endif

#if ((CCP_CFG_PWM_MODE_SELECTED) == (CCP1_CFG_SELECTED_MODE) || (CCP_CFG_PWM_MODE_SELECTED) == (CCP2_CFG_SELECTED_MODE))
Std_ReturnType CCP_START_PWM(const CCP_CFG *ccp);
Std_ReturnType CCP_STOP_PWM(const CCP_CFG *ccp);
Std_ReturnType CCP_SET_DUTY_CYCLE(const CCP_CFG *ccp, uint8 duty);
#endif

#endif	/* HAL_CCP_H */

