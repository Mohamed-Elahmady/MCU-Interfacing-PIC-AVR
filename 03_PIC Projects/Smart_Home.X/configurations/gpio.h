/* 
 * File:   gpio.h
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#ifndef GPIO_H
#define	GPIO_H

/******************* Section 1 : Includes *******************/
#include "../Platform.h"
#include <xc.h>

/******************* Section 2 : Macros Declarations *******************/

/* Logic Levels */
#define GPIO_LOW        (uint8)0
#define GPIO_HIGH       (uint8)1

/* Pin Direction */
#define GPIO_INPUT      (uint8)1
#define GPIO_OUTPUT     (uint8)0

/******************* Section 3 : Data Types *******************/

/**
 * @brief GPIO port identifiers
 */
typedef enum
{
    GPIO_PORTA_INDEX = 0,
    GPIO_PORTB_INDEX,
    GPIO_PORTC_INDEX,
    GPIO_PORTD_INDEX,
    GPIO_PORTE_INDEX
} gpio_port_t;

/**
 * @brief GPIO pin configuration structure
 */
typedef struct
{
    gpio_port_t port;     /**< Port name (A, B, C, D, E) */
    uint8 pin;            /**< Pin number (0?7) */
    uint8 direction;      /**< GPIO_INPUT or GPIO_OUTPUT */
    uint8 logic;          /**< GPIO_LOW or GPIO_HIGH */
} gpio_pin_t;

/******************* Section 4 : Function Prototypes *******************/

/**
 * @brief Initialize a GPIO pin direction and logic level.
 * @param pin_config Pointer to pin configuration struct.
 */
void GPIO_Init(const gpio_pin_t *pin_config);

/**
 * @brief Write logic level to a GPIO pin.
 * @param pin_config Pointer to pin configuration struct.
 * @param logic Desired logic level (GPIO_HIGH / GPIO_LOW).
 */
void GPIO_WritePin(const gpio_pin_t *pin_config, uint8 logic);

/**
 * @brief Read current logic level from a GPIO pin.
 * @param pin_config Pointer to pin configuration struct.
 * @return GPIO_HIGH or GPIO_LOW.
 */
uint8 GPIO_ReadPin(const gpio_pin_t *pin_config);

/**
 * @brief Toggle the logic level of a GPIO pin.
 * @param pin_config Pointer to pin configuration struct.
 */
void GPIO_TogglePin(const gpio_pin_t *pin_config);

#endif	/* GPIO_H */