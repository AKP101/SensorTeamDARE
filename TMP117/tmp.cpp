#include <Wire.h>
#include <Adafruit_TMP117.h>
#include <Adafruit_Sensor.h>

const int buttonPin = 12;
const int LED = 13;

int buttonState = 0;
bool startSensing = false;
bool shouldRecord = false;

Adafruit_TMP117 tmp117;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

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
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !startSensing) {
    startSensing = true;
    shouldRecord = true;
    Serial.println("Sensing started");
  } else if (buttonState == LOW && startSensing) {
    startSensing = false;
    shouldRecord = false;
    Serial.println("Sensing stopped");
  }

  if (startSensing) {
    sensors_event_t temp;
    tmp117.getEvent(&temp);
    Serial.print(temp.temperature); // Send temperature to serial terminal
    Serial.print(",");
    Serial.println(getTimeStamp()); // Send timestamp to serial terminal

    if (shouldRecord) {
      // You can manually copy and save the received data from the serial terminal to a CSV file on your laptop
      // Save the temperature and timestamp data to a CSV file on your laptop using a custom script or serial terminal program
    }
  }

  delay(100);
}

String getTimeStamp() {
  String timeStamp = "";
  timeStamp += String(year());
  timeStamp += "-";
  if (month() < 10)
    timeStamp += "0";
  timeStamp += String(month());
  timeStamp += "-";
  if (day() < 10)
    timeStamp += "0";
  timeStamp += String(day());
  timeStamp += " ";
  if (hour() < 10)
    timeStamp += "0";
  timeStamp += String(hour());
  timeStamp += ":";
  if (minute() < 10)
    timeStamp += "0";
  timeStamp += String(minute());
  timeStamp += ":";
  if (second() < 10)
    timeStamp += "0";
  timeStamp += String(second());
  return timeStamp;
}
