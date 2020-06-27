#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#include "SoftSpi/SoftSpi.h"
#include "ThreeTimesSevenSegDisp/ThreeTimesSevenSegDisp.h"

#define delay_ms_1Mhz(x) (_delay_ms(x))   // Delay when prescaller set to 8x
#define delay_ms_16Mhz(x) (_delay_ms(x*16)) // Delay when prescaller set to 1x so we need to burn 8x as many cycles

#define LED (1<<PB5)
#define SENSOR PD3

volatile uint8_t digNr = 0;
volatile uint8_t calcSpeed = 0;
volatile uint8_t pulseCount = 0;
volatile uint8_t displayDigit = 0;

uint8_t hundreds = 0;
uint8_t tens = 0;
uint8_t unity = 0;

uint8_t helpVar = 0;

char digit[10] = {
	0xc0, //0
	0xf9, //1
	0xa4, //2
	0xb0, //3
	0x99, //4
	0x92, //5
	0x82, //6
	0xf8, //7
	0x80, //8
	0x90  //9
};

ISR(TIMER0_COMPA_vect)    // Timer1 ISR
{
	if(digNr>3) digNr=0;
	digNr++;
	displayDigit = 1;
}
ISR(TIMER1_COMPA_vect)    // Timer1 ISR
{
	PORTB ^= LED;
	calcSpeed = 1;
}
ISR(INT0_vect)
{
	pulseCount++;
}
int main()
{
	initSoftSpi();
	initDisplay();
	DDRB |= LED;
	
	//------EXTERNAL INTERRUPT------//
	PORTD = (1<<SENSOR);
	EICRA |= (1<<ISC01);	//FALLING EDGE
	EIMSK = (1<<INT0);
	
	//------TIMER0------//
	TCCR0A = (1<<WGM01);
	OCR0A = 222;
	TIMSK0 = (1<<OCIE0A);
	TCCR0B = (1<<CS01)|(1<<CS00);
	
	//------TIMER1------//
	TCCR1B = (1<<WGM12);		//CTC clear timer on compare
	OCR1A = 15625;				//every second, information to calculate speed
	TIMSK1 = (1<<OCIE1A);
	TCCR1B |= (1<<CS12) | (1<<CS10); //Preskaler
	
	sei();						//interrupts ON
	
	while(1)
	{
		if(calcSpeed == 1)
		{
			hundreds = pulseCount/100;
			tens = (pulseCount - 100*hundreds)/10;
			unity = pulseCount%10;
			helpVar++;
			calcSpeed = 0;
			pulseCount = 0;
		}
		if(displayDigit==1)
		{
			if(digNr==1)
			{
				sendSoftSpi(digit[hundreds]);
				digit1Run();
			}else if (digNr==2)
			{
				sendSoftSpi(digit[tens]);
				digit2Run();
			}else if (digNr==3)
			{
				sendSoftSpi(digit[unity]);
				digit3Run();
				digNr=0;
			}
			displayDigit = 0;
		}
	}
}