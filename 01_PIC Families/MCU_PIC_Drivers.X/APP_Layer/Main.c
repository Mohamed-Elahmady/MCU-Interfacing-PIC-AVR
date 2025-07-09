/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

#define _XTAL_FREQ                       8000000UL


Std_ReturnType Ret = E_OK;

GPIO_SEGMENT seg1 = {
    .pins[0].PORT = GPIO_PORTC,
    .pins[0].PIN = GPIO_PIN0,
    .pins[0].DIRECTION = GPIO_OUTPUT,
    .pins[0].LOGIC = GPIO_LOW,

    .pins[1].PORT = GPIO_PORTC,
    .pins[1].PIN = GPIO_PIN1,
    .pins[1].DIRECTION = GPIO_OUTPUT,
    .pins[1].LOGIC = GPIO_LOW,
    
    .pins[2].PORT = GPIO_PORTC,
    .pins[2].PIN = GPIO_PIN2,
    .pins[2].DIRECTION = GPIO_OUTPUT,
    .pins[2].LOGIC = GPIO_LOW,

    .pins[3].PORT = GPIO_PORTC,
    .pins[3].PIN = GPIO_PIN3,
    .pins[3].DIRECTION = GPIO_OUTPUT,
    .pins[3].LOGIC = GPIO_LOW,
    
    .connection = SEGMENT_COMMON_ANODE 
};

//GPIO_SEGMENT seg2 = {
//    .pins[0].PORT = GPIO_PORTD,
//    .pins[0].PIN = GPIO_PIN0,
//    .pins[0].DIRECTION = GPIO_OUTPUT,
//    .pins[0].LOGIC = GPIO_LOW,
//
//    .pins[1].PORT = GPIO_PORTD,
//    .pins[1].PIN = GPIO_PIN1,
//    .pins[1].DIRECTION = GPIO_OUTPUT,
//    .pins[1].LOGIC = GPIO_LOW,
//    
//    .pins[2].PORT = GPIO_PORTD,
//    .pins[2].PIN = GPIO_PIN2,
//    .pins[2].DIRECTION = GPIO_OUTPUT,
//    .pins[2].LOGIC = GPIO_LOW,
//
//    .pins[3].PORT = GPIO_PORTD,
//    .pins[3].PIN = GPIO_PIN3,
//    .pins[3].DIRECTION = GPIO_OUTPUT,
//    .pins[3].LOGIC = GPIO_LOW,
//    
//    .connection = SEGMENT_COMMON_CATHODE
//};

GPIO_PIN_CFG pin1 ={
    .PORT = GPIO_PORTD,
    .PIN = GPIO_PIN0,
    .DIRECTION = GPIO_OUTPUT,
    .LOGIC = GPIO_LOW
};

GPIO_PIN_CFG pin2 ={
    .PORT = GPIO_PORTD,
    .PIN = GPIO_PIN1,
    .DIRECTION = GPIO_OUTPUT,
    .LOGIC = GPIO_LOW
};

uint8 number = 32;

uint8 data1,data2;

int main() {
    application_init();
    while (1) {
        for(uint8 i = 0; i < 50; i++){
            
            Ret = GPIO_PIN_WRITE_LOGIC(&pin2, GPIO_HIGH);
            Ret = GPIO_SEGMENT_WRITE_NUMBER(&seg1, number%10);
            Ret = GPIO_SEGMENT_READ_NUMBER(&seg1, &data1);
            __delay_ms(10);
            Ret = GPIO_PIN_WRITE_LOGIC(&pin2, GPIO_LOW);
            Ret = GPIO_PIN_WRITE_LOGIC(&pin1, GPIO_HIGH);
            Ret = GPIO_SEGMENT_WRITE_NUMBER(&seg1, number/10);
            Ret = GPIO_SEGMENT_READ_NUMBER(&seg1, &data2);
            __delay_ms(10);
            Ret = GPIO_PIN_WRITE_LOGIC(&pin1, GPIO_LOW);
        }
        number++;
        if(number >= 100){
            number = 0;
        }
    }
        
    return (EXIT_SUCCESS);
}

void application_init(void) {
    Ret = GPIO_SEGMENT_INIT(&seg1);
//    Ret = GPIO_SEGMENT_INIT(&seg2);
    Ret = GPIO_PIN_INIT(&pin1);
    Ret = GPIO_PIN_INIT(&pin2);
}