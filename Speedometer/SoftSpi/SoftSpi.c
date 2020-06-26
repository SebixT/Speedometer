/*
 * SoftSpi.c
 *
 * Created: 2020-03-29 19:28:29
 *  Author: Sebastian
 */ 
#include<avr/io.h>
#include<util/delay.h>

#include "SoftSpi.h"

void initSoftSpi()
{
	DDRB |= (1<<MOSI) | (1<<SCK) | (1<<CS);
	PORTB &= ~((1<<MOSI) | (1<<SCK) | (1<<CS));
}
void sendSoftSpi( uint8_t data)
{
	uint8_t cnt = 0x80;
	SCK_0;
	while(cnt)
	{
		if(data & cnt) MOSI_1;
		else MOSI_0;
		SCK_1;
		SCK_0;
		cnt>>=1;
	}
	PORTB |= (1<<CS);
	_delay_us(10);
	PORTB &= ~(1<<CS);
}