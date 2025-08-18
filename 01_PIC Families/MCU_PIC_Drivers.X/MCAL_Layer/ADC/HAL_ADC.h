/* 
 * File:   HAL_ADC.h
 * Author: mohammedel-ahmady
 *
 * Created on August 7, 2025, 6:20 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_ADC_CFG.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../GPIO/HAL_GPIO.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define ADC_ANSEL0_POSITION                       (uint8)0x00
#define ADC_ANSEL1_POSITION                       (uint8)0x01
#define ADC_ANSEL2_POSITION                       (uint8)0x02
#define ADC_ANSEL3_POSITION                       (uint8)0x03
#define ADC_ANSEL4_POSITION                       (uint8)0x04
#define ADC_ANSEL5_POSITION                       (uint8)0x05
#define ADC_ANSEL6_POSITION                       (uint8)0x06
#define ADC_ANSEL7_POSITION                       (uint8)0x07

#define ADC_ANSEH8_POSITION                       (uint8)0x00
#define ADC_ANSEH9_POSITION                       (uint8)0x01
#define ADC_ANSEH10_POSITION                      (uint8)0x02
#define ADC_ANSEH11_POSITION                      (uint8)0x03
#define ADC_ANSEH12_POSITION                      (uint8)0x04

/******************* Section 3 : Macros Functions Declarations *******************/

/**
 * @brief : Function Like Macros For ADCON0 Register
 */
#define ADC_MODULE_DISABLE()                                                    CLEAR_BIT(ADCON0, _ADCON0_ADON_POSITION)
#define ADC_MODULE_ENABLE()                                                     SET_BIT(ADCON0, _ADCON0_ADON_POSITION)

// GO/DONE was Cleared by Hardware
#define ADC_START_CONVERSION_STATUS_GO_DONE()                                   SET_BIT(ADCON0, _ADCON0_GO_DONE_POSITION)
#define ADC_READ_CONVERSION_STATUS_GO_DONE()                                    READ_BIT(ADCON0, _ADCON0_GO_DONE_POSITION)

/**
 * @brief : Function Like Macros For ADCON1 Register
 */
#define ADC_POSITIVE_VOLTAGE_REFRENCE_SELECT_VDD()                              CLEAR_BIT(ADCON1, _ADCON1_VCFG0_POSITION)
#define ADC_POSITIVE_VOLTAGE_REFRENCE_SELECT_VREF()                             SET_BIT(ADCON1, _ADCON1_VCFG0_POSITION)

#define ADC_NEGATIVE_VOLTAGE_REFRENCE_SELECT_VSS()                              CLEAR_BIT(ADCON1, _ADCON1_VCFG1_POSITION)
#define ADC_NEGATIVE_VOLTAGE_REFRENCE_SELECT_VREF()                             SET_BIT(ADCON1, _ADCON1_VCFG1_POSITION)

// For Select PIN Configuration Digital(I/O) or Analog
// Digital Functionality for only GPIO
#define ADC_AN0_TO_AN7_SET_DIGITAL_IO_FUNCTIONALITY(__POSITION)                 CLEAR_BIT(ANSEL, __POSITION)
#define ADC_AN8_TO_AN12_SET_DIGITAL_IO_FUNCTIONALITY(__POSITION)                CLEAR_BIT(ANSELH, __POSITION)

// Analog Functionality for only ADC

#define ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(__POSITION)                     SET_BIT(ANSEL, __POSITION)
#define ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(__POSITION)                    SET_BIT(ANSELH, __POSITION)

/**
 * @brief : Function Like Macros For ADCON2 Register
 */

#define ADC_RESULT_FORMAT_LEFT_B6_B15()                                         CLEAR_BIT(ADCON2, _ADCON2_ADFM_POSITION)
#define ADC_RESULT_FORMAT_RIGHT_B0_B9()                                         SET_BIT(ADCON2, _ADCON2_ADFM_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void ( *ADC_HANDLER)(void);

// Using ADC channel select enum to also set CHS<0:3> Value
typedef enum{
    ADC_CHANNEL_AN0 = (uint8)0x00,
    ADC_CHANNEL_AN1,
#if ((ADC_FEATURE_DISABLE) == (ADC_VOLTAGE_REFRENCE_VREF_CFG))            
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
#endif
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
    ADC_CHANNEL_AN8,
    ADC_CHANNEL_AN9,
    ADC_CHANNEL_AN10,
    ADC_CHANNEL_AN11,
    ADC_CHANNEL_AN12
}ADC_CHANNEL_SELECT;

typedef enum{
    ADC_INTERNAL_VOLTAGE_REFERENCE = (uint8)0x00,
    ADC_EXTERNAL_VOLTAGE_REFERENCE
}ADC_VOLTAGE_REFERENCE;

typedef enum{
    ADC_ACQ_0TAD = (uint8)0x00,
    ADC_ACQ_2TAD,
    ADC_ACQ_4TAD,
    ADC_ACQ_6TAD,
    ADC_ACQ_8TAD,
    ADC_ACQ_12TAD,
    ADC_ACQ_16TAD,
    ADC_ACQ_20TAD
}ADC_ACQUISITION_TIME;

typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = (uint8)0x00,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
}ADC_CONVERSION_CLOCK;

typedef enum{
    ADC_RESULT_FORMAT_LEFT = (uint8)0x00,
    ADC_RESULT_FORMAT_RIGHT
}ADC_RESULT_FORMAT;

typedef enum{
    ADC_CONVERSION_IN_PROGRESS = (uint8)0x00,
    ADC_CONVERSION_SUCCESS
}ADC_CONVERSION_STATES;

typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
    ADC_HANDLER     ADC_INTERRUPT; // @ref : ADC_HANDLER
    INTERRUPT_PRIORITY   priority; // @ref : INTERRUPT_PRIORITY
#endif
    ADC_CHANNEL_SELECT channel   ; // @ref : ADC_CHANNEL_SELECT
    ADC_ACQUISITION_TIME tad     ; // @ref : ADC_ACQUISITION_TIME
    ADC_CONVERSION_CLOCK clk     ; // @ref : ADC_CONVERSION_CLOCK
    ADC_VOLTAGE_REFERENCE vref   ; // @ref : ADC_VOLTAGE_REFERENCE
    ADC_RESULT_FORMAT   format   ; // @ref : ADC_RESULT_FORMAT
    
    uint8 ADC_RESERVED           ;
}ADC_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType ADC_INIT(const ADC_CFG *adc);
Std_ReturnType ADC_DEINIT(const ADC_CFG *adc);
Std_ReturnType ADC_SELECT_CHANNEL(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel);
Std_ReturnType ADC_START_CONVERSION(const ADC_CFG *adc);
Std_ReturnType ADC_IS_CONVERSION_DONE(const ADC_CFG *adc, ADC_CONVERSION_STATES *state);
Std_ReturnType ADC_GET_CONVERSION_RESULT(const ADC_CFG *adc, uint16 *result); 
Std_ReturnType ADC_GET_CONVERSION_BLOCKING(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel, uint16 *result);
Std_ReturnType ADC_START_CONVERSION_INTERRUPT(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel);

#endif	/* HAL_ADC_H */