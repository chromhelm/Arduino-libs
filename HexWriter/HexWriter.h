#ifndef HexWriter_H
#define HexWriter_H

#include <Arduino.h>
#include <Print.h>

class HexWriter
{
public:
	struct mode_t
	{
		uint8_t showHeader		:1;
		uint8_t showOffset		:1;
		uint8_t show16bit		:1;
		uint8_t showText		:1;
		uint8_t offsetLength	:4;
	};
	
	void begin(Print* print, struct mode_t mode = (mode_t){1, 1, 1, 1, 2});
	
	void print(uint8_t* data, uint16_t length, uint16_t offset = 0);
	
	void print(uint8_t  value, uint8_t decimals = 0);
	void print(uint16_t value, uint8_t decimals = 0);
	
	mode_t mode;
	
private:
	void printHeader(uint8_t offsetLength);
	void printLine(uint8_t* data, uint16_t pos, uint16_t offset, uint16_t end, uint8_t offsetLength);
	void putChar(uint8_t data);
	
	static uint8_t getNumberLength(uint16_t number);
	static uint8_t getNumberLength(uint8_t number);
	
	Print* p;
	
	static const uint8_t c[16];
};
#endif //HexWriter_H
