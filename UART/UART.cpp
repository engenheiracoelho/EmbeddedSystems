/*
 * UART.cpp
 *
 * Created on: 26 de Set de 2018
 *    Author: Leticia Coelho
 */

#include "UART.h"

UART::UART(int Baud, Databits_t Data,Parity_t Parity, Stop_bit_t Stop){

	uint16_t MYUBRR = (F_CPU/16/Baud-1);
	UBRR0 = MYUBRR;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = Data|Parity|Stop;

}

void UART::UART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
}

unsigned char UART::UART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
		return UDR0;
}
