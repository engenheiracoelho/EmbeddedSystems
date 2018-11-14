/*
 * USART.cpp
 *
 * Created on: 26 de Set de 2018
 *    Author: Leticia Coelho
 */

#include "USART.h"
#include <avr/interrupt.h>

USART::USART(int Baud, Databits_t Data,Parity_t Parity, Stop_bit_t Stop){

	uint16_t MYUBRR = (F_CPU/16/Baud-1);
	UBRR0 = MYUBRR;
	UCSR0B = (1<<RXEN0)||(1<<TXEN0)||(1<<RXCIE0);
	UCSR0C = Data|Parity|Stop;
}

void USART::USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
}

unsigned char USART::USART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
		return UDR0;
}

ISR(USART_RX_vect)
{USART::rx_isr();}
void USART::rx_isr(){
	_rx_buffer = UDR0;
	_new_data = true;
	return;
}

ISR(USART_UDRE_vect)
{USART::tx_isr();}
void USART::tx_isr(){
	// Coloca a fifo aqui, deve ser colocado e dado.
	UDR0 = _tx_buffer;
	UCSR0B |= (1<<UDRIE0);
}

uint8_t USART::get(){
	_new_data=false;
	return _rx_buffer;
}

void USART::put(uint8_t data){
	_tx_buffer = data;
	UCSR0B &= ~(1<<UDRIE0);
}

bool USART::has_data(){
	return _new_data;
}
