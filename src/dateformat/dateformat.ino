// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "DS3231.h"

DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(115200);

  // Initialize DS3231
  Serial.println("Initialize DS3231");
  clock.begin();

  // Set sketch compiling time
  clock.setDateTime(__DATE__, __TIME__);

  // Manual from UNIX timestamp
  // clock.setDateTime(1397408400);

  // Manual from date (YYYY, MM, DD, HH, II, SS)
  // clock.setDateTime(2024, 1, 1, 00, 00, 00);
}

void loop()
{
  dt = clock.getDateTime();

  Serial.print("Long number format:\t\t");
  Serial.println(clock.dateFormat("d-m-Y H:i:s", dt));

  Serial.print("Long format with month name:\t");
  Serial.println(clock.dateFormat("d F Y H:i:s",  dt));

  Serial.print("Short format witch 12h mode:\t");
  Serial.println(clock.dateFormat("jS M y, h:ia", dt));

  Serial.print("Today is:\t\t\t");
  Serial.print(clock.dateFormat("l, z", dt));
  Serial.println(" days of the year.");

  Serial.print("Actual month has:\t\t");
  Serial.print(clock.dateFormat("t", dt));
  Serial.println(" days.");

  Serial.print("Unixtime:\t\t\t");
  Serial.println(clock.dateFormat("U", dt));

  Serial.println();

  delay(1000);
}
