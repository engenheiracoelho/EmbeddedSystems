#include "UART.h"

UART::UART(int baud, DataBits_t data, Parity_t parity, StopBit_t stop, DoubleSpeed_t speed) {
	// Equation for Calculating UBRR Value:
	uint16_t MYUBRR;
	if (speed == 0) {
		MYUBRR = (F_CPU/16/baud) - 1;
	} else {
		MYUBRR = (F_CPU/8/baud) - 1;
	}
	UBRR0 = MYUBRR;

	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

	UCSR0C = data | parity | stop;

	UCSR0A |= speed;

	_rx_buffer.clear();
	_tx_buffer.clear();
}

UART::~UART() {}

bool UART::has_data() {
	return _rx_buffer.get_size();
}

ISR(USART0_RX_vect) {UART::rx_isr();}

void UART::rx_isr() {
	if (self()->_rx_buffer.cheia()) {
		return;
	}
	self()->_rx_buffer.push(UDR0);
}

uint8_t UART::get() {
	while (_rx_buffer.vazia());
	return _rx_buffer.pop();
}

ISR(USART0_UDRE_vect) {UART::tx_isr();}

void UART::tx_isr() {
	UDR0 = self()->_tx_buffer.pop();
	if (self()->_tx_buffer.vazia()) {
		UCSR0B &= ~(1 << UDRIE0); // coloca zero no registrador na posição UDRIE0
	}
}

void UART::put(uint8_t dado) {
	while (_tx_buffer.cheia());

	_tx_buffer.push(dado);
	UCSR0B |= (1 << UDRIE0); // coloca um no registrador na posição UDRIE0
}

void UART::puts(char* dado) {
	for (int i = 0; dado[i] != '\0'; i++) {
		UART::put(dado[i]);
	}
}
