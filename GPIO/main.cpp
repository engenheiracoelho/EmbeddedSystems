#include <avr/io.h>
#include <util/delay.h>
#include "GPIO.h"


//LEDS PLACA (acende com '0')
GPIO led0(0, GPIO::OUTPUT);		//PE0
GPIO led1(1, GPIO::OUTPUT);		//PE1

//LEDS PLACA (acende com '1')
GPIO led13(13, GPIO::OUTPUT);	//PB7

//Adicionar LED
GPIO led4(4, GPIO::OUTPUT);		//PG5
GPIO led6(6, GPIO::OUTPUT);		//PH0

int main(void){

	UCSR0B = 0;

	led0.set(1);
	led1.set(1);
	led6.clear();
	led4.clear();
	led13.clear();
	_delay_ms(1000);
	led0.clear();
	led1.clear();
	led6.set(1);
	led4.set(1);
	led13.set(1);
	_delay_ms(1000);

	while (1){
		led0.toggle();
		led1.toggle();
		led6.toggle();
		led4.toggle();
		led13.toggle();
		_delay_ms(1000);
	}

}
