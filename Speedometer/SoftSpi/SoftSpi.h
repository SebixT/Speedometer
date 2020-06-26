/*
 * SoftSpi.h
 *
 * Created: 2020-03-29 19:28:35
 *  Author: Sebastian
 */ 


#ifndef SOFTSPI_H_
#define SOFTSPI_H_


#define MOSI PB1			//SER PIN
#define SCK PB2				//SCK CLOCK
#define CS PB3				//RCK LATCH
#define SCK_0 PORTB &= ~(1<<SCK)
#define SCK_1 PORTB |= (1<<SCK)
#define MOSI_0 PORTB &= ~(1<<MOSI)
#define MOSI_1 PORTB |= (1<<MOSI)


void initSoftSpi();
void sendSoftSpi( uint8_t data);

#endif /* SOFTSPI_H_ */