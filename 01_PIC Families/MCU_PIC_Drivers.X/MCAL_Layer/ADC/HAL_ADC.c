/* 
 * File:   HAL_ADC.c
 * Author: mohammedel-ahmady
 *
 * Created on August 7, 2025, 6:20 PM
 */


/******************* Section 0 : Includes *******************/

#include "HAL_ADC.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))

static ADC_HANDLER ADC_HANDLER_FUNCTION = NULL;

#endif

static Std_ReturnType ADC_SET_DISABLE(const ADC_CFG *adc);
static Std_ReturnType ADC_SET_ENABLE(const ADC_CFG *adc);
static Std_ReturnType ADC_SET_CONVERSION_CLOCK(const ADC_CFG *adc);
static Std_ReturnType ADC_SET_ACQUISITION_TIME(const ADC_CFG *adc);
static Std_ReturnType ADC_SET_CHANNEL_CONFIGURATIONS(const ADC_CHANNEL_SELECT channel);
static Std_ReturnType ADC_SET_RESULT_FORMAT(const ADC_CFG *adc);
static Std_ReturnType ADC_SET_VOLTAGE_REFERENCE(const ADC_CFG *adc);

#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
static Std_ReturnType ADC_SET_INTERRUPT_CONFIGURATION(const ADC_CFG *adc);
#endif
/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((ADC_FEATURE_ENABLE) == (ADC_CFG_FEATURE))

/**
 * @brief   Initialize the ADC module with the given configuration.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or invalid configuration
 */

Std_ReturnType ADC_INIT(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || adc->channel > ADC_CHANNEL_AN12) {
        Retval = E_NOT_OK;
    } else {
        // 1. Disable ADC "ADON"
        Retval = ADC_SET_DISABLE(adc);
        // 2. Configure Conversion Clock
        Retval = ADC_SET_CONVERSION_CLOCK(adc);
        // 3. Set Voltage reference 
        Retval = ADC_SET_VOLTAGE_REFERENCE(adc);
        // 4. Configure Channel
        Retval = ADC_SET_CHANNEL_CONFIGURATIONS(adc->channel);
        // 5.  Set result format
        Retval = ADC_SET_RESULT_FORMAT(adc);
        // 6. Configure ACQ time
        Retval = ADC_SET_ACQUISITION_TIME(adc);
        // 7. Configure Interrupt
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
        Retval = ADC_SET_INTERRUPT_CONFIGURATION(adc);
#endif
        // 8. enable ADC module "ADON"
        Retval = ADC_SET_ENABLE(adc);
    }
    return Retval;
}

/**
 * @brief   De-initialize the ADC module (disable ADC and interrupt if enabled).
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */

Std_ReturnType ADC_DEINIT(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        // 1. Disable ADC "ADON"
        Retval = ADC_SET_DISABLE(adc);
#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))
        // 2. Disable "ADIE"
        INT_INTERRUPT_ADC_DISABLE();
        // 3. CLear Flag "ADIF"
        INT_INTERRUPT_ADC_CLEAR_FLAG();
#endif
    }
    return Retval;
}

/**
 * @brief   Select an ADC channel.
 * @param   adc     : Pointer to ADC configuration structure @ref ADC_CFG
 * @param   channel : Desired ADC channel @ref ADC_CHANNEL_SELECT
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or invalid channel
 */

Std_ReturnType ADC_SELECT_CHANNEL(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || channel > ADC_CHANNEL_AN12) {
        Retval = E_NOT_OK;
    } else {
        Retval = ADC_SET_CHANNEL_CONFIGURATIONS(channel);
    }
    return Retval;
}

/**
 * @brief   Start ADC conversion.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */

Std_ReturnType ADC_START_CONVERSION(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        ADC_START_CONVERSION_STATUS_GO_DONE();
    }
    return Retval;
}

/**
 * @brief   Check if ADC conversion is completed.
 * @param   adc   : Pointer to ADC configuration structure @ref ADC_CFG
 * @param   state : Pointer to store ADC conversion state @ref ADC_CONVERSION_STATES
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */

Std_ReturnType ADC_IS_CONVERSION_DONE(const ADC_CFG *adc, ADC_CONVERSION_STATES *state) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || NULL == state) {
        Retval = E_NOT_OK;
    } else {
        *state = ADC_READ_CONVERSION_STATUS_GO_DONE();
        if (*state == 0x00) {
            *state = ADC_CONVERSION_SUCCESS;
        } else {
            *state = ADC_CONVERSION_IN_PROGRESS;
        }
    }
    return Retval;
}

/**
 * @brief   Retrieve the ADC conversion result.
 * @param   adc    : Pointer to ADC configuration structure @ref ADC_CFG
 * @param   result : Pointer to store ADC result (10-bit or 8-bit depending on format)
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or invalid format
 */

Std_ReturnType ADC_GET_CONVERSION_RESULT(const ADC_CFG *adc, uint16 *result) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || NULL == result) {
        Retval = E_NOT_OK;
    } else {
        switch (adc->format) {
            case ADC_RESULT_FORMAT_LEFT:
                *result = ((uint16) ADRESH << 2) | (ADRESL >> 6);
                break;
            case ADC_RESULT_FORMAT_RIGHT:
                *result = ((uint16) ADRESH << 8) | ADRESL;
                break;
            default:
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/**
 * @brief   Perform blocking ADC conversion (wait until result is ready).
 * @param   adc    : Pointer to ADC configuration structure @ref ADC_CFG
 * @param   channel: ADC channel to convert @ref ADC_CHANNEL_SELECT
 * @param   result : Pointer to store ADC result
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or invalid channel
 */

Std_ReturnType ADC_GET_CONVERSION_BLOCKING(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel, uint16 *result) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || NULL == result || channel > ADC_CHANNEL_AN12) {
        Retval = E_NOT_OK;
    } else {
        // 1. Select channel
        Retval = ADC_SELECT_CHANNEL(adc, channel);
        // 2. Start ADC Conversion
        Retval = ADC_START_CONVERSION(adc);
        // 3. Another Way Wait until Conversion Done
        while (ADC_READ_CONVERSION_STATUS_GO_DONE());
        Retval = ADC_GET_CONVERSION_RESULT(adc, result);
    }
    return Retval;
}

/**
 * @brief   Start ADC conversion in interrupt mode.
 * @param   adc    : Pointer to ADC configuration structure @ref ADC_CFG
 * @param   channel: ADC channel to convert @ref ADC_CHANNEL_SELECT
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or invalid channel
 */

Std_ReturnType ADC_START_CONVERSION_INTERRUPT(const ADC_CFG *adc, ADC_CHANNEL_SELECT channel) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc || channel > ADC_CHANNEL_AN12) {
        Retval = E_NOT_OK;
    } else {
        // 1. Select channel
        Retval = ADC_SELECT_CHANNEL(adc, channel);
        // 2. Start ADC Conversion
        Retval = ADC_START_CONVERSION(adc);
        // Note. if the interrupt end the flag will set abd the conversion result will return
    }
    return Retval;
}

#endif

#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))

/**
 * @brief   ADC interrupt service routine (ISR).
 *          Clears interrupt flag and calls user-defined callback if available.
 */

void ADC_ISR(void) {
    // 1. Clear Flag
    INT_INTERRUPT_ADC_CLEAR_FLAG();
    // 2. Code

    // 3. Call Back Function
    if (ADC_HANDLER_FUNCTION) {
        ADC_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

/**
 * @brief   Disable the ADC module.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */

static Std_ReturnType ADC_SET_DISABLE(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        ADC_MODULE_DISABLE();
    }
    return Retval;
}

/**
 * @brief   Enable the ADC module.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */


static Std_ReturnType ADC_SET_ENABLE(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        ADC_MODULE_ENABLE();
    }
    return Retval;
}

/**
 * @brief   Configure ADC conversion clock.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */


static Std_ReturnType ADC_SET_CONVERSION_CLOCK(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        ADCON2bits.ADCS = adc->clk;
    }
    return Retval;
}

/**
 * @brief   Configure ADC acquisition time.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer
 */

static Std_ReturnType ADC_SET_ACQUISITION_TIME(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        ADCON2bits.ACQT = adc->tad;
    }
    return Retval;
}

/**
 * @brief   Configure ADC channel settings and assign corresponding pin as input.
 * @param   channel : ADC channel @ref ADC_CHANNEL_SELECT
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid channel
 */

static Std_ReturnType ADC_SET_CHANNEL_CONFIGURATIONS(const ADC_CHANNEL_SELECT channel) {
    Std_ReturnType Retval = E_OK;
    if (channel > ADC_CHANNEL_AN12) {
        Retval = E_NOT_OK;
    } else {
        ADCON0bits.CHS = channel;

        switch (channel) {
            case ADC_CHANNEL_AN0:
            {
                GPIO_PIN_CFG pinA0 = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN0, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA0);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL0_POSITION);
                break;
            }
            case ADC_CHANNEL_AN1:
            {
                GPIO_PIN_CFG pinA1 = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN1, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA1);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL1_POSITION);
                break;
            }
#if ((ADC_FEATURE_DISABLE) == (ADC_VOLTAGE_REFRENCE_VREF_CFG))
            case ADC_CHANNEL_AN2:
            {
                GPIO_PIN_CFG pinA2 = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN2, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA2);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL2_POSITION);
                break;
            }
            case ADC_CHANNEL_AN3:
            {
                GPIO_PIN_CFG pinA3 = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN3, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA3);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL3_POSITION);
                break;
            }
#endif
            case ADC_CHANNEL_AN4:
            {
                GPIO_PIN_CFG pinA4 = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN5, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA4);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL4_POSITION);
                break;
            }
            case ADC_CHANNEL_AN5:
            {
                GPIO_PIN_CFG pinA5 = {.PORT = GPIO_PORTE, .PIN = GPIO_PIN0, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA5);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL5_POSITION);
                break;
            }
            case ADC_CHANNEL_AN6:
            {
                GPIO_PIN_CFG pinA6 = {.PORT = GPIO_PORTE, .PIN = GPIO_PIN1, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA6);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL6_POSITION);
                break;
            }
            case ADC_CHANNEL_AN7:
            {
                GPIO_PIN_CFG pinA7 = {.PORT = GPIO_PORTE, .PIN = GPIO_PIN2, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA7);
                ADC_AN0_TO_AN7_SET_ANALOG_FUNCTIONALITY(ADC_ANSEL7_POSITION);
                break;
            }
            case ADC_CHANNEL_AN8:
            {
                GPIO_PIN_CFG pinA8 = {.PORT = GPIO_PORTB, .PIN = GPIO_PIN2, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA8);
                ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(ADC_ANSEH8_POSITION);
                break;
            }
            case ADC_CHANNEL_AN9:
            {
                GPIO_PIN_CFG pinA9 = {.PORT = GPIO_PORTB, .PIN = GPIO_PIN3, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA9);
                ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(ADC_ANSEH9_POSITION);
                break;
            }
            case ADC_CHANNEL_AN10:
            {
                GPIO_PIN_CFG pinA10 = {.PORT = GPIO_PORTB, .PIN = GPIO_PIN1, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA10);
                ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(ADC_ANSEH10_POSITION);
                break;
            }
            case ADC_CHANNEL_AN11:
            {
                GPIO_PIN_CFG pinA11 = {.PORT = GPIO_PORTB, .PIN = GPIO_PIN4, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA11);
                ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(ADC_ANSEH11_POSITION);
                break;
            }
            case ADC_CHANNEL_AN12:
            {
                GPIO_PIN_CFG pinA12 = {.PORT = GPIO_PORTB, .PIN = GPIO_PIN0, .DIRECTION = GPIO_INPUT};
                Retval = GPIO_PIN_DIRECTION_INIT(&pinA12);
                ADC_AN8_TO_AN12_SET_ANALOG_FUNCTIONALITY(ADC_ANSEH12_POSITION);
                break;
            }
            default:
            {
                Retval = E_NOT_OK;
                break;
            }
        }
    }
    return Retval;
}

/**
 * @brief   Set ADC result format (left or right justified).
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or format
 */


static Std_ReturnType ADC_SET_RESULT_FORMAT(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        switch (adc->format) {
            case ADC_RESULT_FORMAT_LEFT:
                ADC_RESULT_FORMAT_LEFT_B6_B15();
                break;
            case ADC_RESULT_FORMAT_RIGHT:
                ADC_RESULT_FORMAT_RIGHT_B0_B9();
                break;
            default:
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/**
 * @brief   Configure ADC voltage reference source.
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * @return  Status of the function
 *          (E_OK)     : Function executed successfully
 *          (E_NOT_OK) : Invalid pointer or voltage reference setting
 */


static Std_ReturnType ADC_SET_VOLTAGE_REFERENCE(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        switch (adc->vref) {
            case ADC_INTERNAL_VOLTAGE_REFERENCE:
                ADC_POSITIVE_VOLTAGE_REFRENCE_SELECT_VDD();
                ADC_NEGATIVE_VOLTAGE_REFRENCE_SELECT_VSS();
                break;
            case ADC_EXTERNAL_VOLTAGE_REFERENCE:
                ADC_POSITIVE_VOLTAGE_REFRENCE_SELECT_VREF();
                ADC_NEGATIVE_VOLTAGE_REFRENCE_SELECT_VREF();
                break;
            default:
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (ADC_INTERRUPT_FEATURE))

/**
 * @brief   Configure ADC interrupt settings and priority.
 * 
 * This function enables and configures the ADC interrupt based on the 
 * provided configuration. It supports both priority-enabled and 
 * non-priority interrupt modes.
 * 
 * @param   adc : Pointer to ADC configuration structure @ref ADC_CFG
 * 
 * @return  Status of the function:
 *          - (E_OK)     : Function executed successfully.
 *          - (E_NOT_OK) : Invalid pointer or invalid priority setting.
 */

static Std_ReturnType ADC_SET_INTERRUPT_CONFIGURATION(const ADC_CFG *adc) {
    Std_ReturnType Retval = E_OK;
    if (NULL == adc) {
        Retval = E_NOT_OK;
    } else {
        INT_INTERRUPT_ADC_ENABLE();
        INT_INTERRUPT_ADC_CLEAR_FLAG();
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        if (INTERRUPT_HIGH_PRIORITY == adc->priority) {
            INT_INTERRUPT_ADC_HIGH_PRIORITY();
        }
        else if (INTERRUPT_LOW_PRIORITY == adc->priority) {
            INT_INTERRUPT_ADC_LOW_PRIORITY();
        }
        else {
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        ADC_HANDLER_FUNCTION = adc->ADC_INTERRUPT;
    }
    return Retval;
}

#endif