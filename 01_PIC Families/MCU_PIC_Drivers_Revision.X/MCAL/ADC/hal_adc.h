/* 
 * File:   hal_adc.h
 * Author: mohammedel-ahmady
 *
 * Created on August 12, 2025, 1:29 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "hal_adc_cfg.h"
#include "../INTERRUPT/hal_int_interrupt.h"
#include "../GPIO/hal_gpio.h"


/******************* Section 2 : Macros Declarations *******************/

#define ansel_ans0_position                         (uint8)0x00
#define ansel_ans1_position                         (uint8)0x01
#define ansel_ans2_position                         (uint8)0x02
#define ansel_ans3_position                         (uint8)0x03
#define ansel_ans4_position                         (uint8)0x04
#define ansel_ans5_position                         (uint8)0x05
#define ansel_ans6_position                         (uint8)0x06
#define ansel_ans7_position                         (uint8)0x07

#define anselh_ans8_position                        (uint8)0x00
#define anselh_ans9_position                        (uint8)0x01
#define anselh_ans10_position                       (uint8)0x02
#define anselh_ans11_position                       (uint8)0x03
#define anselh_ans12_position                       (uint8)0x04

/******************* Section 3 : Macros Functions Declarations *******************/

// adc ADCON0 Register

#define adc_disable_bit()                                    clear_bit(ADCON0, _ADCON0_ADON_POSITION)
#define adc_enable_bit()                                     set_bit(ADCON0, _ADCON0_ADON_POSITION)

#define adc_start_conversion_go_done()                       set_bit(ADCON0, _ADCON0_GO_DONE_POSITION)
#define adc_read_conversion_status()                         read_bit(ADCON0, _ADCON0_GO_DONE_POSITION)

// adc disable Analog functionality "Digital I/O"
#define adc_set_ansel_digital_IO_functionality(position)     clear_bit(ANSEL, position)
#define adc_set_anselh_digital_IO_functionality(position)    clear_bit(ANSELH, position)

// adc enable Analog functionality
#define adc_set_ansel_analog_functionality(position)         set_bit(ANSEL, position)
#define adc_set_anselh_analog_functionality(position)        set_bit(ANSELH, position)

// adc ADCON1 Register

#define adc_internal_positive_voltage_reference_VDD()        clear_bit(ADCON1, _ADCON1_VCFG0_POSITION)
#define adc_internal_negative_voltage_reference_VSS()        clear_bit(ADCON1, _ADCON1_VCFG1_POSITION)

#define adc_external_positive_voltage_reference_Vref()       set_bit(ADCON1, _ADCON1_VCFG0_POSITION)
#define adc_external_negative_voltage_reference_Vref()       set_bit(ADCON1, _ADCON1_VCFG1_POSITION)

// adc ADCON2 Register

#define adc_result_format_left()                             clear_bit(ADCON2, _ADCON2_ADFM_POSITION)
#define adc_result_format_right()                            set_bit(ADCON2, _ADCON2_ADFM_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* adc_handler)(void);

typedef enum{
    adc_channel_an0 = (uint8)0x00,
    adc_channel_an1,
#if ((adc_feature_enable) == (adc_internal_voltage_reference_cfg))
    adc_channel_an2,
    adc_channel_an3,
#endif
    adc_channel_an4,
    adc_channel_an5,
    adc_channel_an6,
    adc_channel_an7,
    adc_channel_an8,
    adc_channel_an9,
    adc_channel_an10,
    adc_channel_an11,
    adc_channel_an12,
}adc_channel;

typedef enum{
    adc_internal_voltage_reference = (uint8)0x00, 
    adc_external_voltage_reference
}adc_voltage_reference;

typedef enum{
    adc_conversion_clock_fosc_div_2 = (uint8)0x00,
    adc_conversion_clock_fosc_div_8,
    adc_conversion_clock_fosc_div_32,
    adc_conversion_clock_fosc_div_frc,
    adc_conversion_clock_fosc_div_4,
    adc_conversion_clock_fosc_div_16,
    adc_conversion_clock_fosc_div_64
}adc_conversion_clock;

typedef enum{
    adc_acq_0tad = (uint8)0x00,
    adc_acq_2tad,
    adc_acq_4tad,
    adc_acq_6tad,
    adc_acq_8tad,
    adc_acq_12tad,
    adc_acq_16tad,
    adc_acq_20tad
}adc_acquisition_time;

typedef enum{
    adc_format_left = (uint8)0x00,
    adc_format_right
}adc_result_format;

typedef enum{
    adc_conversion_completed = (uint8)0x00,
    adc_conversion_in_progress
}adc_conversion_status;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_adc))
    adc_handler    adc_interrupt;
    interrupt_priority  priority;
#endif
    adc_channel          channel;
    adc_conversion_clock     clk;
    adc_acquisition_time     acq;
    adc_voltage_reference    ref;
    adc_result_format     format;
}adc_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType adc_init(const adc_cfg *adc);
Std_ReturnType adc_deinit(const adc_cfg *adc);
Std_ReturnType adc_set_channel(const adc_cfg *adc, adc_channel channel);
Std_ReturnType adc_start_conversion(const adc_cfg *adc);
Std_ReturnType adc_is_conversion_done(const adc_cfg *adc, adc_conversion_status *state);
Std_ReturnType adc_get_conversion_result(const adc_cfg *adc, uint16 *result);
Std_ReturnType adc_get_conversion_blocking(const adc_cfg *adc, adc_channel channel, uint16 *result);
Std_ReturnType adc_start_conversion_interrupt(const adc_cfg *adc, adc_channel channel);



#endif	/* HAL_ADC_H */

