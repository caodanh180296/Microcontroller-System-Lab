/*
Lab 2.1
Additional part a
*/

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


unsigned char tot_overflow = 0;

void timer2_setup()
{
	TCCR2 |= (1<<WGM21) | (1<<WGM20)| (1<<CS20) | (1<<CS21)| (1<<CS22); // Fast PWM mode; 1024 pre-scalar
	TCNT2 = 0; // Set initial value of counter
	TIMSK |= (1<<TOIE2); // Enable Overflow Interrupt
	sei();
}

ISR(TIMER2_OVF_vect)
{
	tot_overflow++; // counting number of times the timer overflow
}

void pin_setup()
{
	DDRD=255; // set all pins of Port C as output
}

int main(void)
{
	pin_setup();
	timer2_setup();
	while(1){
		PORTD ^= (1<<PD6); // this line is strange ?????????
		if ( tot_overflow >= 61)
		{	
			if (TCNT2>=9)
			{
				TCNT2 = 0;            // reset counter
				tot_overflow=0;	// overflow count reset
				PORTD ^= (1<<PD3);	//light up led at pin PC3
			}
			
		}
	}
}