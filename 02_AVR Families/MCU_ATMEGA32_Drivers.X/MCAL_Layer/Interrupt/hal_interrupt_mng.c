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

#if ((Interrupt_Feature_Enable) == (ADC_Interrupt_Feature))        

ISR(ADC_vect){
    ADC_ISR();
}

#endif

#if ((Interrupt_Feature_Enable) == (Timer0_Interrupt_Feature))

ISR(TIMER0_OVF_vect){
    TMR0_ISR();
}

ISR(TIMER0_COMP_vect){
    CTC_ISR();
}

#endif 

#if ((Interrupt_Feature_Enable) == (Timer1_Interrupt_Feature))

ISR(TIMER1_OVF_vect){
    TMR1_ISR();
}

ISR(TIMER1_COMPA_vect){
    CTC_OCRA_ISR();
}

ISR(TIMER1_COMPB_vect){
    CTC_OCRB_ISR();
}

ISR(TIMER1_CAPT_vect){
    CTC_ICR_ISR();
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

