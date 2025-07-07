/* 
 * File:   ECUAL_DC_MOTOR.c
 * Author: mohammedel-ahmady
 *
 * Created on July 6, 2025, 9:41 PM
 */

/******************* Section 0 : Includes *******************/

#include "ECUAL_DC_MOTOR.h"

/******************* Section 1 :  Variables Definitions *******************/



/******************* Section 2 :  Helper Functions Declarations *******************/



/******************* Section 3 : Software Interfaces Definitions (APIs) *******************/

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function initializes the direction control pins of the DC motor.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed pin init)
 */

Std_ReturnType GPIO_DC_MOTOR_INIT(const DC_MOTOR *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        for(uint8 i = 0; i < MOTOR_PINS; i++){
            Retval = GPIO_PIN_INIT(&(motor->INs[i]));
        }
    }
    return Retval;
}

#endif

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function reads the current rotation direction of the DC motor.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @param state     : Pointer to store the current rotation state @ref MOTOR_STATE
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed logic read)
 */

Std_ReturnType GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(const DC_MOTOR *motor, MOTOR_STATE *state){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor || NULL == state){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic[MOTOR_PINS];
        for(uint8 i = 0; i < MOTOR_PINS; i++){
            Retval = GPIO_PIN_READ_LOGIC(&(motor->INs[i]), &logic[i]);
        }
        
        if(logic[0] == GPIO_HIGH && logic[1] == GPIO_LOW){
            *state = MOTOR_CLOCKWISE;
        }
        else if(logic[0] == GPIO_LOW && logic[1] == GPIO_HIGH){
            *state = MOTOR_COUNTER_CLOCKWISE;
        }
        else{
            *state = MOTOR_BRAKE;
        }
    }
    return Retval;
}

#endif

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function stops the motor by setting both control pins to LOW.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed logic write)
 */

Std_ReturnType GPIO_DC_MOTOR_BRAKE(const DC_MOTOR *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic[MOTOR_PINS] = {GPIO_LOW, GPIO_LOW};
        for(uint8 i = 0; i < MOTOR_PINS; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(motor->INs[i]), logic[i]);
        }
    }
    return Retval;
}

#endif

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function rotates the DC motor in clockwise direction.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed logic write)
 */

Std_ReturnType GPIO_DC_MOTOR_ROTATE_CLOCKWISE(const DC_MOTOR *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic[MOTOR_PINS] = {GPIO_HIGH, GPIO_LOW};
        for(uint8 i = 0; i < MOTOR_PINS; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(motor->INs[i]), logic[i]);
        }
    }
    return Retval;
}

#endif

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function rotates the DC motor in counter-clockwise direction.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed logic write)
 */

Std_ReturnType GPIO_DC_MOTOR_ROTATE_COUNTER_CLOCKWISE(const DC_MOTOR *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_LOGIC logic[MOTOR_PINS] = {GPIO_LOW, GPIO_HIGH};
        for(uint8 i = 0; i < MOTOR_PINS; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(motor->INs[i]), logic[i]);
        }
    }
    return Retval;
}

#endif

#if ((DC_MOTOR_CFG_ENABLE) == (DC_MOTOR_CFG))

/**
 * @brief           : This function toggles the current rotation direction of the motor.
 *                    If the motor is rotating clockwise, it will switch to counter-clockwise and vice versa.
 * @param motor     : Pointer to motor configuration @ref GPIO_MOTOR
 * @return          : Status of the function
 *      (E_OK)      : The function completed successfully
 *      (E_NOT_OK)  : The function encountered an error (e.g., NULL pointer or failed internal calls)
 */

Std_ReturnType GPIO_DC_MOTOR_ROTATE_TOGGLE(const DC_MOTOR *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        MOTOR_STATE state = MOTOR_BRAKE;
        Retval = GPIO_DC_MOTOR_READ_ROTATE_DIRECTION(motor, &state);
        
        if(state == MOTOR_CLOCKWISE){
            Retval = GPIO_DC_MOTOR_ROTATE_COUNTER_CLOCKWISE(motor);
        }
        
        else{
            Retval = GPIO_DC_MOTOR_ROTATE_CLOCKWISE(motor);
        }
    }
    return Retval;
}

#endif

/******************* Section 2 :  Helper Functions Definitions *******************/