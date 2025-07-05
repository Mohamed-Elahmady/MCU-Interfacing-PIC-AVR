/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

#define _XTAL_FREQ                       16000000

GPIO_RELAY relay1 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN = GPIO_PIN0,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW
};

GPIO_RELAY relay2 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN = GPIO_PIN1,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_HIGH
};

Std_ReturnType Ret = E_OK;

RELAY_STATE state;

int main() {
    application_init();
    while (1) {
//        __delay_ms(1000);
//        Ret = GPIO_RELAY_TURN_ON(&relay1);
//        __delay_ms(1000);
//        Ret = GPIO_RELAY_TURN_OFF(&relay1);
        
          Ret = GPIO_RELAY_TURN_TOGGLE(&relay1);
          Ret = GPIO_RELAY_TURN_TOGGLE(&relay2);
          Ret = GPIO_RELAY_READ_LOGIC(&relay1, &state);
          __delay_ms(1000);
    }

    return (EXIT_SUCCESS);
}

void application_init(void) {
    Ret = GPIO_RELAY_INIT(&relay1);
    Ret = GPIO_RELAY_INIT(&relay2);

}