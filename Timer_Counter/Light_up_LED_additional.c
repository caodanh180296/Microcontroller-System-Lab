/*
Lab 2.1
Additonal part b
*/
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char tot_overflow = 0 , i=0; // declare global variable

void timer0_setup()
{
	TCCR0 |= (1<<WGM01) | (1<<WGM00)| (1<<CS00) | (1<<CS02); // Fast PWM mode; 1024 pre-scalar
	TCNT0 = 0; // Set initial value of counter
	TIMSK |= (1<<TOIE0); // Enable Overflow Interrupt
	sei();
}

ISR(TIMER0_OVF_vect)
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
	timer0_setup();

	while(1)
	{
		_delay_ms(50); 
		if ( tot_overflow>= 61)
		{
			if (TCNT0>=9)
			{
				i++;
				TCNT0 = 0;            // reset counter
				tot_overflow=0 ;//reset overflow counter
				if ((i==1) | (i==2) | (i==4) |(i==6))
				{
					PORTD = (1<<PD3);	//light up led at pin PC3
					_delay_ms(200);
					PORTD = (0<<PD3);	//turn of Led at pin PC3
					if (i==6)
					{
						i=0;
					}
				}
			}
		}
	}
}

// Change the blinking speed of LED by 1 second step