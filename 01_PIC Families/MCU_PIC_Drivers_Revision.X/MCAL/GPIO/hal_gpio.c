/* 
 * File:   hal_gpio.c
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:35 AM
 */

/******************* Section 0 : Includes *******************/

#include "hal_gpio.h"

/******************* Section 1 :  Variables Definitions *******************/

volatile uint8 * const tris_regs[reg_no] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
volatile uint8 * const port_regs[reg_no] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};
volatile uint8 * const lat_regs[reg_no]  = {&LATA, &LATB, &LATC, &LATD, &LATE};



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((gpio_pin_cfg_enable) == (gpio_pin_cfg_t))

Std_ReturnType gpio_pin_direction_init(const gpio_pin_cfg *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no){
        Retval = E_NOT_OK;
    }
    else{
        switch(pin->direction){
            case gpio_output :
                clear_bit(*tris_regs[pin->port], pin->pin);
                break;
            case gpio_input :
                set_bit(*tris_regs[pin->port], pin->pin);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return (Retval);
}

Std_ReturnType gpio_pin_get_direction_status(const gpio_pin_cfg *pin, gpio_direction *direction){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no || NULL == direction ){
        Retval = E_NOT_OK;
    }
    else{
        *direction = read_bit(*tris_regs[pin->port], pin->pin);
    }
    return (Retval);
}
    
Std_ReturnType gpio_pin_write_logic(const gpio_pin_cfg *pin, gpio_logic logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no){
        Retval = E_NOT_OK;
    }
    else{
        switch(logic){
            case gpio_low:
                clear_bit(*lat_regs[pin->port], pin->pin);
                break;
            case gpio_high:
                set_bit(*lat_regs[pin->port], pin->pin);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return (Retval);
}

Std_ReturnType gpio_pin_read_logic(const gpio_pin_cfg *pin, gpio_logic *logic){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        *logic = read_bit(*port_regs[pin->port], pin->pin);
    }
    return (Retval);
}

Std_ReturnType gpio_pin_toggle_logic(const gpio_pin_cfg *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no){
        Retval = E_NOT_OK;
    }
    else{
        toggle_bit(*lat_regs[pin->port], pin->pin);
    }
    return (Retval);
}

Std_ReturnType gpio_pin_init(const gpio_pin_cfg *pin){
    Std_ReturnType Retval = E_OK;
    if(NULL == pin || pin->pin >= pin_no){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_pin_direction_init(pin);
        Retval = gpio_pin_write_logic(pin, pin->logic);
    }
    return (Retval);
}

#endif

#if ((gpio_port_cfg_enable) == (gpio_port_cfg_t))

Std_ReturnType gpio_port_direction_init(const gpio_port port, uint8 direction){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no){
        Retval = E_NOT_OK;
    }
    else{
        *tris_regs[port] = direction;
    }
    return (Retval);
}

Std_ReturnType gpio_port_get_direction_status(const gpio_port port, uint8 *direction){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no || NULL == direction){
        Retval = E_NOT_OK;
    }
    else{
        *direction = *tris_regs[port];
    }
    return (Retval);
}

Std_ReturnType gpio_port_write_logic(const gpio_port port, uint8 logic){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no){
        Retval = E_NOT_OK;
    }
    else{
        *lat_regs[port] = logic;
    }
    return (Retval);
}

Std_ReturnType gpio_port_read_logic(const gpio_port port, uint8 *logic){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no || NULL == logic){
        Retval = E_NOT_OK;
    }
    else{
        *logic = *port_regs[port];
    }
    return (Retval);
}

Std_ReturnType gpio_port_toggle_logic(const gpio_port port){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no){
        Retval = E_NOT_OK;
    }
    else{
        *lat_regs[port] ^= port_mask;
    }
    return (Retval);
}

Std_ReturnType gpio_port_init(const gpio_port port, uint8 direction, uint8 logic){
    Std_ReturnType Retval = E_OK;
    if(port >= port_no){
        Retval = E_NOT_OK;
    }
    else{
        Retval = gpio_port_direction_init(port, direction);
        Retval = gpio_port_write_logic(port, logic);
    }
    return (Retval);
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/