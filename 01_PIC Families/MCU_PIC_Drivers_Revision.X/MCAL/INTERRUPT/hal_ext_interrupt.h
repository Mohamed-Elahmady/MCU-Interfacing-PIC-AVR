/* 
 * File:   hal_ext_interrupt.h
 * Author: mohammedel-ahmady
 *
 * Created on July 31, 2025, 6:14 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EXT_INTERRUPT_H
#define	HAL_EXT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "hal_interrupt_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

// FOR INTX INTERRUPTS
// FOR INT0

#define external_interrupt_int0_clear_flag()                        (INTCONbits.INT0IF = (uint8)0x00)

#define external_interrupt_int0_disable()                           (INTCONbits.INT0IE = (uint8)0x00)
#define external_interrupt_int0_enable()                            (INTCONbits.INT0IE = (uint8)0x01)

#define external_interrupt_int0_falling_edge()                      (INTCON2bits.INTEDG0 = (uint8)0x00)
#define external_interrupt_int0_rising_edge()                       (INTCON2bits.INTEDG0 = (uint8)0x01)

// FOR INT1

#define external_interrupt_int1_clear_flag()                        (INTCON3bits.INT1IF = (uint8)0x00)

#define external_interrupt_int1_disable()                           (INTCON3bits.INT1IE = (uint8)0x00)
#define external_interrupt_int1_enable()                            (INTCON3bits.INT1IE = (uint8)0x01)

#define external_interrupt_int1_falling_edge()                      (INTCON2bits.INTEDG1 = (uint8)0x00)
#define external_interrupt_int1_rising_edge()                       (INTCON2bits.INTEDG1 = (uint8)0x01)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define external_interrupt_int1_low_priority()                      (INTCON3bits.INT1IP = (uint8)0x00)
#define external_interrupt_int1_high_priority()                     (INTCON3bits.INT1IP = (uint8)0x01)

#endif

// FOR INT2

#define external_interrupt_int2_clear_flag()                        (INTCON3bits.INT2IF = (uint8)0x00)

#define external_interrupt_int2_disable()                           (INTCON3bits.INT2IE = (uint8)0x00)
#define external_interrupt_int2_enable()                            (INTCON3bits.INT2IE = (uint8)0x01)

#define external_interrupt_int2_falling_edge()                      (INTCON2bits.INTEDG2 = (uint8)0x00)
#define external_interrupt_int2_rising_edge()                       (INTCON2bits.INTEDG2 = (uint8)0x01)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define external_interrupt_int2_low_priority()                      (INTCON3bits.INT2IP = (uint8)0x00)
#define external_interrupt_int2_high_priority()                     (INTCON3bits.INT2IP = (uint8)0x01)

#endif

// FOR RBX INTERRUPTS

#define external_interrupt_rbx_clear_flag()                         (INTCONbits.RBIF = (uint8)0x00)

#define external_interrupt_rbx_disable()                            (INTCONbits.RBIE = (uint8)0x00)
#define external_interrupt_rbx_enable()                             (INTCONbits.RBIE = (uint8)0x01)

#define external_interrupt_rb4_disable()                            (IOCBbits.IOCB4 = (uint8)0x00)
#define external_interrupt_rb4_enable()                             (IOCBbits.IOCB4 = (uint8)0x01)

#define external_interrupt_rb5_disable()                            (IOCBbits.IOCB5 = (uint8)0x00)
#define external_interrupt_rb5_enable()                             (IOCBbits.IOCB5 = (uint8)0x01)

#define external_interrupt_rb6_disable()                            (IOCBbits.IOCB6 = (uint8)0x00)
#define external_interrupt_rb6_enable()                             (IOCBbits.IOCB6 = (uint8)0x01)

#define external_interrupt_rb7_disable()                            (IOCBbits.IOCB7 = (uint8)0x00)
#define external_interrupt_rb7_enable()                             (IOCBbits.IOCB7 = (uint8)0x01)

#if ((interrupt_feature_enable) == (interrupt_priority_levels))

#define external_interrupt_rbx_low_priority()                      (INTCON2bits.RBIP = (uint8)0x00)
#define external_interrupt_rbx_high_priority()                     (INTCON2bits.RBIP = (uint8)0x01)

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* interrupt_handler)(void);

typedef enum{
    interrupt_int0 = (uint8)0x00,
    interrupt_int1,
    interrupt_int2
}intx_source;

typedef enum{
    interrupt_rb4 = (uint8)0x00,
    interrupt_rb5,
    interrupt_rb6,
    interrupt_rb7
}rbx_source;

typedef enum{
    interrupt_falling_edge = (uint8)0x00,
    interrupt_rising_edge
}intx_edge;

typedef enum{
    interrupt_on_change = (uint8)0x00
}rbx_edge;

typedef struct{
    interrupt_handler      intx_isr;
    gpio_pin_cfg                pin;
    intx_source                 src;
    intx_edge                   edg;
    interrupt_priority     priority;
}interrupt_intx;

typedef struct{
    interrupt_handler       rbx_isr_high;
    interrupt_handler        rbx_isr_low;
    gpio_pin_cfg                     pin;
    intx_source                      src;
    intx_edge                        edg;
    interrupt_priority          priority;
}interrupt_rbx;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType external_interrupt_intx_init(const interrupt_intx *inter);
Std_ReturnType external_interrupt_intx_deinit(const interrupt_intx *inter);

Std_ReturnType external_interrupt_rbx_init(const interrupt_rbx *inter);
Std_ReturnType external_interrupt_rbx_deinit(const interrupt_rbx *inter);

#endif	/* HAL_EXT_INTERRUPT_H */

