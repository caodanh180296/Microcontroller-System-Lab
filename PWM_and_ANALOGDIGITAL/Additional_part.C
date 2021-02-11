#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

void PWM_setup()
{
TCCR1A = (1 << WGM10) | (0 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
TCCR1B = (1 << CS10) | (1 << WGM12)| (0 << WGM13);


// Could not file prescaler
// clear OC1B on compare match, set OC1B at Bottom
// fast pwm mode
}

void adc_converter_setup()
{
	ADMUX |= (1<<ADLAR) | (1<<REFS0);
	// PA0 = ADC0
	// Left Adjust result
	// AVCC with external capacitor at AREF pin

	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADIE) ;
	// enable ADC
	// pre-scaler 2
	// enable interupt

}

void pin_setup()
{
	DDRC = 0xff; // all pins of Port C as output
	DDRB = 0xff; // all pins of Port B as output
	DDRD |= (1<<PD4); //set PD4 of Port 4 as output
}

ISR(ADC_vect)
{
	PORTB = ADCL;
	PORTC = ADCH;
}

int main()
{
	unsigned char i;
	unsigned char duty_cycle;

	PWM_setup();
	adc_converter_setup();
	pin_setup();

	sei();

	while(1)
	{
		for (i=1;i<=100;i++)
		{
			duty_cycle=(255/100)*i;
			OCR1B = duty_cycle;
			ADCSRA |= (1 << ADSC); // start a conversion
			_delay_ms(100);
		}

		for (i=1;i<=100;i++)
		{
			duty_cycle=(255/100)*(100-i);
			OCR1B = duty_cycle;
			ADCSRA |= (1 << ADSC); // start a conversion
			_delay_ms(100);
		}
	}
}