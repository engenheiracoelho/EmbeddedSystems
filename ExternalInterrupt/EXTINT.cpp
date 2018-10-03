/*
 * EXTINT.cpp
 *
 * Created on: 26 de Set de 2018
 *    Author: Leticia Coelho
 */

#include "EXTINT.h"

EXTINT::EXTINT(Intx_t Id, ISC_t int_config, to_function pCallback){
	_id = Id;
	_pCallback = pCallback;
	EIMSK = _id;

	switch(Id){
		case ONE:

		break;

		case TWO:

		break;

		case TREE:

		break;

		case FOUR:

		break;

		case FIVE:

		break;

		case SIX:

		break;

		case SEVEN:

		break;
	}
}

void EXTINT::enable(){

}

void EXTINT::disable(){

}

void EXTINT::into_handle(){

}
