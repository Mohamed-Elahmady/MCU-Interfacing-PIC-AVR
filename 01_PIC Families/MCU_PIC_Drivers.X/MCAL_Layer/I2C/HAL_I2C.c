/* 
 * File:   HAL_I2C.c
 * Author: mohammedel-ahmady
 *
 * Created on October 5, 2025, 12:40 AM
 */

/******************* Section 0 : Includes *******************/

#include "HAL_I2C.h"

/******************* Section 1 :  Variables Definitions *******************/

#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))
static I2C_HANDLER I2C_HANDLER_FUNCTION = NULL;
static I2C_HANDLER I2C_OVF_HANDLER_FUNCTION = NULL;
static I2C_HANDLER I2C_COL_HANDLER_FUNCTION = NULL;
#endif

/******************* Section 2 :  Helper Functions Declarations *******************/

static Std_ReturnType I2C_SET_DISABLE(const I2C_CFG *i2c);
static Std_ReturnType I2C_SET_ENABLE(const I2C_CFG *i2c);
static Std_ReturnType I2C_SET_MODE_CONFIGURATIONS(const I2C_CFG *i2c);
static Std_ReturnType I2C_PINS_INIT(const I2C_CFG *i2c);
static Std_ReturnType I2C_SET_SLEW_RATE(const I2C_CFG *i2c);
static Std_ReturnType I2C_SET_SMBUS(const I2C_CFG *i2c);

#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))

static Std_ReturnType I2C_CONFIGURE_INTERRUPTS(const I2C_CFG *i2c);

#endif

/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

Std_ReturnType I2C_INIT(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable I2C module
        Retval = I2C_SET_DISABLE(i2c);
        // 2. Set I2C Mode & Mode Configurations
        Retval = I2C_SET_MODE_CONFIGURATIONS(i2c);
        // 3. I2C Pins Initialize
        Retval = I2C_PINS_INIT(i2c);
        // 4. Set I2C SLEW Rate
        Retval = I2C_SET_SLEW_RATE(i2c);
        // 5. Set I2C SMBUS
        Retval = I2C_SET_SMBUS(i2c);
        // 6. Configure I2C Interrupts if needed
#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))
        Retval = I2C_CONFIGURE_INTERRUPTS(i2c);
#endif
        // 7. Enable I2C module
        Retval = I2C_SET_ENABLE(i2c);
    }
    return Retval;
}

Std_ReturnType I2C_DEINIT(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Disable I2C module
        Retval = I2C_SET_DISABLE(i2c);
        // 1. Disable and Clear All I2C Interrupts Configurations
#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))
        INT_INTERRUPT_I2C_DISABLE();
        INT_INTERRUPT_I2C_BUS_COL_DISABLE();
        INT_INTERRUPT_I2C_CLEAR_FLAG();
        INT_INTERRUPT_I2C_BUS_COL_CLEAR_FLAG();
#endif
    }
    return Retval;
}


Std_ReturnType I2C_MASTER_SEND_START_CONDITION(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;

    if (NULL == i2c)
    {
        Retval = E_NOT_OK;
    }
    else
    {
        // 1. Initiate Start Condition
        I2C_MASTER_TRANSMIT_START_CONDITION();

        // 2. Wait until Start Condition is completed
        while (I2C_MASTER_SENDING_START_CONDITION_STATE());

        // 3. Clear interrupt flag if used 
#if (I2C_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE)
        INT_INTERRUPT_I2C_CLEAR_FLAG();
#endif
        // 4. Verify Start Condition was detected
        if (I2C_MASTER_START_CONDITION_DETECTION()){
            Retval = E_OK;
        }
        else{
            Retval = E_NOT_OK;
        }
    }

    return Retval;
}

Std_ReturnType I2C_MASTER_SEND_STOP_CONDITION(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Initiate Stop Condition
        I2C_MASTER_TRANSMIT_STOP_CONDITION();
        // 2. Wait until Stop Condition is Completed
        while(I2C_MASTER_SENDING_STOP_CONDITION_STATE());
        // 3. Clear interrupt flag if used 
#if (I2C_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE)
        INT_INTERRUPT_I2C_CLEAR_FLAG();
#endif        
        // 4. Verify Stop Condition was detected
        if(I2C_MASTER_STOP_CONDITION_DETECTION()){
            Retval = E_OK;
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

Std_ReturnType I2C_MASTER_SEND_REPEATED_START_CONDITION(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Initiate Start Condition
        I2C_MASTER_TRANSMIT_REPEATED_START_CONDITION();

        // 2. Wait until Start Condition is completed
        while (I2C_MASTER_SENDING_REPEATED_START_CONDITION_STATE());

        // 3. Clear interrupt flag if used 
#if (I2C_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE)
        INT_INTERRUPT_I2C_CLEAR_FLAG();
#endif
    }
    return Retval;
}

 
Std_ReturnType I2C_MASTER_WRITE_BYTE_BLOCKING(const I2C_CFG *i2c, uint8 data, uint8 *ack){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c || NULL == ack){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Write Data in I2C Register
        SSPBUF = data;
        // 2. Wait Until the data transmission
        while(!I2C_TRANSMISSION_STATUS());
        // 3. Clear interrupt flag if used 
#if (I2C_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE)
        INT_INTERRUPT_I2C_CLEAR_FLAG();
#endif
        // 4. Check if Write Collision Happened
        if(I2C_MASTER_SLAVE_READ_COLLISION_STATUS()){
            I2C_MASTER_SLAVE_CLEAR_COLLISION();
            Retval = E_NOT_OK;
        }
        
        // 5. Send Acknowledge or Not Acknowledge Bit
        if(!I2C_MASTER_ACKNOWLEDGE_STATUS()){
            *ack = I2C_MASTER_ACK_RECEIVED;
        }
        else{
            *ack = I2C_MASTER_ACK_NOT_RECEIVED;
        }
    }
    return Retval;
}

Std_ReturnType I2C_MASTER_WRITE_STRING_BLOCKING(const I2C_CFG *i2c, uint8 *str, uint8 *ack){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c || NULL == str || NULL == ack){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = I2C_MASTER_WRITE_BYTE_BLOCKING(i2c, *str, ack);
            str++;
        }
    }
    return Retval;
}

Std_ReturnType I2C_MASTER_READ_BYTE_BLOCKING(const I2C_CFG *i2c, uint8 *data, uint8 ack){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c || NULL == data){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Enable Master Mode Receiving
        I2C_MASTER_RECEIVE_ENABLE();
        // 2. Wait Until Receiving Data
        while(!I2C_RECEIVING_STATUS());
        // 3. Catch Data from the buffer register
        *data = SSPBUF;
        // 4. Send ACK or Not ACK for Slave
        if(ack == I2C_MASTER_SEND_ACK){
            I2C_MASTER_TRANSMIT_ACKNOWLEDGE();
        }
        else if(ack == I2C_MASTER_SEND_NACK){
            I2C_MASTER_TRANSMIT_NOT_ACKNOWLEDGE();
        }
        else{
            Retval = E_NOT_OK;
        }
        // 4. Initiate ACK Sequence
        I2C_MASTER_INITIATE_ACKNOWLEDGMENT_ENABLE(); 
        // 5. Disable Receive Mpde
        I2C_MASTER_RECEIVE_DISABLE();
    }
    return Retval;
}


Std_ReturnType I2C_MASTER_SEND_FRAME(const I2C_CFG *i2c, uint16 add, uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        uint8 slave_ack = 0;
        Retval = I2C_MASTER_SEND_START_CONDITION(i2c);
        Retval = I2C_MASTER_WRITE_BYTE_BLOCKING(i2c, add, &slave_ack);
        if(slave_ack == I2C_MASTER_SEND_ACK){
            Retval = I2C_MASTER_WRITE_BYTE_BLOCKING(i2c, data, &slave_ack);
            if(slave_ack == I2C_MASTER_SEND_ACK){
                Retval = I2C_MASTER_SEND_STOP_CONDITION(i2c);
            }
            else if(slave_ack == I2C_MASTER_SEND_NACK){
                Retval = I2C_MASTER_SEND_STOP_CONDITION(i2c);
            }
            else{ /* Nothing */ }
        }
        else if(slave_ack == I2C_MASTER_SEND_NACK){
            Retval = I2C_MASTER_SEND_STOP_CONDITION(i2c);
        }
        else{ /* Nothing */ }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))

void I2C_ISR(void){
    // 1. Clear Flag
    INT_INTERRUPT_I2C_CLEAR_FLAG();
    // 2. Code
    // 3. CallBack Function
    if(I2C_HANDLER_FUNCTION){
        I2C_HANDLER_FUNCTION();
    }
    if(I2C_OVF_HANDLER_FUNCTION){
        I2C_OVF_HANDLER_FUNCTION();
    }
}

void I2C_BC_ISR(void){
    // 1. Clear Flag
    INT_INTERRUPT_I2C_BUS_COL_CLEAR_FLAG();
    // 2. Code
    // 3. CallBack Function
    if(I2C_COL_HANDLER_FUNCTION){
        I2C_COL_HANDLER_FUNCTION();
    }
}

#endif

/******************* Section 4:  Helper Functions Definitions *******************/

static Std_ReturnType I2C_SET_DISABLE(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        I2C_MODULE_DISABLE();
    }
    return Retval;
}

static Std_ReturnType I2C_SET_ENABLE(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        I2C_MODULE_ENABLE();
    }
    return Retval;
}

static Std_ReturnType I2C_SET_MODE_CONFIGURATIONS(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Set I2C Mode
        switch(i2c->i2c_frame.mode){
            case I2C_MASTER_MODE:
                // 1.1. Set mode configurations
                if(i2c->i2c_frame.mode_cfg == I2C_MASTER_MODE_CLK || i2c->i2c_frame.mode_cfg == I2C_MASTER_MODE_FIRMWARE){
                    I2C_SET_MODE_CFG(i2c->i2c_frame.mode_cfg);
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                // 1.2. Set Receive Mode in Master - Initial condition set it Disable
                I2C_MASTER_RECEIVE_DISABLE();
                
                // 1.3. Set Master Clock Configurations
                if(i2c->i2c_frame.mode_cfg == I2C_MASTER_MODE_CLK){
                    SSPADD = (uint8)(((_XTAL_FREQ) / (i2c->i2c_clock * 4.0)) - 1);
                }
                else if(i2c->i2c_frame.mode_cfg == I2C_MASTER_MODE_FIRMWARE){
                    // For Future Uses
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                // 1.4 Clear Write Collision By default
                I2C_MASTER_SLAVE_CLEAR_COLLISION(); // No Collision
                // 2.5 Clear Receive Overflow By default
                I2C_MASTER_SLAVE_CLEAR_OVERFLOW(); // No Overflow
                
                break;
            case I2C_SLAVE_MODE:
                // 2.1. Set mode configurations
                if(i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_7BIT_ADD || i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_10BIT_ADD ||
                   i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_7BIT_ADD_SP_INTERRUPTS || i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_10BIT_ADD_SP_INTERRUPTS){
                    I2C_SET_MODE_CFG(i2c->i2c_frame.mode_cfg);
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                // 2.2. Set General call configurations
                if(i2c->i2c_frame.general_call == I2C_GENERAL_CALL_ENABLE){
                    I2C_SLAVE_GENERAL_CALL_ENABLE();
                }
                else if(i2c->i2c_frame.general_call == I2C_GENERAL_CALL_DISABLE){
                    I2C_SLAVE_GENERAL_CALL_DISABLE();
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                // 2.3 Clear Write Collision By default
                I2C_MASTER_SLAVE_CLEAR_COLLISION(); // No Collision
                // 2.4 Clear Receive Overflow By default
                I2C_MASTER_SLAVE_CLEAR_OVERFLOW(); // No Overflow
                // 2.5 Release Clock Stretching
                I2C_SLAVE_RELEASE_CLOCK_STRETCHING();
                
                // 2. Clear I2C Interrupt Flag
                INT_INTERRUPT_I2C_CLEAR_FLAG();
                INT_INTERRUPT_I2C_BUS_COL_CLEAR_FLAG();
                
                // 2.6 Assign Slave Address
                if(i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_7BIT_ADD || i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_7BIT_ADD_SP_INTERRUPTS){
                    SSPADD = (uint8)(i2c->i2c_frame.i2c_slave_add);
                    SSPMSK = (uint8)0xFE;
                }
                else if(i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_10BIT_ADD || i2c->i2c_frame.mode_cfg == I2C_SLAVE_MODE_10BIT_ADD_SP_INTERRUPTS){
                    // For Future Uses
                }
                else{
                    Retval = E_NOT_OK;
                }
                
                break;
            default :
                break;
        }
    }
    return Retval;
}

static Std_ReturnType I2C_PINS_INIT(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_PIN_CFG SCL_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN3, .DIRECTION = GPIO_INPUT};
        GPIO_PIN_CFG SDA_pin = {.PORT = GPIO_PORTC, .PIN = GPIO_PIN4, .DIRECTION = GPIO_INPUT};
        
        Retval = GPIO_PIN_DIRECTION_INIT(&SCL_pin);
        Retval = GPIO_PIN_DIRECTION_INIT(&SDA_pin);
    }
    return Retval;
}

static Std_ReturnType I2C_SET_SLEW_RATE(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        if(i2c->i2c_frame.slew_rate == I2C_SLEW_RATE_400KHZ_ENABLE){
            I2C_SLEW_RATE_ENABLE_400KHZ();
        }
        else if(i2c->i2c_frame.slew_rate == I2C_SLEW_RATE_100KHZ_DISABLE){
            I2C_SLEW_RATE_DISABLE_100KHZ();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

static Std_ReturnType I2C_SET_SMBUS(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        if(i2c->i2c_frame.smbus == I2C_SMBUS_ENABLE){
            I2C_SMBUS_ENABLE_SPECIFIC_INPUT();
        }
        else if(i2c->i2c_frame.smbus == I2C_SMBUS_DISABLE){
            I2C_SMBUS_DISABLE_SPECIFIC_INPUT();
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}

#if ((INTERRUPT_FEATURE_ENABLE) == (I2C_INTERRUPT_FEATURE))

static Std_ReturnType I2C_CONFIGURE_INTERRUPTS(const I2C_CFG *i2c){
    Std_ReturnType Retval = E_OK;
    if(NULL == i2c){
        Retval = E_NOT_OK;
    }
    else{
        // 1. Enable I2C Interrupts Feature
        INT_INTERRUPT_I2C_ENABLE();
        INT_INTERRUPT_I2C_BUS_COL_ENABLE();
        // 2. Clear I2C Interrupt Flag
        INT_INTERRUPT_I2C_CLEAR_FLAG();
        INT_INTERRUPT_I2C_BUS_COL_CLEAR_FLAG();
        // 3. Set I2C Priority and GIE
#if ((INTERRUPT_FEATURE_ENABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_ENABLE();
        GLOBAL_INTERRUPT_HIGH_ENABLE();
        GLOBAL_INTERRUPT_LOW_ENABLE();
        if(i2c->i2c_priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_I2C_HIGH_PRIORITY();
        }
        else if(i2c->i2c_priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_I2C_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
        if(i2c->col_priority == INTERRUPT_HIGH_PRIORITY){
            INT_INTERRUPT_I2C_BUS_COL_HIGH_PRIORITY();
        }
        else if(i2c->col_priority == INTERRUPT_LOW_PRIORITY){
            INT_INTERRUPT_I2C_BUS_COL_LOW_PRIORITY();
        }
        else{
            Retval = E_NOT_OK;
        }
#elif ((INTERRUPT_FEATURE_DISABLE) == (INTERRUPT_PRIORITY_LEVELS))
        INTERRUPT_PRIORITY_BIT_DISABLE();
        GLOBAL_INTERRUPT_ENABLE();
        PERIPHERAL_INTERRUPT_ENABLE();
#endif
        // 4. Assign Call Back Functions
        I2C_HANDLER_FUNCTION = i2c->I2C_INTERRUPT;
        I2C_OVF_HANDLER_FUNCTION = i2c->I2C_OVF_INTERRUPT;
        I2C_COL_HANDLER_FUNCTION = i2c->I2C_COL_INTERRUPT;
    }
    return Retval;
}

#endif