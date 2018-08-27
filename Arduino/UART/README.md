# UART

UART is the universal asynchronous receiver transmitter and is one type of serial communication. Serial communication just means that only one bit of information is sent a time (as opposed to parallel communication). The UART is therefore a serial port on a board used for communication between the board and a computer or other devices and all Arduino boards have at least one serial port. Here we are going to do an experiment to learn and start using the UART. At Arduino UNO, the UART are the digital pins 0 (RX) and 1 (TX) which receive and send data respectively - used for communication with other devices - and the USB - communication between the board and the computer. Thus, if you want to comunicate with other devices and you are using the RX and TX pins (0 and 1), you cannot also use those pins for digital input or output. Those pins also have corresponding LEDs on Arduino labeled RX and TX that blink when data passes. The main usages of the UART are the upload of programs to our Arduino(via USB), the communication between our micro-controller(Atmega) and our computer and the talk to some sensors/chips as graphical lcd’s and GPS modules that use almost always an serial interface.

This experiment is based on contents of [this UFSC project](https://wiki.sj.ifsc.edu.br/wiki/index.php/Embedded_Systems_Experiments_for_the_Telecommunication_Engineering_Course).

# Experiments

1. The exercise proposed here is to didactically understand the operation of the serial comunication through UART using serial monitors to visualize the results of the processes. It's a ECO program that return the value on ASCII;

2. Here we are going to do an experiment to implement a real aplication with UART. The exercise proposed here is to implement a communication between two boards, namelly two Arduinos Uno. A led on the second arduino(slave board) will blink according to the data received from the first arduino(master board). Therefore we need to programm to types of code: one for the master(sender) board and one for the slave board(receiver). In order to understand all the concepts used in this experiment it is recommended to see at first the basic UART script.

# Code

1. [UART code](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/UART/UART/UART.ino).
2. [SLAVE code](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/UART/UART_slave/UART_slave.ino).
3. [MASTER code](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/UART/UART_master/UART_master.ino).

# Schematic
1. Experiment 1 : Use just the Arduino Board.

2. Experiment 2 :
![Assembly](https://github.com/leticiacoelho/EmbeddedSystems/blob/master/Arduino/Image/Uart_AVR.png)

# Part List

* 1 LED
* 2 Arduinos UNO
* 1 220 ohm resistor
* 1 Protoboard
* Copper wires (tinned) or jumpers

# Tools

* AVR GCC and tools
* Arduino IDE
* [Cutecom](http://cutecom.sourceforge.net/).
