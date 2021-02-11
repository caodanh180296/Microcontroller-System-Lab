/* Change the brightness of LED to demonstrate PWM, change average voltage on pin PB3
*/
/* Lab 3_Nguyen Cao Danh
Mandatory part*/

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


void PWM_setup()
{
TCCR1A = (1 << WGM10) | (0 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
TCCR1B = (1 << CS10) | (1 << WGM12)| (0 << WGM13);

// fast pwm mode
// No prescaler
// clear OC1B on compare match, set OC1B at Bottom
}

void pin_setup()
{
	DDRD |= (1<<PD4); // Set PD4 as output
}

int main()
{
	unsigned char i, duty_cycle;

	PWM_setup();
	pin_setup();
	
	while(1)
	{
		for (i=1;i<=100;i++)
		{
			duty_cycle=(255/100)*i;
			OCR1B = duty_cycle;
			_delay_ms(25);
		}

		for (i=1;i<=100;i++)
		{
			duty_cycle=(255/100)*(100-i);
			OCR1B = duty_cycle;
			_delay_ms(25);
		}
	}
	
}