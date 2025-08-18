/* 
 * File:   hal_adc.c
 * Author: mohammedel-ahmady
 *
 * Created on August 12, 2025, 1:29 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_adc.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((interrupt_feature_enable) == (int_interrupt_adc))

static adc_handler adc_interrupt_handler = NULL;

#endif 

static Std_ReturnType adc_set_disable(const adc_cfg *adc);
static Std_ReturnType adc_set_conversion_clock(const adc_cfg *adc);
static Std_ReturnType adc_set_voltage_reference(const adc_cfg *adc);
static Std_ReturnType adc_set_channel_configuration(const adc_channel channel);
static Std_ReturnType adc_set_result_format(const adc_cfg *adc);
static Std_ReturnType adc_set_acquisition_time(const adc_cfg *adc);
static Std_ReturnType adc_set_enable(const adc_cfg *adc);

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType adc_init(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable ADC Configuration
        Retval = adc_set_disable(adc);
        // 2. set conversion clock
        Retval = adc_set_conversion_clock(adc);
        // 3. set voltage ref
        Retval = adc_set_voltage_reference(adc);
        // 4. select input channel
        Retval = adc_set_channel_configuration(adc->channel);
        // 5. select result format
        Retval = adc_set_result_format(adc);
        // 6. select acquisition time
        Retval = adc_set_acquisition_time(adc);
        // 7. Configure Interrupt if needed
#if ((interrupt_feature_enable) == (int_interrupt_adc))
        intenral_interrupt_adc_clear_flag();
        intenral_interrupt_adc_enable();
#if ((interrupt_feature_enable) == (interrupt_priority_levels))
        interrupt_priority_bit_enable();
        global_interrupt_high_enable();
        global_interrupt_low_enable();
        if(interrupt_high_priority == adc->priority){
            intenral_interrupt_adc_high_priority();
        }
        else if(interrupt_low_priority == adc->priority){
            intenral_interrupt_adc_low_priority();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((interrupt_feature_disable) == (interrupt_priority_levels)) 
        interrupt_priority_bit_disable();
        global_interrupt_enable();
        peripheral_interrupt_enable();
#endif
        adc_interrupt_handler = adc->adc_interrupt;
#endif
        // 8. Enable Adc module
        Retval = adc_set_enable(adc);
    }
    return Retval;
}

Std_ReturnType adc_deinit(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable ADC module
        Retval = adc_set_disable(adc);
#if ((interrupt_feature_enable) == (int_interrupt_adc))
        // 2. Disable ADC Interrupt
        intenral_interrupt_adc_disable();
        // 3. Clear ADC flag
        intenral_interrupt_adc_clear_flag();
#endif
    }
    return Retval;
}

Std_ReturnType adc_set_channel(const adc_cfg *adc, adc_channel channel){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc || channel > adc_channel_an12){
        Retval = E_NOT_OK;
    }
    else{
        Retval = adc_set_channel_configuration(channel);
    }
    return Retval;
}

Std_ReturnType adc_start_conversion(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        adc_start_conversion_go_done();
    }
    return Retval;
}

Std_ReturnType adc_is_conversion_done(const adc_cfg *adc, adc_conversion_status *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        if(!adc_read_conversion_status()){
            *state = adc_conversion_completed;
        }
        else{
            *state = adc_conversion_in_progress;
        }
    }
    return Retval;
}

Std_ReturnType adc_get_conversion_result(const adc_cfg *adc, uint16 *result){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc || NULL == result){
        Retval = E_NOT_OK;
    }
    else{
        switch(adc->format){
            case adc_format_left:
                *result = (uint16)((ADRESH << 2) | (ADRESL >> 6));
                break;
            case adc_format_right:                
                *result = (uint16)(((uint16)ADRESH << 8) | ADRESL);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

Std_ReturnType adc_get_conversion_blocking(const adc_cfg *adc, adc_channel channel, uint16 *result){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc || NULL == result || channel > adc_channel_an12){
        Retval = E_NOT_OK;
    }
    else{
        // 1. set channel
        Retval = adc_set_channel(adc, channel);
        // 2. start conversion
        Retval = adc_start_conversion(adc);
        // 3. wait until conversion done
        while(adc_read_conversion_status());
        // 4. return the result
        Retval = adc_get_conversion_result(adc, result);
    }
    return Retval;
}

Std_ReturnType adc_start_conversion_interrupt(const adc_cfg *adc, adc_channel channel){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc || channel > adc_channel_an12){
        Retval = E_NOT_OK;
    }
    else{
        // 1. set channel
        Retval = adc_set_channel(adc, channel);
        // 2. start conversion
        Retval = adc_start_conversion(adc);
        // 3. this function for interrupts u can complete the conversion steps in ISR
        // flag set when the conversion done
    }
    return Retval;
}

void adc_isr(void){
    // 1. Clear Flag
    intenral_interrupt_adc_clear_flag();
    // 2. code
    
    // 3. Callback function
    if(adc_interrupt_handler){
        adc_interrupt_handler();
    }
}

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType adc_set_disable(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        adc_disable_bit();
    }
    return Retval;
}

static Std_ReturnType adc_set_conversion_clock(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        ADCON2bits.ADCS = adc->clk;
    }
    return Retval;
}

static Std_ReturnType adc_set_voltage_reference(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        switch(adc->ref){
            case adc_internal_voltage_reference:
                adc_internal_positive_voltage_reference_VDD();
                adc_internal_negative_voltage_reference_VSS();
                break;
            case adc_external_voltage_reference:
                adc_external_positive_voltage_reference_Vref();
                adc_external_negative_voltage_reference_Vref();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType adc_set_channel_configuration(const adc_channel channel){
    Std_ReturnType Retval = E_OK;
    if(channel > adc_channel_an12){
        Retval = E_NOT_OK;
    }
    else{
        // 1. set channel in ADCON0 Register CHS bits
        ADCON0bits.CHS = channel;
        // 2. initialize as input pin & disable digital I/O functionality
        switch (channel){
            case adc_channel_an0 :{
                gpio_pin_cfg pinA0 = {.port = gpio_portA, .pin = gpio_pin0, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA0);
                adc_set_ansel_analog_functionality(ansel_ans0_position);
                break;
            }
            case adc_channel_an1 :{
                gpio_pin_cfg pinA1 = {.port = gpio_portA, .pin = gpio_pin1, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA1);
                adc_set_ansel_analog_functionality(ansel_ans1_position);
                break;
            }
#if ((adc_feature_enable) == (adc_internal_voltage_reference_cfg))
            case adc_channel_an2 :{
                gpio_pin_cfg pinA2 = {.port = gpio_portA, .pin = gpio_pin2, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA2);
                adc_set_ansel_analog_functionality(ansel_ans2_position);
                break;
            }
            case adc_channel_an3 :{
                gpio_pin_cfg pinA3 = {.port = gpio_portA, .pin = gpio_pin3, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA3);
                adc_set_ansel_analog_functionality(ansel_ans3_position);

                break;
            }
#endif
            case adc_channel_an4 :{
                gpio_pin_cfg pinA4 = {.port = gpio_portA, .pin = gpio_pin5, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA4);
                adc_set_ansel_analog_functionality(ansel_ans4_position);
                break;
            }
            case adc_channel_an5 :{
                gpio_pin_cfg pinA5 = {.port = gpio_portE, .pin = gpio_pin0, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA5);
                adc_set_ansel_analog_functionality(ansel_ans5_position);
                break;
            }
            case adc_channel_an6 :{
                gpio_pin_cfg pinA6 = {.port = gpio_portE, .pin = gpio_pin1, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA6);
                adc_set_ansel_analog_functionality(ansel_ans6_position);
                break;
            }
            case adc_channel_an7 :{
                gpio_pin_cfg pinA7 = {.port = gpio_portE, .pin = gpio_pin2, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA7);
                adc_set_ansel_analog_functionality(ansel_ans7_position);
                break;
            }
            case adc_channel_an8 :{
                gpio_pin_cfg pinA8 = {.port = gpio_portB, .pin = gpio_pin2, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA8);
                adc_set_anselh_analog_functionality(anselh_ans8_position);
                break;
            }
            case adc_channel_an9 :{
                gpio_pin_cfg pinA9 = {.port = gpio_portB, .pin = gpio_pin3, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA9);
                adc_set_anselh_analog_functionality(anselh_ans9_position);
                break;
            }
            case adc_channel_an10 :{
                gpio_pin_cfg pinA10 = {.port = gpio_portB, .pin = gpio_pin1, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA10);
                adc_set_anselh_analog_functionality(anselh_ans10_position);
                break;
            }
            case adc_channel_an11 :{
                gpio_pin_cfg pinA11 = {.port = gpio_portB, .pin = gpio_pin4, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA11);
                adc_set_anselh_analog_functionality(anselh_ans11_position);
                break;
            }
            case adc_channel_an12 :{
                gpio_pin_cfg pinA12 = {.port = gpio_portB, .pin = gpio_pin0, .direction = gpio_input};
                Retval = gpio_pin_direction_init(&pinA12);
                adc_set_anselh_analog_functionality(anselh_ans12_position);
                break;
            }
                default :
                    Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType adc_set_result_format(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        switch(adc->format){
            case adc_format_left:
                adc_result_format_left();
                break;
            case adc_format_right:
                adc_result_format_right();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType adc_set_acquisition_time(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        ADCON2bits.ACQT = adc->acq;
    }
    return Retval;
}

static Std_ReturnType adc_set_enable(const adc_cfg *adc){
    Std_ReturnType Retval = E_OK;
    if(NULL == adc){
        Retval = E_NOT_OK;
    }
    else{
        adc_enable_bit();
    }
    return Retval;
}