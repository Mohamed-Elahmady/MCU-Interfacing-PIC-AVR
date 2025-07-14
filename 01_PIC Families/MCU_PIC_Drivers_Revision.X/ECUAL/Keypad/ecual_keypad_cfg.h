/* 
 * File:   ecual_keypad_cfg.h
 * Author: mohammedel-ahmady
 *
 * Created on July 13, 2025, 1:28 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_KEYPAD_CFG_H
#define	ECUAL_KEYPAD_CFG_H

/******************* Section 1 : Includes *******************/



/******************* Section 2 : Macros Declarations *******************/

#define gpio_keypad_cfg_disable                 0x00
#define gpio_keypad_cfg_enable                  0x01

#define gpio_keypad_cfg                         (gpio_keypad_cfg_enable)

#define keypad_small_calc                       0x00
#define keypad_phone                            0x01
#define keypad_calculator                       0x02

#define keypad_type                             (keypad_small_calc)

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

#endif	/* ECUAL_KEYPAD_CFG_H */

