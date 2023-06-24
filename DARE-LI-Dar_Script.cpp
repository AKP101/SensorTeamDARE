#include <Wire.h>
const int i2cAddress = 0x66;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 12;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
// initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
// initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
  Wire.begin();
  Serial.println("Starting...");

  // Make sure I2C protocol is active
  Wire.requestFrom(i2cAddress, 0);

  // Get product info.
  Wire.beginTransmission(i2cAddress);
  Wire.write('?');
  Wire.write('\r');
  Wire.endTransmission(true);

  delay(10);

  Wire.requestFrom(i2cAddress, 16);
  
  char strBuf[16];

  for (int i = 0; i < 16;++i) {
    strBuf[i] = Wire.read();
  }

  Serial.print('[');
  Serial.print(strBuf);
  Serial.print(']');
  
  Serial.println();
  
  Serial.println("Setup completed");
}
void loop() {
    buttonState = digitalRead(buttonPin);
    if buttonState == HIGH{
  Wire.beginTransmission(i2cAddress);
  Wire.write('?');
  Wire.write('l');
  Wire.write('d');
  Wire.write('f');
  Wire.write(',');
  Wire.write('1');
  Wire.write('\r');
  Wire.endTransmission(true);

  delay(0);

  Wire.requestFrom(i2cAddress, 16);
  
  char strBuf[16];

  for (int i = 0; i < 16;++i) {
    strBuf[i] = Wire.read();
  }

  Serial.print(strBuf + 6);
  
  Serial.println();
    }
  delay(20);
}

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
