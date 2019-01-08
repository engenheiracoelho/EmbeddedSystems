/*
 * UART.h
 *
 *  Created on: 26 de Set de 2018
 *     Author: Leticia Coelho
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Singleton.h"

#ifndef UART_H_
#define UART_H_

class UART : public Singleton<UART>{
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
		bool has_data();
		static uint8_t get();
		static void put(uint8_t data);
		static void rx_isr();
		static void tx_isr();

	private:
		bool _new_data;
		uint8_t _rx_buffer;
		uint8_t _tx_buffer;

};


#endif /* UART_H_ */
