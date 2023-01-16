// (C) Felix Mertala, Marcus Andersson, Carl Andreasson, group: 5, (2022)
// Work package 2
// Exercise 3
// Submission code: 3Za#53

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnn
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void);                  // Prints out all persons in the file
void search_by_firstname(char *name);  // Prints out the person if in list
void search_by_famname(char *name);    //function search for person by family name
void search_by_name();                 //function search for person by firstname
void append_file(PERSON *inrecord);    // appends a new person to the file

PERSON create_person(); //function to create new person in file

// ====     Start of main   ======================================

int main(void)
{
    char userInput[20]; //userinput storage for switch
    FILE *read; //file reference
    PERSON ppost = {"pet", "er", "pp"}; //person with hardcoded values
    PERSON person;
    int i = 0;

    while (1) //while loop for switch to rerun
    {
        printf("\n1 Create a new and delete the old file. \n2 Add a new person to the file. \n3 Search for a person in the file. \n4 Print out all in the file. \n5 Exit the program.\nMake your choice!");
        scanf("%s", &userInput);
            switch (userInput[0]) //switch that takes in userinput
            {
            case '1':
                write_new_file(&ppost); //option 1 to write new file and delete old
                break;
            case '2':
                person = create_person(); //option 2 create new person and adds to file
                append_file(&person);
                break;
            case '3':
                search_by_name(); //option 3 search by first or family name
                break;
            case '4':
                printfile(); //option 4 prints out all in file
                break;
            case '5':
                return 0; //option 5 breaks out of while loop and ends program
                break;
            default: //default ie when there is invalid input
                printf("Invalid choice\n");
                break;
            }
    }

    return 0;
}

// ====     End of main   ======================================

void write_new_file(PERSON *inrecord) //write new file function
{
    FILE *data = fopen("test.bin", "wb"); //opens and reads existing file
    if (data == NULL)
    {
        printf("Error reading");
    }
    fwrite(inrecord, sizeof(PERSON), 1, data); //writes
    fclose(data);                              //closes file
}

void append_file(PERSON *inrecord) //append file function
{
    FILE *data = fopen("test.bin", "ab"); //opens and reads existing file
    if (data == NULL)
    {
        printf("Error reading");
    }
    fwrite(inrecord, sizeof(PERSON), 1, data);
    fclose(data); //closes file
}

PERSON create_person() //create person function
{
    char firstname[20];   //variable declaration set to 20 characters
    char famname[20];     //variable declaration set to 20 characters
    char pers_number[13]; //variable declaration set to 13 characters
    PERSON person;        //variable declaration

    printf("Enter firstname:\n"); //enter firstname
    scanf("%s", firstname);       //userinput

    printf("\nEnter family name:\n"); //enter family name
    scanf("%s", famname);             //userinput

    printf("\nEnter personal number:\n"); //enter personal number
    scanf("%s", pers_number);             //userinput

    strncpy(person.firstname, firstname, 20);     //stringcopy on userinput
    strncpy(person.famname, famname, 20);         //stringcopy on userinput
    strncpy(person.pers_number, pers_number, 13); //stringcopy on userinput

    return person; //returns person
}

void printfile(void) //print file function
{
    PERSON pread;
    FILE *read;
    int i = 0;
    read = fopen("test.bin", "rb"); //opens file
    if (read == NULL)
    {
        printf("Error reading");
    }
    while (i == 0)
    {
        fread(&pread, sizeof(PERSON), 1, read); //reads one person from file
        if (!feof(read))                        //checks if there is more to read in the file.
        {
            printf("pnmbr = %s name = %s %s\n", pread.pers_number, pread.firstname, pread.famname);
        }
        else
        {
            i = 1; //exits loop when end of file is reached.
        }
    }
    fclose(read); //closes file
}

PERSON input_record(void) //reads and returns a person from file
{
    FILE *read = fopen("test.bin", "rb"); //opens file
    PERSON pread;
    fread(&pread, sizeof(PERSON), 1, read); //reads file
    return pread; //return person in file
}

void search_by_name() //search by name selection function
{
    char name[20];      //variable declaration set to 20
    char selection[20]; //variable declaration set to 20

    printf("\n Do you want to search by firstname(1) or family name(2)?"); //asks for preferred search option, first or family name
    scanf("%s", selection);
    if (selection[0] == '1' || selection[0] == '2') // selection depending on userinput
    {
        printf("Enter name:\n"); //ask for name and userinput
        scanf("%s", name);
        if (selection[0] == '1')
        {
            search_by_firstname(name); //if userinput equals to 1 redirects to search by firstname function
        }
        else if (selection[0] == '2')
        { //if userinput equals to 2 redirects to search by family name function
            search_by_famname(name);
        }
    }
}

void search_by_firstname(char *name) //search by firstname function
{
    PERSON pread;                   //temp PERSON for printing in loop
    FILE *read;                     //file that we use
    int i = 0;                      // loop variable
    read = fopen("test.bin", "rb"); //open file
    if (read == NULL)
    {
        printf("Error reading");
    }
    while (i == 0) //Loops until EOF
    {
        fread(&pread, sizeof(PERSON), 1, read); //reads one person from file
        if (!feof(read))                        //checks if there is more to read in the file.
        {
            if (strcmp(pread.firstname, name) == 0) //only prints when name and firstname is equal
            {
                printf("pnmbr = %s name = %s %s\n", pread.pers_number, pread.firstname, pread.famname);
            }
        }
        else
        {
            i = 1; //exits loop when end of file is reached.
        }
    }
    fclose(read); //closes file
}

void search_by_famname(char *name) //search by family name function
{
    PERSON pread;                   //temp PERSON for printing in loop
    FILE *read;                     //file that we use
    int i = 0;                      // loop variable
    read = fopen("test.bin", "rb"); //open file
    if (read == NULL)
    {
        printf("Error reading");
    }
    while (i == 0) //Loops until EOF
    {
        fread(&pread, sizeof(PERSON), 1, read); //reads one person from file
        if (!feof(read))                        //checks if there is more to read in the file.
        {
            if (strcmp(pread.famname, name) == 0) //only prints when name and famname is equal
            {
                printf("pnmbr = %s name = %s %s\n", pread.pers_number, pread.firstname, pread.famname);
            }
        }
        else
        {
            i = 1; //exits loop when end of file is reached.
        }
    }
    fclose(read); //closes file
}