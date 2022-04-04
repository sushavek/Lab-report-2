
/*
 Stepper Motor Control - speed control 


 */

#include <Stepper.h>                  // Stepper motor library       
int JoystickValue;
int pos = 0;
const int stepsPerRevolution = 2048;  // the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 10;  // number of steps the motor has taken
int dt= 500;

void setup() {
  // nothing to do inside the setup
  Serial.begin(9600);
  myStepper.setSpeed(stepCount);

}

void loop() {
  int joystickValue = analogRead(A0);
  int motorSpeed = map ( joystickValue, 0, 1023, 0, 100);
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution/100);  
  }
  Serial.print(motorSpeed);
}
