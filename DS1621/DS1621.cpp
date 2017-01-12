#include "DS1621.h"

void DS1621::begin(byte addr)
{
    this->address = addr >> 1;
    
    Wire.begin();
    Wire.beginTransmission(this->address);              // connect to DS1621 (#0)
    Wire.write(0xAC);                                   // Access Config
    Wire.write(0x02);                                   // set for continuous conversion
    Wire.beginTransmission(this->address);              // restart
    Wire.write(0xEE);                                   // start conversions
    Wire.endTransmission();
}


float DS1621::getTemp(void)
{
    int8_t firstByte;
    int8_t secondByte;
    float temp = 0;
    
    Wire.beginTransmission(this->address);
    Wire.write(0xAA);                                   // read temperature command
    Wire.endTransmission();
    Wire.requestFrom(this->address, byte(2));           // request two bytes from DS1621 (0.5 deg. resolution)

    firstByte = Wire.read();                            // get first byte
    secondByte = Wire.read();                           // get second byte

    temp = firstByte;

    if (secondByte)                                     // if there is a 0.5 deg difference
        temp += 0.5;

    return temp;
}
