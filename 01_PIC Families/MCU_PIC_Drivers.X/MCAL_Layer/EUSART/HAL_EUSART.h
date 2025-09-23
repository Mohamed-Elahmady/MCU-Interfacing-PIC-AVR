/* 
 * File:   HAL_EUSART.h
 * Author: mohammedel-ahmady
 *
 * Created on September 18, 2025, 10:20 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EUSART_H
#define	HAL_EUSART_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_EUSART_CFG.h"
#include "../GPIO/HAL_GPIO.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/

#define EUSART_BR_LOW_SPEED                                (uint8)0x00
#define EUSART_BR_HIGH_SPEED                               (uint8)0x01

#define EUSART_ASYNCHRONOUS                                (uint8)0x00
#define EUSART_SYNCHRONOUS                                 (uint8)0x01

#define EUSART_BR_8BIT                                     (uint8)0x00
#define EUSART_BR_16BIT                                    (uint8)0x01

/******************* Section 3 : Macros Functions Declarations *******************/

// EUSART Transmitting Macros Functions

#define EUSART_TX_READ_TSR_STATE()                          READ_BIT(TXSTA, _TXSTA_TRMT_POSITION)

#define EUSART_ASYNC_TX_DISABLE()                           CLEAR_BIT(TXSTA, _TXSTA_TXEN_POSITION)
#define EUSART_ASYNC_TX_ENABLE()                            SET_BIT(TXSTA, _TXSTA_TXEN_POSITION)

#define EUSART_ASYNC_TX_9BIT_DISABLE()                      CLEAR_BIT(TXSTA, _TXSTA_TX9_POSITION)
#define EUSART_ASYNC_TX_9BIT_ENABLE()                       SET_BIT(TXSTA, _TXSTA_TX9_POSITION)

// EUSART Receiving Macros Functions

#define EUSART_RX_READ_RSR_STATE()                          READ_BIT(PIR1, _PIR1_RCIF_POSITION)

#define EUSART_ASYNC_RX_DISABLE()                           CLEAR_BIT(RCSTA, _RCSTA_CREN_POSITION)
#define EUSART_ASYNC_RX_ENABLE()                            SET_BIT(RCSTA, _RCSTA_CREN_POSITION)

#define EUSART_ASYNC_RX_9BIT_DISABLE()                      CLEAR_BIT(RCSTA, _RCSTA_RX9_POSITION)
#define EUSART_ASYNC_RX_9BIT_ENABLE()                       SET_BIT(RCSTA, _RCSTA_RX9_POSITION)

// EUSART Error Handling Macros Functions

#define EUSART_READ_FRAMING_ERROR_STATE                      READ_BIT(RCSTA, _RCSTA_FERR_POSITION)
#define EUSART_READ_OVERRUN_ERROR_STATE                      READ_BIT(RCSTA, _RCSTA_FERR_POSITION)

// EUSART Macros Functions

#define EUSART_MODULE_DISABLE()                             CLEAR_BIT(RCSTA, _RCSTA_SPEN_POSITION)
#define EUSART_MODULE_ENABLE()                              SET_BIT(RCSTA, _RCSTA_SPEN_POSITION)

#define EUSART_ASYNC_LOW_SPEED_BAUD_RATE()                  CLEAR_BIT(TXSTA, _TXSTA_BRGH_POSITION)
#define EUSART_ASYNC_HIGH_SPEED_BAUD_RATE()                 SET_BIT(TXSTA, _TXSTA_BRGH_POSITION)

#define EUSART_ASYNCHRONOUS_MODE()                          CLEAR_BIT(TXSTA, _TXSTA_SYNC_POSITION)
#define EUSART_SYNCHRONOUS_MODE()                           SET_BIT(TXSTA, _TXSTA_SYNC_POSITION)

#define EUSART_BRG_8BIT()                                   CLEAR_BIT(BAUDCON, _BAUDCON_BRG16_POSITION)
#define EUSART_BRG_16BIT()                                  SET_BIT(BAUDCON, _BAUDCON_BRG16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* EUSART_HANDLER)(void);

// EUSART Transmitting enums & data types

typedef enum{
    EUSART_ASYNC_TX_DISABLE_STATE = (uint8)0x00,
    EUSART_ASYNC_TX_ENABLE_STATE
}EUSART_ASYNC_TX_STATE;

typedef enum{
    EUSART_ASYNC_TX_INTERRUPT_DISABLE_STATE = (uint8)0x00,
    EUSART_ASYNC_TX_INTERRUPT_ENABLE_STATE
}EUSART_ASYNC_TX_INTERRUPT_STATE;

typedef enum{
    EUSART_ASYNC_TX_9BIT_SIZE_DISABLE = (uint8)0x00,
    EUSART_ASYNC_TX_9BIT_SIZE_ENABLE
}EUSART_ASYNC_TX_SIZE_STATE;

typedef struct{
    EUSART_HANDLER                         tx_interrupt;
    INTERRUPT_PRIORITY                      tx_priority;
    
    EUSART_ASYNC_TX_STATE                         state;
    EUSART_ASYNC_TX_INTERRUPT_STATE     interrupt_state;
    EUSART_ASYNC_TX_SIZE_STATE                  tx_size;  
}EUSART_TX_CFG;

// EUSART Receiving enums & data types

typedef enum{
    EUSART_ASYNC_RX_DISABLE_STATE = (uint8)0x00,
    EUSART_ASYNC_RX_ENABLE_STATE
}EUSART_ASYNC_RX_STATE;

typedef enum{
    EUSART_ASYNC_RX_INTERRUPT_DISABLE_STATE = (uint8)0x00,
    EUSART_ASYNC_RX_INTERRUPT_ENABLE_STATE
}EUSART_ASYNC_RX_INTERRUPT_STATE;

typedef enum{
    EUSART_ASYNC_RX_9BIT_SIZE_DISABLE = (uint8)0x00,
    EUSART_ASYNC_RX_9BIT_SIZE_ENABLE
}EUSART_ASYNC_RX_SIZE_STATE;

typedef struct{
    EUSART_HANDLER                         rx_interrupt;
    INTERRUPT_PRIORITY                      rx_priority;
    EUSART_HANDLER                    farming_interrupt;
    EUSART_HANDLER                    overrun_interrupt;
    
    EUSART_ASYNC_RX_STATE                         state;
    EUSART_ASYNC_RX_INTERRUPT_STATE     interrupt_state;
    EUSART_ASYNC_RX_SIZE_STATE                  rx_size;  
}EUSART_RX_CFG;

// EUSART Error Handling enums & data types

typedef enum {
    EUSART_FRAMING_ERROR_CLEARED = (uint8)0x00,
    EUSART_FRAMING_ERROR_DETECTED
}EUSART_FRAMING_ERROR;

typedef enum {
    EUSART_OVERRUN_ERROR_CLEARED = (uint8)0x00,
    EUSART_OVERRUN_ERROR_DETECTED
}EUSART_OVERRUN_ERROR;

typedef union{
    struct{
        uint8   EUSART_FARMING_STATE   :1;
        uint8   EUSART_OVERRUN_STATE   :1;
        uint8   EUSART_RESERVED        :6;
    };
    uint8 status;
}EUSART_ERROR_STATUS;

// EUSART enums & data types

typedef enum{
    EUSART_BR_ASYNC_8BIT_LOW_SPEED = (uint8)0x00,
    EUSART_BR_ASYNC_8BIT_HIGH_SPEED,
    EUSART_BR_ASYNC_16BIT_LOW_SPEED,
    EUSART_BR_ASYNC_16BIT_HIGH_SPEED,
    EUSART_BR_SYNC_8BIT,
    EUSART_BR_SYNC_16BIT
}EUSART_BR_CONFIGURATION;

typedef struct{
    EUSART_TX_CFG       eusart_tx_mode;
    EUSART_RX_CFG       eusart_rx_mode;
    EUSART_ERROR_STATUS   error_states;
    
    uint32                   baud_rate;
    EUSART_BR_CONFIGURATION     br_cfg;
}EUSART_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType EUSART_ASYNC_INIT(const EUSART_CFG *eusart);
Std_ReturnType EUSART_ASYNC_DEINIT(const EUSART_CFG *eusart);

Std_ReturnType EUSART_ASYNC_TX_WRITE_BYTE_NON_BLOCKING(const EUSART_CFG *eusart, uint8 data);
Std_ReturnType EUSART_ASYNC_TX_WRITE_STRING_NON_BLOCKING(const EUSART_CFG *eusart, uint8 *str);
Std_ReturnType EUSART_ASYNC_TX_WRITE_BYTE_BLOCKING(const EUSART_CFG *eusart, uint8 data);
Std_ReturnType EUSART_ASYNC_TX_WRITE_STRING_BLOCKING(const EUSART_CFG *eusart, uint8 *str);

Std_ReturnType EUSART_ASYNC_RX_RESTART(const EUSART_CFG *eusart);
Std_ReturnType EUSART_ASYNC_RX_READ_BYTE_NON_BLOCKING(const EUSART_CFG *eusart, uint8 *data);
Std_ReturnType EUSART_ASYNC_RX_READ_BYTE_BLOCKING(const EUSART_CFG *eusart, uint8 *data);


#endif	/* HAL_EUSART_H */

