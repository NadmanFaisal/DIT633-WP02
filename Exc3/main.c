#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// -----typedefs -------
typedef struct {
char firstname[20]; //firstaname
char famname[20]; //familyname
char pers_number[13]; // yyyymmddnnnc
} PERSON;

// this method clears buffer after user input
void clearBuffer (void) {
    char input;
    while ( (input = getchar()) != '\n' && input != EOF );
}

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void printfile(void); // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if in list
void append_file(PERSON *inrecord); // appends a new person to the file
//print menu function
void printMenu();

//############# main function #################

int main(void){

int menuNUm; //variable declaration to store the menu number
PERSON ppost; ////the variable holds the data type of person
bool progRunning = true; //boolean to control the program exit

/*The while loop executes till the user enter 5 to exit, it triggers the boolean
value to false and the program ends. Inside the while loop, the printMenu() prints
out the menu list for the user. It takes the user input which ranges from 1-5.
According to the user input the 'If Condition' is executed, the if condition calls
the function according to user prefernce and it executes till the user wants to exit.*/
while (progRunning) {

    printMenu(); // method to print the menu

    int userInput = scanf("%d", &menuNUm); // read the number input
    clearBuffer(); // clear buffer

    if (userInput != 1 || menuNUm < 1 || menuNUm > 5) { //checks if the input is a valid number
        printf("Invalid input! Please enter a number between 1 and 5.\n");
        continue; // continue to the program
    }

    if (menuNUm == 1) { //if the user types 1, new binanry file create method is called
        write_new_file(&ppost);
    } else if (menuNUm == 2) { //if the user types 2, the program executes the append_file() function
        append_file(&ppost);
    } else if (menuNUm == 3) { //if the user types 3, search by name function is called
        search_by_firstname(ppost.firstname);
    } else if (menuNUm == 4) { //if the inoput is 4, printfile() method is executed.
        printfile();
    } else if (menuNUm == 5) //finally input 5 to exit the program
    {   
        printf("Exiting the program........");
        progRunning = false; //boolean turns false once user input is 5 and exits the program
        return 0; //return on succeeful execution
    }
    
}

return(0); //return on succeeful execution
}

//##################################

/*This method acts as menu list, it prints out the available option
for the user. This method helps to keep the code more readble by havig this heavily
texual content on a separte funtion*/
void printMenu(){
    printf("*************************************************\n");
    printf("1 Create a new and delete the old file.\n"
           "2 Add a new person to the file.\n"
           "3 Search for a person in the file.\n"
           "4 Print out all in the file.\n"
           "5 Exit the program.\n");
    printf("*************************************************\n");
    printf("Enter option: ");
}

/*This method is a type of person, it takes values from the user input
It ask the user to enter 3 types of values and stores them in their type variable*/
PERSON input_record(void){
    PERSON person; //the variable holds the data type of person

    printf("Enter the first name of the person: "); //prompt the user to enter the frist name
    scanf("%s", person.firstname); //stores the first name provided by the user
    clearBuffer(); //clear buffer

    printf("Enter the family name of the person: "); //prompt the user to enter the last name
    scanf("%s", person.famname); //stores the last name provided by the user
    clearBuffer(); //clear buffer

    printf("Enter the personal number of the person: "); //prompt the user to enter the personal number
    scanf("%s", person.pers_number); //stores the personal number provided by the user
    clearBuffer();//clear buffer

    return person; //return the person struct
}

/*This method creates a binary file and writes a dummy record initially. We create the file
using 'wb' so if a new file is created it overrides the previous one, hence the old one is
removed. Function initialises inrecord with the dummy record and we clode the file.*/
void write_new_file(PERSON *inrecord){ 
    
    //we use strcpy aswe can not directly initialise values to char array
    strcpy(inrecord->firstname, "DummyFirstName"); //initializing firstname
    strcpy(inrecord->famname, "DummyFamilyName"); //initializing famname
    strcpy(inrecord->pers_number, "199901019999"); //initializing pars_name

    FILE *file = fopen("personRecord.bin","wb"); //creating a binanary file

    if (file == NULL){ //if we are unable to create the binary file a error is printed
        printf("Error, the file could not be opened");
        return;
    } else {
        fwrite(inrecord, sizeof(PERSON), 1, file); //if the file is created, we insert the person value in the file.
    }

    fclose(file); //closing the file

}

/*We open the existing file to appeand, first we ask the user to enter the needed input values.
The input values are stored in Person struct. The record is appended in the file through
fwrite() method, then we cose the scanner*/
void append_file(PERSON *inrecord){

    FILE *file; // declaring the file

    if ((file = fopen("personRecord.bin","rb")) == NULL) { // checking if the file exists
        printf("Error! File not found.\n"); //print if file not found
        return; // returns to the program
    }
    
    file = fopen("personRecord.bin","ab"); //open the existing binanry file in appeand mode
    printf("*************************************************\n");
    *inrecord = input_record(); //initializing the increcord with user input

    fwrite(inrecord, sizeof(PERSON), 1, file); //adding the input values in the binanry file

    fclose(file); //close the file

}


/*Open the binanary file in read mode, then we take the first name as input from the user.
Then we compare is the user input first name is in the record, if it matches the persons details
is printed out. If no match found we prompt the user with a message and close the file*/
void search_by_firstname(char *name){

    PERSON person; //the variable holds the data type of person
    int personFound = 0; //initializing the variable to see if we found a match
    int personCount = 1; //initiazling the variable to keep count while printing
    FILE *file;

    if ((file = fopen("personRecord.bin","rb")) == NULL) { // checking if the file exists
        printf("Error! File not found.\n"); //print if file not found
        return; // returns to the program
    }

    file = fopen("personRecord.bin","rb"); //oen the file in read mode
    printf("*************************************************\n");
    printf("Enter the first name of the person you want to search : "); //prompt the user to first name
    scanf("%s", name); //stores the user input
    clearBuffer(); //clear buffer

    /*The loop keeps reading the record till the end of file, &person is the address where data will be stored,
    the we set how many byte to read in the Person struct, 1 is the number of record per call and lastly the file
    pointer to read from. On a successful read the fread() retruns a 1 and when counters an error it returns 0.*/
    while (fread(&person, sizeof(PERSON), 1, file) == 1) {
        if (strcmp(person.firstname, name) == 0) { //checking if the first name of the current read person is same sa the user input
            printf("=================================================\n");
            printf("Person%d found: \n", personCount); //prints the count
            printf("Person first name: %s\n", person.firstname); //prints the first name
            printf("Person family name: %s\n", person.famname); //prints the family name
            printf("Person personal number: %s\n", person.pers_number); //prints the personal number
            printf("=================================================\n");
            personFound++; //incriment the number of people found till the end
            personCount++; //incriment the count of the people when printing
        }
    }
    if (personFound == 0) { //if no person has been found we prompt the user to try again.
            printf("No person found with the name, try again!\n");
        }

    fclose(file); //close the file
    
}

/*With this function we get the person data type and intirate through the file
with a while loop to file all the person record and print them one by one*/
void printfile(void){

    PERSON person;  //the variable holds the data type of person

    FILE *file = fopen("personRecord.bin","rb"); //open the file
    int personCount = 1; //initiazling the variable to keep count while printing

    if (file == NULL) { // checking if the file exists
        printf("Error! File not found.\n"); //print if file not found
        return; // returns to the program
    }

    /*The loop keeps reading the record till the end of file, &person is the address where data will be stored,
    the we set how many byte to read in the Person struct, 1 is the number of record per call and lastly the file
    pointer to read from. On a successful read the fread() retruns a 1 and when counters an error it returns 0.
    And keeps printing all record found in the file in a count order*/
    while (fread(&person, sizeof(PERSON), 1, file) == 1) {
        printf("=================================================\n");
        printf("Person No.%d: \n", personCount);
        printf("Person first name: %s\n", person.firstname);
        printf("Person family name: %s\n", person.famname);
        printf("Person personal number: %s\n", person.pers_number);
        printf("=================================================\n");
        personCount++;
    }
    fclose(file);
}

