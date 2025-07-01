/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:25 AM
 */

#include "app.h"

#define _XTAL_FREQ 16000000

gpio_led led1 = {
    .pin.port = gpio_portC,
    .pin.pin = gpio_pin0,
    .pin.direction = gpio_output,
    .pin.logic = gpio_low,     // initial logic
    .con = led_sink
};

led_logic current_state = led_off;

int main() {
    Std_ReturnType ret = E_NOT_OK;

    // Initialize LED
    ret = gpio_led_init(&led1);

    while (1) {
        // Turn LED ON
        gpio_led_turn_on(&led1);

        // Read current logic
        gpio_led_read_logic(&led1, &current_state);

        __delay_ms(500);


        // Toggle LED
        gpio_led_turn_toggle(&led1);
        
        // Read current logic
        gpio_led_read_logic(&led1, &current_state);
        
        __delay_ms(500);

        // Turn LED OFF
        gpio_led_turn_off(&led1);
        __delay_ms(500);
    }

    return (EXIT_SUCCESS);
}