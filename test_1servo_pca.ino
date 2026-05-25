#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

void setup() {

  Serial.begin(9600);

  pca.begin();
  pca.setPWMFreq(50);

  delay(500);

  Serial.println("Enter Servo Angle (0 to 180):");
}

void loop() {

  if (Serial.available() > 0) {

    int angle = Serial.parseInt();

    // Limit angle range
    angle = constrain(angle, 0, 180);

    // Convert angle to pulse
    int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);

    // Move servo on channel 0
    pca.setPWM(0, 0, pulse);

    Serial.print("Moved Servo to: ");
    Serial.print(angle);
    Serial.println(" degrees");
  }
}