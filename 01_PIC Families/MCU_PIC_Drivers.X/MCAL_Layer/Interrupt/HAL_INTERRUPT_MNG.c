/* 
 * File:   HAL_INTERRUPT_MNG.c
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:03 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_INTERRUPT_MNG.h"

/******************* Section 1 :  Variables Definitions *******************/

static volatile uint8 RB4_ISR_FLAG = 0x01;
static volatile uint8 RB5_ISR_FLAG = 0x01;
static volatile uint8 RB6_ISR_FLAG = 0x01;
static volatile uint8 RB7_ISR_FLAG = 0x01;

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

void __interrupt() INTERRUPT_MANAGER_HIGH_PRIORITY(void){
    if((INTCONbits.INT0IF == INTERRUPT_OCCUR) && (INTCONbits.INT0IE == INTERRUPT_ENABLE)){
        INT0_ISR();
    }
    else{/* Nothing */}
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
    /* ================== EUSART_TX_Interrupt Service Routine ================== */
    if((PIR1bits.TXIF == INTERRUPT_OCCUR) && (PIE1bits.TXIE == INTERRUPT_ENABLE)){
        EUSART_TX_ISR();
    }
    else{/* Nothing */}
    /* ================== EUSART_RX_Interrupt Service Routine ================== */
    if((PIR1bits.RCIF == INTERRUPT_OCCUR) && (PIE1bits.RCIE == INTERRUPT_ENABLE)){
        EUSART_RX_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE))
    /* ================== CCP2_Interrupt Service Routine ================== */
    if((PIR2bits.CCP2IF == INTERRUPT_OCCUR) && (PIE2bits.CCP2IE == INTERRUPT_ENABLE)){
        CCP2_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
    if((PIR1bits.ADIF == INTERRUPT_OCCUR) && (PIE1bits.ADIE == INTERRUPT_ENABLE)){
        ADC_ISR();
    }
    else{/* Nothing */}
#endif    
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
    /* ================== Timer0_Interrupt Service Routine ================== */
    if((INTCONbits.TMR0IF == INTERRUPT_OCCUR) && (INTCONbits.TMR0IE == INTERRUPT_ENABLE)){
        TMR0_ISR();
    }
    else{/* Nothing */}
#endif
    if((INTCON3bits.INT2F == INTERRUPT_OCCUR) && (INTCON3bits.INT2IE == INTERRUPT_ENABLE)){
        INT2_ISR();
    }
    else{/* Nothing */}
}

void __interrupt(low_priority) INTERRUPT_MANAGER_LOW_PRIORITY(void){
    if((INTCON3bits.INT1F == INTERRUPT_OCCUR) && (INTCON3bits.INT1IE == INTERRUPT_ENABLE)){
        INT1_ISR();
    }
    else{/* Nothing */}
    
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
    /* ================== SPI_Interrupt Service Routine ================== */
    if((PIR1bits.SSPIF == INTERRUPT_OCCUR) && (PIE1bits.SSPIE == INTERRUPT_ENABLE)){
        SPI_ISR();
    }
    else{/* Nothing */}
#endif

#if ((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
    /* ================== CCP2_Interrupt Service Routine ================== */
    if((PIR2bits.CCP2IF == INTERRUPT_OCCUR) && (PIE2bits.CCP2IE == INTERRUPT_ENABLE)){
        CCP2_ISR();
    }
    else{/* Nothing */}
#endif
    
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))
    /* ================== Timer1_Interrupt Service Routine ================== */
    if((PIR1bits.TMR1IF == INTERRUPT_OCCUR) && (PIE1bits.TMR1IE == INTERRUPT_ENABLE)){
        TMR1_ISR();
    }
    else{/* Nothing */}
#endif
    
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))
    /* ================== Timer2_Interrupt Service Routine ================== */
    if((PIR1bits.TMR2IF == INTERRUPT_OCCUR) && (PIE1bits.TMR2IE == INTERRUPT_ENABLE)){
        TMR2_ISR();
    }
    else{/* Nothing */}
#endif

#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
    /* ================== Timer3_Interrupt Service Routine ================== */
    if((PIR2bits.TMR3IF == INTERRUPT_OCCUR) && (PIE2bits.TMR3IE == INTERRUPT_ENABLE)){
        TMR3_ISR();
    }
    else{/* Nothing */}
#endif
    
    /* ================== PORTB Interrupt on Change each interrupt must have 2 ISR from high to low & from low to high ========================*/
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       &&(IOCBbits.IOCB4 == INTERRUPT_ENABLE) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_ISR_FLAG == 0x01)){
        RB4_ISR(CHANGE_HIGH);
        RB4_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB4 == INTERRUPT_ENABLE) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_ISR_FLAG == 0x00)){
        RB4_ISR(CHANGE_LOW);
        RB4_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB5 == INTERRUPT_ENABLE) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_ISR_FLAG == 0x01)){
        RB5_ISR(CHANGE_HIGH);
        RB5_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB5 == INTERRUPT_ENABLE) && (PORTBbits.RB5 == GPIO_LOW) && (RB5_ISR_FLAG == 0x00)){
        RB5_ISR(CHANGE_LOW);
        RB5_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE)
       && (IOCBbits.IOCB6 == INTERRUPT_ENABLE) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_ISR_FLAG == 0x01)){
        RB6_ISR(CHANGE_HIGH);
        RB6_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB6 == INTERRUPT_ENABLE) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_ISR_FLAG == 0x00)){
        RB6_ISR(CHANGE_LOW);
        RB6_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB7 == INTERRUPT_ENABLE) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_ISR_FLAG == 0x01)){
        RB7_ISR(CHANGE_HIGH);
        RB7_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB7 == INTERRUPT_ENABLE) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_ISR_FLAG == 0x00)){
        RB7_ISR(CHANGE_LOW);
        RB7_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
}

#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))

void __interrupt() INTERRUPT_MANAGER(void){
    /* ================== INT0_Interrupt Service Routine ================== */
    if((INTCONbits.INT0IF == INTERRUPT_OCCUR) && (INTCONbits.INT0IE == INTERRUPT_ENABLE)){
        INT0_ISR();
    }
    else{/* Nothing */}
#if ((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE))
    /* ================== CCP1_Interrupt Service Routine ================== */
    if((PIR1bits.CCP1IF == INTERRUPT_OCCUR) && (PIE1bits.CCP1IE == INTERRUPT_ENABLE)){
        CCP1_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))
    /* ================== EUSART_TX_Interrupt Service Routine ================== */
    if((PIR1bits.TXIF == INTERRUPT_OCCUR) && (PIE1bits.TXIE == INTERRUPT_ENABLE)){
        EUSART_TX_ISR();
    }
    else{/* Nothing */}
    /* ================== EUSART_RX_Interrupt Service Routine ================== */
    if((PIR1bits.RCIF == INTERRUPT_OCCUR) && (PIE1bits.RCIE == INTERRUPT_ENABLE)){
        EUSART_RX_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
    /* ================== ADC_Interrupt Service Routine ================== */
    if((PIR1bits.ADIF == INTERRUPT_OCCUR) && (PIE1bits.ADIE == INTERRUPT_ENABLE)){
        ADC_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
    /* ================== SPI_Interrupt Service Routine ================== */
    if((PIR1bits.SSPIF == INTERRUPT_OCCUR) && (PIE1bits.SSPIE == INTERRUPT_ENABLE)){
        SPI_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))
    /* ================== CCP2_Interrupt Service Routine ================== */
    if((PIR2bits.CCP2IF == INTERRUPT_OCCUR) && (PIE2bits.CCP2IE == INTERRUPT_ENABLE)){
        CCP2_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))
    /* ================== Timer0_Interrupt Service Routine ================== */
    if((INTCONbits.TMR0IF == INTERRUPT_OCCUR) && (INTCONbits.TMR0IE == INTERRUPT_ENABLE)){
        TMR0_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))
    /* ================== Timer1_Interrupt Service Routine ================== */
    if((PIR1bits.TMR1IF == INTERRUPT_OCCUR) && (PIE1bits.TMR1IE == INTERRUPT_ENABLE)){
        TMR1_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))
    /* ================== Timer2_Interrupt Service Routine ================== */
    if((PIR1bits.TMR2IF == INTERRUPT_OCCUR) && (PIE1bits.TMR2IE == INTERRUPT_ENABLE)){
        TMR2_ISR();
    }
    else{/* Nothing */}
#endif
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))
    /* ================== Timer3_Interrupt Service Routine ================== */
    if((PIR2bits.TMR3IF == INTERRUPT_OCCUR) && (PIE2bits.TMR3IE == INTERRUPT_ENABLE)){
        TMR3_ISR();
    }
    else{/* Nothing */}
#endif
    /* ================== INT1_Interrupt Service Routine ================== */
    if((INTCON3bits.INT1F == INTERRUPT_OCCUR) && (INTCON3bits.INT1IE == INTERRUPT_ENABLE)){
        INT1_ISR();
    }
    else{/* Nothing */}
    /* ================== INT2_Interrupt Service Routine ================== */
    if((INTCON3bits.INT2F == INTERRUPT_OCCUR) && (INTCON3bits.INT2IE == INTERRUPT_ENABLE)){
        INT2_ISR();
    }
    else{/* Nothing */}
    
    /* ================== PORTB Interrupt on Change each interrupt must have 2 ISR from high to low & from low to high ========================*/
    /* ================== RBX _Interrupt Service Routine ================== */
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       &&(IOCBbits.IOCB4 == INTERRUPT_ENABLE) && (PORTBbits.RB4 == GPIO_HIGH) && (RB4_ISR_FLAG == 0x01)){
        RB4_ISR(CHANGE_HIGH);
        RB4_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB4 == INTERRUPT_ENABLE) && (PORTBbits.RB4 == GPIO_LOW) && (RB4_ISR_FLAG == 0x00)){
        RB4_ISR(CHANGE_LOW);
        RB4_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB5 == INTERRUPT_ENABLE) && (PORTBbits.RB5 == GPIO_HIGH) && (RB5_ISR_FLAG == 0x01)){
        RB5_ISR(CHANGE_HIGH);
        RB5_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB5 == INTERRUPT_ENABLE) && (PORTBbits.RB5 == GPIO_LOW) && (RB5_ISR_FLAG == 0x00)){
        RB5_ISR(CHANGE_LOW);
        RB5_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE)
       && (IOCBbits.IOCB6 == INTERRUPT_ENABLE) && (PORTBbits.RB6 == GPIO_HIGH) && (RB6_ISR_FLAG == 0x01)){
        RB6_ISR(CHANGE_HIGH);
        RB6_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB6 == INTERRUPT_ENABLE) && (PORTBbits.RB6 == GPIO_LOW) && (RB6_ISR_FLAG == 0x00)){
        RB6_ISR(CHANGE_LOW);
        RB6_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB7 == INTERRUPT_ENABLE) && (PORTBbits.RB7 == GPIO_HIGH) && (RB7_ISR_FLAG == 0x01)){
        RB7_ISR(CHANGE_HIGH);
        RB7_ISR_FLAG = 0x00;
    }
    else{/* Nothing */}
    
    if((INTCONbits.RBIF == INTERRUPT_OCCUR) && (INTCONbits.RBIE == INTERRUPT_ENABLE) 
       && (IOCBbits.IOCB7 == INTERRUPT_ENABLE) && (PORTBbits.RB7 == GPIO_LOW) && (RB7_ISR_FLAG == 0x00)){
        RB7_ISR(CHANGE_LOW);
        RB7_ISR_FLAG = 0x01;
    }
    else{/* Nothing */}
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/