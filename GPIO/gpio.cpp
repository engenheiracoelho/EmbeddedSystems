#include <avr/interrupt.h>
#include <avr/delay.h>
#include "GPIO.h"


void GPIO::GPIO(int id, PortDirection_t direction){ // The direction indicate output or input.
  GPIO _id = id;
  switch (id){
    case 0:
      _pin = DDE0;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
        DDRE |= (1 << _pin);  //OUTPUT
      break;

    case 1:
        _pin = DDE1;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); ///INPUT
      else
    	  DDRE |= (1 << _pin);  //OUTPUT
    break;

    case 2:
        _pin = DDE4;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
    		DDRE |= (1 << _pin);  //OUTPUT
    break;

    case 3:
        _pin = DDE5;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
        DDRE |= (1 << _pin);  //OUTPUT
    break;

    case 4:
        _pin = DDG5;
      if(direction == 'INPUT')
        DDRG &= ~(1 << _pin); ///INPUT
      else
        DDRG |= (1 << _pin);  //OUTPUT
    break;

   case 5:
      _pin = DDE3;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
    	 DDRE |= (1 << _pin);  //OUTPUT
   break;

   case 6:
      _pin = DDH3;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); //INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 7:
      _pin = DDH4;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); ///INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 8:
      _pin = DDH5;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); //INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 9:
      _pin = DDH6;
     if(direction == 'INPUT')
        DDRH &= ~(1 << _pin); ///INPUT
     else
        DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 10:
      _pin = DDB4;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 11:
      _pin = DDB5;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 12:
      _pin = DDB6;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); ///INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 13:
      _pin = DDB7;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;
}

bool GPIO::GET(){}

bool GPIO::SET(bool value){
    int var;

    if(_id == 0 || _id == 1 || _id == 2 || _id == 3 || _id == 5)
      var = 1;
    if(_id == 5)
      var = 2;
    if(_id == 6 || _id == 7 || _id == 8 || _id == 9)
      var = 3;
    if(_id == 10 || _id == 11 || _id == 12 || _id == 13)
      var = 4;

    switch (var){
      case 1:
        if(value)
          PORTE &= ~(1 << _pin); // ON - 1
        else
          PORTE |= (1 << _pin);  // OFF - 0
      break;

      case 2:
        if(value)
          PORTG &= ~(1 << _pin); // ON - 1
        else
          PORTG |= (1 << _pin);  // OFF - 0
      break;

      case 3:
        if(value)
          PORTH &= ~(1 << _pin); // ON - 1
        else
      	  PORTH |= (1 << _pin);  // OFF - 0
      break;

      case 4:
        if(value)
          PORTB &= ~(1 << _pin); // ON - 1
        else
          PORTB |= (1 << _pin);  // OFF - 0
      break;
   }
}

bool GPIO::Clear(){}

bool GPIO::Toggle(){}
