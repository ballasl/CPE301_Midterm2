/*
 * CpE301 - Midterm 2-TX.c
 *
 * Created: 17-Apr-18 3:28:59 PM
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "nrf24l01.h" 

#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD - 1
void setup_timer(void); 
nRF24L01 *setup_rf(void); 
void usart_init();
int USART0SendByte(char u8Data);
void USARTSendStr(char* _str);
void adc_init(void);

volatile bool rf_interrupt = false;
volatile bool send_message = false;
char* tempTemplate = "TX: Temperature is %u degrees Fahrnheit\n";

int main(void)
{
    uint8_t to_address[5] = { 0x01, 0x01, 0x01, 0x01, 0x01 }; 
	int16_t adc_value;
	int8_t temp;
	char printBuffer[64];

	nRF24L01 *rf = setup_rf();
	setup_timer();
	adc_init();
	usart_init();

	sei();
  
	while (1) 
	{
		if (rf_interrupt) {
			rf_interrupt = false;
			int success = nRF24L01_transmit_success(rf);
			if (success != 0)
				nRF24L01_flush_transmit_message(rf);
		}

		if (send_message) {
			send_message = false;
			/* Start the ADC conversion */
			ADCSRA |= (1 << ADSC); 
			/* Wait for completion. ADSC reads 1 while still in progress */
			while (ADCSRA	&	(1<<ADSC));
			/* save ADC value to a variable */
			adc_value=ADCL;
			adc_value = (ADCH<<8) + adc_value;
			/*
				For LM34:
				Vout = + 10.0 mV/ºF
				So the temperature will be:
				temp = adc_value * (5V/adcresolution) / 10.0mV
				or:
			*/
			temp = ((float)adc_value * 5 / 1024) / 0.010;
			sprintf(printBuffer, tempTemplate, temp);
			USARTSendStr(printBuffer);

			nRF24L01Message msg;

			/* We will send only the value in alfa format to the Receiver */
			itoa(temp, (char*)msg.data, 10);
			msg.length = strlen((char *)msg.data) + 1;
			nRF24L01_transmit(rf, to_address, &msg);
		}
	}
}

nRF24L01 *setup_rf(void) { 

	nRF24L01 *rf = nRF24L01_init(); 
	rf->ss.port = &PORTB;
	rf->ss.pin = PINB2; 
	rf->ce.port = &PORTB; 
	rf->ce.pin = PINB1;   
	rf->sck.port = &PORTB; 
	rf->sck.pin = PINB5;   
	rf->mosi.port = &PORTB;  
	rf->mosi.pin = PINB3;   
	rf->miso.port = &PORTB;  
	rf->miso.pin = PINB4; 
	EICRA |= (1<<ISC01); // Falling edge generates interrupt
	EIMSK |= (1<<INT0); // Use INT0 (PD2)
	nRF24L01_begin(rf); 
	return rf; 
}

// nRF24L01 interrupt
ISR(INT0_vect) {
     rf_interrupt = true; 
}

// setup timer to trigger interrupt every second when at 16MHz
void setup_timer(void) { 
	TCCR1A = 0;
	// set up timer with CTC mode and prescaling = 256
	TCCR1B |= (1 << WGM12)|(1 << CS12);
	
	// initialize counter
	TCNT1 = 0;
	/*
	 Initialize compare value
	 With prescalar = 256, the frequency is 16,000,000 Hz / 256 -> period = 0.000016 sec
	 TimerCount=Requireddelay/period -1
	 For example, for 1 sec delay -> TimerCount = 1/0.000016 -1 = 62499
	 Let's consider this as the value for our delay.
	*/

	OCR1A = 62499; // value for 1 second delay
	// Enable compare interrupt
	TIMSK1 |= (1 << OCIE1A);
}

// each one second interrupt
ISR(TIMER1_COMPA_vect) {
	send_message = true;
}

void usart_init()
{
	UBRR0H = (MYUBRR) >> 8;
	UBRR0L = MYUBRR;
	UCSR0B |= (1 << TXEN0); // Enable transmitter
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
}

void adc_init(void)
{
	ADMUX = 0; // use ADC0
	ADMUX |=  (1 << REFS0); // // use AVcc as the reference
	/*
		ADC operates within a frequency range between 50Kz and 200Kz
		With a prescaler of 128 at CPU clock frequency of 16Mz, we will be in range:
		F_ADC=F_CPU/128 = 125
		So:
	*/
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescaler for CPU@16Mhz
	ADCSRB = 0; // 0 for free running mode
	ADCSRA |= (1 << ADEN); // Enable the ADC
}