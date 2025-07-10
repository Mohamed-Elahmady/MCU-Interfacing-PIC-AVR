 /* 
 * File:   ecual_7seg.c
 * Author: mohammedel-ahmady
 *
 * Created on July 10, 2025, 6:56 PM
 */


/******************* Section 0 : Includes *******************/

#include "ecual_7seg.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_segment_cfg_enable) == (gpio_segment_cfg))

Std_ReturnType gpio_segment_init(const gpio_segment *seg){
    Std_ReturnType Retval = E_OK;
    if(NULL== seg){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < segment_pins; i++){
            Retval = gpio_pin_init(&(seg->pins[i]));
        }
    }
    return Retval;
}

Std_ReturnType gpio_segment_read_number(const gpio_segment *seg, uint8 *number){
    Std_ReturnType Retval = E_OK;
    if(NULL== seg || NULL == number){
        Retval = E_NOT_OK;
    }
    else{
        *number = 0;
        gpio_logic logic;
        for(uint8 i = 0; i < segment_pins; i++){
            Retval = gpio_pin_read_logic(&(seg->pins[i]), &logic);
            *number |= (uint8)((logic & 0x01) << i);
        }
        if(*number >= seg_max_number){
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

Std_ReturnType gpio_segment_write_number(const gpio_segment *seg, uint8 number){
    Std_ReturnType Retval = E_OK;
    if(NULL== seg || number >= seg_max_number){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < segment_pins; i++){
            Retval = gpio_pin_write_logic(&(seg->pins[i]), (gpio_logic)((number >> i) & (0x01)));
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/

