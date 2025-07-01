///* 
// * File:   Main.c
// * Author: Mohammed.El-Ahmady
// *
// * Created on June 21, 2025, 4:00 AM
// */
//
//#include "Main.h"
//
//#define _XTAL_FREQ                       16000000
//
//#define HWREG8(__X)                      (*((volatile uint8 *)(__X)))
//#define HWREG16(__X)                     (*((volatile uint16 *)(__X)))
//#define HWREG32(__X)                     (*((volatile uint32 *)(__X)))
//#define HWREG64(__X)                     (*((volatile uint64 *)(__X)))
//
//#define SET_BIT(REG, BIT_POS)            (REG |= (uint8)(1 << BIT_POS))
//#define CLEAR_BIT(REG, BIT_POS)          (REG &= ~(uint8)(1 << BIT_POS))
//#define TOGGLE_BIT(REG, BIT_POS)         (REG ^= (uint8)(1 << BIT_POS))
//
//
//#define TRISC_Mohammed           0xF94
//#define LATC_Mohammed            0xF8B
//#define PORTC_Mohammed           0xF82
//
//int main() {
//    HWREG8(TRISC_Mohammed) = 0x00;
//    while(1){
//        HWREG8(LATC_Mohammed) = 0x00;
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) |= ((1 << 0) | (1 << 7)) ;
//        SET_BIT(HWREG8(LATC_Mohammed), 0);
//        SET_BIT(HWREG8(LATC_Mohammed), 7);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) |= ((1 << 1) | (1 << 6)) ;
//        SET_BIT(HWREG8(LATC_Mohammed), 1);
//        SET_BIT(HWREG8(LATC_Mohammed), 6);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) |= ((1 << 2) | (1 << 5)) ;
//        SET_BIT(HWREG8(LATC_Mohammed), 2);
//        SET_BIT(HWREG8(LATC_Mohammed), 5);        
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) |= ((1 << 3) | (1 << 4)) ;
//        SET_BIT(HWREG8(LATC_Mohammed), 3);
//        SET_BIT(HWREG8(LATC_Mohammed), 4);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) &= ~((1 << 3) | (1 << 4)) ;
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 3);
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 4);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) &= ~((1 << 2) | (1 << 5)) ;
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 2);
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 5);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) &= ~((1 << 1) | (1 << 6)) ;
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 1);
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 6);
//        __delay_ms(1000);
////        HWREG8(LATC_Mohammed) &= ~((1 << 0) | (1 << 7)) ;
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 0);
//        CLEAR_BIT(HWREG8(LATC_Mohammed), 7);
//        __delay_ms(1000);
//    }
//
//    return (EXIT_SUCCESS);
//}