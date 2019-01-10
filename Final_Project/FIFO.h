#ifndef FIFO_H_
#define FIFO_H_

template <typename TYPE, int SIZE> class FIFO {

public:
	FIFO() {
		first = last = quant = 0;
	}

	~FIFO();

	bool push(TYPE data){
		if (quant >= SIZE){
			return true;
		}

		_buffer[first] = data;
		first = ((first + 1) % SIZE);
		quant = quant + 1; //incrementa a FIFO

		return false;
	}

	TYPE pop(){
		if(quant == 0) {
			return (TYPE)true;
		} else {
			TYPE data = _buffer[last];
			last = (last + 1) % SIZE;
			quant = quant - 1;
			return data;
		}
	}

	int get_size(){
		return quant;
	}

	void clear(){
		first = last = quant = 0;
	}

	bool cheia(){
		return (quant == SIZE);
	}

	bool vazia(){
		return (quant == 0);
	}

private:
	TYPE _buffer[SIZE];
	int first, last, quant;
};

#endif /* FIFO_H_ */
