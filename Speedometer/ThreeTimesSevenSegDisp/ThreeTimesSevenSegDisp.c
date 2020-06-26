/*
 * ThreeTimesSevenSegDisp.c
 *
 * Created: 2020-03-29 19:52:27
 *  Author: Sebastian
 */ 
#include<avr/io.h>
#include<util/delay.h>

#include "ThreeTimesSevenSegDisp.h"

void initDisplay()
{
	DDRC |= (1<<DIGIT1)|(1<<DIGIT2)|(1<<DIGIT3);
	PORTC = 0;
}
void digit1Run()
{
	PORTC |= (1<<DIGIT1);
	PORTC &= ~(1<<DIGIT2);
	PORTC &= ~(1<<DIGIT3);
}
void digit2Run()
{
	PORTC |= (1<<DIGIT2);
	PORTC &= ~(1<<DIGIT1);
	PORTC &= ~(1<<DIGIT3);
}
void digit3Run()
{
	PORTC |= (1<<DIGIT3);
	PORTC &= ~(1<<DIGIT1);
	PORTC &= ~(1<<DIGIT2);
}