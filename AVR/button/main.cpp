#define __AVR_ATmega2560__

#include <avr/io.h>

bool read(uint8_t port, uint8_t pin){
	if ((port & (1 << pin)) > 0)
		return true;
	else
		return false;
}

void write(volatile uint8_t *port, uint8_t pin, bool value){
	if (value)
		*port |= (1 << pin);
	else
		*port &= ~(1 << pin);
}

int main(void){
	DDRB &= ~(1 << DDB7); //PB7 como entrada
	DDRB |= (1 << DDB6);  //PB6 como saida
	DDRB &= ~(1 << DDB5); //PB5 como entrada
	DDRB |= (1 << DDB4);  //PB4 como saida

	while(1){
		write(&PORTB, PORTB6, read(PINB, PINB7));
		write(&PORTB, PORTB4, read(PINB, PINB5));
	}
	return 0;

}
