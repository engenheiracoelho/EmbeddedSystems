#include "avr/io.h"
#include "avr/interrupt.h"
#include <util/delay.h>

bool state = true;
long count=0;
long last_interrupt = 0;
long count_cicle = 2000000000;

void write_led(volatile uint8_t *port, uint8_t pin,bool state){
	if(state){
		*port |= (1 << pin); // Led ON
	} else {
		*port &= ~(1 << pin); //Led OFF
	}
}

ISR(INT4_vect){
	if(debounce())
    	state = !state;
}

bool debounce(){
    if(count - interrupt>16000) {
    	last_interrupt = count;
        return true;
    }
    else
        return false;
}

int main(void) {
	DDRH |= (1 << DD6);
	EIMSK |= (1 << 4);

	sei();
    while(1) {
        write_led(&PORTH,PORTH6,state);
        count++;
        if(count>count_cicle){
          last_interrupt = 0;
        	count = 0;
        }
    }
}
