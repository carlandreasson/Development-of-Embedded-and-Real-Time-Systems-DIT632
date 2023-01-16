// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 2
// Exercise 1
// Submission code: 3Za#53 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 #define MAX_COORDINATE 99  //defineing the maximum cordinats of the grid where the robot can start
 #define MIN_COORDINATE 0   //defineing the minimum cordinats of the grid where the robot can start

enum DIRECTION {N,E,S,W};
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 


void move(ROBOT* robot);
void turn(ROBOT* robot);

int main(){
    char command[50];
    int xcord;
    int ycord;
    int startPos;
    char startDir;
    int i;
    ROBOT *robot;

    // In the while loop it takes input from the user x and y cordinates for the starting possition of the robot
    // and checks if they are within the MAX and MIN cordinatevalue. If they are not the program tells the user it's 
    // to high or low and terminates the prgram. If the enterd input is valid it prints the startinposition of the robot.

    while (MAX_COORDINATE < xcord || MIN_COORDINATE > xcord || MAX_COORDINATE < ycord || MIN_COORDINATE > ycord )
    {
    printf("Choose X coordinate: ");
        scanf("%d", &xcord);

        if(xcord >= MAX_COORDINATE){
            printf("The X coordinate is too high");
            return 1;
        } else if (xcord <= MIN_COORDINATE) {
            printf("The X coordinate is too low");
            return 1;
        }

    printf("Choose Y coordinate: ");
        scanf("%d", &ycord); 

        if(ycord >= MAX_COORDINATE){
            printf("The Y coordinate is too high");
            return 1;
        }else if (xcord <= MIN_COORDINATE) {
            printf("The Y coordinate is too low");
            return 1;
        }else {
            printf("Robots starting position is: %d, %d", xcord, ycord);
        }
    }

    robot = (ROBOT*)malloc(sizeof(ROBOT));

        startDir = N; // defines North as starting direction for the robot

        robot->dir = startDir;
        robot->xpos = xcord;
        robot->ypos = ycord;

    // In the for loop the user can enter and input string of 'm' and 't' where 'm' makes the robot move one step in the direction
    // it's looking and 't' to turn the robot 90 degrees clockwise. It also prints out the new position of the robot and asks for 
    // a new string command or if you want to exit the program!

    while (1){

    printf("\nMove robot with 'm' for forward and 't' for turning 90 degres clockwise. \nEnter 'e' to exit. \nEnter command for the robot: ");

    scanf("%s", command);

    for (i = 0; i < strlen(command); i++) {
        if (command[i] == 'm'){
            move(robot);
        } 
        if (command[i] == 't') {
            turn(robot);
        }
        else if (command[i] == 'e'){
            return 0;
        }
    }
    printf ("robots current position:\n %d latitude,\n %d longitude.\n", robot->xpos, robot->ypos);
    }
}

void move(ROBOT* robot) {       // The move switch takes the input and either adds or subtracts from the y or x position
    switch (robot->dir) {       // depending on the direktion the robot i pointing.
        case N:
            robot->ypos++;
            break;
        case E:
            robot->xpos++;
            break;
        case S:
            robot->ypos--;
            break;
        case W:
            robot->xpos--;
            break;
    }
}
void turn(ROBOT* robot) {       // The trun switch takes the input and turns the robot to the next position depending
    switch (robot->dir) {       // on the robots curnet direction.
        case N:
            robot->dir = E;
            break;
        case E:
            robot->dir = S;
            break;
        case S:
            robot->dir = W;
            break;
        case W:
            robot->dir = N;
            break;
    }
}
