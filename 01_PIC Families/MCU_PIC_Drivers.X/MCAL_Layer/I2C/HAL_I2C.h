/* 
 * File:   HAL_I2C.h
 * Author: mohammedel-ahmady
 *
 * Created on October 5, 2025, 12:40 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_I2C_H
#define	HAL_I2C_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_I2C_CFG.h"
#include "../GPIO/HAL_GPIO.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define I2C_MASTER_ACK_RECEIVED                            (uint8)0x00
#define I2C_MASTER_ACK_NOT_RECEIVED                        (uint8)0x01
#define I2C_MASTER_SEND_ACK                                (uint8)0x00
#define I2C_MASTER_SEND_NACK                               (uint8)0x01

/******************* Section 3 : Macros Functions Declarations *******************/

// Macros For I2C Frame Initialization

#define I2C_MODULE_DISABLE()                                CLEAR_BIT(SSPCON1, _SSPCON1_SSPEN_POSITION)
#define I2C_MODULE_ENABLE()                                 SET_BIT(SSPCON1, _SSPCON1_SSPEN_POSITION)

#define I2C_SET_MODE_CFG(__CONFIG)                          (SSPCON1bits.SSPM = (__CONFIG & 0x0F))

#define I2C_SLEW_RATE_DISABLE_100KHZ()                      SET_BIT(SSPSTAT, _SSPSTAT_SMP_POSITION)
#define I2C_SLEW_RATE_ENABLE_400KHZ()                       CLEAR_BIT(SSPSTAT, _SSPSTAT_SMP_POSITION)

#define I2C_SMBUS_DISABLE_SPECIFIC_INPUT()                  CLEAR_BIT(SSPSTAT, _SSPSTAT_CKE_POSITION)
#define I2C_SMBUS_ENABLE_SPECIFIC_INPUT()                   SET_BIT(SSPSTAT, _SSPSTAT_CKE_POSITION)

// Receiving Configuration Used only when u receive data not transmit
#define I2C_MASTER_RECEIVE_DISABLE()                        CLEAR_BIT(SSPCON2, _SSPCON2_RCEN_POSITION)
#define I2C_MASTER_RECEIVE_ENABLE()                         SET_BIT(SSPCON2, _SSPCON2_RCEN_POSITION)

#define I2C_SLAVE_GENERAL_CALL_DISABLE()                    CLEAR_BIT(SSPCON2, _SSPCON2_GCEN_POSITION)
#define I2C_SLAVE_GENERAL_CALL_ENABLE()                     SET_BIT(SSPCON2, _SSPCON2_GCEN_POSITION)

// Macros For I2C Frame Data

// Start Condition bit will be automatically '0'=> after sending
#define I2C_MASTER_SENDING_START_CONDITION_STATE()          READ_BIT(SSPCON2, _SSPCON2_SEN_POSITION)
// Stop Condition bit will be automatically '0'=> after sending
#define I2C_MASTER_SENDING_STOP_CONDITION_STATE()           READ_BIT(SSPCON2, _SSPCON2_PEN_POSITION)
// Repeated Start Condition bit will be automatically '0'=> after sending
#define I2C_MASTER_SENDING_REPEATED_START_CONDITION_STATE() READ_BIT(SSPCON2, _SSPCON2_RSEN_POSITION)

// Start condition not detected '0' or Detected '1' 
#define I2C_MASTER_START_CONDITION_DETECTION()              READ_BIT(SSPSTAT, _SSPSTAT_S_POSITION)
// Stop condition not detected '0' or Detected '1'
#define I2C_MASTER_STOP_CONDITION_DETECTION()               READ_BIT(SSPSTAT, _SSPSTAT_P_POSITION)
// Received Data is Address '0' or Data '1' 
#define I2C_SLAVE_RECEIVED_DATA_TYPE()                      READ_BIT(SSPSTAT, _SSPSTAT_D_A_POSITION)
 
// When the flag is set that mean 1 Byte was completely transmitted
#define I2C_TRANSMISSION_STATUS()                           READ_BIT(PIR1, _PIR1_SSPIF_POSITION)
// Read ACK Bit from Slave '1' => ACK Was Not Received, '0' => ACK Was Received
#define I2C_MASTER_ACKNOWLEDGE_STATUS()                     READ_BIT(SSPCON2, _SSPCON2_ACKSTAT_POSITION)
// When the buffer flag is set that mean 1 Byte was completely received
#define I2C_RECEIVING_STATUS()                              READ_BIT(SSPSTAT, _SSPSTAT_BF_POSITION)
// if Write Collision flag happened '1' else '0'
#define I2C_MASTER_SLAVE_READ_COLLISION_STATUS()            READ_BIT(SSPCON1, _SSPCON1_WCOL_POSITION)
// if Receive Over flow flag happened '1' else '0'
#define I2C_MASTER_SLAVE_READ_OVERFLOW_STATUS()             READ_BIT(SSPCON1, _SSPCON1_SSPOV_POSITION)

#define I2C_MASTER_SLAVE_CLEAR_COLLISION()                  CLEAR_BIT(SSPCON1, _SSPCON1_WCOL_POSITION)
#define I2C_MASTER_SLAVE_CLEAR_OVERFLOW()                   CLEAR_BIT(SSPCON1, _SSPCON1_SSPOV_POSITION)

// master start condition cleared by hardware
#define I2C_MASTER_TRANSMIT_START_CONDITION()               SET_BIT(SSPCON2, _SSPCON2_SEN_POSITION)
#define I2C_MASTER_TRANSMIT_STOP_CONDITION()                SET_BIT(SSPCON2, _SSPCON2_PEN_POSITION)
#define I2C_MASTER_TRANSMIT_REPEATED_START_CONDITION()      SET_BIT(SSPCON2, _SSPCON2_RSEN_POSITION)
#define I2C_MASTER_INITIATE_ACKNOWLEDGMENT_ENABLE()         SET_BIT(SSPCON2, _SSPCON2_ACKEN_POSITION)

#define I2C_MASTER_TRANSMIT_ACKNOWLEDGE()                   CLEAR_BIT(SSPCON2, _SSPCON2_ACKDT_POSITION)
#define I2C_MASTER_TRANSMIT_NOT_ACKNOWLEDGE()               SET_BIT(SSPCON2, _SSPCON2_ACKDT_POSITION)

#define I2C_SLAVE_CLOCK_STRETCHING_DISABLE()                CLEAR_BIT(SSPCON2, _SSPCON2_SEN_POSITION)
#define I2C_SLAVE_CLOCK_STRETCHING_ENABLE()                 SET_BIT(SSPCON2, _SSPCON2_SEN_POSITION)

#define I2C_SLAVE_HOLD_CLOCK_STRETCHING()                   CLEAR_BIT(SSPCON1, _SSPCON1_CKP_POSITION)
#define I2C_SLAVE_RELEASE_CLOCK_STRETCHING()                SET_BIT(SSPCON1, _SSPCON1_CKP_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (*I2C_HANDLER)(void);

typedef enum{
    I2C_SLAVE_MODE = (uint8)0x00,
    I2C_MASTER_MODE
}I2C_MODE;

typedef enum{
    I2C_SLAVE_MODE_7BIT_ADD = (uint8)0x06,
    I2C_SLAVE_MODE_10BIT_ADD,
    I2C_MASTER_MODE_CLK,
    I2C_MASTER_MODE_FIRMWARE = (uint8)0x0B,
    I2C_SLAVE_MODE_7BIT_ADD_SP_INTERRUPTS = (uint8)0x0E,
    I2C_SLAVE_MODE_10BIT_ADD_SP_INTERRUPTS
}I2C_MODE_CFG;

typedef enum{
    I2C_SLEW_RATE_100KHZ_DISABLE = (uint8)0x00,
    I2C_SLEW_RATE_400KHZ_ENABLE
}I2C_SLEW_RATE;

typedef enum{
    I2C_SMBUS_DISABLE = (uint8)0x00,
    I2C_SMBUS_ENABLE
}I2C_SMBUS;

typedef enum{
    I2C_GENERAL_CALL_DISABLE = (uint8)0x00,
    I2C_GENERAL_CALL_ENABLE
}I2C_SLAVE_GENERAL_CALL_STATE;

typedef enum{
    I2C_RECEIVE_DISABLE = (uint8)0x00,
    I2C_RECEIVE_ENABLE
}I2C_MASTER_RECEIVE_STATE;

typedef struct{
    I2C_MODE                                mode;
    I2C_MODE_CFG                        mode_cfg;
    uint16                         i2c_slave_add;
    I2C_SLEW_RATE                      slew_rate;
    I2C_SMBUS                              smbus;
    I2C_SLAVE_GENERAL_CALL_STATE    general_call;
    I2C_MASTER_RECEIVE_STATE        receive_mode;
}I2C_FRAME_CFG;

typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))
    I2C_HANDLER                 I2C_INTERRUPT;
    I2C_HANDLER             I2C_COL_INTERRUPT;
    I2C_HANDLER             I2C_OVF_INTERRUPT;
    INTERRUPT_PRIORITY           i2c_priority;
    INTERRUPT_PRIORITY           col_priority;
#endif
    uint32                          i2c_clock;
    I2C_FRAME_CFG                   i2c_frame;
}I2C_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType I2C_INIT(const I2C_CFG *i2c);
Std_ReturnType I2C_DEINIT(const I2C_CFG *i2c);

Std_ReturnType I2C_MASTER_SEND_START_CONDITION(const I2C_CFG *i2c);
Std_ReturnType I2C_MASTER_SEND_STOP_CONDITION(const I2C_CFG *i2c); 
Std_ReturnType I2C_MASTER_SEND_REPEATED_START_CONDITION(const I2C_CFG *i2c);

Std_ReturnType I2C_MASTER_WRITE_BYTE_BLOCKING(const I2C_CFG *i2c, uint8 data, uint8 *ack);
Std_ReturnType I2C_MASTER_WRITE_STRING_BLOCKING(const I2C_CFG *i2c, uint8 *str,uint8 *ack);

Std_ReturnType I2C_MASTER_READ_BYTE_BLOCKING(const I2C_CFG *i2c, uint8 *data, uint8 ack); 

Std_ReturnType I2C_MASTER_SEND_FRAME(const I2C_CFG *i2c, uint16 add, uint8 data);

#endif	/* HAL_I2C_H */