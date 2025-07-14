/* 
 * File:   main.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 7:59 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef MAIN_H
#define	MAIN_H

/******************* Section 1 : Includes *******************/

#include "../ECUAL_Layer/ECUAL_INIT.h"

/******************* Section 2 : Macros Declarations *******************/

#define F_CPU 4000000UL

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

extern GPIO_Led led1;
extern GPIO_Keypad keypad1;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

void Application_Init(void);


#endif	/* MAIN_H */

