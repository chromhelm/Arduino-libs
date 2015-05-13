#ifndef PCF8577C_H
#define PCF8577C_H

#include <Arduino.h>
#include <Wire.h>

class PCF8577C {
    public:
        static const uint8_t DIRECT_DRIVE = 0x0;
        static const uint8_t DUPLEX_DRIVE = 0x1;
        
        void begin(uint8_t DriveMode, uint8_t subaddress);
        void selectBank(uint8_t bankNumber);
        void write(uint8_t* data, uint8_t length);
    private:
    	uint8_t ControlRegister;
};

#endif //PCF8577C_H
