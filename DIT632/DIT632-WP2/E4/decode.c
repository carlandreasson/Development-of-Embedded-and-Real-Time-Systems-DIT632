// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 2
// Exercise 4
// Submission code: 3Za#53

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
int bit; //storage for bits
int print; //number that is printed after correct bits are assigned
int x; //index for bitconversion for engine and key
if(argc != 2){
    printf("invalid amount of arguments");
    return 1;
}
long argument = strtol(argv[1], NULL, 16);
if(argument < 0 || argument > 0xFF){
    printf("invalid value");
}

//bit 7 = eng
//bit 6 5 4 = gear
//bit 3 2 = key
//bit 1 = brake
//bit 0 = brake
printf("\nName          Value\n------------------------");
for(int n = 7; n >= 0; n--){ //loops through the bit values of the given HEX input

bit = (argument >> n) & 1U; //sets bit to the same value of the n:th bit in argument
if(n == 7){printf("\nengine_on       %d\n",bit);} //1 bit only no bit shifting needed
else if(n == 6){
    x = 2; //sets x to 2 as we expect 3 bits before we print this value
    print = 0; //sets print to 0 so we dont have left over values from previous prints
    print ^= (-bit ^ print) & (1UL << x); //sets the Xth bit in print to the value of bit
    x--;
}
else if(n == 5){ 
    print ^= (-bit ^ print) & (1UL << x); //sets the Xth bit in print to the value of bit
    x--;
    }
else if(n == 4){
    print ^= (-bit ^ print) & (1UL << x); //sets the Xth bit in print to the value of bit
    printf("gear_pos        %d \n",print); //prints the number
}
else if(n == 3){
    x = 1; //sets x to 1 as we expect 2 bits before we print this value 
    print = 0; //sets print to 0 so we dont have left over bits from previous print
    print ^= (-bit ^ print) & (1UL << x); //sets the Xth bit in print to the value of bit
    x--;
}
else if(n == 2){
    print ^= (-bit ^ print) & (1UL << x); //sets the Xth bit in print to the value of bit
    printf("key_pos         %d \n",print); //prints the value
}
else if(n == 1){printf("brake1          %d\n",bit);} //single bit no bitshifting needed
else if(n == 0){printf("brake2          %d\n",bit);} //single bit no bitshifting needed
}


    /*
        engine, pos 1
        gear, pos 2-4
        key, pos 5-6
        brake 1, pos 7
        brake 2, pos 8
    */

}