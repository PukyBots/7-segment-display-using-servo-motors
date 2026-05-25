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


void setup() {

  Serial.begin(9600);

  pca.begin();
  pca.setPWMFreq(50);

  delay(500);

  Serial.println("Multi Servo Control Started");


  moveServos(170, 20, 50, 100, 50, 150, 150);

  Serial.println("Initial Position Set");

  delay(2000);

 

  moveServos(70, 120, 150, 0, 150, 50, 50);

  Serial.println("Second Position Set");

  delay(2000);

  // ================= BACK TO INITIAL =================

  moveServos(170, 20, 50, 100, 50, 150, 150);

  Serial.println("Returned to Initial Position");
}

void loop() {

}

void moveServos(int angle0, int angle1,int angle4, int angle9,int angle11, int angle5,int angle8) {

  // Constrain angles within limits
  angle0 = constrain(angle0, CH0_MIN, CH0_MAX);
  angle1 = constrain(angle1, CH1_MIN, CH1_MAX);
  angle4 = constrain(angle4, CH0_MIN, CH0_MAX);
  angle9 = constrain(angle9, CH1_MIN, CH1_MAX);
  angle11 = constrain(angle11, CH0_MIN, CH0_MAX);
  angle5 = constrain(angle5, CH1_MIN, CH1_MAX);
  angle8 = constrain(angle8, CH0_MIN, CH0_MAX);
  

  // Convert angles to PWM pulses
  int pulse0 = map(angle0, 0, 180, SERVOMIN, SERVOMAX);
  int pulse1 = map(angle1, 0, 180, SERVOMIN, SERVOMAX);
  int pulse4 = map(angle4, 0, 180, SERVOMIN, SERVOMAX);
  int pulse9 = map(angle9, 0, 180, SERVOMIN, SERVOMAX);
  int pulse11 = map(angle11, 0, 180, SERVOMIN, SERVOMAX);
  int pulse5 = map(angle5, 0, 180, SERVOMIN, SERVOMAX);
  int pulse8 = map(angle8, 0, 180, SERVOMIN, SERVOMAX);


  // Move servos together
  pca.setPWM(0, 0, pulse0); // Channel 0
  pca.setPWM(1, 0, pulse1); // Channel 1
  pca.setPWM(4, 0, pulse4); // Channel 4
  pca.setPWM(9, 0, pulse9); // Channel 9
  pca.setPWM(11, 0, pulse11); // Channel 11
  pca.setPWM(5, 0, pulse5); // Channel 5
  pca.setPWM(8, 0, pulse8); // Channel 8
}