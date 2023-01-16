// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: Da-346!

float celsiusTemp = 0; //variable for storing temp
const int wait = 500; // time between readings in seconds

void setup()
{
  pinMode(A0, INPUT); //temp input
  Serial.begin(9600); //begin serial communication to be able to print temp
}

void loop(){
  celsiusTemp = (((analogRead(A0) * 4.9) - 500) / 10); //read voltage from pin A0 then conversion from voltage to celsius this method differs a little bit(1-2C) at some values.
  //also some diff att different values but that is not relevant for this
  Serial.println(celsiusTemp); 
  delay(wait); //wait as we dont need to read temp as fast as we possibly can
}
