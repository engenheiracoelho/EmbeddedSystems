
#include "GPIO_Port.h"

namespace GPIO_PORT {

enum PORT_ADDR_BASE {
	AVR_PB = 0x0023,
	AVR_PE = 0x002C,
	AVR_PG = 0x0032,
	AVR_PH = 0x0100
};

GPIO_Port * PB = reinterpret_cast<GPIO_Port*>(AVR_PB);
GPIO_Port * PE = reinterpret_cast<GPIO_Port*>(AVR_PE);
GPIO_Port * PG = reinterpret_cast<GPIO_Port*>(AVR_PG);
GPIO_Port * PH = reinterpret_cast<GPIO_Port*>(AVR_PH);

//GPIO_Port * PB = (GPIO_Port *)AVR_PB;


void GPIO_Port::dir(uint8_t p, bool io) {
    if (io)
        ddr |= p;
    else
        ddr &= ~p;
}

void GPIO_Port::set(uint8_t p, bool val) {
    if (val)
        port |= p;
    else
        port &= ~p;
}
void GPIO_Port::clear(uint8_t p) {
    set(p,0);
}
bool GPIO_Port::get(uint8_t p) {
    return pin & p;
}

void GPIO_Port::toggle(uint8_t p) {
	pin = p;
}


} /* namespace GPIO_PORT */
