// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "DS3231.h"

DS3231 clock;
RTCDateTime dateTime;

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
  dateTime = clock.getDateTime();

  Serial.print("Date: ");

  // Date
  Serial.print(dateTime.year);
  Serial.print("-");
  Serial.print(dateTime.month);
  Serial.print("-");
  Serial.print(dateTime.day);

  // Separator
  Serial.print(" ");

  // Time
  Serial.print(dateTime.hour);
  Serial.print(":");
  Serial.print(dateTime.minute);
  Serial.print(":");
  Serial.print(dateTime.second);
  Serial.println();

  delay(1000);
}
