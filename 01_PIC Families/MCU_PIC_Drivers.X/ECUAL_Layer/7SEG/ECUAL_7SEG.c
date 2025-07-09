/* 
 * File:   ECUAL_7SEG.c
 * Author: mohammedel-ahmady
 *
 * Created on July 9, 2025, 5:39 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_7SEG.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((GPIO_SEGMENT_CFG_ENABLE) == (GPIO_SEGMENT_CFG))

Std_ReturnType GPIO_SEGMENT_INIT(const GPIO_SEGMENT *seg){
    Std_ReturnType Retval = E_OK;
    if(NULL == seg){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < SEGMENT_PINS; i++){
            Retval = GPIO_PIN_INIT(&(seg->pins[i]));
        }
    }
    return Retval;
}

#endif 

#if ((GPIO_SEGMENT_CFG_ENABLE) == (GPIO_SEGMENT_CFG))

Std_ReturnType GPIO_SEGMENT_READ_NUMBER(const GPIO_SEGMENT *seg, uint8 *number){
    Std_ReturnType Retval = E_OK;
    if(NULL == seg || NULL == number){
        Retval = E_NOT_OK;
    }
    else{
        *number = 0x00;
        GPIO_LOGIC logic;
        for(uint8 i = 0; i < SEGMENT_PINS; i++){
            Retval = GPIO_PIN_READ_LOGIC(&(seg->pins[i]), &logic);
            *number |= (uint8)(logic << i);
        }
        if(*number >= MAX_NUMBER){
                Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#endif

#if ((GPIO_SEGMENT_CFG_ENABLE) == (GPIO_SEGMENT_CFG))

Std_ReturnType GPIO_SEGMENT_WRITE_NUMBER(const GPIO_SEGMENT *seg, uint8 number){
    Std_ReturnType Retval = E_OK;
    if(NULL == seg || number >= MAX_NUMBER){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < SEGMENT_PINS; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(seg->pins[i]), (GPIO_LOGIC)READ_BIT(number, i));
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/