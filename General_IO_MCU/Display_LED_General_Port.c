/*
 * Lab_1.1.c
 * Author : Nguyen Cao Danh
 * Mandatory Part a
 */ 

#define F_CPU 16000000 

#include <avr/io.h> // AVR library
#include <util/delay.h> // Delay library


int main(void)
{
	DDRB=255; // Setting up all pins of Port A as Output
	int array[5]={1, 3, 5, 9, 17}; // Declaring all required numbers as Global variables
	while (1)
	{
		for (int i=0;i<=4;i++) // displaying of Leds in Port A
		{
			PORTB = array[i];
			_delay_ms(1000); // delay of one second
		}	
	}
	return 0;
}