#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Singleton.h"
#include "FIFO.h"

class UART : public Singleton<UART> {
public:
  enum DataBits_t {
    five_bits = 0,
    six_bits = 2,
    seven_bits = 4,
    eight_bits = 6
  };

  enum Parity_t {
    none = 0,
    even = 32,
    odd = 48
  };

  enum StopBit_t {
    one = 0,
    two = 8
  };

  enum DoubleSpeed_t {
	disable = 0,
	enable = 2
  };

  UART(int baud, DataBits_t data, Parity_t parity, StopBit_t stop, DoubleSpeed_t speed);
  ~UART();
  void put(uint8_t dado); // transmite char
  void puts(char* dado); // transmite string
  uint8_t get(); // recebe
  bool has_data();
  static void rx_isr();
  static void tx_isr();

private:
  bool _newdata;
  FIFO<uint8_t, 20> _rx_buffer;
  FIFO<uint8_t, 20> _tx_buffer;
};

#endif /* UART_H_ */
