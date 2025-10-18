/* 
 * File:   interrupts.h
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "../Platform.h"
#include <xc.h>

/******************* Section 1 : Callback Type *******************/
typedef void (*ISR_Callback_t)(void);

/******************* Section 2 : Function Prototypes *******************/

/**
 * @brief Register callback for MSSP (I2C / SPI) interrupt.
 */
void INTERRUPT_SetMSSPHandler(ISR_Callback_t callback);

/**
 * @brief Register callback for Bus Collision interrupt.
 */
void INTERRUPT_SetBusCollisionHandler(ISR_Callback_t callback);

/**
 * @brief Initialize and enable global & peripheral interrupts.
 */
void INTERRUPT_Init(void);

/**
 * @brief Global interrupt service routine.
 * Automatically calls registered callbacks.
 */
void __interrupt() INTERRUPT_Handler(void);

#endif /* INTERRUPTS_H */