/* 
 * File:   ECUAL_KEYPAD_CFG.h
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 6:26 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_KEYPAD_CFG_H
#define	ECUAL_KEYPAD_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define GPIO_KEYPAD_CFG_DISABLE                 0x00
#define GPIO_KEYPAD_CFG_ENABLE                  0x01

#define GPIO_KEYPAD_CFG                         (GPIO_KEYPAD_CFG_ENABLE)

#define KEYPAD_SMALL_CALC                       0x00
#define KEYPAD_PHONE                            0x01
#define KEYPAD_CALCULATOR                       0x02

#define KEYPAD_TYPE                             (KEYPAD_SMALL_CALC)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/


#endif	/* ECUAL_KEYPAD_CFG_H */

