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
//typedef union{
//    struct{
//        
//        uint8 sspm               :4;
//        uint8 ckp                :1;
//        uint8 sspen              :1;
//        uint8 sspov              :1;
//        uint8 wcol                :1;
//    };
//    uint8  latc_APORT;
//}sspcon_t;
//
//typedef union{
//    struct{
//        uint8 latc_A0            :1;
//        uint8 latc_A1            :1;
//        uint8 latc_A2            :1;
//        uint8 latc_A3            :1;
//        uint8 latc_A4            :1;
//        uint8 latc_A5            :1;
//        uint8 latc_A6            :1;
//        uint8 latc_A7            :1;
//    };
//    uint8  latc_APORT;
//}self_latc;
//
//#define self_latc_D               (*((volatile self_latc *)(0xF8B)))
//#define self_latc_A               ((volatile self_latc *)(0xF8B))
//
//int main() {
//    HWREG8(TRISC_Mohammed) = 0x00;
//    while(1){ 
//        self_latc_D.latc_APORT = 0x01;
//        __delay_ms(200);
//        self_latc_D.latc_APORT = 0xAA;
//        __delay_ms(200);
//        self_latc_A->latc_APORT= 0x55;
//        __delay_ms(200);
//        self_latc_A->latc_APORT= 0x00;
//        __delay_ms(200);
//        self_latc_A->latc_A6 = 1;
//        __delay_ms(200);
//    }
//
//    return (EXIT_SUCCESS);
//}