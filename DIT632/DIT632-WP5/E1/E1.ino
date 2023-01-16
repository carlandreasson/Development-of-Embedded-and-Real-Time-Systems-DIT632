// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 5
// Exercise 1
// Submission code: ?567kLm! 

//Code from our (Group 5) earlier work in WP 3 E 1

void setup()
{
  pinMode(13, OUTPUT); //PIN LED
  pinMode(3, OUTPUT); //PIN LED/button
  digitalWrite(3, HIGH); //Power for LED/button
  
}

void loop()
{
  digitalWrite(13, HIGH); //light LED
  delay(1000); // wait one second
  digitalWrite(13, LOW); //turn off LED
  delay(1000); // wait one second
}
