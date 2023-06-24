#include <Arduino.h>
#include <Wire.h>
#include "CG_RadSens.h"
#include <TimeLib.h>

const int buttonPin = 12;
const int LED = 13;

int buttonState = 0;
bool startSensing = false;

CG_RadSens radSens(RS_DEFAULT_I2C_ADDRESS);

void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);

  Serial.begin(115200);
  Wire.begin();
  delay(1000);

  while (!radSens.init()) {
    Serial.println("Sensor wiring error!");
    delay(1000);
  }

  uint8_t sensorChipId = radSens.getChipId();
  Serial.print("Chip id: 0x");
  Serial.println(sensorChipId, HEX);

  uint8_t firmWareVer = radSens.getFirmwareVersion();
  Serial.print("Firmware version: ");
  Serial.println(firmWareVer);

  setSyncProvider(getTime);
  setSyncInterval(60);
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !startSensing) {
    startSensing = true;
    Serial.println("Sensing started");
  } else if (digitalRead(buttonPin) == LOW && startSensing) {
    startSensing = false;
    Serial.println("Sensing stopped");
  }

  if (startSensing) {
    Serial.print("Rad intensity dynamic: ");
    Serial.println(radSens.getRadIntensyDynamic());

    Serial.print("Rad intensity static: ");
    Serial.println(radSens.getRadIntensyStatic());

    Serial.print("Number of pulses: ");
    Serial.println(radSens.getNumberOfPulses());

    printTimeStamp();
    Serial.println();
  }
  delay(2000);
}

void printTimeStamp() {
  char timeStamp[20];
  sprintf(timeStamp, "%02d:%02d:%02d", hour(), minute(), second());
  Serial.print("Time: ");
  Serial.print(timeStamp);
}

time_t getTime() {
  return now();
}
