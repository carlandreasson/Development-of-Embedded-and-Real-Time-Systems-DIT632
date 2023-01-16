// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 6
// Exercise 2
// Submission code: S3570


//distances for different levels of alerting
const int maxDistance = 200;
const int highDistance = 141;
const int lowDistance = 83;
const int lowerDistance = 30;
const int minDistance = 25;
const int waitAmount = 200;

//pins for sensor speaker and leds
const int distSensPin = 6;
const int speakerPin = 9;
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;

int cm = 0; //distance variable in cm

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  cm = getDistance(distSensPin); //measure distance in cm
 
 //following if block controls the distance and activates lights and noise if an object is close enough to the sensor
 //the else statement also turns of the lights to make them blink if they get activated by the loop in the next pass through.
  if(cm >= maxDistance) {ledControl(0); noise(0);}
  else if(cm > highDistance) {ledControl(1); noise(250); }
  else if(cm > lowDistance) {ledControl(2); noise(400); }
  else if(cm >= lowerDistance){ledControl(3); noise(500); }
  else if(cm >= minDistance) {ledControl(4); noise(600); }
  else {ledControl(4); noise(900); delay(waitAmount); ledControl(0);}

  delay(waitAmount); // wait for the amount of time given in waitAmount
}

int getDistance(int sensorPin)
{
  pinMode(sensorPin, OUTPUT);  // Clear the trigger
  digitalWrite(sensorPin, LOW);
  delay(2);
  // Sets the sensor pin to HIGH state for 10 microseconds
  digitalWrite(sensorPin, HIGH);
  delay(10);
  digitalWrite(sensorPin, LOW);
  pinMode(sensorPin, INPUT);
  return 0.01723 * pulseIn(sensorPin, HIGH); //reads the traveltime and converts it to centimeters(* 0.01723)
}

void ledControl (int amountLights) { //takes an int from 0-4 and turns on the amount of lights in the int all amounts greater than 4 will turn on 4 lights

    if (amountLights == 0) { //turn off lights
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (amountLights == 1) {  //turn on 1 light
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (amountLights == 2) { //turn on 2 lights
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (amountLights == 3) { //turn on 3 lights
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }

  else if (amountLights == 4) { //turn on 4 lights
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }

}

void noise (int freq) { //takes a frequency as input and activates the speaker. A freq of 0 will turn off the speaker.

  if(freq == 0){
   noTone(speakerPin); //turn off speaker
  }

  else{
  tone(speakerPin, freq); //send freq to speaker
  }
}
