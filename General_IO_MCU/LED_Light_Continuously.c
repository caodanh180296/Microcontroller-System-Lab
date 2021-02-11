/*
 * Lab_1.1.c
 * Author : Nguyen Cao Danh
 * Additional part 
 */ 

#define F_CPU 16000000

#include <avr/io.h> // AVR library
#include <util/delay.h> // Delay library

int main(void) 
{
	DDRA=0; // Setting up all pins of Port A as Input
	DDRB=255; // Setting up all pins of Port B as Output
	PORTA |= 1<<2; // Activate pull up resistor PB2
	PORTA |= 1<<3; // Activate pull up resistor PB3
	char i=1;
	
	while (1) 
	{
		PORTB=i;
		if (!(PINA & (1<<2))) // Monitoring of pin PB2
		{
			i++;
		}
		if (!(PINA & (1<<3))) // Monitoring of pin PB3
		{
			i--;
		}
		_delay_ms(500);
   }
    return 0;
}

