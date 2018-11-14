/*
 * USART.h
 *
 *  Created on: 26 de Set de 2018
 *     Author: Leticia Coelho
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Singleton.h"

#ifndef USART_H_
#define USART_H_

class USART : public Singleton<USART>{
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

		USART(int Baud, Databits_t Data,Parity_t Parity, Stop_bit_t Stop);
		~USART();
		void USART_Transmit(unsigned char data);
		unsigned char USART_Receive(void);
		bool has_data();
		static uint8_t get();
		static void put(uint8_t data);
		static void rx_isr();
		static void tx_isr();

	private:
		static bool _new_data;
		static uint8_t _rx_buffer;
		static uint8_t _tx_buffer;

};


#endif /* USART_H_ */
