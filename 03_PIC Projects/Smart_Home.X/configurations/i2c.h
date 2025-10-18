/* 
 * File:   i2c.h
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#ifndef I2C_H
#define I2C_H

#include "../Platform.h"
#include "interrupts.h"
#include <xc.h>

/******************* Section 1 : Configuration *******************/

#define _XTAL_FREQ     16000000UL
#define I2C_BAUD       (((_XTAL_FREQ / (4UL * 100000UL)) - 1))  // 100kHz

/******************* Section 2 : User Defined Data Types *******************/

/**
 * @brief I2C operating modes
 */
typedef enum
{
    I2C_MODE_MASTER = 0,
    I2C_MODE_SLAVE
} I2C_Mode_t;

/**
 * @brief I2C event callback type
 */
typedef void (*I2C_Callback_t)(void);

/******************* Section 3 : Function Prototypes *******************/

/**
 * @brief Initialize I2C peripheral as Master or Slave.
 * @param mode Select Master or Slave mode.
 * @param slaveAddress Used only in slave mode.
 */
void I2C_Init(I2C_Mode_t mode, uint8 slaveAddress);

/**
 * @brief Enable I2C interrupts and assign user callbacks.
 */
void I2C_EnableInterrupts(I2C_Callback_t onReceive, I2C_Callback_t onTransmit);

/**
 * @brief Disable I2C interrupts.
 */
void I2C_DisableInterrupts(void);

/**
 * @brief Generate Start condition (Master mode only)
 */
void I2C_Start(void);

/**
 * @brief Generate Stop condition (Master mode only)
 */
void I2C_Stop(void);

/**
 * @brief Write a single byte on I2C bus.
 */
void I2C_WriteByte(uint8 data);

/**
 * @brief Read a single byte from I2C bus.
 * @param ack 1 = ACK, 0 = NACK
 * @return Byte received
 */
uint8 I2C_ReadByte(boolean ack);



uint8 I2C_ReadByteRegister(uint8 slaveAddress, uint8 reg);

/**
 * @brief Transmit multiple bytes as a frame.
 */
void I2C_WriteFrame(uint8 slaveAddress, uint8 *data, uint8 length);

/**
 * @brief Receive multiple bytes as a frame.
 */
void I2C_ReadFrame(uint8 slaveAddress, uint8 *data, uint8 length);

#endif /* I2C_H */