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

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/


/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

void ECUAL_LAYER_INIT(void);

#endif	/* ECUAL_INIT_H */

