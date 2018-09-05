#define FOSC 1843200// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)

#include <avr/io.h>

void USART_Init( unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
}

unsigned char USART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
		return UDR0;
}

int main(void){
	USART_Init(MYUBRR);
	while(1){
		USART_Transmit('a');
	}
}
