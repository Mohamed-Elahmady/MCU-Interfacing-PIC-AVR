/* 
 * File:   HAL_SPI.h
 * Author: mohammedel-ahmady
 *
 * Created on September 25, 2025, 9:35 PM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_SPI_H
#define	HAL_SPI_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_SPI_CFG.h"
#include "../GPIO/HAL_GPIO.h"
#include "../Interrupt/HAL_INT_INTERRUPT.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"

/******************* Section 2 : Macros Declarations *******************/



/******************* Section 3 : Macros Functions Declarations *******************/

#define SPI_TRANSMISSION_STATUS()                                       READ_BIT(PIR1, _PIR1_SSPIF_POSITION)
#define SPI_TRANSMISSION_COLLISION_STATUS()                             READ_BIT(SSPCON1, _SSPCON1_WCOL_POSITION)
#define SPI_TRANSMISSION_CLEAR_COLLISION()                              CLEAR_BIT(SSPCON1, _SSPCON1_WCOL_POSITION)

#define SPI_RECEIVING_STATUS()                                          READ_BIT(SSPSTAT, _SSPSTAT_BF_POSITION)
#define SPI_RECEIVING_OVERFLOW_STATUS()                                 READ_BIT(SSPCON1, _SSPCON1_SSPOV_POSITION)
#define SPI_RECEIVING_CLEAR_OVERFLOW()                                  CLEAR_BIT(SSPCON1, _SSPCON1_SSPOV_POSITION)

#define SPI_MODULE_DISABLE()                                            CLEAR_BIT(SSPCON1, _SSPCON1_SSPEN_POSITION)
#define SPI_MODULE_ENABLE()                                             SET_BIT(SSPCON1, _SSPCON1_SSPEN_POSITION)

#define SPI_SET_MODE_CONFIGURATIONS(__CONFIG)                           (SSPCON1bits.SSPM = (__CONFIG & 0x0F))

#define SPI_IDLE_POLARITY_LOW()                                         CLEAR_BIT(SSPCON1, _SSPCON1_CKP_POSITION)
#define SPI_IDLE_POLARITY_HIGH()                                        SET_BIT(SSPCON1, _SSPCON1_CKP_POSITION)

#define SPI_TRANSMISSION_PHASE_IDLE_ACTIVE()                            CLEAR_BIT(SSPSTAT, _SSPSTAT_CKE_POSITION)
#define SPI_TRANSMISSION_PHASE_ACTIVE_IDLE()                            SET_BIT(SSPSTAT, _SSPSTAT_CKE_POSITION)

#define SPI_MASTER_SLAVE_RECEIVING_SAMPLE_MIDDLE()                      CLEAR_BIT(SSPSTAT, _SSPSTAT_SMP_POSITION)
#define SPI_MASTER_RECEIVING_SAMPLE_END()                               SET_BIT(SSPSTAT, _SSPSTAT_SMP_POSITION)

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

typedef void (* SPI_HANDLER)(void);

typedef enum{
    SPI_SLAVE_MODE = (uint8)0x00,
    SPI_MASTER_MODE
}SPI_MODE;

typedef enum{
    SPI_MASTER_CLOCK_FOSC_DIV_4 = (uint8)0x00,
    SPI_MASTER_CLOCK_FOSC_DIV_16,
    SPI_MASTER_CLOCK_FOSC_DIV_64,
    SPI_MASTER_CLOCK_TMR2,
    SPI_SLAVE_CLOCK_SCK_SS_ENABLE,
    SPI_SLAVE_CLOCK_SCK_SS_DISABLE
}SPI_MODE_CFG;

typedef enum{
    SPI_IDLE_STATE_LOW_LEVEL = (uint8)0x00,
    SPI_IDLE_STATE_HIGH_LEVEL
}SPI_CLOCK_POLARITY;

typedef enum{
    SPI_TRANSMISSION_IDLE_ACTIVE = (uint8)0x00,
    SPI_TRANSMISSION_ACTIVE_IDLE
}SPI_CLOCK_PHASE;

typedef enum{
    SPI_MASTER_SLAVE_RECEIVING_MIDDLE_SAMPLING = (uint8)0x00,
    SPI_MASTER_RECEIVING_END_SAMPLING
}SPI_CLOCK_SAMPLE;

typedef struct{
    SPI_MODE                            mode;
    SPI_MODE_CFG                    mode_cfg;
    SPI_CLOCK_POLARITY          clk_polarity;
    SPI_CLOCK_PHASE                clk_phase;
    SPI_CLOCK_SAMPLE              clk_sample;
}SPI_SYNCHRONIZATION_CFG;

typedef struct{
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
    SPI_HANDLER              SPI_INTERRUPT;
    INTERRUPT_PRIORITY            priority;
#endif
    
    SPI_SYNCHRONIZATION_CFG        spi_cfg;
    GPIO_PIN_CFG                    ss_pin;
}SPI_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType SPI_INIT(const SPI_CFG *spi);
Std_ReturnType SPI_DEINIT(const SPI_CFG *spi);

Std_ReturnType SPI_WRITE_BYTE_NON_BLOCKING(const SPI_CFG *spi, uint8 data);
Std_ReturnType SPI_WRITE_STRING_NON_BLOCKING(const SPI_CFG *spi, uint8 *str);
Std_ReturnType SPI_WRITE_BYTE_BLOCKING(const SPI_CFG *spi, uint8 data);
Std_ReturnType SPI_WRITE_STRING_BLOCKING(const SPI_CFG *spi, uint8 *str);

Std_ReturnType SPI_READ_BYTE_NON_BLOCKING(const SPI_CFG *spi, uint8 *data);
Std_ReturnType SPI_READ_BYTE_BLOCKING(const SPI_CFG *spi, uint8 *data);

#endif	/* HAL_SPI_H */

