/* 
 * File:   main.c
 * Author: mohammedel-ahmady
 *
 * Created on June 22, 2025, 8:05 PM
 */

#include "main.h"

rtc_t rtc_main;

uint8 data = 0;

gpio_pin_t led = {
    .port = GPIO_PORTC_INDEX,
    .pin = 0,
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW
};

int main() {
    
    System_Init();
//    EUSART_WriteByte('A');
//            EUSART_WriteString("The Time = ");

    while(1){
        rtc_main = RTC_DS1307_Get_Date_Time();
        EUSART_WriteString("The Time = ");
        EUSART_WriteByte((rtc_main.Hrs / 10) + '0');
        EUSART_WriteByte((rtc_main.Hrs % 10) + '0');
        EUSART_WriteString(" : ");
        EUSART_WriteByte((rtc_main.Min / 10) + '0');
        EUSART_WriteByte((rtc_main.Min % 10) + '0');
        EUSART_WriteString(" : ");
        EUSART_WriteByte((rtc_main.Sec / 10) + '0');
        EUSART_WriteByte((rtc_main.Sec % 10) + '0');
        EUSART_WriteByte('\r');
        EUSART_WriteString("The Date = ");
        EUSART_WriteByte((rtc_main.Year / 10) + '0');
        EUSART_WriteByte((rtc_main.Year % 10) + '0');
        EUSART_WriteString(" : ");
        EUSART_WriteByte((rtc_main.Month / 10) + '0');
        EUSART_WriteByte((rtc_main.Month % 10) + '0');
        EUSART_WriteString(" : "); 
        EUSART_WriteByte((rtc_main.Day / 10) + '0');
        EUSART_WriteByte((rtc_main.Day % 10) + '0');
        EUSART_WriteByte('\r');
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

void System_Init(void){
    EUSART_Init();
    INTERRUPT_Init();
    I2C_Init(I2C_MODE_MASTER, 0x00);
}

void EEPROM_24C02C_Write_Byte(uint8 slave_add, uint8 byte_add, uint8 data){}
uint8  EEPROM_24C02C_Read_Byte(uint8 slave_add, uint8 byte_add){}