#include <Servo.h>
int motor=3;
int POTpin=A0;
int POT1;
int motorval;
int servoval;
int servopin=6;
Servo Isha;
void setup() {
Serial.begin(9600);
pinMode(motor,OUTPUT);
pinMode(POTpin,INPUT);
Isha.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:

POT1=analogRead(POTpin);
motorval = map(POT1, 0, 1023, 0, 255);
Serial.println(POT1);
Serial.println(motorval);
analogWrite(motor, motorval);


servoval = map(POT1, 0, 1023, 40, 140);
Isha.write(servoval);
Serial.println(servoval);

}
