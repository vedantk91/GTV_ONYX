const int PWMB = 6;
const int BIN1 = 5;
const int BIN2 = 4;
const int PWMA = 11;
const int AIN1 = 12;
const int AIN2 = 10;

int motorval;

#include <ServoInput.h>
#include <Servo.h>
/* The signal pin for ServoInput MUST be an interrupt-capable pin!
 *     Uno, Nano, Mini (328P): 2, 3
 *     Micro, Leonardo (32U4): 0, 1, 2, 3, 7
 *             Mega, Mega2560: 2, 3, 18, 19, 20, 21
 * Reference: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 */
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
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

}

void loop() {
  float angle1 = servo1.getAngle();// get angle of servo (0 - 180)
  float angle2 = servo3.getAngle(); // get angle of servo (0 - 180)
  //float ishaval = map(angle1, 22, 180, 40,140);
  float vedantval = map(angle2,18,180,0,1023);
  float speed1=vedantval;
  Serial.println("SPEED");
  Serial.println(angle2);
  Serial.println(speed1);


 if (speed1 < 500){
  motorval = map(speed1, 0, 500, 255, 0);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, motorval);
  analogWrite(PWMB, motorval);
 }

  if (speed1 > 525){
      motorval = map(speed1, 525, 1023, 0, 255);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, motorval);
   analogWrite(PWMA, motorval);
   }

Serial.println();
Serial.println("MOTOR");
Serial.println(motorval);
  //isha.write(angle1);
   //isha.write(angle1);
  //Serial.println(angle1);
 //Serial.println("Angle Value");
 //Serial.println(angle1);
 //Serial.println("Isha Value");
  //Serial.println(ishaval);
//  Serial.print("Angle 2: ");
//  Serial.println(angle2);
//  Serial.print("Vedant Value: ");
//  Serial.println(vedantval);
//delay(1000);
}
