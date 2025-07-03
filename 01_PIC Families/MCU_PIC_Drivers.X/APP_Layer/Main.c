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
    .pin.PIN = GPIO_PIN0,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW
};

GPIO_LED led2 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN = GPIO_PIN1,
    .pin.DIRECTION = GPIO_OUTPUT,
    .pin.LOGIC = GPIO_LOW
};

GPIO_BTN btn1 = {
    .pin.PORT = GPIO_PORTC,
    .pin.PIN = GPIO_PIN2,
    .pin.DIRECTION = GPIO_INPUT,
    .pin.LOGIC = GPIO_LOW,
    .connection = BTN_ACTIVE_HIGH,
    .state = BTN_RELEASED
};

GPIO_BTN btn2 = {
    .pin.PORT = GPIO_PORTD,
    .pin.PIN = GPIO_PIN0,
    .pin.DIRECTION = GPIO_INPUT,
    .pin.LOGIC = GPIO_HIGH,
    .connection = BTN_ACTIVE_LOW,
    .state = BTN_RELEASED
};

BTN_STATE state1 = BTN_RELEASED;
BTN_STATE state2 = BTN_RELEASED;

GPIO_LOGIC lg = GPIO_LOW;

Std_ReturnType Ret = E_OK;

uint32 counter = 0;
BTN_STATE press_state = BTN_RELEASED;
BTN_STATE last_press_state = BTN_RELEASED;

LED_LOGIC lelog;

uint8 incremental;

int main() {
    application_init();
    while (1) {
        Ret = GPIO_BTN_READ_STATE(&btn1, &state1);
        Ret = GPIO_BTN_READ_STATE(&btn2, &state2);
        // APP1
        //        if(BTN_PRESSED == state1){
        //            Ret = GPIO_LED_TURN_ON(&led1);
        //        }
        //        else{
        //            
        //        }
        //        
        //        if(BTN_PRESSED == state2){
        //            Ret = GPIO_LED_TURN_OFF(&led1);
        //        }
        //        else{
        //        }

        //APP2
//        if (BTN_PRESSED == state1) {
//            lg ^= 0x01;
//            if(lg == GPIO_HIGH){
//                Ret = GPIO_LED_TURN_ON(&led1);
//            }
//            else{
//                Ret = GPIO_LED_TURN_OFF(&led1);
//            }
//        }
        
        //APP3
//        if (BTN_PRESSED == state1) {
//            counter++;
//            if(counter >= 500){
//                press_state = BTN_PRESSED;
//            }
//        }
//        else{
//            counter = 0;
//            press_state = BTN_RELEASED;
//        }
//        if(press_state != last_press_state){
//            last_press_state == press_state;
//            if(press_state == BTN_PRESSED){
//                Ret = GPIO_LED_READ_LOGIC(&led1, &lelog);
//                if(lelog == LED_OFF){
//                    Ret = GPIO_LED_TURN_ON(&led1);
//                    lelog = LED_ON;
//                }
//                else{
//                    Ret = GPIO_LED_TURN_OFF(&led1);
//                    lelog = LED_OFF;
//                }
//            }
//        }
        
        //APP4
        if (BTN_PRESSED == state1) {
            counter++;
            if(counter >= 500){
                press_state = BTN_PRESSED;
            }
        }
        else{
            counter = 0;
            press_state = BTN_RELEASED;
        }
        if(press_state != last_press_state){
            last_press_state == press_state;
            if(press_state == BTN_PRESSED){
                incremental++;
            }
        }

    }

    return (EXIT_SUCCESS);
}

void application_init(void) {
    Ret = GPIO_LED_INIT(&led1);
    Ret = GPIO_LED_INIT(&led2);
    Ret = GPIO_BTN_INIT(&btn1);
    Ret = GPIO_BTN_INIT(&btn2);
}