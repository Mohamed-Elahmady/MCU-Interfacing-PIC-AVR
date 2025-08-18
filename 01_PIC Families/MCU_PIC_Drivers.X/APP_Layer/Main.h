/* 
 * File:   Main.h
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:22 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef MAIN_H
#define	MAIN_H

/******************* Section 1 : Includes *******************/

#include "../ECUAL_Layer/ECUAL_INIT.h" 

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

extern GPIO_LED       led1;
extern GPIO_BTN       btn1;
extern GPIO_RELAY   relay1;
extern GPIO_SEGMENT   seg1;
extern DC_MOTOR     motor1;
extern DC_MOTOR     motor2;
extern GPIO_KEYPAD keypad1;
extern CHR_LCD_4BIT lcd1;
extern CHR_LCD_8BIT lcd2;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

void application_init(void);


#endif	/* MAIN_H */

