#include "HYB_HPSD3000.h"

#define I2C_ADDRESS 0x78

#define OFFSET_NORMAL 3277
#define OFFSET_BIDIRECTIONAL 16384
#define FULL_SCALE_OUTPUT 29491
#define FULL_SCALE_SPAN 26214

#define TEMP_OFFSET 8192
#define TEMP_70 24576
#define TEMP_FULL_SCALE_SPAN 16384

void HYB_HPSD3000::begin(int16_t maxPressure, bool biderectional)
{
	_pressMax = maxPressure;
	_biderectional = biderectional;
}

void HYB_HPSD3000::getRawData(uint8_t* data)
{
  int8_t counter = 0;
  int16_t pressure, temperatur;
  
  Wire.beginTransmission(I2C_ADDRESS); // transmit to device)
  Wire.endTransmission();     // stop transmitting
  
  Wire.requestFrom(I2C_ADDRESS, 4);    // request 4 bytes from slave device
  counter = 0;
  while(Wire.available())    // slave may send less than requested
  {
    data[counter] = Wire.read();
    delayMicroseconds(2);
    counter++;
  }
}

void HYB_HPSD3000::setPressCorrection(int16_t offset)
{
  _pressOffset = offset;
}

int16_t HYB_HPSD3000::getPressure()
{ 
  uint8_t data[4];
  
  int16_t pressure;
  
  getRawData(data);
  
  pressure = data[0] << 8 | data[1];
  
  pressure -= (_biderectional)? OFFSET_BIDIRECTIONAL : OFFSET_NORMAL;
  
  pressure += _pressOffset;

  pressure = (pressure * (int32_t)_pressMax) / FULL_SCALE_SPAN;

  return pressure;
}

float HYB_HPSD3000::getPressuref()
{ 
  uint8_t data[4];
  
  float pressure;
  
  getRawData(data);
  
  pressure = data[0] << 8 | data[1];
  
  pressure -= (_biderectional)? OFFSET_BIDIRECTIONAL : OFFSET_NORMAL;
  
  pressure += _pressOffset;

  pressure = (pressure * _pressMax) / FULL_SCALE_SPAN;

  return pressure;
}

void HYB_HPSD3000::setTempCorrection(int16_t offset)
{
  _tempOffset = offset;
}

int16_t HYB_HPSD3000::getTemp()
{
  uint8_t data[4];
  
  int16_t temp;
  
  getRawData(data);
  
  temp = data[2] << 8 | data[3];
  
  temp -= TEMP_OFFSET - _tempOffset;
  
  temp = (temp * (int32_t)7000) / TEMP_FULL_SCALE_SPAN;
  
  return temp;
}

float HYB_HPSD3000::getTempf()
{
  uint8_t data[4];
  
  float temp;
  
  getRawData(data);
  
  temp = data[2] << 8 | data[3];
  
  temp -= TEMP_OFFSET - _tempOffset;
  
  temp = (temp * 70.f) / TEMP_FULL_SCALE_SPAN;
  
  return temp;
}
