/* 
 * File:   i2c.c
 * Author: mohammedel-ahmady
 *
 * Created on October 17, 2025
 */

#include "i2c.h"

/******************* Section 1 : Local Variables *******************/

static I2C_Callback_t I2C_OnReceive = 0;
static I2C_Callback_t I2C_OnTransmit = 0;

/******************* Section 2 : Local ISR Handler *******************/

/**
 * @brief Internal ISR for I2C (MSSP) ? called from global interrupt manager.
 */
static void I2C_ISR(void)
{
    // Address + Write ? Master writing data to slave
    if (!SSPSTATbits.R_W && !SSPSTATbits.D_A)
    {
        volatile uint8 dummy = SSPBUF; // Read to clear buffer
        if (I2C_OnReceive)
            I2C_OnReceive();
    }
    // Address + Read ? Master requesting data
    else if (SSPSTATbits.R_W && !SSPSTATbits.D_A)
    {
        if (I2C_OnTransmit)
            I2C_OnTransmit();
    }

    SSPCON1bits.CKP = 1; // Release clock
}

/******************* Section 3 : Function Definitions *******************/

void I2C_Init(I2C_Mode_t mode, uint8 slaveAddress)
{
    TRISCbits.TRISC3 = 1; // SCL
    TRISCbits.TRISC4 = 1; // SDA
    
    SSPCON1 = 0x00;
    SSPCON2 = 0x00;
    SSPSTAT = 0x00;

    if (mode == I2C_MODE_MASTER)
    {
        SSPCON1bits.SSPM = 0b1000;   // I2C Master mode
        SSPADD = I2C_BAUD;           // Baud rate
        SSPSTATbits.SMP = 1;         // Standard mode (100kHz)
    }
    else
    {
        SSPCON1bits.SSPM = 0b0110;   // I2C Slave mode (7-bit)
        SSPADD = (slaveAddress << 1);
        SSPSTATbits.SMP = 1;
    }

    SSPCON1bits.SSPEN = 1;           // Enable MSSP module
    PIR1bits.SSPIF = 0;
    PIR2bits.BCLIF = 0;
}

void I2C_EnableInterrupts(I2C_Callback_t onReceive, I2C_Callback_t onTransmit)
{
    // Clear interrupt flags
    PIR1bits.SSPIF = 0;
    PIR2bits.BCLIF = 0;

    // Enable MSSP & Bus Collision interrupts
    PIE1bits.SSPIE = 1;
    PIE2bits.BCLIE = 1;
    
    I2C_OnReceive = onReceive;
    I2C_OnTransmit = onTransmit;

    INTERRUPT_SetMSSPHandler(I2C_ISR);
    INTERRUPT_Init();
}

void I2C_DisableInterrupts(void)
{
    PIE1bits.SSPIE = 0;
    PIE2bits.BCLIE = 0;
}

void I2C_Start(void)
{
    SSPCON2bits.SEN = 1;           // Initiate start condition
    while (SSPCON2bits.SEN);       // Wait until completed
}

void I2C_Stop(void)
{
    SSPCON2bits.PEN = 1;           // Initiate stop condition
    while (SSPCON2bits.PEN);       // Wait until completed
}

void I2C_WriteByte(uint8 data)
{
    SSPBUF = data;                 // Load data
//    while (SSPSTATbits.BF);        // Wait until buffer is empty
    while (SSPCON2bits.ACKSTAT);   // Wait for ACK from slave
}

uint8 I2C_ReadByte(boolean ack)
{
    SSPCON2bits.RCEN = 1;          // Enable receive
//    while (!SSPSTATbits.BF);       // Wait until data received
    uint8 data = SSPBUF;           // Read received data

    SSPCON2bits.ACKDT = (ack == 0); // 0=ACK, 1=NACK
    SSPCON2bits.ACKEN = 1;         // Send ACK/NACK
    while (SSPCON2bits.ACKEN);     // Wait for completion

    return data;
}


uint8 I2C_ReadByteRegister(uint8 slaveAddress, uint8 reg)
{
    uint8 data;

    // Write phase: send register address
    I2C_Start();
    I2C_WriteByte((slaveAddress << 1) | 0); // Write mode
    I2C_WriteByte(reg);

    // Read phase
    I2C_Start();
    I2C_WriteByte((slaveAddress << 1) | 1); // Read mode
    data = I2C_ReadByte(0); // NACK after single byte

    I2C_Stop();

    return data;
}


void I2C_WriteFrame(uint8 slaveAddress, uint8 *data, uint8 length)
{
    I2C_Start();
    I2C_WriteByte((slaveAddress << 1) | 0); // 0 = Write
    for (uint8 i = 0; i < length; i++)
        I2C_WriteByte(data[i]);
    I2C_Stop();
}

void I2C_ReadFrame(uint8 slaveAddress, uint8 *data, uint8 length)
{
    I2C_Start();
    I2C_WriteByte((slaveAddress << 1) | 1); // 1 = Read
    for (uint8 i = 0; i < length; i++)
        data[i] = I2C_ReadByte(i < (length - 1)); // ACK for all except last byte
    I2C_Stop();
}