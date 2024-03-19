//Include Libraries
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
Servo isha;
int servoPin=6;
int motorPin = 5;
//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
  isha.attach(servoPin);
  pinMode (motorPin, OUTPUT);
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    int angleValue = {0};
    radio.read(&angleValue, sizeof(angleValue));
    isha.write(angleValue);
    Serial.println(angleValue);

    int motorval = {0};
    radio.read(&motorval, sizeof(motorval));
    analogWrite(motorPin, motorval);
    Serial.println(motorval);
  }
}
