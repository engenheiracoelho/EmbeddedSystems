#include <avr/io.h>
#include "USART.h"

int main(void){

	// Usar sei() para habilitar a interrupção globalmente.

	USART USART_t(9600,USART::Databits_8,USART::NONE,USART::ONE);
		while(1){
			USART_t.USART_Transmit('a');
	}
}
