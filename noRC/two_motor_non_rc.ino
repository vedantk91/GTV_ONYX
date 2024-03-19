[12:59, 12/10/2021] Vedant Kelkar: #include <Servo.h>
const int PWMB = 6;
const int BIN1 = 5;
const int BIN2 = 4;
const int PWMA = 11;
const int AIN1 = 9;
const int AIN2 = 10;

int servopin=3;
Servo Isha;
int servoval;
int POTpin=2;
int POT1;

int Vedantval;

int SC1 = 0;  //pin potmotor

int MotorSpeed1 = 0;


void setup()
{
  Serial.begin(9600);                      //set all pins as output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(SC1,INPUT);
  pinMode(POTpin,INPUT);
  
Isha.attach(servopin);
  
}

void loop()
{
                        //drive forward at full speed by pulling AIN1 High
                        //and AIN2 low, while writing a full 255 to PWMA to
                        //control speed

//Serial.println("MOTOR");

int speed1=analogRead(SC1);
  //Serial.println(speed1);

 // MotorSpeed1 = map(speed1, 0, 1023, 0, 255);
 if (speed1 < 500){
  Vedantval = map(speed1, 0, 500, 255, 0);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA, Vedantval);
  analogWrite(PWMB, Vedantval);
  
  
 }

  if (speed1 > 525){
      Vedantval = map(speed1, 525, 1023, 0, 255);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, Vedantval);
   analogWrite(PWMA, Vedantval);
   }
//Serial.println();
//Serial.println("MOTOR");
//Serial.println(Vedantval);
Serial.println(speed1);
//Serial.println();
Serial.println("SERVO");

  

POT1=analogRead(POTpin);
Serial.println(POT1);
servoval = map(POT1, 0, 1023, 40, 140);
Isha.write(servoval);
//Serial.println(servoval);

delay(1000);
}
[13:43, 12/10/2021] Vedant Kelkar: #include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
Servo isha;
int servoPin=6;

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
  }
}
