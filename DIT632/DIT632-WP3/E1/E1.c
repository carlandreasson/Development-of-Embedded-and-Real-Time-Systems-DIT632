// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: Da-346!

void setup()
{
  pinMode(9, OUTPUT); // output port for the button LED light.
  pinMode(8, OUTPUT); // output port for the flashing LED light.
  digitalWrite(9, HIGH); // turns on output for the button led as the button and not the code controls the flow
}

void loop()
{
  digitalWrite(8, HIGH); // turns on light.
  delay(500);  // delay between on and off 0.5 seconds.
  digitalWrite(8, LOW); // turns off light.
  delay(500); // delay between off and on 0.5 seconds.
}