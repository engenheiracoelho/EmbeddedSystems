/*
 * EXTINT.cpp
 *
 * Created on: 26 de Set de 2018
 *    Author: Leticia Coelho
 */

#include "EXTINT.h"
namespace EXT{
	EXTINT * EXTINT::_ExtInt_singletons[8];

    ISR(INT0_vect){EXTINT::_ExtInt_singletons[0]->callback();}

	ISR(INT1_vect){EXTINT::_ExtInt_singletons[1]->callback();}

	ISR(INT2_vect){EXTINT::_ExtInt_singletons[2]->callback();}

	ISR(INT3_vect){EXTINT::_ExtInt_singletons[3]->callback();}

	ISR(INT4_vect){EXTINT::_ExtInt_singletons[4]->callback();}

	ISR(INT5_vect){EXTINT::_ExtInt_singletons[5]->callback();}

	ISR(INT6_vect){EXTINT::_ExtInt_singletons[6]->callback();}

	ISR(INT7_vect){EXTINT::_ExtInt_singletons[7]->callback();}

	/* Execute external interrupt*/
	EXTINT::EXTINT(Intx_t Id, ISC_t int_config, to_function pCallback){
		_id = Id;
		_pCallback = pCallback;
		EIMSK &= ~(1<<_id); /* Disable */
		_ExtInt_singletons[_id] = this;

		int MSK =(_id%4)*2;
		EICRA = (EICRA &~ (1<<MSK))|(int_config<<MSK); /* Config the EICRA register */
		EICRB = (EICRB &~ (1<<MSK))|(int_config<<MSK); /* Config the EICRB register */
	}

	/* Enable interrupt */
	void EXTINT::enable(){ EIMSK |= (1<<_id);}

	/* Disable interrupt */
	void EXTINT::disable(){ EIMSK &= ~(1<<_id);}

	/* Inform when an interrupt occurs */
	void EXTINT::callback(){ (*_pCallback)();}
};
