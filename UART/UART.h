/*
 * UART.h
 *
 *  Created on: 26 de Set de 2018
 *     Author: Leticia Coelho
 */
#include <avr/io.h>

#ifndef UART_H_
#define UART_H_

class UART {
	public:
		enum PortDirection_t {
			INPUT = 0,
			OUTPUT = 1
		};
		enum Parity_t{
			NONE = 0,
			EVEN = 32,
			ODD = 48
		};
		enum Stop_bit_t{
			ONE = 0,
			TWO = 8
		};
		enum Databits_t{
			Databits_5 = 1,
		    Databits_6 = 2,
		    Databits_7 = 4,
		    Databits_8 = 6
		};

		UART(int Baud, Databits_t Data,Parity_t Parity, Stop_bit_t Stop);
		~UART();
		void UART_Transmit(unsigned char data);
		unsigned char UART_Receive(void);

};


#endif /* UART_H_ */
