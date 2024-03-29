// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include <DS3231.h>

DS3231 clock;

void setup()
{
  Serial.begin(115200);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  clock.begin();
}

void loop()
{
  // The temperature registers are updated after every 64-second conversion.
  // If you want force temperature conversion use forceConversion()
  clock.forceConversion();

  Serial.print("Temperature: ");
  Serial.println(clock.readTemperature());

  delay(1000);
}
