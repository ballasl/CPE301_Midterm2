/*
 * CpE301 - Midterm 2-RX.c
 *
 * Created: 17-Apr-18 3:39:13 PM
  */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nrf24l01.h"
#include "nrf24l01-mnemonics.h"

nRF24L01 *setup_rf(void);
void process_message(char *message);
void usart_init();
int USART0SendByte(char u8Data);

volatile bool rf_interrupt = false;
char* tempTemplate = "RX: Temperature is %s degrees Fahrenheit\n";
void USARTSendStr(char* _str);

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD - 1

int main(void) {
	uint8_t address[5] = { 0x01, 0x01, 0x01, 0x01, 0x01 };

	usart_init();
	
	nRF24L01 *rf = setup_rf();
	sei();
	nRF24L01_listen(rf, 0, address);
	uint8_t addr[5];
	nRF24L01_read_register(rf, CONFIG, addr, 1);

	while (true) {
		if (rf_interrupt) {
			rf_interrupt = false;
//USARTSendStr("INT0\n");
			while (nRF24L01_data_received(rf)) {
				nRF24L01Message msg;
				nRF24L01_read_received_data(rf, &msg);
				/* Write to UART RX for display on a RS232 terminal */
				process_message((char *)msg.data);
			}
			nRF24L01_listen(rf, 0, address);
		}
	}

	return 0;
}

nRF24L01 *setup_rf(void) {
	nRF24L01 *rf = nRF24L01_init();

	//DDRB |= (1<<DDB1);

	rf->ss.port = &PORTL;
	rf->ss.pin = PINL1;
	rf->ce.port = &PORTB;
	rf->ce.pin = PINB0;

	rf->sck.port = &PORTB;
	rf->sck.pin = PINB1;
	rf->mosi.port = &PORTB;
	rf->mosi.pin = PINB2;
	rf->miso.port = &PORTB;
	rf->miso.pin = PINB3;
	// interrupt on falling edge of INT0 (PD2)
	//DDRD = 0xFE;
	//PORTD &= ~0x01;
	EICRA |= (1<<ISC01);
	EIMSK |= (1<<INT0);
	nRF24L01_begin(rf);
	return rf;
}

void process_message(char *message) {
	char printBuffer[64];
	sprintf(printBuffer, tempTemplate, message);
	USARTSendStr(printBuffer);
}

// nRF24L01 interrupt
ISR(INT0_vect) {
	rf_interrupt = true;
}

void usart_init()
{
	UBRR0H = (MYUBRR) >> 8;
	UBRR0L = MYUBRR;
	UCSR0B |= (1 << TXEN0); // Enable Transmitter
	UCSR0C |=  (1 << UCSZ01) | (1 << UCSZ00); // Set frame: 8data, 1 stop
}

int USART0SendByte(char u8Data)
{
	//wait while previous byte is completed
	while(!(UCSR0A&(1<<UDRE0))){};
	// Transmit data
	UDR0=u8Data;
	return 0;
}

void USARTSendStr(char* _str)
{
	int thesize=strlen(_str);
	for (uint8_t i=0; i<thesize;i++)
	{
		USART0SendByte(_str[i]);
	}
};