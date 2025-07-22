/* 
 * File:   ECUAL_INIT.c
 * Author: mohammedel-ahmady
 *
 * Created on July 14, 2025, 12:30 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_INIT.h"

/******************* Section 1 :  Variables Definitions *******************/


/******************* Section 2 :  Helper Functions Declarations *******************/

Chr_Lcd_4Bit lcd1 = {
    .Rs_Pin.Port = GPIO_PortB,
    .Rs_Pin.Pin = GPIO_Pin0,
    .Rs_Pin.Direction = GPIO_Output,
    .Rs_Pin.Logic = GPIO_Low,

    .Rw_Pin.Port = GPIO_PortB,
    .Rw_Pin.Pin = GPIO_Pin1,
    .Rw_Pin.Direction = GPIO_Output,
    .Rw_Pin.Logic = GPIO_Low,

    .En_Pin.Port = GPIO_PortB,
    .En_Pin.Pin = GPIO_Pin2,
    .En_Pin.Direction = GPIO_Output,
    .En_Pin.Logic = GPIO_Low,

    .Data_Pins[0].Port = GPIO_PortC,
    .Data_Pins[0].Pin = GPIO_Pin0,
    .Data_Pins[0].Direction = GPIO_Output,
    .Data_Pins[0].Logic = GPIO_Low,

    .Data_Pins[1].Port = GPIO_PortC,
    .Data_Pins[1].Pin = GPIO_Pin1,
    .Data_Pins[1].Direction = GPIO_Output,
    .Data_Pins[1].Logic = GPIO_Low,

    .Data_Pins[2].Port = GPIO_PortC,
    .Data_Pins[2].Pin = GPIO_Pin2,
    .Data_Pins[2].Direction = GPIO_Output,
    .Data_Pins[2].Logic = GPIO_Low,

    .Data_Pins[3].Port = GPIO_PortC,
    .Data_Pins[3].Pin = GPIO_Pin3,
    .Data_Pins[3].Direction = GPIO_Output,
    .Data_Pins[3].Logic = GPIO_Low
};

Chr_Lcd_8Bit lcd2 = {
    .Rs_Pin.Port = GPIO_PortB,
    .Rs_Pin.Pin = GPIO_Pin3,
    .Rs_Pin.Direction = GPIO_Output,
    .Rs_Pin.Logic = GPIO_Low,

    .Rw_Pin.Port = GPIO_PortB,
    .Rw_Pin.Pin = GPIO_Pin4,
    .Rw_Pin.Direction = GPIO_Output,
    .Rw_Pin.Logic = GPIO_Low,

    .En_Pin.Port = GPIO_PortB,
    .En_Pin.Pin = GPIO_Pin5,
    .En_Pin.Direction = GPIO_Output,
    .En_Pin.Logic = GPIO_Low,

    .Data_Pins[0].Port = GPIO_PortD,
    .Data_Pins[0].Pin = GPIO_Pin0,
    .Data_Pins[0].Direction = GPIO_Output,
    .Data_Pins[0].Logic = GPIO_Low,

    .Data_Pins[1].Port = GPIO_PortD,
    .Data_Pins[1].Pin = GPIO_Pin1,
    .Data_Pins[1].Direction = GPIO_Output,
    .Data_Pins[1].Logic = GPIO_Low,

    .Data_Pins[2].Port = GPIO_PortD,
    .Data_Pins[2].Pin = GPIO_Pin2,
    .Data_Pins[2].Direction = GPIO_Output,
    .Data_Pins[2].Logic = GPIO_Low,

    .Data_Pins[3].Port = GPIO_PortD,
    .Data_Pins[3].Pin = GPIO_Pin3,
    .Data_Pins[3].Direction = GPIO_Output,
    .Data_Pins[3].Logic = GPIO_Low,
    
    .Data_Pins[4].Port = GPIO_PortD,
    .Data_Pins[4].Pin = GPIO_Pin4,
    .Data_Pins[4].Direction = GPIO_Output,
    .Data_Pins[4].Logic = GPIO_Low,

    .Data_Pins[5].Port = GPIO_PortD,
    .Data_Pins[5].Pin = GPIO_Pin5,
    .Data_Pins[5].Direction = GPIO_Output,
    .Data_Pins[5].Logic = GPIO_Low,

    .Data_Pins[6].Port = GPIO_PortD,
    .Data_Pins[6].Pin = GPIO_Pin6,
    .Data_Pins[6].Direction = GPIO_Output,
    .Data_Pins[6].Logic = GPIO_Low,

    .Data_Pins[7].Port = GPIO_PortD,
    .Data_Pins[7].Pin = GPIO_Pin7,
    .Data_Pins[7].Direction = GPIO_Output,
    .Data_Pins[7].Logic = GPIO_Low
};

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

void Ecual_Init(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = GPIO_Chr_Lcd_4Bit_INIT(&lcd1);
    ret = GPIO_Chr_Lcd_8Bit_INIT(&lcd2);
}

/******************* Section 4:  Helper Functions Definitions *******************/
