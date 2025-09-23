/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

Std_ReturnType Ret = E_OK;

GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

int main() {
    application_init();
    while (1) {
        
    }
    return (EXIT_SUCCESS);
}

void application_init(void) {
    ECUAL_LAYER_INIT();
    GPIO_LED_INIT(&led1);
}
