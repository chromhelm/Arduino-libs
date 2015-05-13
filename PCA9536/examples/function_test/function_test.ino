#include <PCA9536.h>

void setup()
{
  Serial.begin(9600);
  PCA9536.begin();
}

void loop()
{
	Serial.print("Read : ");
	Serial.println(PCA9536.read(), BIN);
	delay(1000);
}
