/* 
 * File:   eusart.h
 * Author: mohammedel-ahmady
 * 
 * Created on October 17, 2025
 */

#ifndef EUSART_H
#define	EUSART_H

/******************* Section 1 : Includes *******************/
#include "../Platform.h"

/******************* Section 2 : Function Prototypes *******************/

/**
 * @brief Initialize the EUSART module.
 * Configures:
 *   - Asynchronous Mode
 *   - 8-bit Transmit / 8-bit Receive
 *   - Baud Rate: 9600 (Fosc = 16MHz)
 */
void EUSART_Init(void);

/**
 * @brief Send one byte via EUSART.
 * @param data 8-bit data to transmit.
 */
void EUSART_WriteByte(uint8 data);

void EUSART_WriteString(uint8 *str);

/**
 * @brief Read one byte from EUSART (blocking).
 * Waits until a byte is received.
 * @return Received 8-bit data.
 */
uint8 EUSART_ReadByte(void);

/**
 * @brief Check if new data is available in RX buffer.
 * @return TRUE if data is ready, otherwise FALSE.
 */
boolean EUSART_DataReady(void);

#endif	/* EUSART_H */