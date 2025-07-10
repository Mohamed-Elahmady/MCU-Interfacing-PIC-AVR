/* 
 * File:   ecual_7seg.h
 * Author: mohammedel-ahmady
 *
 * Created on July 10, 2025, 6:56 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef ECUAL_7SEG_H
#define	ECUAL_7SEG_H

/******************* Section 1 : Includes *******************/

#include "../../MCAL/GPIO/hal_gpio.h"
#include "ecual_7seg_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define segment_pin0            (uint8)0x00
#define segment_pin1            (uint8)0x01
#define segment_pin2            (uint8)0x02
#define segment_pin3            (uint8)0x03

#define segment_pins            (uint8)0x04

#define seg_max_number          (uint8)0x0A

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef enum{
    segment_common_cathode      = (uint8)0x00,
    segment_common_anode      = (uint8)0x01
}segment_con;

typedef struct{
    gpio_pin_cfg pins[segment_pins];
    segment_con          connection;
}gpio_segment;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_segment_init(const gpio_segment *seg);
Std_ReturnType gpio_segment_read_number(const gpio_segment *seg, uint8 *number);
Std_ReturnType gpio_segment_write_number(const gpio_segment *seg, uint8 number);

#endif	/* ECUAL_7SEG_H */

