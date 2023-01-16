// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 2
// Submission code: FR22KL1

#include <stdio.h>
#include <stdlib.h>
void encrypt(int steps);
int main(int argc, char *argv[])
{
    if (argc > 1) {

    encrypt(atoi(argv[1])); // Converts arg to int then calls function
    } else {
        printf("\nNo arguments given, restart program!"); // Prints out failure message and tells you to restart the program
        return 1;
    }
    printf("\nGood job!");      //Prints good job if encryting of the word succedes
    return 0;
}

void encrypt(int steps)
{
    int size = 0;           // Declaring variable and setting its value ot zero
    char word[100];         // Declaring the Array "word" with a size of 100 slots
    int i;                  // Declaring index variable for first loop
    int z;                  // Declaring variable for second loop
    int index;              // Declaring the new index to swithc out the letter
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; // Array with the alphabet

    scanf("%s", word);   // Input scan for the the word you wanted to encrypt


    size = (sizeof word / sizeof word[0]); // Determening the length of the entered word
    for (i = 0; i < size; i++) //loops through each letter and replaces it with steps given as a launch argument
    {
        if (word[i] == '\0') //detects end of string and breaks out of loop
        {
            break;
        }

        for (z = 0; z < 26; z++) //loop through alphabet that first finds the letter word[i] in the alphabet and then exchanges it with the letter the correct amount of steps away(alphabet[z]).
        {
            if (word[i] == alphabet[z])
            {
                index = (z + steps) % 26; //makes sure we dont go outside of the alphabet
                word[i] = alphabet[index];

                break;
            }
        }


    }

            // Prints the encrypted word and lets you enter an new word to encrypt with the same chosen int argument

    printf("\n%s", word); //prints encrypted word
    encrypt(steps); //function call to restart after complete encryption
}
