/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

#define _XTAL_FREQ                       16000000

GPIO_LED led1 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN =  GPIO_PIN0,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW, 
};

GPIO_LED led2 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN =  GPIO_PIN1,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_HIGH, 
};

GPIO_LED led3 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN =  GPIO_PIN2,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW, 
};

GPIO_LED led4 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN =  GPIO_PIN3,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_HIGH, 
};

Std_ReturnType ret = E_OK;

LED_LOGIC logi;

int main() { 
    application_init();
    while(1){ 
       ret =  GPIO_LED_READ_LOGIC(&led4, &logi);
       __delay_ms(200);
       if(LED_ON == logi){
           ret = GPIO_LED_TURN_TOGGLE(&led1);
       }
       __delay_ms(500); 
       ret = GPIO_LED_TURN_OFF(&led2);
       ret = GPIO_LED_TURN_ON(&led3);
       __delay_ms(2000);
       ret = GPIO_LED_TURN_TOGGLE(&led4);
    }

    return (EXIT_SUCCESS);
}

void application_init(void){
    ret = GPIO_LED_INIT(&led1);
    ret = GPIO_LED_INIT(&led2);
    ret = GPIO_LED_INIT(&led3);
    ret = GPIO_LED_INIT(&led4);

}