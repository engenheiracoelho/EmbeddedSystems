# PWM

This experiment is based on contents of [this UFSC project](http://www.lisha.ufsc.br/teaching/quark/).

Here we are going to build an experiment with an led to learn and start using the PWM. PWM is called Pulse Width Modulation, and it is basically a technique used in many areas of electronics, perhaps the most common is the use in switching power supplies but can also be used for motor speed control, light control, servo motor control and many other applications. Here we will use the PWM functionality to control the light intensity of one led. Before we start it is necessary to know the two essential configurations of the PWM. Practically, what we do with the PWM, is to configure the pulse width - the period a wave stays high - and the frequency in wich we want the signal to operate - how fast or how slow will be the pulse width. Therefore to configure the pulse width we use the “duty cycle” parameter and to configure the frequency he use the signal’s frequency parameter. The duty cycle is given as a percentage of the signals period, on wich the signal is high (Duty Cycle = Pulse Width x 100 / Period) and is set on a microcontroller by storing the duty value in a register (duty value from 0 - 0% to 256 - 100% in 8 bits registers and from 0 - 0% to 1024 - 100% in 16 bits registers).
![Assembly](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/Image/PWM_Schema.jpg)
The frequency parameter of the generated signal is set on the microcontroller by dividing its timers clock frequency with prescalers as commonly 1, 8, 64, 256 and 1024. Per example, if the clock frequency of the microcontroller is 16MHz and dividing it by the prescaler 1, the signal frequency will be 16MHz - consequently the pulse width will be really fast- and dividing it by the maximal prescaler of 1024, the signal frequency will be 16KHz - consequently the pulse width will be more slow. Finally, to apply the PWM functionality on the digital signal that will control the LED light, we need to connect the led on digital pins that already are configured to use the pwm and they are D3, D5, D6, D9, D10 and D11.

# Code
1. [PWM Code](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/PWM/PWM.ino).

# Schematic
![Assembly](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/Image/pwm.png)

# Part List
* 1 LED
* 1 220 ohm resistor
* 1 Protoboard
* 2 copper wires (tinned) or jumpers

# Tools
* AVR GCC and tools
* Arduino IDE
