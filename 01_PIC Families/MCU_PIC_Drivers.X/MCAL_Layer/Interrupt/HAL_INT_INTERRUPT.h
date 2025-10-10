/* 
 * File:   HAL_INT_INTERRUPT.h
 * Author: mohammedel-ahmady
 *
 * Created on July 29, 2025, 5:03 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_INT_INTERRUPT_H
#define	HAL_INT_INTERRUPT_H

/******************* Section 1 : Includes *******************/

#include "HAL_INTERRUPT_CFG.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

// Analog to Digital Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))

// ADC Flag bit
#define INT_INTERRUPT_ADC_CLEAR_FLAG()                        CLEAR_BIT(PIR1, _PIR1_ADIF_POSITION)

// ADC Enable Bit
#define INT_INTERRUPT_ADC_DISABLE()                           CLEAR_BIT(PIE1, _PIE1_ADIE_POSITION)
#define INT_INTERRUPT_ADC_ENABLE()                            SET_BIT(PIE1, _PIE1_ADIE_POSITION)

// ADC Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_ADC_LOW_PRIORITY()                      CLEAR_BIT(IPR1, _IPR1_ADIP_POSITION)
#define INT_INTERRUPT_ADC_HIGH_PRIORITY()                     SET_BIT(IPR1, _IPR1_ADIP_POSITION)

#endif

#endif

// Timer0 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER0_INTERRUPT_FEATURE))

// Timer0 Flag bit
#define INT_INTERRUPT_TIMER0_CLEAR_FLAG()                     CLEAR_BIT(INTCON, _INTCON_TMR0IF_POSITION)

// Timer0 Enable Bit
#define INT_INTERRUPT_TIMER0_DISABLE()                        CLEAR_BIT(INTCON, _INTCON_TMR0IE_POSITION)
#define INT_INTERRUPT_TIMER0_ENABLE()                         SET_BIT(INTCON, _INTCON_TMR0IE_POSITION)

// Timer0 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER0_LOW_PRIORITY()                   CLEAR_BIT(INTCON2, _INTCON2_TMR0IP_POSITION)
#define INT_INTERRUPT_TIMER0_HIGH_PRIORITY()                  SET_BIT(INTCON2, _INTCON2_TMR0IP_POSITION)

#endif

#endif

// Timer1 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER1_INTERRUPT_FEATURE))

// Timer1 Flag bit
#define INT_INTERRUPT_TIMER1_CLEAR_FLAG()                     CLEAR_BIT(PIR1, _PIR1_TMR1IF_POSITION)

// Timer1 Enable Bit
#define INT_INTERRUPT_TIMER1_DISABLE()                        CLEAR_BIT(PIE1, _PIE1_TMR1IE_POSITION)
#define INT_INTERRUPT_TIMER1_ENABLE()                         SET_BIT(PIE1, _PIE1_TMR1IE_POSITION)

// Timer1 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER1_LOW_PRIORITY()                   CLEAR_BIT(IPR1, _IPR1_TMR1IP_POSITION)
#define INT_INTERRUPT_TIMER1_HIGH_PRIORITY()                  SET_BIT(IPR1, _IPR1_TMR1IP_POSITION)

#endif

#endif

// Timer2 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER2_INTERRUPT_FEATURE))

// Timer2 Flag bit
#define INT_INTERRUPT_TIMER2_CLEAR_FLAG()                     CLEAR_BIT(PIR1, _PIR1_TMR2IF_POSITION)

// Timer2 Enable Bit
#define INT_INTERRUPT_TIMER2_DISABLE()                        CLEAR_BIT(PIE1, _PIE1_TMR2IE_POSITION)
#define INT_INTERRUPT_TIMER2_ENABLE()                         SET_BIT(PIE1, _PIE1_TMR2IE_POSITION)

// Timer2 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER2_LOW_PRIORITY()                   CLEAR_BIT(IPR1, _IPR1_TMR2IP_POSITION)
#define INT_INTERRUPT_TIMER2_HIGH_PRIORITY()                  SET_BIT(IPR1, _IPR1_TMR2IP_POSITION)

#endif

#endif

// Timer3 Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (TIMER3_INTERRUPT_FEATURE))

// Timer3 Flag bit
#define INT_INTERRUPT_TIMER3_CLEAR_FLAG()                     CLEAR_BIT(PIR2, _PIR2_TMR3IF_POSITION)

// Timer3 Enable Bit
#define INT_INTERRUPT_TIMER3_DISABLE()                        CLEAR_BIT(PIE2, _PIE2_TMR3IE_POSITION)
#define INT_INTERRUPT_TIMER3_ENABLE()                         SET_BIT(PIE2, _PIE2_TMR3IE_POSITION)

// Timer3 Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_TIMER3_LOW_PRIORITY()                   CLEAR_BIT(IPR2, _IPR2_TMR3IP_POSITION)
#define INT_INTERRUPT_TIMER3_HIGH_PRIORITY()                  SET_BIT(IPR2, _IPR2_TMR3IP_POSITION)

#endif

#endif

// CCP1 Module Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (CCP1_INTERRUPT_FEATURE))

// CCP1 Module Flag Bit
#define INT_INTERRUPT_CCP1_CLEAR_FLAG()                        CLEAR_BIT(PIR1, _PIR1_CCP1IF_POSITION)

// CCP1 Module Enable Bit
#define INT_INTERRUPT_CCP1_DISABLE()                           CLEAR_BIT(PIE1, _PIE1_CCP1IE_POSITION)
#define INT_INTERRUPT_CCP1_ENABLE()                            SET_BIT(PIE1, _PIE1_CCP1IE_POSITION)

// CCP1 Module Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_CCP1_LOW_PRIORITY()                      CLEAR_BIT(IPR1, _IPR1_CCP1IP_POSITION)
#define INT_INTERRUPT_CCP1_HIGH_PRIORITY()                     SET_BIT(IPR1, _IPR1_CCP1IP_POSITION)

#endif

#endif


// CCP2 Module Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (CCP2_INTERRUPT_FEATURE))

// CCP2 Module Flag Bit
#define INT_INTERRUPT_CCP2_CLEAR_FLAG()                        CLEAR_BIT(PIR2, _PIR2_CCP2IF_POSITION)

// CCP2 Module Enable Bit
#define INT_INTERRUPT_CCP2_DISABLE()                           CLEAR_BIT(PIE2, _PIE2_CCP2IE_POSITION)
#define INT_INTERRUPT_CCP2_ENABLE()                            SET_BIT(PIE2, _PIE2_CCP2IE_POSITION)

// CCP2 Module Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_CCP2_LOW_PRIORITY()                      CLEAR_BIT(IPR2, _IPR2_CCP2IP_POSITION)
#define INT_INTERRUPT_CCP2_HIGH_PRIORITY()                     SET_BIT(IPR2, _IPR2_CCP2IP_POSITION)

#endif

#endif

// EUSART Module Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (EUSART_INTERRUPT_FEATURE))

// EUSART Module Flag Bit
#define INT_INTERRUPT_EUSART_TX_CLEAR_FLAG()                   CLEAR_BIT(PIR1, _PIR1_TXIF_POSITION)
#define INT_INTERRUPT_EUSART_RX_CLEAR_FLAG()                   CLEAR_BIT(PIR1, _PIR1_RCIF_POSITION)

// EUSART Module Enable Bit
#define INT_INTERRUPT_EUSART_TX_DISABLE()                      CLEAR_BIT(PIE1, _PIE1_TXIE_POSITION)
#define INT_INTERRUPT_EUSART_TX_ENABLE()                       SET_BIT(PIE1, _PIE1_TXIE_POSITION)
#define INT_INTERRUPT_EUSART_RX_DISABLE()                      CLEAR_BIT(PIE1, _PIE1_RCIE_POSITION)
#define INT_INTERRUPT_EUSART_RX_ENABLE()                       SET_BIT(PIE1, _PIE1_RCIE_POSITION)

// EUSART Module Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_EUSART_TX_LOW_PRIORITY()                 CLEAR_BIT(IPR1, _IPR1_TXIP_POSITION)
#define INT_INTERRUPT_EUSART_TX_HIGH_PRIORITY()                SET_BIT(IPR1, _IPR1_TXIP_POSITION)
#define INT_INTERRUPT_EUSART_RX_LOW_PRIORITY()                 CLEAR_BIT(IPR1, _IPR1_RCIP_POSITION)
#define INT_INTERRUPT_EUSART_RX_HIGH_PRIORITY()                SET_BIT(IPR1, _IPR1_RCIP_POSITION)

#endif

#endif

// SPI Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))

// SPI Flag bit
#define INT_INTERRUPT_SPI_CLEAR_FLAG()                        CLEAR_BIT(PIR1, _PIR1_SSPIF_POSITION)

// SPI Enable Bit
#define INT_INTERRUPT_SPI_DISABLE()                           CLEAR_BIT(PIE1, _PIE1_SSPIE_POSITION)
#define INT_INTERRUPT_SPI_ENABLE()                            SET_BIT(PIE1, _PIE1_SSPIE_POSITION)

// SPI Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))

#define INT_INTERRUPT_SPI_LOW_PRIORITY()                      CLEAR_BIT(IPR1, _IPR1_SSPIP_POSITION)
#define INT_INTERRUPT_SPI_HIGH_PRIORITY()                     SET_BIT(IPR1, _IPR1_SSPIP_POSITION)

#endif

#endif

// I2C Interrupt Configuration
#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))

// I2C Flag bit

// I2C Main Interrupt Flag
#define INT_INTERRUPT_I2C_CLEAR_FLAG()                        CLEAR_BIT(PIR1, _PIR1_SSPIF_POSITION)
// I2C Bus Collision Interrupt Flag
#define INT_INTERRUPT_I2C_BUS_COL_CLEAR_FLAG()                CLEAR_BIT(PIR2, _PIR2_BCLIF_POSITION)

// I2C Enable Bit

// I2C Main Interrupt Enable
#define INT_INTERRUPT_I2C_DISABLE()                           CLEAR_BIT(PIE1, _PIE1_SSPIE_POSITION)
#define INT_INTERRUPT_I2C_ENABLE()                            SET_BIT(PIE1, _PIE1_SSPIE_POSITION)
// I2C Bus Collision Interrupt Enable
#define INT_INTERRUPT_I2C_BUS_COL_DISABLE()                   CLEAR_BIT(PIE2, _PIE2_BCLIE_POSITION)
#define INT_INTERRUPT_I2C_BUS_COL_ENABLE()                    SET_BIT(PIE2, _PIE2_BCLIE_POSITION)

// I2C Priority Bit
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
// I2C Main Interrupt
#define INT_INTERRUPT_I2C_LOW_PRIORITY()                      CLEAR_BIT(IPR1, _IPR1_SSPIP_POSITION)
#define INT_INTERRUPT_I2C_HIGH_PRIORITY()                     SET_BIT(IPR1, _IPR1_SSPIP_POSITION)
// I2C Bus Collision Interrupt Priority
#define INT_INTERRUPT_I2C_BUS_COL_LOW_PRIORITY()              CLEAR_BIT(IPR2, _IPR2_BCLIP_POSITION)
#define INT_INTERRUPT_I2C_BUS_COL_HIGH_PRIORITY()             SET_BIT(IPR2, _IPR2_BCLIP_POSITION)

#endif

#endif

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/



/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/



#endif	/* HAL_INT_INTERRUPT_H */

