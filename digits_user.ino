#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

// ================= LIMITS =================

#define CH0_MIN 70
#define CH0_MAX 170

#define CH1_MIN 20
#define CH1_MAX 120

#define CH4_MIN 50
#define CH4_MAX 150

#define CH9_MIN 0
#define CH9_MAX 100

#define CH11_MIN 50
#define CH11_MAX 150

#define CH5_MIN 50
#define CH5_MAX 150

#define CH8_MIN 50
#define CH8_MAX 150

int number;

void setup() {

  Serial.begin(9600);

  pca.begin();
  pca.setPWMFreq(50);

  delay(500);

  Serial.println("Multi Servo Control Started");

  // ================= DEMO =================

  runDigit(0);
  delay(2000);

  runDigit(1);
  delay(2000);

  runDigit(2);
  delay(2000);

  runDigit(3);
  delay(2000);

  runDigit(4);
  delay(2000);

  runDigit(5);
  delay(2000);

  runDigit(6);
  delay(2000);

  runDigit(7);
  delay(2000);

  runDigit(8);
  delay(2000);

  runDigit(9);
  delay(2000);

  Serial.println("Enter a digit (0-9):");
}

void loop() {

  if (Serial.available() > 0) {

    number = Serial.parseInt();

    if (number >= 0 && number <= 9) {

      runDigit(number);

      Serial.print("Displayed Digit: ");
      Serial.println(number);
    }
    else {

      Serial.println("Invalid Input. Enter 0-9");
    }
  }
}

// ===================================================
// DIGIT FUNCTION
// ===================================================

void runDigit(int digit) {

  switch(digit) {

    case 0:
      moveServos(70, 120, 150, 0, 150, 150, 50);
      break;

    case 1:
      moveServos(170, 120, 150, 100, 50, 150, 150);
      break;

    case 2:
      moveServos(70, 120, 50, 0, 150, 50, 150);
      break;

    case 3:
      moveServos(70, 120, 150, 100, 150, 50, 150);
      break;

    case 4:
      moveServos(170, 120, 150, 100, 50, 50, 50);
      break;

    case 5:
      moveServos(70, 20, 150, 100, 150, 50, 50);
      break;

    case 6:
      moveServos(70, 20, 150, 0, 150, 50, 50);
      break;

    case 7:
      moveServos(70, 120, 150, 100, 50, 150, 150);
      break;

    case 8:
      moveServos(70, 120, 150, 0, 150, 50, 50);
      break;

    case 9:
      moveServos(70, 120, 150, 100, 150, 50, 50);
      break;
  }
}

// ===================================================
// MOVE SERVOS
// ===================================================

void moveServos(int angle0, int angle1, int angle4,
                int angle9, int angle11,
                int angle5, int angle8) {

  // Constrain angles

  angle0  = constrain(angle0, CH0_MIN, CH0_MAX);
  angle1  = constrain(angle1, CH1_MIN, CH1_MAX);

  angle4  = constrain(angle4, CH4_MIN, CH4_MAX);
  angle9  = constrain(angle9, CH9_MIN, CH9_MAX);

  angle11 = constrain(angle11, CH11_MIN, CH11_MAX);
  angle5  = constrain(angle5, CH5_MIN, CH5_MAX);

  angle8  = constrain(angle8, CH8_MIN, CH8_MAX);

  // Convert to PWM pulse

  int pulse0  = map(angle0, 0, 180, SERVOMIN, SERVOMAX);
  int pulse1  = map(angle1, 0, 180, SERVOMIN, SERVOMAX);

  int pulse4  = map(angle4, 0, 180, SERVOMIN, SERVOMAX);
  int pulse9  = map(angle9, 0, 180, SERVOMIN, SERVOMAX);

  int pulse11 = map(angle11, 0, 180, SERVOMIN, SERVOMAX);
  int pulse5  = map(angle5, 0, 180, SERVOMIN, SERVOMAX);

  int pulse8  = map(angle8, 0, 180, SERVOMIN, SERVOMAX);

  // Move Servos

  pca.setPWM(0, 0, pulse0);
  pca.setPWM(1, 0, pulse1);

  pca.setPWM(4, 0, pulse4);
  pca.setPWM(9, 0, pulse9);

  pca.setPWM(11, 0, pulse11);
  pca.setPWM(5, 0, pulse5);

  pca.setPWM(8, 0, pulse8);
}