// Name: ProgramAndRun
// Author: Dustin Mendoza (penguindustin@gmail.com)
// 
// Description: Simple program to drive ESC for BLDC motor, must have serial monitor open
// for program to work.
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
  ESC.write(180);
  
  Serial.println("Please connect battery and press Enter after hearing Beep-Beep");
  delay(100);
  waitForEnter();
  Serial.println("Throttle Calibration complete");
  Serial.println("Press enter to run BLDC");
  delay(100);
  ESC.write(0);
  waitForEnter();
  
}

void loop() {
  int tmp;
  // put your main code here, to run repeatedly:
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