/*
 * Lab_1.1.c
 * Author : Nguyen Cao Danh
 * Mandatory Part b
 */ 

#define F_CPU 16000000

#include <avr/io.h> // AVR library
#include <util/delay.h> // Delay library

int main(void)
{
	DDRB=255; // Setting up Port B as Output
	int array[8]={1, 128, 2, 64, 4, 32, 8, 16};
	int i;
	
	while(1)
	{
		for (i=0;i<=7;i++) // displaying of Leds in Port B from 1 to 8
		{
			PORTB=array[i];
			_delay_ms(1000); // delay of one second
		}
	
		for (i=0;i<=7;i++) // displaying of Leds in Port B from 8 to 16
		{
			PORTB=array[7-i];
			_delay_ms(1000); // delay of one second
		}
	}
	return 0;
}