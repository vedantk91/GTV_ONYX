//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop()
{
  //Send message to receiver
  //const char text[] = "Hello World";
  //radio.write(&text, sizeof(text));
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));
  Serial.println(potValue);
  Serial.println(angleValue);

  int pot1Value_1 = analogRead(A1);
  int motorval = map(pot1Value_1, 0, 1023, 0, 255);

  radio.write(&motorval, sizeof(motorval));
  Serial.println(pot1Value_1);
  Serial.println(motorval);
  delay(1000);
}
