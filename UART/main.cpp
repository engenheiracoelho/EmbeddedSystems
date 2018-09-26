#include <avr/io.h>
#include "UART.h"

int main(void){

	UART uart_t(9600,UART::Databits_8,UART::NONE,UART::ONE);
		while(1){
			uart_t.UART_Transmit('a');
	}
}
