/* 
 * File:   HAL_GPIO.h
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:30 AM
 */

/******************* Section 0 : File Guard *******************/

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/******************* Section 1 : Includes *******************/

#include "pic18f46k20.h"
#include "HAL_GPIO_CFG.h"
#include "../mcal_std_types.h"
#include "../device_cfg.h"


/******************* Section 2 : Macros Declarations *******************/

#define BIT_MASK                            (uint8)0x01
#define PORT_LOW                            (uint8)0x00
#define PORT_MASK                           (uint8)0xFF

#define PIN_NO                              (uint8)0x08
#define PORT_NO                             (uint8)0x05
#define REGs_NO                             (uint8)0x05

/******************* Section 3 : Macros Functions Declarations *******************/

#define SET_BIT(REG, BIT_POS)               (REG |= (uint8)(BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)             (REG &= ~(uint8)(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG, BIT_POS)            (REG ^= (uint8)(BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)              ((REG >> BIT_POS) & (uint8)BIT_MASK)  

/******************* Section 4 : User Defined Data Types & Variables Declarations *******************/

volatile extern uint8 *TRIS_REGs[REGs_NO];
volatile extern uint8 *PORT_REGs[REGs_NO];
volatile extern uint8 *LAT_REGs[REGs_NO];

typedef enum{
    GPIO_PORTA            = (uint8)0x00,
    GPIO_PORTB            = (uint8)0x01,
    GPIO_PORTC            = (uint8)0x02,
    GPIO_PORTD            = (uint8)0x03,
    GPIO_PORTE            = (uint8)0x04 
}GPIO_PORT;

typedef enum{
    GPIO_PIN0             = (uint8)0x00,
    GPIO_PIN1             = (uint8)0x01,
    GPIO_PIN2             = (uint8)0x02,
    GPIO_PIN3             = (uint8)0x03,
    GPIO_PIN4             = (uint8)0x04,
    GPIO_PIN5             = (uint8)0x05,
    GPIO_PIN6             = (uint8)0x06,
    GPIO_PIN7             = (uint8)0x07
}GPIO_PIN;

typedef enum{
    GPIO_OUTPUT           = (uint8)0x00,
    GPIO_INPUT            = (uint8)0x01  
}GPIO_DIRECTION;

typedef enum{
    GPIO_LOW              = (uint8)0x00,
    GPIO_HIGH             = (uint8)0x01  
}GPIO_LOGIC;

typedef struct{
    uint8 PORT            :3;   /* @ref : GPIO_PORT */
    uint8 PIN             :3;   /* @ref : GPIO_PIN */
    uint8 DIRECTION       :1;   /* @ref : GPIO_DIRECTION */
    uint8 LOGIC           :1;   /* @ref : GPIO_LOGIC */
}GPIO_PIN_CFG;

/******************* Section 5 : Software Interfaces Declarations (APIs) *******************/

Std_ReturnType GPIO_PIN_DIRECTION_INIT(const GPIO_PIN_CFG *pin);
Std_ReturnType GPIO_PIN_GET_DIRECTION_STATUS(const GPIO_PIN_CFG *pin, GPIO_DIRECTION *direction);
Std_ReturnType GPIO_PIN_WRITE_LOGIC(const GPIO_PIN_CFG *pin, GPIO_LOGIC logic);
Std_ReturnType GPIO_PIN_READ_LOGIC(const GPIO_PIN_CFG *pin, GPIO_LOGIC *logic);
Std_ReturnType GPIO_PIN_TOGGLE_LOGIC(const GPIO_PIN_CFG *pin);
Std_ReturnType GPIO_PIN_INIT(const GPIO_PIN_CFG *pin);

Std_ReturnType GPIO_PORT_DIRECTION_INIT(const GPIO_PORT port, uint8 direction);
Std_ReturnType GPIO_PORT_GET_DIRECTION_STATUS(const GPIO_PORT port, uint8 *direction);
Std_ReturnType GPIO_PORT_WRITE_LOGIC(const GPIO_PORT port, uint8 logic);
Std_ReturnType GPIO_PORT_READ_LOGIC(const GPIO_PORT port, uint8 *logic);
Std_ReturnType GPIO_PORT_TOGGLE_LOGIC(const GPIO_PORT port);
Std_ReturnType GPIO_PORT_INIT(const GPIO_PORT port, uint8 direction, uint8 logic); 

#endif	/* HAL_GPIO_H */

