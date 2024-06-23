#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Written by Bryan Schmidiger 
// Program for controlling the servos

#define SERVOMIN  140 // Min movement servo
#define SERVOMAX  575 // Max movement servo

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  setServoPositions(0); // 0 Grad
  delay(10000); // wait 10 Sek

  setServoPositions(180); // 180 Grad
  delay(10000); // wait 10 Sek
}

void setServoPositions(uint8_t angle) {
  for (uint8_t servoNum = 0; servoNum < 16; servoNum++) {
    pwm.setPWM(servoNum, 0, map(angle, 0, 180, SERVOMIN, SERVOMAX));
  }
}