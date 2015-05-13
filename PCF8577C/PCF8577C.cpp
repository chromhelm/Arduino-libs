#include <PCF8577C.h>

#define DISPLAY_ADD 0x3A

void PCF8577C::begin(uint8_t DriveMode, uint8_t subaddress)
{
  Wire.begin();
  
  ControlRegister = 0;
  ControlRegister |= (DriveMode) ? 0x80 : 0x00;
  ControlRegister |= (subaddress & 0x7) << 3;
}

void PCF8577C::selectBank(uint8_t bankNumber)
{
    if(bankNumber)
    {
        ControlRegister |= 0x40;
    }
    else
    {
        ControlRegister &= ~0x40;
    }
}

void PCF8577C::write(uint8_t* data, uint8_t length)
{
    uint8_t lcd[9], i;
    
    if(length > 8) return;
    
    lcd[0] = ControlRegister;

    while(i < length)
    {
        lcd[i + 1] = data[i];
        i++;
    }

    Wire.beginTransmission(DISPLAY_ADD); 
    Wire.write(lcd, length + 1);
    Wire.endTransmission();
}

