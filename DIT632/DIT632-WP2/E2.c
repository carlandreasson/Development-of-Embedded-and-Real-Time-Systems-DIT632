// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 2
// Exercise 2
// Submission code: 3Za#53

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5   
 
// ##### typedefs          #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; //counter for printing
 
    REGTYPE *act_post , *head=NULL; 
 
    srand(time(0));  //   Random seed  
    head=random_list(); //creates a random list with the length given in MAX
    act_post=head; 
    while( act_post!=NULL){ //loops through listed from top to bottom printing each element
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }   
    nr=0;
    act_post=add_first(head, 101);  // Adds a new post of a value of 101 to the top pf the linkedlist.
    printf("\nAfter adding first\n");
     while( act_post!=NULL){  //loops through listed from top to bottom printing each element
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }   
       
 
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   
                    
 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void ){ 
    int nr, i=0; //generated number storage and index for loop
    REGTYPE *top, *old, *item;
    item = (REGTYPE*)malloc(sizeof(REGTYPE)); //creates a current item before starting since we have none.
    old = NULL; //sets old to null since we dont have an old
    for(i = 0;  i < MAX; i++){
        top = (REGTYPE*)malloc(sizeof(REGTYPE)); //creates next element
        int nr = (rand() % 100); //randomizes number
        item->number = nr; //sets number to randomized number
        item->prev = top; //sets previous to top as we add to the top of the list
        item->next = old; //sets next to old as we add to the top of the list
        old = item; //sets old to the current item for next iteration
        item = top; //replaces item with top to leave space for new in next loop iteration
    }
    old->prev=NULL; //sets previous to null as we return the top.
    return(old);
} 
 
//==========================================================                 
REGTYPE* add_first(REGTYPE* temp, int data){ 
    
    REGTYPE* item;
    while (temp->prev != NULL) // Finds the first element of the linked list.
    {
    temp = temp->prev; // sets temp to prev in order to find the top element.
    }

    item = (REGTYPE*)malloc(sizeof(REGTYPE));   // allocates momory for a new first elment.
    item->prev = NULL; //sets previous to NULL as this is the top element
    item->number = data; //sets number to data(argument)
    item->next = temp; //sets next to the previous top element
    temp->prev = item; //sets prev of the last top element to the new top element
    return (item); //returns top element in the linked list
} 