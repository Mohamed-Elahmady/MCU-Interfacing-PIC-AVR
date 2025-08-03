/* 
 * File:   hal_interrupt_mng.c
 * Author: mohammedel-ahmady
 *
 * Created on August 3, 2025, 6:17 PM
 */

/******************* Section 0 : Includes *******************/

#include "hal_interrupt_mng.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

ISR(INT0_vect){
    INT0_ISR();
}

ISR(INT1_vect){
    INT1_ISR();
}

ISR(INT2_vect){
    INT2_ISR();
}

/******************* Section 4:  Helper Functions Definitions *******************/

