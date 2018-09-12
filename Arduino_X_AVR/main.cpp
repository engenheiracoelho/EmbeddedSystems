
#include <avr/io.h>
#include <util/delay.h>

int main(){

	UCSR0B = 0;
	DDRB = 0xFF;
	DDRE = 0xFF;
	while(1){
		PORTB = 0x00;
		PORTE = 0x00;
		_delay_ms(1000);
		PORTB = 0xFF;
		PORTE = 0xFF;
		_delay_ms(1000);
	}
	return 1;
}
