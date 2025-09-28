/* 
 * File:   HAL_SPI.c
 * Author: mohammedel-ahmady
 *
 * Created on September 25, 2025, 9:35 PM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_SPI.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
static SPI_HANDLER SPI_HANDLER_FUNCTION = NULL;
#endif

static Std_ReturnType SPI_SET_DISABLE(const SPI_CFG *spi);
static Std_ReturnType SPI_SET_ENABLE(const SPI_CFG *spi);
static Std_ReturnType SPI_SET_MODE_CONFIG(const SPI_CFG *spi);
static Std_ReturnType SPI_PINS_INIT(const SPI_CFG *spi);
static Std_ReturnType SPI_SET_CLOCK_CONFIGURATIONS(const SPI_CFG *spi);

#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))

static Std_ReturnType SPI_CONFIGURE_INTERRUPT(const SPI_CFG *spi);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType SPI_INIT(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable SPI Module
        Retval = SPI_SET_DISABLE(spi);
        // 2. Set SPI Mode & Mode Configurations
        Retval = SPI_SET_MODE_CONFIG(spi);
        // 3. SPI Pins Initialization
        Retval = SPI_PINS_INIT(spi);
        // 4. SPI Set Clock Configurations
        Retval = SPI_SET_CLOCK_CONFIGURATIONS(spi);
        // 5. Configure SPI Interrupts if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
        Retval = SPI_CONFIGURE_INTERRUPT(spi);
#endif
        // 6. Enable SPI Module
        Retval = SPI_SET_ENABLE(spi);
    }
    return Retval;
}

Std_ReturnType SPI_DEINIT(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable SPI Module
        Retval = SPI_SET_DISABLE(spi);
#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))
        INT_INTERRUPT_SPI_DISABLE();
        INT_INTERRUPT_SPI_CLEAR_FLAG();
#endif
    }
    return Retval;
}

Std_ReturnType SPI_WRITE_BYTE_NON_BLOCKING(const SPI_CFG *spi, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        if(SPI_TRANSMISSION_COLLISION_STATUS()){
            SPI_TRANSMISSION_CLEAR_COLLISION();
            Retval = E_NOT_OK;
        }
        else{
            if(SPI_TRANSMISSION_STATUS()){
                SSPBUF = data;
            }
            else{/* Nothing */}
        }
    }
    return Retval;
}

Std_ReturnType SPI_WRITE_STRING_NON_BLOCKING(const SPI_CFG *spi, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            if(SPI_TRANSMISSION_COLLISION_STATUS()){
                SPI_TRANSMISSION_CLEAR_COLLISION();
                Retval = E_NOT_OK;
            }
            else if(SPI_TRANSMISSION_STATUS()){
                SSPBUF = *str;
                str++;
                INT_INTERRUPT_SPI_CLEAR_FLAG();
            }
            else{
                Retval = E_NOT_OK;
            }
        }
    }
    return Retval;
}

Std_ReturnType SPI_WRITE_BYTE_BLOCKING(const SPI_CFG *spi, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        if(SPI_TRANSMISSION_COLLISION_STATUS()){
            SPI_TRANSMISSION_CLEAR_COLLISION();
            uint8 dummy = SSPBUF;
            Retval = E_NOT_OK;
        }
        else{
            SSPBUF = data;
            while(!SPI_TRANSMISSION_STATUS());
            uint8 dummy = SSPBUF;
        }
    }
    return Retval;
}

Std_ReturnType SPI_WRITE_STRING_BLOCKING(const SPI_CFG *spi, uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = SPI_WRITE_BYTE_BLOCKING(spi, *str);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType SPI_READ_BYTE_NON_BLOCKING(const SPI_CFG *spi, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        if(SPI_RECEIVING_STATUS()){
            *data = SSPBUF;
        }
        else{/* Nothing */}
    }
    return Retval;
}

Std_ReturnType SPI_READ_BYTE_BLOCKING(const SPI_CFG *spi, uint8 *data){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        while(!SPI_RECEIVING_STATUS());
        *data = SSPBUF;
        
        if(SPI_RECEIVING_OVERFLOW_STATUS() && spi->spi_cfg.mode == SPI_SLAVE_MODE){
            SPI_RECEIVING_CLEAR_OVERFLOW();
        }
        else{/* Nothing */}
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))

void SPI_ISR(void){
    // 1. Clear SPI Flag
    INT_INTERRUPT_SPI_CLEAR_FLAG();
    // 2. Code if needed
    // 3. Callback Function
    if(SPI_HANDLER_FUNCTION){
        SPI_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType SPI_SET_DISABLE(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        SPI_MODULE_DISABLE();
    }
    return Retval;
}

static Std_ReturnType SPI_SET_ENABLE(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        SPI_MODULE_ENABLE();
    }
    return Retval;
}

static Std_ReturnType SPI_SET_MODE_CONFIG(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        switch(spi->spi_cfg.mode_cfg){
            case SPI_MASTER_CLOCK_FOSC_DIV_4:
                SPI_SET_MODE_CONFIGURATIONS(SPI_MASTER_CLOCK_FOSC_DIV_4);
                break;
            case SPI_MASTER_CLOCK_FOSC_DIV_16:
                SPI_SET_MODE_CONFIGURATIONS(SPI_MASTER_CLOCK_FOSC_DIV_16);
                break;
            case SPI_MASTER_CLOCK_FOSC_DIV_64:
                SPI_SET_MODE_CONFIGURATIONS(SPI_MASTER_CLOCK_FOSC_DIV_64);
                break;
            case SPI_MASTER_CLOCK_TMR2:
                SPI_SET_MODE_CONFIGURATIONS(SPI_MASTER_CLOCK_TMR2);
                break;
            case SPI_SLAVE_CLOCK_SCK_SS_ENABLE:
                SPI_SET_MODE_CONFIGURATIONS(SPI_SLAVE_CLOCK_SCK_SS_ENABLE);
                break;
            case SPI_SLAVE_CLOCK_SCK_SS_DISABLE:
                SPI_SET_MODE_CONFIGURATIONS(SPI_SLAVE_CLOCK_SCK_SS_DISABLE);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType SPI_PINS_INIT(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Definition Main Pins
        GPIO_PIN_CFG SDI_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN4, .DIRECTION = GPIO_INPUT};
        GPIO_PIN_CFG SDO_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN5, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
        // 2. Initialize Main Pins
        Retval = GPIO_PIN_DIRECTION_INIT(&SDI_pin);
        Retval = GPIO_PIN_INIT(&SDO_pin);
        
        switch(spi->spi_cfg.mode){
            case SPI_MASTER_MODE:{
                // 3. Definition Mode Dependant Pins
                GPIO_PIN_CFG SCK_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN3, .DIRECTION = GPIO_OUTPUT, .LOGIC = GPIO_LOW};
                // 4. Initialize Mode Dependant Pins
                Retval = GPIO_PIN_INIT(&SCK_pin);
                Retval = GPIO_PIN_INIT(&(spi->ss_pin));
                break;
            }
            case SPI_SLAVE_MODE:
                // 3. Definition Mode Dependant Pins
                GPIO_PIN_CFG SCK_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN3, .DIRECTION = GPIO_INPUT};
                GPIO_PIN_CFG SS_pin = {.PORT = GPIO_PORTA, .PIN = GPIO_PIN5, .DIRECTION = GPIO_INPUT};
                // 4. Initialize Mode Dependant Pins
                Retval = GPIO_PIN_DIRECTION_INIT(&SCK_pin);
                Retval = GPIO_PIN_DIRECTION_INIT(&SS_pin);
                break;
        }
    }
    return Retval;
}

static Std_ReturnType SPI_SET_CLOCK_CONFIGURATIONS(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Set Clock Polarity
        if(spi->spi_cfg.clk_polarity == SPI_IDLE_STATE_HIGH_LEVEL){
            SPI_IDLE_POLARITY_HIGH();
        }
        else if(spi->spi_cfg.clk_polarity == SPI_IDLE_STATE_LOW_LEVEL){
            SPI_IDLE_POLARITY_LOW();
        }
        else{
            Retval = E_NOT_OK;
        }
        // 2. Set Clock Phase
        if(spi->spi_cfg.clk_phase == SPI_TRANSMISSION_ACTIVE_IDLE){
            SPI_TRANSMISSION_PHASE_ACTIVE_IDLE();
        }
        else if(spi->spi_cfg.clk_phase == SPI_TRANSMISSION_IDLE_ACTIVE){
            SPI_TRANSMISSION_PHASE_IDLE_ACTIVE();
        }
        else{
            Retval = E_NOT_OK;
        }
        
        // 3. Select Read Sample
        switch(spi->spi_cfg.mode){
            case SPI_MASTER_MODE:
                if(spi->spi_cfg.clk_sample == SPI_MASTER_SLAVE_RECEIVING_MIDDLE_SAMPLING){
                    SPI_MASTER_SLAVE_RECEIVING_SAMPLE_MIDDLE();
                }
                else if(spi->spi_cfg.clk_sample == SPI_MASTER_RECEIVING_END_SAMPLING){
                    SPI_MASTER_RECEIVING_SAMPLE_END();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case SPI_SLAVE_MODE:
                    SPI_MASTER_SLAVE_RECEIVING_SAMPLE_MIDDLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (SPI_INTERRUPT_FEATURE))

static Std_ReturnType SPI_CONFIGURE_INTERRUPT(const SPI_CFG *spi){
    Std_ReturnType Retval = E_OK;
    if(NULL == spi){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Enable SPI Interrupt
        INT_INTERRUPT_SPI_ENABLE();
        // 2. Clear SPI Interrupt flag
        INT_INTERRUPT_SPI_CLEAR_FLAG();
        // 3. Set SPI Priority & Enable GIE
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        if(spi->priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_SPI_HIGH_PRIORITY();
        }
        else if(spi->priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_SPI_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        // 4. Assign Callback Function
        SPI_HANDLER_FUNCTION = spi->SPI_INTERRUPT;
    }
    return Retval;
}

#endif