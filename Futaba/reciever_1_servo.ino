

#include <ServoInput.h>
#include <Servo.h>

ServoInputPin<2> servo1;
ServoInputPin<3> servo3;
Servo isha;
int ishaPin = 9;
float vedantval;

//Servo aakas;

void setup() {
  Serial.begin(115200);
  isha.attach(ishaPin);
  pinMode(ishaPin, OUTPUT);
 //aakas.attach(11,1000,2000);

}

void loop() {
  float angle1 = servo1.getAngle();// get angle of servo (0 - 180)
  float angle2 = servo3.getAngle(); // get angle of servo (0 - 180)
  //float ishaval = map(angle1, 22, 180, 40,140);
   isha.write(angle1);
  //Serial.println(angle1);
 Serial.println("Angle Value");
 Serial.println(angle1);
// //Serial.println("Isha Value");
//  //Serial.println(ishaval);
//  Serial.print("Angle 2: ");
//  Serial.println(angle2);
//  Serial.print("Vedant Value: ");
//  Serial.println(vedantval);
}
