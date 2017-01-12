#ifndef DS1621_h
#define DS1621_h

#include <Arduino.h>
#include <Wire.h>

class DS1621
{
public:
    void begin(byte addr = 0x90);
    float getTemp(void);
private:
    byte address;
};

#endif