/*
 * File:   main.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 7:24 PM
 */

#include "main.h"

const uint8 Battery[5][8] = {{0x0E, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x00},
                             {0x0E, 0x1F, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x00},
                             {0x0E, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x00},
                             {0x0E, 0x1F, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00},
                             {0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00}};

uint8 str1[],str2[];

int main(void) {
    Std_ReturnType ret = E_NOT_OK;
    Application_Init();
//    ret = GPIO_Chr_Lcd_4Bit_Send_Character(&lcd1, 'C');
//    ret = GPIO_Chr_Lcd_8Bit_Send_Character(&lcd2, 'C');
//    
//    ret = GPIO_Chr_Lcd_4Bit_Send_Character_Pos(&lcd1, 'M', 2, 8);
//    ret = GPIO_Chr_Lcd_8Bit_Send_Character_Pos(&lcd2, 'M', 2, 8);
//    
//    _delay_ms(1000);
//    ret = GPIO_Chr_Lcd_4Bit_Send_String_Pos(&lcd1, "Mohamed", 1, 1);
//    ret = GPIO_Chr_Lcd_8Bit_Send_String_Pos(&lcd2, "Mohamed", 1, 1);
//    
//    ret = GPIO_Chr_Lcd_4Bit_Send_String_Pos(&lcd1, "Ghareeb ", 2, 8);
//    ret = GPIO_Chr_Lcd_8Bit_Send_String_Pos(&lcd2, "Ghareeb ", 2, 8);
//
//    ret = GPIO_Chr_Lcd_4Bit_Send_String(&lcd1, "Mohamed");
//    ret = GPIO_Chr_Lcd_8Bit_Send_String(&lcd2, "Mohamed");
//
//    _delay_ms(1000);
//    ret = GPIO_Chr_Lcd_4Bit_Send_Command(&lcd1, 0x01);
//    ret = GPIO_Chr_Lcd_8Bit_Send_Command(&lcd2, 0x01);
    while (1) {
        
        for(uint8 i = 0; i < 5 ;i++){
            GPIO_Chr_Lcd_4Bit_Send_Custom_Character(&lcd1, Battery[i], 1, 20, 0);
            GPIO_Chr_Lcd_8Bit_Send_Custom_Character(&lcd2, Battery[i], 1, 20, 0);
            _delay_ms(250);
        }
        ret = GPIO_Chr_Lcd_4Bit_Send_Command(&lcd1, 0x01);
        ret = GPIO_Chr_Lcd_8Bit_Send_Command(&lcd2, 0x01);
        _delay_ms(1000);
        Convert_Byte_To_String(33,str1);
        ret = GPIO_Chr_Lcd_4Bit_Send_String_Pos(&lcd1, str1, 2, 8);
        Convert_Short_To_String(550,str2);
        ret = GPIO_Chr_Lcd_8Bit_Send_String_Pos(&lcd2, str2, 2, 8);
        _delay_ms(1000);
    }

    return EXIT_SUCCESS;
}

void Application_Init(void){
    Ecual_Init();
}
