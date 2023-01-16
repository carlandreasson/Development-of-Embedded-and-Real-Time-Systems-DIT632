// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 4
// Submission code: FR22KL1 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void convertToBinary(long conv, char number[], int size);
void reverseArray(char number[], int length);
int validNumber(char *string);

int main(int argc, char *argv[])
{
    char binary[65] = {'0'}; //array for binary as long is max size 65 places is enough (65 for EOS)
    char *s; //used for conversion of args to long
    long int convertNumber; //number to be converted
    int size = 0; //how many bites the array should contain
    int z; //loop index

    //launch argument check
    if(argc < 2 || argc > 2){
        printf("ERROR wrong amount of launch arguments");
        return 2;
    }
    else if(strcmp(argv[1], "-h")==0){
        printf("To use this program enter a number in the launch arguments\nthis will then be converted to binary");
        return 2;
    }
    else if(validNumber(argv[1]) == 1){
        printf("ERROR not a valid number");
        return 2;
    }
    else{
        convertNumber = strtol(argv[1], &s, 10);
    }

    //array size determination
    if (convertNumber <= 127)
    {
        size = 8; //char
    }
    else if (convertNumber <= 32767)
    {
        size = 16; //short
    }
    else if (convertNumber <= 2137483647)
    {
        size = 32; //int
    }
    else
    {
        size = 64; // long
    }

    binary[size] = '\0'; //set EOS to right size.
    for (z = 0; z < size; z++) //fill array until EOS with 0, helps with leading 0's when printing
    {
        binary[z] = '0';
    }
    convertToBinary(convertNumber, binary, size);

    return 0;
}


int validNumber(char *string){ //checks so arg string only contains numbers
while (*string) {
        if (isdigit(*string++) == 0) return 1; //string contains not only numbers
    }
    return 0; //string contains only numbers
}

void convertToBinary(long conv, char number[], int size) //converts conv to binary and outputs result in number array.
{
    int i = 0;
    number[size - 1] = '0';
    int rest;
    while (conv > 0) // binary conversion inspired from https://www.geeksforgeeks.org/program-decimal-binary-conversion/
    {
        rest = conv % 2;
        if (rest == 1)
        {
            number[i] = '1';
        }
        else
        {
            number[i] = '0';
        }
        conv /= 2;
        i++;
    }
    reverseArray(number, size); // after conversion array is in wrong order and needs to be reversed
}
void reverseArray(char number[], int length) //reverses array
{
    int x;
    int y = length - 1;
    int temp;
    int half = (length / 2) - 1;

    for (x = 0; x <= half; x++) //reversal of array with 2 pointers(x & y).
    {
        temp = number[x];
        number[x] = number[y];
        number[y] = temp;
        y--;
    }

    printf("%s\n", number); //print final binary number.
}
