#include "arduino_secrets.h"


#include <Servo.h>

Servo doorlock;

const int irsensorPin = 2;
const int unlockAngle = 90;
const int lockAngle = 0;

void setup() {
  pinMode(irsensorPin, INPUT);
  doorlock.attach(9);
  doorlock.write(lockAngle);  // Start locked
}

void loop() {
  int sensorvalue = digitalRead(irsensorPin);

  if (sensorvalue == LOW) {  // IR detects object
    doorlock.write(unlockAngle);
    delay(3000);              // Stay unlocked for 3 seconds
    doorlock.write(lockAngle);
  }

  delay(100); // prevent bouncing
}
