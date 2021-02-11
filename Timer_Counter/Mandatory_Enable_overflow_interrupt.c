#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char tot_overflow = 0;

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
	DDRD=255; // set all pins of Port D as output
	PORTD=0;
}
int main(void)
{
	pin_setup();
	timer0_setup();
	while(1)
	{
	   _delay_ms(20);//This line for the code to run????	
		if ( tot_overflow>= 30)
		{
		     if (TCNT0>=133)
			{
				PORTD=TCNT0;
				TCNT0=0;
				tot_overflow=0;
				_delay_ms(500);
			}
			
		}
	}
}