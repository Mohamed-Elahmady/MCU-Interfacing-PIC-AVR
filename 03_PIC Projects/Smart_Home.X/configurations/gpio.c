/* 
 * File:   gpio.c
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#include "gpio.h"

/******************* Private Helper Macros *******************/
#define SET_PIN_OUTPUT(TRIS, BIT_POS)   (CLEAR_BIT((TRIS), (BIT_POS)))
#define SET_PIN_INPUT(TRIS, BIT_POS)    (SET_BIT((TRIS), (BIT_POS)))

#define WRITE_PIN(PORT, BIT_POS, LOGIC) \
    do { \
        if (LOGIC == GPIO_HIGH) { SET_BIT((PORT), (BIT_POS)); } \
        else { CLEAR_BIT((PORT), (BIT_POS)); } \
    } while(0)

/******************* Section 1 : Function Definitions *******************/

void GPIO_Init(const gpio_pin_t *pin_config)
{
    if (pin_config == NULL) return;

    switch (pin_config->port)
    {
        case GPIO_PORTA_INDEX:
            if (pin_config->direction == GPIO_OUTPUT)
                SET_PIN_OUTPUT(TRISA, pin_config->pin);
            else
                SET_PIN_INPUT(TRISA, pin_config->pin);
            WRITE_PIN(PORTA, pin_config->pin, pin_config->logic);
            break;

        case GPIO_PORTB_INDEX:
            if (pin_config->direction == GPIO_OUTPUT)
                SET_PIN_OUTPUT(TRISB, pin_config->pin);
            else
                SET_PIN_INPUT(TRISB, pin_config->pin);
            WRITE_PIN(PORTB, pin_config->pin, pin_config->logic);
            break;

        case GPIO_PORTC_INDEX:
            if (pin_config->direction == GPIO_OUTPUT)
                SET_PIN_OUTPUT(TRISC, pin_config->pin);
            else
                SET_PIN_INPUT(TRISC, pin_config->pin);
            WRITE_PIN(PORTC, pin_config->pin, pin_config->logic);
            break;

        case GPIO_PORTD_INDEX:
            if (pin_config->direction == GPIO_OUTPUT)
                SET_PIN_OUTPUT(TRISD, pin_config->pin);
            else
                SET_PIN_INPUT(TRISD, pin_config->pin);
            WRITE_PIN(PORTD, pin_config->pin, pin_config->logic);
            break;

        case GPIO_PORTE_INDEX:
            if (pin_config->direction == GPIO_OUTPUT)
                SET_PIN_OUTPUT(TRISE, pin_config->pin);
            else
                SET_PIN_INPUT(TRISE, pin_config->pin);
            WRITE_PIN(PORTE, pin_config->pin, pin_config->logic);
            break;

        default:
            break;
    }
}

void GPIO_WritePin(const gpio_pin_t *pin_config, uint8 logic)
{
    if (pin_config == NULL) return;

    switch (pin_config->port)
    {
        case GPIO_PORTA_INDEX: WRITE_PIN(PORTA, pin_config->pin, logic); break;
        case GPIO_PORTB_INDEX: WRITE_PIN(PORTB, pin_config->pin, logic); break;
        case GPIO_PORTC_INDEX: WRITE_PIN(PORTC, pin_config->pin, logic); break;
        case GPIO_PORTD_INDEX: WRITE_PIN(PORTD, pin_config->pin, logic); break;
        case GPIO_PORTE_INDEX: WRITE_PIN(PORTE, pin_config->pin, logic); break;
        default: break;
    }
}

uint8 GPIO_ReadPin(const gpio_pin_t *pin_config)
{
    if (pin_config == NULL) return GPIO_LOW;

    uint8 value = GPIO_LOW;

    switch (pin_config->port)
    {
        case GPIO_PORTA_INDEX: value = READ_BIT(PORTA, pin_config->pin); break;
        case GPIO_PORTB_INDEX: value = READ_BIT(PORTB, pin_config->pin); break;
        case GPIO_PORTC_INDEX: value = READ_BIT(PORTC, pin_config->pin); break;
        case GPIO_PORTD_INDEX: value = READ_BIT(PORTD, pin_config->pin); break;
        case GPIO_PORTE_INDEX: value = READ_BIT(PORTE, pin_config->pin); break;
        default: break;
    }

    return value;
}

void GPIO_TogglePin(const gpio_pin_t *pin_config)
{
    if (pin_config == NULL) return;

    switch (pin_config->port)
    {
        case GPIO_PORTA_INDEX: TOGGLE_BIT(PORTA, pin_config->pin); break;
        case GPIO_PORTB_INDEX: TOGGLE_BIT(PORTB, pin_config->pin); break;
        case GPIO_PORTC_INDEX: TOGGLE_BIT(PORTC, pin_config->pin); break;
        case GPIO_PORTD_INDEX: TOGGLE_BIT(PORTD, pin_config->pin); break;
        case GPIO_PORTE_INDEX: TOGGLE_BIT(PORTE, pin_config->pin); break;
        default: break;
    }
}