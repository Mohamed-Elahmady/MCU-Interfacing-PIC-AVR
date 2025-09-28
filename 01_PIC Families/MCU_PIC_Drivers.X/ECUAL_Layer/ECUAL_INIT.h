/* 
 * File:   ECUAL_INIT.h
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 8:15 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_INIT_H
#define	ECUAL_INIT_H

/******************* Section 1 : Includes *******************/

#include "LED/ECUAL_LED.h"
#include "BTN/ECUAL_BTN.h"
#include "Relay/ECUAL_RELAY.h"
#include "DC_Motor/ECUAL_DC_MOTOR.h"
#include "7SEG/ECUAL_7SEG.h"
#include "Keypad/ECUAL_KEYPAD.h"
#include "CHR_Lcd/GPIO_CHR_LCD.h"

#include "../MCAL_Layer/Interrupt/HAL_EXT_INTERRUPT.h"
#include "../MCAL_Layer/Interrupt/HAL_INT_INTERRUPT.h"

#include "../MCAL_Layer/EEPROM/HAL_EEPROM.h"

#include "../MCAL_Layer/ADC/HAL_ADC.h"

#include "../MCAL_Layer/Timers/Timer0/HAL_TIMER0.h"
#include "../MCAL_Layer/Timers/Timer1/HAL_TIMER1.h"
#include "../MCAL_Layer/Timers/Timer2/HAL_TIMER2.h"
#include "../MCAL_Layer/Timers/Timer3/HAL_TIMER3.h"

#include "../MCAL_Layer/CCP/HAL_CCP.h"

#include "../MCAL_Layer/EUSART/HAL_EUSART.h"
#include "../MCAL_Layer/SPI/HAL_SPI.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/


/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

void ECUAL_LAYER_INIT(void);

#endif	/* ECUAL_INIT_H */

