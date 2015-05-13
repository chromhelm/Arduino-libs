#include <PCF8577C.h>

//init lcd driver
PCF8577C lcd;

void setup()
{
	lcd.begin(PCF8577C::DIRECT_DRIVE, 0);
}

void loop()
{
  uint8_t buffer[4] = {0x55, 0x55, 0x55, 0x55};	

	lcd.write(buffer, 4);
}
