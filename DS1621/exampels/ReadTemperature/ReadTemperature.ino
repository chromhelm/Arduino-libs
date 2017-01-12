#include "DS1621.h"

DS1621 temp1;

void setup() {
  Serial.begin(9600);
  temp1.begin();
}

void loop() {
  Serial.println(temp1.getTemperature());
  delay(1000);
}
