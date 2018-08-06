# KEY Button

This experiment is based on contents of [http://www.lisha.ufsc.br/teaching/quark/ this UFSC project].

Here we are going to build an experiment with an led and a push button to learn and start using the GPIO. GPIO is called General Purpose Input/Output, and it is basically a group of pins responsable of the communication of input and output digital signals in one board.
So the exercise proposed is to turn on and off a led when the push button is pressed or not, respectively.

# Code

Solution:

 	```
#define in1 2
#define in2 3
#define out1 8
#define out2 9

void setup() {
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);   
}

void loop(){
  digitalWrite(out1, digitalRead(in1));    
  digitalWrite(out2, digitalRead(in2));
}
 	```

This code has a comparison statement to see if the push button is pressed (1) or not (0). If yes, the led will turn on and if not (else), the led will stay turned off.

# Schematic
![Assembly](/Image/Led_key.png)

# Part List
* 2 LED
* 2 Push buttons
* 2 10k ohm resistors to the buttons
* 2 220 ohm resistors to the leds
* 1 Protoboard
* 8 copper wires (tinned) or jumpers

# Solutions
* [C - AVR](https://drive.google.com/file/d/0B_chZ-d1CkpCX1ZUU1VzWUFzbkU/view).
* [Arduino UNO](https://drive.google.com/file/d/0B_chZ-d1CkpCdE5EdkRuc1pwNEU/view).

# Tools
* AVR GCC and tools
* Arduino IDE
