#include <HYB_HPSD3000.h>

HYB_HPSD3000 pressSensor = HYB_HPSD3000();

void setup()
{
  Serial.begin(9600);

  pressSensor.begin(1000, false);
  pressSensor.setTempCorrection(2950);
  pressSensor.setPressCorrection(-152);
}

void loop()
{
  Serial.print("Pressure  : ");
  Serial.println(pressSensor.getPressure());
  Serial.print("Pressuref : ");
  Serial.println(pressSensor.getPressuref());
  Serial.print("Temperature  : ");
  Serial.println(pressSensor.getTemp());
  Serial.print("Temperaturef : ");
  Serial.println(pressSensor.getTempf());
  delay(1000);
}

