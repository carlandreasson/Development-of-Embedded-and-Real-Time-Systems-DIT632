// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: Da-346!

#include <Keypad.h> //import keypad library


const byte ROWS = 4; //amount of rows
const byte COLS = 4; //amount of columns
char keys[ROWS][COLS] = { //our keypad
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //pins for rows
byte colPins[COLS] = {7, 6, 5, 4}; //pins for columns

//create keypad
Keypad tinkerKeypad = Keypad(makeKeymap(keys), 
                             rowPins, 
                             colPins, 
                             ROWS, 
                             COLS); 

void setup()
{
  Serial.begin(9600); //initiate serial
}

void loop()
{
  char pressedKey = tinkerKeypad.getKey(); //gets currently pressed key
  if (pressedKey){ //checks if a key is pressed
    Serial.println(pressedKey); //prints the key that was pressed
  }
  delay(10); // Delay a little bit to improve simulation performance
}