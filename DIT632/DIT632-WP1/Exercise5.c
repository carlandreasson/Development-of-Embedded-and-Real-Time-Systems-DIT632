// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 1
// Exercise 5
// Submission code: FR22KL1 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
 
#define MAX 10 // Defines the maximum number of the values in the table 
#define MAXNUMBER 15 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab);   
 
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq );  
 
// ------ Function definitions   ---------- 
 
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
// 
int main (void){ 
 
    int table[MAX], n ;  // array for generated random numbers
    int frequency[MAXNUMBER] = { 0 }; // array for frequency of generated numbers
    create_random(table); // fills array with generated numbers
    count_frequency(table, frequency); // counts occurences of numbers in array
    draw_histogram(frequency); //draws histogram with the newly counted occurences
}
void create_random(int *tab){
    int i; //loop index
    srand(time(NULL));
    for(i = 0; i < MAX; i++){ //generate  one random number with each entry generates until MAX is reached.
    tab[i] = (rand() % MAXNUMBER);
}
} 
void count_frequency(int *tab, int *freq ){
int z; //loop index
for(z = 0; z < MAX; z++){ // goes through the randomised array and counts occurences
    freq[tab[z]] = freq[tab[z]] += 1;
}
}   
void draw_histogram(int *freq ){
    int y; //loop 1 index
    int x; //loop 2 index
for(y = 0; y < MAXNUMBER; y++){ //loop through occurence table
    if(freq[y] > 0){ //if there is an occurence print x's corresponding to the amount of occurences.
        printf("\n%d", y);
        printf("    ");
        for(x=0; x<freq[y]; x++){
            printf("x");
        }  
    }
}
}
