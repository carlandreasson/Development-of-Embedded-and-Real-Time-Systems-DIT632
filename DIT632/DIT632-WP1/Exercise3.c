// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 3
// Submission code: FR22KL1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 10 // maximum amount of tries

int guessNumber(); //game function, limitation: crashes with some invalid input such as letters


// ------ Main   -------------------------- 

int main(void)
{

guessNumber(); //the function call inside main
    return 0;

}

// ------ Main   -------------------------- 

int guessNumber(){ //function that is the game
    int randomNumber = 0; //variable declaration set to zero
    int number = 0; //variable declaration set to zero
    int counter = 0; //variable declaration set to zero
    int playAgain = 0; //variable declaration set to zero

    srand(time(NULL)); // sets the random number
    randomNumber = rand() % 100 + 1; //generates the random number between 1 and 100

    printf("I want to play a game.\n Guess the number between 1 to 100, you have 10 tries to.\n Good Luck! \n");
    printf("Guess the number: ");

    while (counter < MAX_NUMBER) // while loop that goes on as long as the counter does not exceed maximum amount of tries
    {
        counter++; //counts the tries
        scanf("%d", &number);

        if (number == randomNumber) ////checks and sends message if the guessed number is equal to the random number
        {
            printf("You guessed correctly in %d out of 10 tries! Well done!\n Do you want to play again?\n 1 for Yes 2 for No:", counter);
            scanf("%d", &playAgain);
            if (playAgain == 1){ //if user presses 1 the game starts over, else it terminates
                guessNumber();
            }
            else {
                return 0;
            }
        }
        if (number < randomNumber){ //checks and sends message if the guessed number is smaller than the random number
            printf("Too low.\n Try again: ");
        }
        if (number > randomNumber){ //checks and sends message if the guessed number is bigger than the random number
            printf("Too high.\n Try again: ");
        }
        if (counter == MAX_NUMBER){ //checks and sends message if counter exceeds the amount of tries
           printf("You have reached maximum amount of tries. Try again!\n ");  
           guessNumber(); //starts the game over
        }
    }
    return 0;
}
