#include <avr/interrupt.h>
#include "EXTINT.h"
#include "UART.h"

using namespace EXT;

UART uart(9600, UART::Databits_8, UART::NONE, UART::ONE);

void int0_handler(void){
	uart.put('0');
	return;
}

void int1_handler(void){
	uart.put('1');
	return;
}

void int2_handler(void){
	uart.put('2');
	return;
}

void int3_handler(void){
	uart.put('3');
	return;
}

void int4_handler(void){
	uart.put('4');
	return;
}

void int5_handler(void){
	uart.put('5');
	return;
}

void int6_handler(void){
	uart.put('6');
	return;
}

void int7_handler(void){
	uart.put('7');
	return;
}

int main( void ){

	EXTINT int0_obj(EXTINT::INT_0, EXTINT::FALLING, &int0_handler);
	EXTINT int1_obj(EXTINT::INT_1, EXTINT::FALLING, &int1_handler);
	EXTINT int2_obj(EXTINT::INT_2, EXTINT::FALLING, &int2_handler);
	EXTINT int3_obj(EXTINT::INT_3, EXTINT::FALLING, &int3_handler);
	EXTINT int4_obj(EXTINT::INT_4, EXTINT::FALLING, &int4_handler);
	EXTINT int5_obj(EXTINT::INT_5, EXTINT::FALLING, &int5_handler);
	EXTINT int6_obj(EXTINT::INT_6, EXTINT::FALLING, &int6_handler);
	EXTINT int7_obj(EXTINT::INT_7, EXTINT::FALLING, &int7_handler);

	int0_obj.enable();
	int1_obj.enable();
	int2_obj.enable();
	int3_obj.enable();
	int4_obj.enable();
	int5_obj.enable();
	int6_obj.enable();
	int7_obj.enable();

	sei();
	while(1){
		if (uart.has_data()){
			uint8_t t = uart.get();
			uart.put(t);		/* echo the received character */
			uart.put((EICRA));
			uart.put((EICRB));
		}
	}

	return 0;
}
