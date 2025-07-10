/* 
 * File:   ECUAL_7SEG.h
 * Author: mohammedel-ahmady
 *
 * Created on July 9, 2025, 5:39 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_7SEG_H
#define	ECUAL_7SEG_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL_Layer/GPIO/HAL_GPIO.h"
#include "ECUAL_7SEG_CFG.h"

/******************* Section 2 : Macros Declarations *******************/

#define SEGMENT_PIN0        (uint8)0x00
#define SEGMENT_PIN1        (uint8)0x01
#define SEGMENT_PIN2        (uint8)0x02
#define SEGMENT_PIN3        (uint8)0x03

#define SEGMENT_PINS        (uint8)0x04

#define SEG_MAX_NUMBER      (uint8)0x0A

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    SEGMENT_COMMON_CATHODE  = (uint8)0x00,
    SEGMENT_COMMON_ANODE    = (uint8)0x01
}SEGMENT_CON;

typedef struct{
    GPIO_PIN_CFG pins[SEGMENT_PINS];
    SEGMENT_CON          connection;
}GPIO_SEGMENT;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_SEGMENT_INIT(const GPIO_SEGMENT *seg);
Std_ReturnType GPIO_SEGMENT_READ_NUMBER(const GPIO_SEGMENT *seg, uint8 *number);
Std_ReturnType GPIO_SEGMENT_WRITE_NUMBER(const GPIO_SEGMENT *seg, uint8 number);

#endif	/* ECUAL_7SEG_H */

