 ///*
// * File:   main.c
// * Author: mohammedel-ahmady
// *
// * Created on June 26, 2025, 7:24 PM
// */
//

#include "Main.h"

void tmr2_app_isr(void);

GPIO_Led led1 = {.pin.Port = GPIO_PortC, .pin.Pin = GPIO_Pin0, .pin.Direction = GPIO_Output, .connection = Led_Source, .state = Led_Off};

Timer2_CFG tim2_timer = {
    .timer2_interrupt = tmr2_app_isr,
    .mode = Timer2_Normal_Mode,
    .com_mode = Timer2_COM_Mode_OC2_Disable,
    .prescaler = Timer2_Prescaler_DIV_1024,
    .preloaded_value = 95
};

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    
    Application_Init();
    
    while (1) {
    }
    return EXIT_SUCCESS;
}

void Application_Init(void) {
    Ecual_Init();
    GPIO_Led_INIT(&led1);
    Timer2_INIT(&tim2_timer);
}

void tmr2_app_isr(void){
    GPIO_Led_Turn_Toggle(&led1);
}