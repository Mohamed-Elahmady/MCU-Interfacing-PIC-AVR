#include <stdio.h>
#define PORTA (*((volatile unsigned char *)(0xF80)))
#define PORTB (*((volatile unsigned char *)(0xF81)))
#define PORTC (*((volatile unsigned char *)(0xF82)))
#define PORTD (*((volatile unsigned char *)(0xF83)))
#define PORTE (*((volatile unsigned char *)(0xF84)))

volatile unsigned char *ptr =((volatile unsigned char *)(0xF82));

unsigned int var = 0;

int main(){

    while (1)
    {
        var = hw_reg8();
        do
        {
            //motor_turn_left();
        } while (var != 1);
    }
    

    return 0;
}