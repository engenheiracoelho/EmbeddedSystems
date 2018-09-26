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
		_bit = id;
		if (dir)
			DDRE |= (1 << _bit);
		else
			DDRE &= ~(1 << _bit);
		break;

	case 2:
	case 3:
		_bit = id + 2;
		if (dir)
			DDRE |= (1 << _bit);
		else
			DDRE &= ~(1 << _bit);
		break;

	case 4:
		_bit = DDG5;
		if (dir)
			DDRG |= (1 << _bit);
		else
			DDRG &= ~(1 << _bit);
		break;

	case 5:
		_bit = DDE3;
		if (dir)
			DDRE |= (1 << _bit);
		else
			DDRE &= ~(1 << _bit);
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		_bit = id - 3;
		if (dir)
			DDRH |= (1 << _bit);
		else
			DDRH &= ~(1 << _bit);
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		_bit = id - 6;
		if (dir)
			DDRB |= (1 << _bit);
		else
			DDRB &= ~(1 << _bit);
		break;

	}

}

GPIO::~GPIO() {}

bool GPIO::get() {
	switch (_id) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 5:
		return (bool) PINE & (1 << _bit);

	case 4:
		return (bool) PING & (1 << _bit);

	case 6:
	case 7:
	case 8:
	case 9:
		return (bool) PINH & (1 << _bit);

	case 10:
	case 11:
	case 12:
	case 13:
		return (bool) PINB & (1 << _bit);
	}
}

void GPIO::set(bool val) {
	switch (_id) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 5:
		if (val)
			PORTE |= (1 << _bit);
		else
			PORTE &= ~(1 << _bit);
		break;

	case 4:
		if (val)
			PORTG |= (1 << _bit);
		else
			PORTG &= ~(1 << _bit);
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		if (val)
			PORTH |= (1 << _bit);
		else
			PORTH &= ~(1 << _bit);
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		if (val)
			PORTB |= (1 << _bit);
		else
			PORTB &= ~(1 << _bit);
		break;

	}

}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	switch (_id) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 5:
		PINE = (1 << _bit);
		break;

	case 4:
		PING = (1 << _bit);
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		PINH = (1 << _bit);
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		PINB = (1 << _bit);
		break;

	}
}
