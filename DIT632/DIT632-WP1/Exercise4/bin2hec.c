// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 4
// Submission code: FR22KL1 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validNumber(char *string); //checks that there is only numbers in the given string

int main(int argc, char *argv[]){
   long int binary; // binary value stored here
   long int hexa = 0; // final value stored here
   long int i = 1; // used in conversion to hex
   long int rest; // storing the reminder in the conversion loop
   char *s; //string pointer needed for string to long

   if(argc > 1){ //arg check
   if(strcmp(argv[1], "-h") == 0){
      printf("To use the program write a binary number that you want to convert to hexadecimal in the console or provide it in the arguments\n");
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
        binary = strtol(argv[1], &s, 10); //convert string to long
    }
   }
   else{
      scanf("%ld", &binary);
   }

   while (binary != 0){ // code inspired by https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
      rest = binary % 10;
      hexa = hexa + rest * i;
      i = i * 2;
      binary = binary / 10;
   }
   //following if block decides how many 0s to pad with.
   if(hexa <= 0xff){ printf("%02lX", hexa); } // 8 bit
   else if(hexa <= 0xffff){ printf("%04lX", hexa); } // 16 bit
   else if(hexa <= 0xffffffff){ printf("%08lX", hexa); } //32 bit
   else{ printf("%016lx", hexa); } //64bit
   return 0;
}

int validNumber(char *string){ 
while (*string) {
        if (isdigit(*string++) == 0) return 1; //string contains not only numbers
    }
    return 0; //string contains only numbers
}
