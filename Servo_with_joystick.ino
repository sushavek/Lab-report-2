/*
 This program is a servo motor that works with joystick. 
 The purpose of the joystick is be able to move either 0 degrees and 180 degrees.
 */



#include <Servo.h>                          // library of servo motor
                   
int JoystickValue;                          // the value of the joystick
Servo myservo;                         
int pos = 0;                                // initial position of the servo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                      // Serial communication
myservo.attach(9);                         // Pin for servo is 9
                 
}

void loop() {
        
int JoystickValue= analogRead(A1);         // value of the joystick can up to 1028 because of bit values of analog
pos= map(JoystickValue,0,1023,0,180);      // doing the map so it will be easier to have its position
myservo.write(pos);                        // the output of the servo's position
Serial.print(pos);
}
