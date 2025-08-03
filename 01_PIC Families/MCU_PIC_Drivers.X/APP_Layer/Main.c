/* 
 * File:   Main.c
 * Author: Mohammed.El-Ahmady
 *
 * Created on June 21, 2025, 4:00 AM
 */

#include "Main.h"

void INT0_APP_ISR(void);
void INT1_APP_ISR(void);
void INT2_APP_ISR(void);
void RB4_APP_ISR_HIGH(void);
void RB4_APP_ISR_LOW(void);
void RB5_APP_ISR_HIGH(void);
void RB5_APP_ISR_LOW(void);
void RB6_APP_ISR_HIGH(void);
void RB6_APP_ISR_LOW(void);
void RB7_APP_ISR_HIGH(void);
void RB7_APP_ISR_LOW(void);

Std_ReturnType Ret = E_OK;

GPIO_LED led1 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN0, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led2 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN1, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led3 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN2, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led4 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN3, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led5 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN4, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led6 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN5, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led7 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN6, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

GPIO_LED led8 = {.pin.PORT = GPIO_PORTC, .pin.PIN =  GPIO_PIN7, .pin.DIRECTION = GPIO_OUTPUT, .pin.LOGIC = GPIO_LOW};

INTERRUPT_INTX int0_ob = {.INTERRUPT_ISR = INT0_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN0, .pin.DIRECTION = GPIO_INPUT,
                          .source = INTERRUPT_INT0, .priority = INTERRUPT_HIGH_PRIORITY,.edge = INTERRUPT_RISING_EDGE};

INTERRUPT_INTX int1_ob = {.INTERRUPT_ISR = INT1_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN1, .pin.DIRECTION = GPIO_INPUT,
                          .source = INTERRUPT_INT1, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_FALLING_EDGE};

INTERRUPT_INTX int2_ob = {.INTERRUPT_ISR = INT2_APP_ISR, .pin.PORT = GPIO_PORTB, .pin.PIN  = GPIO_PIN2, .pin.DIRECTION = GPIO_INPUT,
                          .source = INTERRUPT_INT2, .priority = INTERRUPT_HIGH_PRIORITY, .edge = INTERRUPT_RISING_EDGE};

INTERRUPT_RBX rb4_ob = {.INTERRUPT_ISR_CHANGE_HIGH = RB4_APP_ISR_HIGH, .INTERRUPT_ISR_CHANGE_LOW = RB4_APP_ISR_LOW, .pin.PORT = GPIO_PORTB, .pin.PIN = GPIO_PIN4, .pin.DIRECTION = GPIO_INPUT,
                        .source = INTERRUPT_RB4, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_ON_CHANGE};


INTERRUPT_RBX rb5_ob = {.INTERRUPT_ISR_CHANGE_HIGH = RB5_APP_ISR_HIGH, .INTERRUPT_ISR_CHANGE_LOW = RB5_APP_ISR_LOW, .pin.PORT = GPIO_PORTB, .pin.PIN = GPIO_PIN5, .pin.DIRECTION = GPIO_INPUT,
                        .source = INTERRUPT_RB5, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_ON_CHANGE};

INTERRUPT_RBX rb6_ob = {.INTERRUPT_ISR_CHANGE_HIGH = RB6_APP_ISR_HIGH, .INTERRUPT_ISR_CHANGE_LOW = RB6_APP_ISR_LOW, .pin.PORT = GPIO_PORTB, .pin.PIN = GPIO_PIN6, .pin.DIRECTION = GPIO_INPUT,
                        .source = INTERRUPT_RB6, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_ON_CHANGE};

INTERRUPT_RBX rb7_ob = {.INTERRUPT_ISR_CHANGE_HIGH = RB7_APP_ISR_HIGH, .INTERRUPT_ISR_CHANGE_LOW = RB7_APP_ISR_LOW, .pin.PORT = GPIO_PORTB, .pin.PIN = GPIO_PIN7, .pin.DIRECTION = GPIO_INPUT,
                        .source = INTERRUPT_RB7, .priority = INTERRUPT_LOW_PRIORITY, .edge = INTERRUPT_ON_CHANGE};


int main() {
    application_init();
    
    while (1) {
        
    }
        
    return (EXIT_SUCCESS);
}

void application_init(void) {
    ECUAL_LAYER_INIT();
    
    GPIO_LED_INIT(&led1);
    GPIO_LED_INIT(&led2);
    GPIO_LED_INIT(&led3);
    GPIO_LED_INIT(&led4);
    GPIO_LED_INIT(&led5);
    GPIO_LED_INIT(&led6);
    GPIO_LED_INIT(&led7);
    GPIO_LED_INIT(&led8);
    
    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int0_ob);
    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int1_ob);
    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int2_ob);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&rb4_ob);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&rb5_ob);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&rb6_ob);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&rb7_ob);
}

void INT0_APP_ISR(void){
    GPIO_LED_TURN_TOGGLE (&led1);
}

void INT1_APP_ISR(void){
    GPIO_LED_TURN_TOGGLE (&led2);
}

void INT2_APP_ISR(void){
    GPIO_LED_TURN_TOGGLE (&led3);
}

void RB4_APP_ISR_HIGH(void){
    GPIO_LED_TURN_ON(&led5);
}
void RB4_APP_ISR_LOW(void){
    GPIO_LED_TURN_ON(&led6);
}

void RB5_APP_ISR_HIGH(void){
    GPIO_LED_TURN_OFF(&led5);
}
void RB5_APP_ISR_LOW(void){
    GPIO_LED_TURN_OFF(&led6);
}

void RB6_APP_ISR_HIGH(void){
    GPIO_LED_TURN_ON(&led7);
}
void RB6_APP_ISR_LOW(void){
    GPIO_LED_TURN_ON(&led8);
}
void RB7_APP_ISR_HIGH(void){
    GPIO_LED_TURN_OFF(&led7);
}
void RB7_APP_ISR_LOW(void){
    GPIO_LED_TURN_OFF(&led8);
}