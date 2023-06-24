#include <Wire.h>
#include <Adafruit_TMP117.h>
#include <Adafruit_Sensor.h>
#include <TimeLib.h>

const int buttonPin = 12;
const int LED = 13;

int buttonState = 0;
bool startSensing = false;

Adafruit_TMP117 tmp117;

void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);

  Serial.begin(115200);
  while (!Serial)
    delay(10);
  Serial.println("Adafruit TMP117 test!");

  if (!tmp117.begin()) {
    Serial.println("Failed to find TMP117 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("TMP117 Found!");
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
    sensors_event_t temp;
    tmp117.getEvent(&temp);
    Serial.print(temp.temperature); // Send temperature to serial terminal
    Serial.print(",");
    printTimeStamp(); // Send timestamp to serial terminal
    Serial.println();
  }
  delay(500);
}

void printTimeStamp() {
  char timeStamp[20];
  sprintf(timeStamp, "%02d:%02d:%02d", hour(), minute(), second());
  Serial.print(timeStamp);
}


