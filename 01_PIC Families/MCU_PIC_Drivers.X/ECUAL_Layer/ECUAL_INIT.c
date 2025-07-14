/* 
 * File:   ECUAL_INIT.c
 * Author: mohammedel-ahmady
 *
 * Created on July 12, 2025, 8:15 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_INIT.h"

/******************* Section 1 :  Variables Definitions *******************/

GPIO_KEYPAD keypad1 = {
    .row_pins[0].PORT = GPIO_PORTC,
    .row_pins[0].PIN = GPIO_PIN0,
    .row_pins[0].DIRECTION = GPIO_OUTPUT,
    .row_pins[0].LOGIC = GPIO_LOW,

    .row_pins[1].PORT = GPIO_PORTC,
    .row_pins[1].PIN = GPIO_PIN1,
    .row_pins[1].DIRECTION = GPIO_OUTPUT,
    .row_pins[1].LOGIC = GPIO_LOW,

    .row_pins[2].PORT = GPIO_PORTC,
    .row_pins[2].PIN = GPIO_PIN2,
    .row_pins[2].DIRECTION = GPIO_OUTPUT,
    .row_pins[2].LOGIC = GPIO_LOW,

    .row_pins[3].PORT = GPIO_PORTC,
    .row_pins[3].PIN = GPIO_PIN3,
    .row_pins[3].DIRECTION = GPIO_OUTPUT,
    .row_pins[3].LOGIC = GPIO_LOW,
    
    .col_pins[0].PORT = GPIO_PORTC,
    .col_pins[0].PIN = GPIO_PIN4,
    .col_pins[0].DIRECTION = GPIO_INPUT,
    
    .col_pins[1].PORT = GPIO_PORTC,
    .col_pins[1].PIN = GPIO_PIN5,
    .col_pins[1].DIRECTION = GPIO_INPUT,

    .col_pins[2].PORT = GPIO_PORTC,
    .col_pins[2].PIN = GPIO_PIN6,
    .col_pins[2].DIRECTION = GPIO_INPUT,

    .col_pins[3].PORT = GPIO_PORTC,
    .col_pins[3].PIN = GPIO_PIN7,
    .col_pins[3].DIRECTION = GPIO_INPUT
};

GPIO_LED led1 = {
    .pin.PORT = GPIO_PORTD,
    .pin.PIN = GPIO_PIN0,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW
};

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

void ECUAL_LAYER_INIT(void) {
    Std_ReturnType Ret = E_OK;
    Ret = GPIO_KEYPAD_INIT(&keypad1);
    Ret = GPIO_LED_INIT(&led1);
}

/******************* Section 2 :  Helper Functions Definitions *******************/