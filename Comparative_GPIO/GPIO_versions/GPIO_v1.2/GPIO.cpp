/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include <avr/io.h>
#include "GPIO.h"

GPIO::GPIO(uint8_t id, PortDirection_t dir):
_id(id)
{
	switch (_id) {
	case 0:
	case 1:
		_bit = (1 << id);
		_pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;

	case 2:
	case 3:
		_bit = (1 << (id + 2));
		_pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;

	case 4:
		_bit = (1 << DDG5);
		_pin = &PING;
		_ddr = &DDRG;
		_port = &PORTG;
		break;

	case 5:
		_bit = (1 << DDE3);
		_pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		_bit = (1 << (id - 3));
		_pin = &PINH;
		_ddr = &DDRH;
		_port = &PORTH;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		_bit = (1 << (id - 6));
		_pin = &PINB;
		_ddr = &DDRB;
		_port = &PORTB;
		break;

	}

	if (dir)
		*_ddr |= _bit;
	else
		*_ddr &= ~_bit;

}

GPIO::~GPIO() {}


bool GPIO::get() {
	return (bool) _pin & _bit;
}


void GPIO::set(bool val) {
	if (val)
		*_port |= _bit;
	else
		*_port &= ~_bit;
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	*_pin = _bit;
}
