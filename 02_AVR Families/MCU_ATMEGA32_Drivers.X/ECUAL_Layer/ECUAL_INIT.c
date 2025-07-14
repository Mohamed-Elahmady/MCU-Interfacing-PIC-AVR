/* 
 * File:   ECUAL_INIT.c
 * Author: mohammedel-ahmady
 *
 * Created on July 14, 2025, 12:30 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_INIT.h"

/******************* Section 1 :  Variables Definitions *******************/

GPIO_Keypad keypad1 = {
    .Row_Pins[0].Port = GPIO_PortC,
    .Row_Pins[0].Pin = GPIO_Pin0,
    .Row_Pins[0].Direction = GPIO_Output,
    .Row_Pins[0].Logic = GPIO_Low,

    .Row_Pins[1].Port = GPIO_PortC,
    .Row_Pins[1].Pin = GPIO_Pin1,
    .Row_Pins[1].Direction = GPIO_Output,
    .Row_Pins[1].Logic = GPIO_Low,

    .Row_Pins[2].Port = GPIO_PortC,
    .Row_Pins[2].Pin = GPIO_Pin2,
    .Row_Pins[2].Direction = GPIO_Output,
    .Row_Pins[2].Logic = GPIO_Low,

    .Row_Pins[3].Port = GPIO_PortC,
    .Row_Pins[3].Pin = GPIO_Pin3,
    .Row_Pins[3].Direction = GPIO_Output,
    .Row_Pins[3].Logic = GPIO_Low,

    .Col_Pins[0].Port = GPIO_PortC,
    .Col_Pins[0].Pin = GPIO_Pin4,
    .Col_Pins[0].Direction = GPIO_Input,

    .Col_Pins[1].Port = GPIO_PortC,
    .Col_Pins[1].Pin = GPIO_Pin5,
    .Col_Pins[1].Direction = GPIO_Input,

    .Col_Pins[2].Port = GPIO_PortC,
    .Col_Pins[2].Pin = GPIO_Pin6,
    .Col_Pins[2].Direction = GPIO_Input,

    .Col_Pins[3].Port = GPIO_PortC,
    .Col_Pins[3].Pin = GPIO_Pin7,
    .Col_Pins[3].Direction = GPIO_Input
};

GPIO_Led led1 = {
    .pin.Port = GPIO_PortD,
    .pin.Pin = GPIO_Pin0,
    .pin.Direction = GPIO_Output,
    .pin.Logic = GPIO_Low,
    .connection = Led_Source,
    .state = Led_Off
};

/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

void Ecual_Init(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = GPIO_Keypad_INIT(&keypad1);
    ret = GPIO_Led_INIT(&led1);
}

/******************* Section 4:  Helper Functions Definitions *******************/
