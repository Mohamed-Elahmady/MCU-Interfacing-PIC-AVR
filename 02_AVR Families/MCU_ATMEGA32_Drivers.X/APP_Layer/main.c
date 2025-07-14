/*
 * File:   main.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 7:24 PM
 */

#include "main.h"

uint8 data = 0;

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    Application_Init();
    while (1) {
        ret = GPIO_Keypad_Read_Data(&keypad1, &data);
        
        if(data == '3'){
            ret = GPIO_Led_Turn_On(&led1);
        }
        else if(data == '6'){
            ret = GPIO_Led_Turn_On(&led1);
        }
        else{
            ret = GPIO_Led_Turn_Off(&led1);
        }
        
    }

    return EXIT_SUCCESS;
}

void Application_Init(void){
    Ecual_Init();
}