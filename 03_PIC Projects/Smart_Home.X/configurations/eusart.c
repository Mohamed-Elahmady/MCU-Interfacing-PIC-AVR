/* 
 * File:   eusart.c
 * Author: mohammedel-ahmady
 * 
 * Created on October 17, 2025
 */

#include <xc.h>
#include "eusart.h"

/**
 * @brief EUSART driver for PIC18F46K20.
 * Configuration: 8-bit TX/RX, 9600 Baud, 16 MHz Crystal.
 *
 * Baud Rate Calculation:
 *   SPBRG = (Fosc / (16 * BaudRate)) - 1
 *   SPBRG = (16,000,000 / (16 * 9600)) - 1 = 103.16 ? use 103
 */

/******************* Section 1 : Initialization *******************/
void EUSART_Init(void)
{
    /* Baud Rate Configuration */
    TXSTAbits.BRGH = 1;      // High speed
    BAUDCONbits.BRG16 = 0;   // 8-bit Baud Rate Generator
    SPBRG = 103;             // Baud rate 9600 @ 16MHz

    /* Transmit Configuration */
    TXSTAbits.SYNC = 0;      // Asynchronous mode
    TXSTAbits.TX9 = 0;       // 8-bit transmission
    TXSTAbits.TXEN = 1;      // Enable Transmit

    /* Receive Configuration */
    RCSTAbits.RX9 = 0;       // 8-bit reception
    RCSTAbits.CREN = 1;      // Enable continuous receive
    RCSTAbits.SPEN = 1;      // Enable serial port (TX/RX pins active)

    /* Pin Directions */
    TRISCbits.TRISC6 = 0;    // TX pin output
    TRISCbits.TRISC7 = 1;    // RX pin input
}

/******************* Section 2 : Write Function *******************/
void EUSART_WriteByte(uint8 data)
{
    while (!PIR1bits.TXIF)   // Wait until TX buffer empty
        ;
    TXREG = data;            // Load data into TX register
}


void EUSART_WriteString(uint8 *str){
    while(*str){
        EUSART_WriteByte(*str);
        str++;
    }
}
/******************* Section 3 : Read Function *******************/
uint8 EUSART_ReadByte(void)
{
    while (!PIR1bits.RCIF)   // Wait until data received
        ;
    return RCREG;            // Return received byte
}

/******************* Section 4 : Status Function *******************/
boolean EUSART_DataReady(void)
{
    return (PIR1bits.RCIF) ? true : false;
}