/*
 * UART.cpp
 *
 * Created on: 26 de Set de 2018
 *    Author: Leticia Coelho
 */

#include <avr/interrupt.h>
#include "UART.h"

UART::UART(int Baud, Databits_t Data,Parity_t Parity, Stop_bit_t Stop){

	uint16_t MYUBRR = (F_CPU/16/Baud-1);
	UBRR0 = MYUBRR;
	UCSR0B = (1<<RXEN0)||(1<<TXEN0)||(1<<RXCIE0);
	UCSR0C = Data|Parity|Stop;
	_new_data = false;
	_rx_buffer = 0;
	_tx_buffer = 0;
}

~UART(){}

void UART::UART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
}

unsigned char UART::UART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
		return UDR0;
}

ISR(UART_RX_vect)
{UART::rx_isr();}
void UART::rx_isr(){
	self()->_rx_buffer = UDR0;
	self()->_new_data = true;
	return;
}

ISR(USART_UDRE_vect)
{UART::tx_isr();}
void UART::tx_isr(){
	// Insert the FIFO here.
	UDR0 = self()->_tx_buffer;
	UCSR0B |= (1<<UDRIE0);
}

uint8_t UART::get(){
	_new_data=false;
	return _rx_buffer;
}

void UART::put(uint8_t data){
	_tx_buffer = data;
	UCSR0B &= ~(1<<UDRIE0);
}

bool UART::has_data(){
	return _new_data;
}
