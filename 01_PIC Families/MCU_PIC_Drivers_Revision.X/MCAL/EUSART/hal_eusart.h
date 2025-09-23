/* 
 * File:   hal_eusart.h
 * Author: mohammedel-ahmady
 *
 * Created on September 21, 2025, 12:46 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_EUSART_H
#define	HAL_EUSART_H

/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "hal_eusart_cfg.h"
#include "../GPIO/hal_gpio.h"
#include "../INTERRUPT/hal_int_interrupt.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

// eusart transmitter function macros

#define eusart_async_tx_read_shift_register()               read_bit(TXSTA, _TXSTA_TRMT_POSITION)
#define eusart_async_tx_read_9bit()                         read_bit(TXSTA, _TXSTA_TX9D_POSITION)


#define eusart_async_tx_disable()                           clear_bit(TXSTA, _TXSTA_TXEN_POSITION)
#define eusart_async_tx_enable()                            set_bit(TXSTA, _TXSTA_TXEN_POSITION)

#define eusart_async_tx_9bit_disable()                      clear_bit(TXSTA, _TXSTA_TX9_POSITION)
#define eusart_async_tx_9bit_enable()                       set_bit(TXSTA, _TXSTA_TX9_POSITION)

// eusart receiver function macros

#define eusart_async_rx_read_shift_register()               read_bit(PIR1, _PIR1_RCIF_POSITION)
#define eusart_async_rx_read_9bit()                         read_bit(RCSTA, _RCSTA_RX9D_POSITION)

#define eusart_async_rx_disable()                           clear_bit(RCSTA, _RCSTA_CREN_POSITION)
#define eusart_async_rx_enable()                            set_bit(RCSTA, _RCSTA_CREN_POSITION)

#define eusart_async_rx_9bit_disable()                      clear_bit(RCSTA, _RCSTA_RX9_POSITION)
#define eusart_async_rx_9bit_enable()                       set_bit(RCSTA, _RCSTA_RX9_POSITION)

// eusart errors handling function macros

#define eusart_read_framing_error_status()                  read_bit(RCSTA, _RCSTA_FERR_POSITION)

#define eusart_read_overrun_error_status()                  read_bit(RCSTA, _RCSTA_OERR_POSITION)

// eusart function macros

#define eusart_module_disable()                             clear_bit(RCSTA, _RCSTA_SPEN_POSITION)
#define eusart_module_enable()                              set_bit(RCSTA, _RCSTA_SPEN_POSITION)

#define eusart_asynchronous_mode()                          clear_bit(TXSTA, _TXSTA_SYNC_POSITION)
#define eusart_synchronous_mode()                           set_bit(TXSTA, _TXSTA_SYNC_POSITION)

#define eusart_sync_slave()                                 clear_bit(TXSTA, _TXSTA_CSRC_POSITION)
#define eusart_sync_master()                                set_bit(TXSTA, _TXSTA_CSRC_POSITION)

#define eusart_async_baud_rate_low_speed()                  clear_bit(TXSTA, _TXSTA_BRGH_POSITION)
#define eusart_async_baud_rate_high_speed()                 set_bit(TXSTA, _TXSTA_BRGH_POSITION)

#define eusart_baud_rate_8bit()                       clear_bit(BAUDCON, _BAUDCON_BRG16_POSITION)
#define eusart_baud_rate_16bit()                      set_bit(BAUDCON, _BAUDCON_BRG16_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* eusart_handler)(void);

// eusart transmitter enums & data types

typedef enum{
    eusart_tx_disable_state = (uint8)0x00,
    eusart_tx_enable_state
}eusart_tx_state;

typedef enum{
    eusart_tx_interrupt_disable_state = (uint8)0x00,
    eusart_tx_interrupt_enable_state
}eusart_tx_interrupt_state;

typedef enum{
    eusart_tx_9bit_disable_state = (uint8)0x00,
    eusart_tx_9bit_enable_state
}eusart_tx_9bit_state;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
    eusart_handler                tx_interrupt;
    interrupt_priority             tx_priority;
    eusart_tx_interrupt_state     tx_int_state;
#endif
    
    eusart_tx_state                   tx_state;
    eusart_tx_9bit_state         tx_9bit_state;
}eusart_tx_cfg;

// eusart receiver enums & data types

typedef enum{
    eusart_rx_disable_state = (uint8)0x00,
    eusart_rx_enable_state
}eusart_rx_state;

typedef enum{
    eusart_rx_interrupt_disable_state = (uint8)0x00,
    eusart_rx_interrupt_enable_state
}eusart_rx_interrupt_state;

typedef enum{
    eusart_rx_9bit_disable_state = (uint8)0x00,
    eusart_rx_9bit_enable_state
}eusart_rx_9bit_state;

typedef struct{
#if ((interrupt_feature_enable) == (int_interrupt_eusart))
    eusart_handler                rx_interrupt;
    eusart_handler           framing_interrupt;
    eusart_handler           ovverun_interrupt;
    interrupt_priority             rx_priority;
    eusart_rx_interrupt_state     rx_int_state;
#endif
    eusart_rx_state                   rx_state;
    eusart_rx_9bit_state         rx_9bit_state;
}eusart_rx_cfg;

// eusart errors handling enums & data types

typedef enum{
    eusart_framing_cleared = (uint8)0x00,
    eusart_framing_detected
}eusart_framing_status;

typedef enum{
    eusart_overrun_cleared = (uint8)0x00,
    eusart_overrun_detected
}eusart_overrun_status;

typedef union{
    struct{
        uint8       framing_err : 1;
        uint8       overrun_err : 1;
        uint8    error_reserved : 6;
    };
    uint8 status;
}eusart_errors_status;

// eusart enums & data types

typedef enum{
    eusart_async_8bit_low_speed = (uint8)0x00,
    eusart_async_8bit_high_speed,
    eusart_async_16bit_low_speed,
    eusart_async_16bit_high_speed,
    eusart_sync_8bit,
    eusart_sync_16bit
}eusart_baud_rate_cfg;

typedef struct{
    eusart_tx_cfg          tx_transmitter;
    eusart_rx_cfg          rx_reciver;
    
    uint16                      baud_rate;
    eusart_baud_rate_cfg    baud_rate_cfg;
}eusart_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType eusart_init(const eusart_cfg *eusart);
Std_ReturnType eusart_deinit(const eusart_cfg *eusart);

Std_ReturnType eusart_async_tx_write_byte_non_blocking(const eusart_cfg *eusart, uint8 data);
Std_ReturnType eusart_async_tx_write_string_non_blocking(const eusart_cfg *eusart, uint8 *str);
Std_ReturnType eusart_async_tx_write_byte_blocking(const eusart_cfg *eusart, uint8 data);
Std_ReturnType eusart_async_tx_write_string_blocking(const eusart_cfg *eusart, uint8 *str);

Std_ReturnType eusart_async_rx_reset(const eusart_cfg *eusart);
Std_ReturnType eusart_async_rx_read_byte_non_blocking(const eusart_cfg *eusart, uint8 *data);
Std_ReturnType eusart_async_rx_read_byte_blocking(const eusart_cfg *eusart, uint8 *data);

#endif	/* HAL_EUSART_H */

