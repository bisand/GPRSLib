#include <Arduino.h>
#include "GPRSLib.h"

char buffer[64];
HardwareSerial ser1(1);
GPRSLib gprs(buffer, sizeof(buffer), 2, ser1);
unsigned long currentMillis = 0;
unsigned long sensMillis = 0;

void ReadGps()
{
}
void ReadSms()
{
}

void setup()
{
  // put your setup code here, to run once:
  gprs.setup();
}

void loop()
{
  // put your main code here, to run repeatedly:
  // int volt = gprs.batteryVoltage();
  currentMillis = millis();
  if (currentMillis - sensMillis >= 5000UL)
  {
    // Communicate with serial 1
    ReadGps();
#ifdef ESP8266
    ser1.swap();
#endif
    // Communicate with serial 2
    ReadSms();
#ifdef ESP8266
    ser1.swap();
#endif

    sensMillis = currentMillis;
  }
}