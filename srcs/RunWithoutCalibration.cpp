// Name: RunWithoutCalibration
// Author: Dustin Mendoza (penguindustin@gmail.com)
// 
// Description: Simple template code that runs the BLDC motor without having to recalibrate
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

int value = 0;
Servo ESC;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  ESC.attach(ESC_PIN);
  ESC.write(0);
  Serial.println("Waiting for normal startup");
  delay(1500); //One long beep should come from ESC
  Serial.println("One long beep ");
}

void loop() {
  int tmp;
  for(value = 0; value <=70; value+=5){
    tmp = map(value,0,100,0,180);
    ESC.write(tmp);
    delay(1000);
  }
  
  delay(3000);
  for(value = 70; value > 0; value -=5){
    tmp = map(value,0,100,0,180);
    ESC.write(tmp);
    delay(1000);
  }
  
  ESC.write(0);
  delay(2000);
 
 }