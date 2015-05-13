#ifndef PCA9536_H
#define PCA9536_H

#include "Wire.h"

/* arduino class */
class PCA9536class {
	public:
		void begin();
		uint8_t setPinsAsInput(uint8_t pins);
		uint8_t getPinsAsInput();
		
		uint8_t setPinsPolarity(uint8_t pins);
		uint8_t getPinsPolarity();
		
		//return -1 on error
		uint8_t read();
		uint8_t readBuffer();
		uint8_t write(uint8_t data);
	private:
		uint8_t read(uint8_t addresse);
		uint8_t write(uint8_t addresse, uint8_t data);
};

extern PCA9536class PCA9536;
#endif //PCA9536_H
