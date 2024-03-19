const int PWMA = 6;
const int AIN1 = 5;
const int AIN2 = 4;
int Vedantval;

int SC = 0;  
int MotorSpeed1 = 0;


void setup()
{
  Serial.begin(9600);                      //set all pins as output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(SC,INPUT);
  
}

void loop()
{
                        //drive forward at full speed by pulling AIN1 High
                        //and AIN2 low, while writing a full 255 to PWMA to
                        //control speed
int speed1=analogRead(SC);
  Serial.println(speed1);

 // MotorSpeed1 = map(speed1, 0, 1023, 0, 255);
 if (speed1 < 500){
  Vedantval = map(speed1, 0, 500, 255, 0);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, Vedantval);
  
 }




   if (speed1 > 525){
      Vedantval = map(speed1, 525, 1023, 0, 255);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, Vedantval);
   }
Serial.println();
Serial.println("MOTOR");
   Serial.println(Vedantval);
  
                        //wait 1 second
//  delay(1000);

                        //Brake the motor by pulling both direction pins to
                        //the same state (in this case LOW). PWMA doesn't matter
                        //in a brake situation, but set as 0.
                        //change direction to reverse by flipping the states
                        //of the direction pins from their forward state

  //REv



  

//  analogWrite(PWMA, 150);

                        //wait 1 second
//  delay(1000);
//
//                        //Brake again
//  digitalWrite(AIN1, LOW);
//  digitalWrite(AIN2, LOW);
//  analogWrite(PWMA, 0);

                        //wait 1 second
delay(1000);
}
