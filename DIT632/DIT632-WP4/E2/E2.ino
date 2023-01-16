// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 4
// Exercise 2
// Submission code: 032!Ff?

#include <Servo.h>   //servo library
#define SERVO_PIN 9 //servo pin defined


Servo servo_9; //declaring servo
int time = 1; //storage for time, time starts at one due to the way time is incremented

void setup()
{
  servo_9.attach(SERVO_PIN); //set servo to servo pin  
  Serial.begin(9600); //initiate serial to be able to print
}

void loop()
{
  servo_9.write(0); //move servo towards lowest position
  delay(1000); //delay 1 second
  Serial.println(time++); //print and increment time
  servo_9.write(180); //move servo towards highest position
  delay(1000); //delay 1 second
  Serial.println(time++); //print and increment time
}
