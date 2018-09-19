#include <avr/interrupt.h>
#include <avr/delay.h>
#include "GPIO.h"


void GPIO::GPIO(int id, PortDirection_t direction){ // The direction indicate output or input.

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
        _pin = DDE2;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
    		DDRE |= (1 << _pin);  //OUTPUT
    break;

    case 3:
        _pin = DDE3;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
        DDRE |= (1 << _pin);  //OUTPUT
    break;

    case 4:
        _pin = DDE4;
      if(direction == 'INPUT')
        DDRG &= ~(1 << _pin); ///INPUT
      else
        DDRG |= (1 << _pin);  //OUTPUT
    break;

   case 5:
      _pin = DDE5;
      if(direction == 'INPUT')
        DDRE &= ~(1 << _pin); //INPUT
      else
    	 DDRE |= (1 << _pin);  //OUTPUT
   break;

   case 6:
      _pin = DDE6;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); //INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 7:
      _pin = DDE7;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); ///INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 8:
      _pin = DDE8;
     if(direction == 'INPUT')
       DDRH &= ~(1 << _pin); //INPUT
     else
       DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 9:
      _pin = DDE9;
     if(direction == 'INPUT')
        DDRH &= ~(1 << _pin); ///INPUT
     else
        DDRH |= (1 << _pin);  //OUTPUT
   break;

   case 10:
      _pin = DDE10;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 11:
      _pin = DDE11;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 12:
      _pin = DDE12;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); ///INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;

   case 13:
      _pin = DDE13;
      if(direction == 'INPUT')
        DDRB &= ~(1 << _pin); //INPUT
      else
        DDRB |= (1 << _pin);  //OUTPUT
   break;
}

bool GPIO::GET(){}

bool GPIO::SET(bool value){
    switch (value){
      case 0:
        if(value)
          DDRE &= ~(1 << _pin); //INPUT
        else
          DDRE |= (1 << _pin);  //OUTPUT
        break;

      case 1:
        if(value)
          DDRE &= ~(1 << _pin); ///INPUT
        else
      	  DDRE |= (1 << _pin);  //OUTPUT
      break;

      case 2:
        if(value)
          DDRE &= ~(1 << _pin); //INPUT
        else
      		DDRE |= (1 << _pin);  //OUTPUT
      break;

      case 3:
        if(value)
          DDRE &= ~(1 << _pin); //INPUT
        else
          DDRE |= (1 << _pin);  //OUTPUT
      break;

      case 4:
        if(direction == 'INPUT')
          DDRG &= ~(1 << _pin); ///INPUT
        else
          DDRG |= (1 << _pin);  //OUTPUT
      break;

     case 5
        if(direction == 'INPUT')
          DDRE &= ~(1 << _pin); //INPUT
        else
      	 DDRE |= (1 << _pin);  //OUTPUT
     break;

     case 6
       if(direction == 'INPUT')
         DDRH &= ~(1 << _pin); //INPUT
       else
         DDRH |= (1 << _pin);  //OUTPUT
     break;

     case 7
       if(direction == 'INPUT')
         DDRH &= ~(1 << _pin); ///INPUT
       else
         DDRH |= (1 << _pin);  //OUTPUT
     break;

     case 8
       if(direction == 'INPUT')
         DDRH &= ~(1 << _pin); //INPUT
       else
         DDRH |= (1 << _pin);  //OUTPUT
     break;

     case 9
       if(direction == 'INPUT')
          DDRH &= ~(1 << _pin); ///INPUT
       else
          DDRH |= (1 << _pin);  //OUTPUT
     break;

     case 10:
        if(direction == 'INPUT')
          DDRB &= ~(1 << _pin); //INPUT
        else
          DDRB |= (1 << _pin);  //OUTPUT
     break;

     case 11:
        if(direction == 'INPUT')
          DDRB &= ~(1 << _pin); //INPUT
        else
          DDRB |= (1 << _pin);  //OUTPUT
     break;

     case 12:
        if(direction == 'INPUT')
          DDRB &= ~(1 << _pin); ///INPUT
        else
          DDRB |= (1 << _pin);  //OUTPUT
     break;

     case 13:
        if(direction == 'INPUT')
          DDRB &= ~(1 << _pin); //INPUT
        else
          DDRB |= (1 << _pin);  //OUTPUT
     break;
}

bool GPIO::Clear(){}

bool GPIO::Toggle(){}
