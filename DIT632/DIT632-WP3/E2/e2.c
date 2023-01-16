// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: Da-346!

float celsiusTemp = 0; //variable for storing temp
int light = 0; //variable for storing light
const int light0 = 26; //0% light level 
const int light20 = 720; //20% light level
const int light60 = 877; //60% light level
const int wait = 1; // time between readings in seconds
const int red = 4; //pin for red LED
const int blue = 3; //pin for blue LED
const int green = 2; //pin for green LED

void setup()
{
  pinMode(A0, INPUT); //temp input
  pinMode(A1, INPUT); //light sensor input
  pinMode(green, OUTPUT); //GREEN light
  pinMode(blue, OUTPUT); //BLUE light
  pinMode(red, OUTPUT); //RED light
}

void loop(){
  celsiusTemp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); //converts from celsius differs ~1c at some values
  light = analogRead(A1);
  if(light == light0){ //light is 0
    if(celsiusTemp > -12 ){ //temp is greater to or equal to 12, 1c diff
     tempHigh();
    }
    else{ tempNormal(); }
  }
  else if(light <= light20){ //light between 1 and 20
    if(celsiusTemp < -11 ){ //temp less than -12 once again 1c diff
    tempLow();
    }
    else if(celsiusTemp > 1 ){ // 1 degree = 0 actual degrees = temp greater than 0
    tempHigh();
    }
    else{ tempNormal(); } //no temp deviation
  }
  else if(light <= light60){ //light between 21 and 60
    if(celsiusTemp < 1 ){ //less than 0 due to calc diff from temp
    tempLow();
    }
    else if(celsiusTemp > 21 ){ //temp greater than 20 calc diff
    tempHigh();
    }
    else{ tempNormal(); } //no temp deviation
  }
  else{ //light is greater than 60 
    if(celsiusTemp < 22 ){ //temp less than 21 1c diff in calc
    tempLow();
    }
    else{ tempNormal(); } //no temp deviation
  }
  
  delay(wait * 1000); //loop delay
}
void tempNormal(){ //sets lights to normal mode(green light only)
digitalWrite(red, LOW);
digitalWrite(blue, LOW); 
digitalWrite(green, HIGH); 
}
void tempHigh(){ //sets lights to temperature higher mode(red light only)
digitalWrite(red, HIGH); 
digitalWrite(blue, LOW); 
digitalWrite(green, LOW); 
}
void tempLow(){ //sets lights to temperature lower mode(blue light only)
digitalWrite(red, LOW);
digitalWrite(blue, HIGH);
digitalWrite(green, LOW);
}