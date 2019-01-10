#include "GPIO.h"

GPIO::GPIO(uint8_t id, PortDirection_t dir)
{
	_bit = pgm_read_byte(GPIO_PORT::id_to_bit+id);
	_port = GPIO_PORT::AllPorts[pgm_read_byte(GPIO_PORT::id_to_port+id)];
	_port->dir(_bit, dir);
}

GPIO::~GPIO() {}

bool GPIO::get() {
	return _port->get(_bit);
}

void GPIO::set(bool val) {
	_port->set(_bit, val);
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
	_port->toggle(_bit);
}
