# include <stdio.h>
# include <avr/io.h>
#include "GPIO_PORT.h"

# ifndef GPIO_H_
# define GPIO_H_

class gpio {
    public:
        enum PortDirection_t{
            INPUT =0,
            OUTPUT =1
        };
        GPIO(int id, int direction);
        ~GPIO();
        bool GET();
        bool SET(bool value=1);
        bool Clear();
        bool Toggle();
    private:
      int _id;
      int _pin;
      int _port;
};
