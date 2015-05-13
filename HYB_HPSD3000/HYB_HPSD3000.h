#ifndef HYB_HPSD3000_H
#define HYB_HPSD3000_H

#include <Arduino.h>
#include <Wire.h>

/* arduino class */
class HYB_HPSD3000 {
	public:

		void begin(int16_t maxPressure, bool biderectional);
		
		int16_t getPressure();
		float getPressuref();
		
		int16_t getTemp();		//0.01°C
		float getTempf();
		
		void setTempCorrection(int16_t offset);
		void setPressCorrection(int16_t offset);
		
		// retruning 4 byte
		void getRawData(uint8_t* data);
		
	private:
		int16_t _pressMax;
		int16_t _tempOffset;
		int16_t _pressOffset;
		bool _biderectional;
};
#endif //HYB_HPSD3000_H
