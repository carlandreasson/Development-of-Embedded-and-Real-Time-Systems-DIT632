// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 5
// Exercise 2
// Submission code: ?567kLm!

//Code from our (Group 5) earlier work in WP 4 E 1

#include <dht.h>

#define DHTTYPE DHT11   // define what dht sensor we are using
#define LED_W 9 //PIN white LED
#define LED_B 8 //PIN blue LED
#define LED_G 7 //PIN green LED
#define LED_Y 6 //PIN yellow LED
#define LED_R 5 //PIN red LED
#define COLDEST -5 //temp coldest
#define COLD 5 //temp cold
#define NORMAL 15 //temp normal
#define HOT 25 //temp hot
#define HOTTEST 35 //temp hottest
#define DHT11_PIN 11 //pin for DHT sensor
#define WAIT 1000 //wait time for loop iterations in ms

DHT dht(DHT11_PIN ,DHTTYPE); //declare the DHT sensor
float celsiusTemp = 0; //variable for storing temp


void setup()
{
  pinMode(A1, INPUT); //temp input
  pinMode(LED_W, OUTPUT); //white LED
  pinMode(LED_B, OUTPUT); //blue LED
  pinMode(LED_G, OUTPUT); //green LED
  pinMode(LED_Y, OUTPUT);//yellow LED
  pinMode(LED_R, OUTPUT); //red LED
  Serial.begin(9600); //print
  dht.begin(); //initialize the DHT sensor(temperature sensor)
}

void loop()
{
  
  celsiusTemp =  dht.readTemperature(); //read temperature from the DHT11 module
  Serial.print("temperature: ");
  Serial.print(celsiusTemp); //print temperature to serial monitor for verification
  Serial.println("C");
  //Serial.print("humidity: ");
  //Serial.println(dht.readHumidity());
  if (celsiusTemp < COLDEST) //if temp is smaller than defined temperature, turns on one lLED
  {
    tempColdest(); //function call
  }
  else if (celsiusTemp < COLD) //if temp is smaller than defined temperature, turns on two LEDs
  {
    tempCold(); //function call
  }
  else if (celsiusTemp < NORMAL) //if temp is smaller than defined temperature, turns on three LEDs
  {
    tempNormal(); //function call
  }
  else if (celsiusTemp < HOT)//if temp is smaller than defined temperature, turns on four LEDs
  {
    tempHot(); //function call
  }
  else //else temperature is greater than defined temperature and turns on all LEDs
  {
    tempHottest(); //function call
  }
  delay(WAIT); // wait between reads slow sensor and we dont need to know temperature at all times
}

void tempColdest(){ //sets lights to coldest mode(white LED only)
digitalWrite(LED_W, HIGH);
digitalWrite(LED_B, LOW); 
digitalWrite(LED_G, LOW); 
digitalWrite(LED_Y, LOW);
digitalWrite(LED_R, LOW); 
}
void tempCold(){ //sets lights to cold mode(white and blue LED)
digitalWrite(LED_W, HIGH);
digitalWrite(LED_B, HIGH); 
digitalWrite(LED_G, LOW); 
digitalWrite(LED_Y, LOW);
digitalWrite(LED_R, LOW); 
}
void tempNormal(){ //sets lights to normal mode(white,blue and green LED)
digitalWrite(LED_W, HIGH);
digitalWrite(LED_B, HIGH); 
digitalWrite(LED_G, HIGH); 
digitalWrite(LED_Y, LOW);
digitalWrite(LED_R, LOW); 
}
void tempHot(){ //sets lights to hot mode(white, blue, green and yellow LED)
digitalWrite(LED_W, HIGH);
digitalWrite(LED_B, HIGH); 
digitalWrite(LED_G, HIGH); 
digitalWrite(LED_Y, HIGH);
digitalWrite(LED_R, LOW); 
}
void tempHottest(){ //sets lights to hottest mode(all LEDs)
digitalWrite(LED_W, HIGH);
digitalWrite(LED_B, HIGH); 
digitalWrite(LED_G, HIGH); 
digitalWrite(LED_Y, HIGH);
digitalWrite(LED_R, HIGH);  
}
