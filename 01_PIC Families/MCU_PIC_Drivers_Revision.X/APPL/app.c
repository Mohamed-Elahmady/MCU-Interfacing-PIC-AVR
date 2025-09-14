/* 
 * File:   app.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:26 AM
 */

#include "app.h"

gpio_led led1 = {.pin.port = gpio_portD, .pin.pin = gpio_pin0, .pin.direction = gpio_output, 
                 .pin.logic = gpio_low, .con = led_source, .state = led_off};


int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    while(1){
        
    }
    return (EXIT_SUCCESS);
}