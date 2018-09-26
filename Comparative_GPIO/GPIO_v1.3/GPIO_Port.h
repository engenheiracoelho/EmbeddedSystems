
#ifndef GPIO_PORT_H_
#define GPIO_PORT_H_

#include <avr/io.h>


namespace GPIO_PORT {

class GPIO_Port {
public:
    void dir(uint8_t p, bool io);
    void set(uint8_t p, bool val = 1);
    void clear(uint8_t p);
    bool  get(uint8_t p);
    void toggle(uint8_t p);

private:
    uint8_t pin;
    uint8_t ddr;
    uint8_t port;
};

extern GPIO_Port * PB;
extern GPIO_Port * PE;
extern GPIO_Port * PG;
extern GPIO_Port * PH;


} /* namespace GPIO_PORT */
#endif /* GPIO_PORT_H_ */
