#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

// Servo channel limits
#define CH0_MIN 70
#define CH0_MAX 170

#define CH1_MIN 20
#define CH1_MAX 120

void setup() {

  Serial.begin(9600);

  pca.begin();
  pca.setPWMFreq(50);

  delay(500);

  Serial.println("Dual Servo Control Started");

  // ================= INITIAL POSITION =================
  // Channel 0 -> 170
  // Channel 1 -> 20

  moveServos(170, 20);

  Serial.println("Initial Position Set");

  delay(2000);

  // ================= SECOND POSITION =================
  // Channel 0 -> 70
  // Channel 1 -> 120

  moveServos(70, 120);

  Serial.println("Second Position Set");

  delay(2000);

  // ================= BACK TO INITIAL =================

  moveServos(170, 20);

  Serial.println("Returned to Initial Position");
}

void loop() {

}

// ===================================================
// FUNCTION TO MOVE BOTH SERVOS TOGETHER
// ===================================================

void moveServos(int angle0, int angle1) {

  // Constrain angles within limits
  angle0 = constrain(angle0, CH0_MIN, CH0_MAX);
  angle1 = constrain(angle1, CH1_MIN, CH1_MAX);

  // Convert angles to PWM pulses
  int pulse0 = map(angle0, 0, 180, SERVOMIN, SERVOMAX);
  int pulse1 = map(angle1, 0, 180, SERVOMIN, SERVOMAX);

  // Move servos together
  pca.setPWM(0, 0, pulse0); // Channel 0
  pca.setPWM(1, 0, pulse1); // Channel 1
}