/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

#define _XTAL_FREQ 8000000UL

gpio_relay relay1 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_output,
    .pin.logic = gpio_low
};

gpio_relay relay2 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin1,
    .pin.direction = gpio_output,
    .pin.logic = gpio_high
};

relay_state st1,st2;

int main() {
    Std_ReturnType ret = E_NOT_OK;

    ret = gpio_relay_init(&relay1);
    ret = gpio_relay_init(&relay2);

    while (1) {
        ret = gpio_relay_read_logic(&relay1, &st1);
        ret = gpio_relay_read_logic(&relay2, &st2);
        __delay_ms(3000);
        ret = gpio_relay_turn_on(&relay1);
        ret = gpio_relay_turn_toggle(&relay2);
        ret = gpio_relay_read_logic(&relay1, &st1);
        ret = gpio_relay_read_logic(&relay2, &st2);
        __delay_ms(3000);
        ret = gpio_relay_turn_off(&relay1);
        ret = gpio_relay_turn_toggle(&relay2);
        ret = gpio_relay_read_logic(&relay1, &st1);
        ret = gpio_relay_read_logic(&relay2, &st2);
    }

    return (EXIT_SUCCESS);
}