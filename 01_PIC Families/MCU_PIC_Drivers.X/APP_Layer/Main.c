/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"


Std_ReturnType Ret = E_OK;

uint8 data22;

int main() {
    application_init();
    while (1) {
        Ret = GPIO_KEYPAD_READ_DATA(&keypad1, &data22);
        if(data22 == '7'){
            Ret = GPIO_LED_TURN_ON(&led1);
        }
        else{
            Ret = GPIO_LED_TURN_OFF(&led1);
        }
    }
        
    return (EXIT_SUCCESS);
}

void application_init(void) {
    ECUAL_LAYER_INIT();
}