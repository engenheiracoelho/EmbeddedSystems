/*
 * EXTINT.h
 *
 *  Created on: 26 de Set de 2018
 *     Author: Leticia Coelho
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef EXTINT_H_
#define EXTINT_H_

namespace EXT{
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
				INT_0 = 0,
				INT_1 = 1,
				INT_2 = 2,
				INT_3 = 3,
				INT_4 = 4,
				INT_5 = 5,
				INT_6 = 6,
				INT_7 = 7
			};

			EXTINT(Intx_t Id, ISC_t int_config, to_function pCallback);
			static EXTINT *_ExtInt_singletons[8];
			void enable();
			void disable();
			void callback();

		private:
			Intx_t _id;
			to_function _pCallback;
	};
};


#endif /* EXTINT_H_ */
