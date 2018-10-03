/*
 * EXTINT.h
 *
 *  Created on: 26 de Set de 2018
 *     Author: Leticia Coelho
 */
#include <avr/io.h>

#ifndef EXTINT_H_
#define EXTINT_H_

typedef void(*to_function)(void);

class EXTINT{
	public:
	    enum ISC_t{
	    	LOW = 0,     // The low level of INT n generates an interrupt request.
			ANY = 1,     // Any edge of INTn generates asynchronously an interrupt request.
			FALLING = 2, // The falling edge of INTn generates asynchronously an interrupt request.
			RISING = 3   // The rising edge of INTn  asynchronously an interrupt request.
	    };
	    enum Intx_t{
	    	ZERO = 0,
			ONE = 1,
			TWO = 2,
			TREE = 3,
			FOUR = 4,
			FIVE = 5,
			SIX = 6,
			SEVEN = 7
		};

	    EXTINT(Intx_t Id, ISC_t int_config, to_function pCallback);
		void enable();
		void disable();
		static void into_handle();

	private:
		static int _id;
		static int _pCallback;
};


#endif /* EXTINT_H_ */
