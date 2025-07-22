/* 
 * File:   ECUAL_INIT.c
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 8:15 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_INIT.h"

/******************* Section 1 :  Variables Definitions *******************/

CHR_LCD_4BIT lcd1 = {
    .rs_pin.PORT = GPIO_PORTB,
    .rs_pin.PIN = GPIO_PIN0,
    .rs_pin.DIRECTION = GPIO_OUTPUT,
    .rs_pin.LOGIC = GPIO_LOW,

    .rw_pin.PORT = GPIO_PORTB,
    .rw_pin.PIN = GPIO_PIN1,
    .rw_pin.DIRECTION = GPIO_OUTPUT,
    .rw_pin.LOGIC = GPIO_LOW,

    .en_pin.PORT = GPIO_PORTB,
    .en_pin.PIN = GPIO_PIN2,
    .en_pin.DIRECTION = GPIO_OUTPUT,
    .en_pin.LOGIC = GPIO_LOW,

    .data_pins[0].PORT = GPIO_PORTC,
    .data_pins[0].PIN = GPIO_PIN0,
    .data_pins[0].DIRECTION = GPIO_OUTPUT,
    .data_pins[0].LOGIC = GPIO_LOW,

    .data_pins[1].PORT = GPIO_PORTC,
    .data_pins[1].PIN = GPIO_PIN1,
    .data_pins[1].DIRECTION = GPIO_OUTPUT,
    .data_pins[1].LOGIC = GPIO_LOW,

    .data_pins[2].PORT = GPIO_PORTC,
    .data_pins[2].PIN = GPIO_PIN2,
    .data_pins[2].DIRECTION = GPIO_OUTPUT,
    .data_pins[2].LOGIC = GPIO_LOW,

    .data_pins[3].PORT = GPIO_PORTC,
    .data_pins[3].PIN = GPIO_PIN3,
    .data_pins[3].DIRECTION = GPIO_OUTPUT,
    .data_pins[3].LOGIC = GPIO_LOW
};

CHR_LCD_8BIT lcd2 = {
    .rs_pin.PORT = GPIO_PORTB,
    .rs_pin.PIN = GPIO_PIN3,
    .rs_pin.DIRECTION = GPIO_OUTPUT,
    .rs_pin.LOGIC = GPIO_LOW,

    .rw_pin.PORT = GPIO_PORTB,
    .rw_pin.PIN = GPIO_PIN4,
    .rw_pin.DIRECTION = GPIO_OUTPUT,
    .rw_pin.LOGIC = GPIO_LOW,

    .en_pin.PORT = GPIO_PORTB,
    .en_pin.PIN = GPIO_PIN5,
    .en_pin.DIRECTION = GPIO_OUTPUT,
    .en_pin.LOGIC = GPIO_LOW,

    .data_pins[0].PORT = GPIO_PORTD,
    .data_pins[0].PIN = GPIO_PIN0,
    .data_pins[0].DIRECTION = GPIO_OUTPUT,
    .data_pins[0].LOGIC = GPIO_LOW,

    .data_pins[1].PORT = GPIO_PORTD,
    .data_pins[1].PIN = GPIO_PIN1,
    .data_pins[1].DIRECTION = GPIO_OUTPUT,
    .data_pins[1].LOGIC = GPIO_LOW,

    .data_pins[2].PORT = GPIO_PORTD,
    .data_pins[2].PIN = GPIO_PIN2,
    .data_pins[2].DIRECTION = GPIO_OUTPUT,
    .data_pins[2].LOGIC = GPIO_LOW,

    .data_pins[3].PORT = GPIO_PORTD,
    .data_pins[3].PIN = GPIO_PIN3,
    .data_pins[3].DIRECTION = GPIO_OUTPUT,
    .data_pins[3].LOGIC = GPIO_LOW,

    .data_pins[4].PORT = GPIO_PORTD,
    .data_pins[4].PIN = GPIO_PIN4,
    .data_pins[4].DIRECTION = GPIO_OUTPUT,
    .data_pins[4].LOGIC = GPIO_LOW,

    .data_pins[5].PORT = GPIO_PORTD,
    .data_pins[5].PIN = GPIO_PIN5,
    .data_pins[5].DIRECTION = GPIO_OUTPUT,
    .data_pins[5].LOGIC = GPIO_LOW,

    .data_pins[6].PORT = GPIO_PORTD,
    .data_pins[6].PIN = GPIO_PIN6,
    .data_pins[6].DIRECTION = GPIO_OUTPUT,
    .data_pins[6].LOGIC = GPIO_LOW,

    .data_pins[7].PORT = GPIO_PORTD,
    .data_pins[7].PIN = GPIO_PIN7,
    .data_pins[7].DIRECTION = GPIO_OUTPUT,
    .data_pins[7].LOGIC = GPIO_LOW
};

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

void ECUAL_LAYER_INIT(void) {
    Std_ReturnType Ret = E_OK;
    Ret = GPIO_LCD_4BIT_INIT(&lcd1);
    Ret = GPIO_LCD_8BIT_INIT(&lcd2);
}

/******************* Section 2 :  Helper Functions Definitions *******************/