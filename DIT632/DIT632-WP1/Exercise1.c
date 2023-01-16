// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 1
// Submission code: FR22KL1 
#include <stdio.h>

void getInteger(); //number input getting and string printing function
void main()
{
  getInteger(); //function call to the "game"
}
void getInteger()
{
  int userInt; //user input stored here
  printf("Enter an int between 1-5: ");
  scanf("%d", &userInt); //get int as user input
  if (userInt == 1) //checks if input equals 1 and prints corresponding part to the theme song of space jam
  {
    printf("Everybody get up it's time to slam now\n");
    getInteger(); //restart function
  }
  else if (userInt == 2) //checks if input equals 2 and prints corresponding part to the theme song of space jam
  {
    printf("We got a real jam goin' down\n");
    getInteger(); //restart function
  }
  else if (userInt == 3) ////checks if input equals 3 and prints corresponding part to the theme song of space jam
  {
    printf("Welcome to the Space Jam\n");
    getInteger(); //restart function
  }
  else if (userInt == 4) //checks if input equals 4 and prints corresponding part to the theme song of space jam
  {
    printf("Here's your chance, do your dance\n");
    getInteger(); //restart function
  }
  else if (userInt == 5) //checks if input equals 5 and prints corresponding part to the theme song of space jam
  {
    printf("At the Space Jam Alright\n");
    getInteger(); //restart function
  }
  else{ //this case handles when the user enters anything thats not accounted for in the if statements
    printf("invalid input");
  }
}
