// Name: Program
// Author: Dustin Mendoza (penguindustin@gmail.com)
// 
// Description: This script programs the throttle calibration to specified timing widths
//
// Notes:
//
// (1) - ESC used: https://hobbyking.com/en_us/hobbywing-x-rotor-esc-20amp.html
// (2) - BLDC motor: https://hobbyking.com/en_us/d2830-11-1000kv-brushless-motor.html
// (3) - Battery used: https://www.sparkfun.com/products/11856
// (4) - Pro Mini 5V version
// (5) - Pro Mini has PWM ports on pins 3,5,6,9,10,11
// (6) - servo.write uses 0-180

#include <Servo.h>

#define LED_PIN 13
#define ESC_PIN 5
#define MAX_SIGNAL 2300
#define NETRUAL 1400
#define MIN_SIGNAL 400

int value = 0;
Servo ESC;

void waitForEnter(){
  while (!Serial.available());
  Serial.read();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  ESC.attach(ESC_PIN);

  Serial.println("Starting Calibration, make sure ESC is not powered (e.g. connected to the battery)");  
  Serial.println("press enter to begin calibrating");
  delay(100);

  waitForEnter();
  Serial.println("Calibrating MaxSignal");
  delay(100);
  ESC.writeMicroseconds(MAX_SIGNAL);
  
  Serial.println("Please connect battery and press Enter after hearing Beep-Beep");
  delay(100);
  waitForEnter();
  Serial.println("Throttle Calibration complete");
  delay(100);
  ESC.writeMicroseconds(MIN_SIGNAL);
  Serial.println("Press enter to finish");
  waitForEnter();
}

void loop() {

}