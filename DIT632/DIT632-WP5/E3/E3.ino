// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 5
// Exercise 3
// Submission code: ?567kLm!

//Code from our (Group 5) earlier work in WP 3 E 2

#include <dht.h>


#define LED_B 5 //PIN blue LED
#define LED_G 6 //PIN green LED
#define LED_R 7 //PIN red LED
#define DHT11_PIN 10 //pin for temp sensor
const int light0 = 50; //0% light
const int light20 = 300; //20% light 
const int light60 = 650; //60% light
const int wait = 2; //wait between loop iterations in seconds

dht DHT; //define the DHT sensor(temp)
float celsiusTemp = 0; //variable for storing temp

void setup()
{
  pinMode(A1, INPUT); //temp input
  pinMode(LED_B, OUTPUT); //blue LED
  pinMode(LED_G, OUTPUT); //green LED
  pinMode(LED_R, OUTPUT); //red LED
  pinMode(A0, INPUT); // light sensor
  Serial.begin(9600); //print
  
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN); //read data from sensor
  int light = analogRead(A0); //read light level
  celsiusTemp =  DHT.temperature; // getting the previously read temp from sensor

  //print statements for light and temp
  Serial.print("temperature: "); 
  Serial.print(celsiusTemp);
  Serial.println("C");
  Serial.print("light: ");
  Serial.println(light);

  lightTempCheck(light, DHT.temperature); //function call to handle the read lights
  delay(wait * 1000); //delay between iterations given in const wait in full seconds
}
void lightTempCheck(int light, float temp){ //compares light and temp and calls functions regarding to what is read
  if(light == light0){ //light is 0
    if(temp > -11 ){ //temp is greater to or equal to 12
     tempHigh();
    }
    else{ tempNormal(); }
  }
  else if(light <= light20){ //light between 1 and 20
    if(temp < -12 ){ //temp less than -12
    tempLow();
    }
    else if(temp > 0 ){ // temp greater than 0
    tempHigh();
    }
    else{ tempNormal(); } //no temp deviation
  }
  else if(light <= light60){ //light between 21 and 60
    if(temp < 0 ){ //less than 0
    tempLow();
    }
    else if(temp > 20 ){ //temp greater than 20 
    tempHigh(); 
    }
    else{ tempNormal(); } //no temp deviation
  }
  else{ //light is greater than 60 
    if(temp < 21 ){ //temp less than 21
    tempLow();
    }
    else{ tempNormal(); } //no temp deviation
  }
}
  void tempNormal(){ //sets lights to normal mode(green light only)
digitalWrite(LED_R, LOW);
digitalWrite(LED_B, LOW); 
digitalWrite(LED_G, HIGH); 
}
void tempHigh(){ //sets lights to temperature higher mode(red light only)
digitalWrite(LED_R, HIGH); 
digitalWrite(LED_B, LOW); 
digitalWrite(LED_G, LOW); 
}
void tempLow(){ //sets lights to temperature lower mode(blue light only)
digitalWrite(LED_R, LOW);
digitalWrite(LED_B, HIGH);
digitalWrite(LED_G, LOW);
}
