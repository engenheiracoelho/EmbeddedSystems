#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define F_CPU 16000000
#define BAUDRATE 9600
#define ADC_channel 0
#define UBRR (F_CPU/16/BAUDRATE-1)

void USART_Init( unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = data;
}

unsigned char USART_Receive(void){
	while (!(UCSR0A & (1<<RXC0)));
		return UDR0;
}

void print(char *msg){
	for(char *in = msg; *in; ++in)
	{
		USART_Transmit(*in);
	}
  USART_Transmit((unsigned char)('\n'));
}

uint16_t ADC_read()
{
  ADCSRA |= (1<<ADSC);
  while(ADCSRA & (1<<ADSC));
  return (ADC);
}

int RMS(int repeat){
	int i = 1;
	// tem que ser long por causa do tamanho máximo da variável, int não dá
  float accumulated = 0.0;
  float average = 0.0;
    do {
        i++;
        long value = ADC_read();//read(analog_value);   //convert the analog-value (voltage) to digital one (0-1024)
        accumulated += value^2;      //accumulate all the digital-values “repeat” times
    } while(repeat >=i);

    long average = accumulated / repeat;
    return sqrt(average);
}

float to_analog(int value_rms){
	return 5.0*value_rms/1024;
}

void ADC_Init(){
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC);
}
int main( void ){
  USART_Init (UBRR);
	ADC_Init();
  float analog = 0.0;

  while(1) {
    char meassure[50];
    char meassure_analog [10];

    value_rms = RMS(30);
    val_analog = to_analog(value_rms);

    _delay_ms(250);

    itoa (value_rms,buffer,10);
    dtostrf(val_analog,3, 2, buffer_analog);

    print("Digital: ");
    println(buffer);

    print("Analog: ");
    print(buffer_analog);
  }
  return 0;
}
