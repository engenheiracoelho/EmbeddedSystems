#ifndef SIMULAFXO_H_
#define SIMULAFXO_H_

#include "GPIO.h"
#include "UART.h"

class SimulaFXO : public Singleton<SimulaFXO> {
  public:
	SimulaFXO(int baud, DataBits_t data, Parity_t parity, StopBit_t stop);
	~SimulaFXO();
	void set_seq(uint8_t seq);
	void manager();
	void enable();
	void disable();

  private:
	uint8_t _seq[];
	uint8_t _seq_prog[] = {'t', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#', 'v'};
};

#endif /* SIMULAFXO_H_ */
