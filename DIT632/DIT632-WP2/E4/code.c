// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 2
// Exercise 4
// Submission code: 3Za#53 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARGAMOUNT 6 //define amount of arguments everything must be updated if changed

int argCheck(int *convert);
void reverseArray(int *number, int length);
void bitpacking(int *input, unsigned char output);
void binaryConvert(int conv, int *number, int length);
int validNumber(char *string);

int main(int argc, char *argv[])
{
if(argc != ARGAMOUNT){
printf("Invalid amount of launch arguments");
return 1;
}
else;

    int argConvert[ARGAMOUNT]; //storage for int converted args
    unsigned char result; //storage for final hex number
    for (int i = 1; i < ARGAMOUNT; i++)
    {
        if (validNumber(argv[i]) != 0) //checks so arguments only consists of positive numbers(covers both negative and non numeric entrys)
        {
            printf("Arguments must consist only of positive numbers");
            return 1;
        } //string contains invalid characters
        else
        {
            argConvert[i - 1] = (argv[i][0] - '0'); //subtracting char 0 from number moving us to the right place in the ascii table(int representation of args[i])
        }
    } //string contains only valid characters
    if (argCheck(argConvert) != 0)
    {
        printf("Invalid argument numbers");
        return 1;
    }
    bitpacking(argConvert, result);
    return 0;
}

void bitpacking(int *input, unsigned char output)
{
    int twoBitStorage[2] = {0}; //used to store binary conversion result
    int threeBitStorage[3] = {0}; //used to store binary conversion result
    int bits[8] = {0}; //storage for final number to be saved in char filled with 0's from begging for simplicity
    int z = 0; //index for bits array
    int x;
    int bit;
    int j; //second index used in bitshifting

    /*
    --positions in bit array--
        engine, pos 1
        gear, pos 2-4
        key, pos 5-6
        brake 1, pos 7
        brake 2, pos 8
    */

    
    for (int i = 0; i < ARGAMOUNT; i++) //loops through all arguments
    {

        if (i == 0 || i == 3 || i == 4) //single bits only allow 1 or 0 so for the bits in question we can just set them directly from the input without any conversion
        {
            bits[z] = input[i];
            z++;
        }
        else if (i == 1)
        {
            binaryConvert(input[i], threeBitStorage, 3); //converts number to binary
            for (x = 0; x < 3; x++) //adds the converted binary number to the bit array(bits[]) and increments z to keep it at the right index
            {
                bits[z] = threeBitStorage[x];
                z++;    
            } //bits[1-3]
        }
        else if (i == 2)
        {
            binaryConvert(input[i], twoBitStorage, 2); //converts number to binary
            for (x = 0; x < 2; x++) //adds the converted binary number to the bit array(bits[]) and increments z to keep it at the right index
            {
                bits[z] = twoBitStorage[x];
                z++;
            } //bits[4-5]
        }
    }
    j = 7;
    for(int y = 0; y < 8; y++){ //bitshifting inspired from https://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit/47990#47990
    output ^= (-bits[y] ^ output) & (1UL << j--); //sets bit [y] in output to equal bits[y] which  was generated earlier
    }
    printf("%X\n", output );   
}

void binaryConvert(int conv, int *number, int length)
{
    int rest; //remainder storage
    int i = 0; //loop index
    while (conv > 0) // binary conversion inspired from https://www.geeksforgeeks.org/program-decimal-binary-conversion/
    {
        rest = conv % 2;
        if (rest == 1)
        {
            number[i] = 1;
        }
        else
        {
            number[i] = 0;
        }
        conv /= 2;
        i++;
    }
    reverseArray(number, length); //convert is done in reverse order and needs to be reversed before continuing 
}
void reverseArray(int *number, int length) //reverses array
{
    int y = length - 1; //upper index of array
    int temp; //temporary storage during swapping
    int half; //middle of array where last swap happens
    half = (length / 2);
    if ((length % 2) == 0) half -= 1;//checks if length is an even number if it is we need to adjust half so the reversal works correctly
        
    for (int x = 0; x <= half; x++) //reversal of array with 2 pointers(x & y).
    {
        if(x == y){ break;} //exits when reversal is complete ie all swaps are done
        else{
        temp = number[x];
        number[x] = number[y];
        number[y] = temp;
        y--;
        }
    }
}

/*
-----------------------------
ARGUMENT CHECKING FUNCTIONS BELOW
-----------------------------
*/

int argCheck(int *convert) //checks so there is only allowed numbers in the arguments.
{
    if (convert[0] > 1 || convert[0] < 0)
    {
        return 1; //arguments contains invalid numbers
    }
    else if (convert[1] > 7 || convert[1] < 0)
    {
        return 1; //arguments contains invalid numbers
    }
    else if (convert[2] > 3 || convert[2] < 0)
    {
        return 1; //arguments contains invalid numbers
    }
    else if (convert[3] > 1 || convert[3] < 0)
    {
        return 1; //arguments contains invalid numbers
    }
    else if (convert[4] > 1 || convert[4] < 0)
    {
        return 1; //arguments contains invalid numbers
    }
    return 0; //arguments only contains valid numbers
}
int validNumber(char *string){ 
while (*string) {
        if (isdigit(*string++) == 0) return 1; //string contains not only numbers
    }
    return 0; //string contains only numbers
}