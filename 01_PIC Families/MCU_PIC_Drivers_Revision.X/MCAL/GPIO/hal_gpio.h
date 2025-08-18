/* 
 * File:   hal_gpio.h
 * Author: mohammedel-ahmady
 *
 * Created on June 26, 2025, 5:35 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/******************* Section 1 : Includes *******************/

#include "../mcu_cfg.h"
#include "hal_gpio_cfg.h"



/******************* Section 2 : Macros Declarations *******************/

#define bit_mask                                 (uint8)0x01
#define port_mask                                (uint8)0xff

#define pin_no                                   (uint8)0x08
#define port_no                                  (uint8)0x05
#define reg_no                                   (uint8)0x05

/******************* Section 3 : Macros Functions Declarations *******************/



/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

extern volatile uint8 * const tris_regs[reg_no];
extern volatile uint8 * const port_regs[reg_no];
extern volatile uint8 * const lat_regs[reg_no];


typedef enum{
    gpio_portA       = (uint8)0x00,
    gpio_portB       = (uint8)0x01,
    gpio_portC       = (uint8)0x02,
    gpio_portD       = (uint8)0x03,
    gpio_portE       = (uint8)0x04,
}gpio_port;

typedef enum{
    gpio_pin0        = (uint8)0x00,
    gpio_pin1        = (uint8)0x01,
    gpio_pin2        = (uint8)0x02,
    gpio_pin3        = (uint8)0x03,
    gpio_pin4        = (uint8)0x04,
    gpio_pin5        = (uint8)0x05,
    gpio_pin6        = (uint8)0x06,
    gpio_pin7        = (uint8)0x07
}gpio_pin;

typedef enum{
    gpio_output      = (uint8)0x00,
    gpio_input       = (uint8)0x01,
}gpio_direction;

typedef enum{
    gpio_low         = (uint8)0x00,
    gpio_high        = (uint8)0x01,
}gpio_logic;

typedef struct{
    uint8 port       :3;
    uint8 pin        :3;
    uint8 direction  :1;
    uint8 logic      :1;
}gpio_pin_cfg;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType gpio_pin_direction_init(const gpio_pin_cfg *pin);
Std_ReturnType gpio_pin_get_direction_status(const gpio_pin_cfg *pin, gpio_direction *direction);
Std_ReturnType gpio_pin_write_logic(const gpio_pin_cfg *pin, gpio_logic logic);
Std_ReturnType gpio_pin_read_logic(const gpio_pin_cfg *pin, gpio_logic *logic);
Std_ReturnType gpio_pin_toggle_logic(const gpio_pin_cfg *pin);
Std_ReturnType gpio_pin_init(const gpio_pin_cfg *pin);

Std_ReturnType gpio_port_direction_init(const gpio_port port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(const gpio_port port, uint8 *direction);
Std_ReturnType gpio_port_write_logic(const gpio_port port, uint8 logic);
Std_ReturnType gpio_port_read_logic(const gpio_port port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(const gpio_port port);
Std_ReturnType gpio_port_init(const gpio_port port, uint8 direction, uint8 logic);


#endif	/* HAL_GPIO_H */

