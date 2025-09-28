/* 
 * File:   Main.h
 * Author: mohammedel-ahmady
 *
 * Created on June 21, 2025, 4:22 AM
 */

#include "Main.h"

Std_ReturnType Ret = E_OK;

int main(void) {
    application_init();

    while(1){
    }
    return (EXIT_SUCCESS);
}

void application_init(void){
    ECUAL_LAYER_INIT();
}