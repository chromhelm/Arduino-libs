#include "PCA9536.h"

#define I2C_ADDRESS 0x41

void PCA9536class::begin()
{
	Wire.begin();
}

uint8_t PCA9536class::setPinsAsInput(uint8_t pins)
{
	return write(0x01, pins);
}

uint8_t PCA9536class::getPinsAsInput()
{
	return read(0x03);
}

uint8_t PCA9536class::setPinsPolarity(uint8_t pins)
{
	return write(0x02, pins);
}

uint8_t PCA9536class::getPinsPolarity()
{
	return read(0x02);
}

uint8_t PCA9536class::read() 
{ 
	return read(0x00);
}

uint8_t PCA9536class::readBuffer()
{
	return read(0x01);
}

uint8_t PCA9536class::write(uint8_t data)
{
	return write(0x01, data);
}

uint8_t PCA9536class::read(uint8_t addresse)
{
	uint8_t data;
	
	Wire.beginTransmission(I2C_ADDRESS);
	Wire.write(addresse);
	if(Wire.endTransmission() == 0)
	{
		Wire.requestFrom(I2C_ADDRESS, 1);
		if(Wire.available()) data = Wire.read();
		else data = -1;
	}
	else data = -1;
	
	return data;
}

uint8_t PCA9536class::write(uint8_t addresse, uint8_t data)
{
	uint8_t ret = 0;
	
	Wire.beginTransmission(I2C_ADDRESS);
	Wire.write(addresse);
	Wire.write(data);
	if(Wire.endTransmission() == 0) ret = 0;
	else ret = -1;
	
	return ret;
}

PCA9536class PCA9536;
