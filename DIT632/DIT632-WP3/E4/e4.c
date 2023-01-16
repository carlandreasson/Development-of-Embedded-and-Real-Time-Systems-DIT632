// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: Da-346!

const int r1 = 11; //pins for rows 1-4
const int r2 = 10;
const int r3 = 9;
const int r4 = 8;
const int c1 = 7; //pins for columns 1-4
const int c2 = 6;
const int c3 = 5;
const int c4 = 4;
const int rows = 4; //amount of rows
const int columns = 4; //amount of columns

void setup()
{
  pinMode(c1, INPUT); //receive signal through columns (c1 - c4)
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  pinMode(c4, INPUT);
  pinMode(r1, OUTPUT); //send signal through rows  (r1 - r4)
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  Serial.begin(9600); //initiate serial
}

void loop()
{
  char print = ' '; //if a key is pressed its value is stored here
  int value[rows][columns];
  digitalWrite(r1, LOW);			// activate row 1
  value[0][0] = digitalRead(c1); 	//  reads column 1-4 of row 1
  value[0][1] = digitalRead(c2);
  value[0][2] = digitalRead(c3);
  value[0][3] = digitalRead(c4);	
  digitalWrite(r1, HIGH);
  
  digitalWrite(r2, LOW);			// activate row 2
  value[1][0] = digitalRead(c1); 	//  reads column 1-4 of row 2
  value[1][1] = digitalRead(c2);
  value[1][2] = digitalRead(c3);
  value[1][3] = digitalRead(c4);	
  digitalWrite(r2, HIGH);
  
  digitalWrite(r3, LOW);			// activate row 3
  value[2][0] = digitalRead(c1); 	//  reads column 1-4 of row 3
  value[2][1] = digitalRead(c2);
  value[2][2] = digitalRead(c3);
  value[2][3] = digitalRead(c4);	
  digitalWrite(r3, HIGH);
  
  digitalWrite(r4, LOW);			// activate row 4
  value[3][0] = digitalRead(c1); 	//  reads column 1-4 of row 4
  value[3][1] = digitalRead(c2);
  value[3][2] = digitalRead(c3);
  value[3][3] = digitalRead(c4);	
  digitalWrite(r4, HIGH);
  
  /* 
  if block below checks if a key is pressed
  value[y][x] corresponds to row (y + 1) and column (x + 1)
  so value[1][2] would correspond to row 2 and column 3
  
  if the value[y][z] is 0 the key has been pressed.

  waits 500ms after a key has been pressed so we dont print more than we need
  */
  if(value[0][0] == 0){ print = '1'; delay(500);}
  if(value[0][1] == 0){ print = '2'; delay(500);}
  if(value[0][2] == 0){ print = '3'; delay(500);}
  if(value[0][3] == 0){ print = 'A'; delay(500);}
  if(value[1][0] == 0){ print = '4'; delay(500);}
  if(value[1][1] == 0){ print = '5'; delay(500);}
  if(value[1][2] == 0){ print = '6'; delay(500);}
  if(value[1][3] == 0){ print = 'B'; delay(500);}
  if(value[2][0] == 0){ print = '7'; delay(500);}
  if(value[2][1] == 0){ print = '8'; delay(500);}
  if(value[2][2] == 0){ print = '9'; delay(500);}
  if(value[2][3] == 0){ print = 'C'; delay(500);}
  if(value[3][0] == 0){ print = '*'; delay(500);}
  if(value[3][1] == 0){ print = '0'; delay(500);}
  if(value[3][2] == 0){ print = '#'; delay(500);}
  if(value[3][3] == 0){ print = 'D'; delay(500);}
  
  /* end of if block */
  
  if(print != ' '){Serial.println(print);} //checks if key is pressed, single print statement for less clutter
  
  delay(10); //little delay to improve performance
} 