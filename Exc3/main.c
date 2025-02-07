

// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 2
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

Improvements:-

More error checking

Questions:-


*/

// -----constants------

#define MAX 10
#define MAX_INPUT_FOR_NAME 20
#define MAX_INPUT_FOR_PERS 13
#define PATH "database.dat"

#define BINARY_READ "rb"
#define BINARY_WRITE "wb"
#define BINARY_APPEND "ab"


// -----typedefs -------

typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)

PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord); // Creates a file and writes the first record

void printfile(void); // Prints out all persons in the file

void search_by_firstname(char *name); // Prints out the person if in list

void append_file(PERSON *inrecord); // appends a new person to the file

void clearstdin(void); // clear input buffer

// Function initalizations

// clear input buffer
void clearstdin(){
    char temp; // temp variable
    while((temp = getchar()) != '\n' && temp != EOF){} // as long as it isnt the \n or the EOF keep emptying the buffer
}

void write_new_file(PERSON *p_to_person){
    FILE *fileptr;

    if((fileptr = fopen(PATH, BINARY_WRITE)) == NULL){
        printf("%s", "Error: Can not create the file. Please try again.\n");
        exit(1);
    }
    
    fclose(fileptr);

}


void append_file(PERSON *p_to_new_person){
    FILE *fileptr;
    char newfname[MAX_INPUT_FOR_NAME];
    char newlname[MAX_INPUT_FOR_NAME];
    char newpersnum[MAX_INPUT_FOR_PERS];

    if((fileptr = fopen(PATH, BINARY_READ)) != NULL){
        if((fileptr = fopen(PATH, BINARY_APPEND)) == NULL){
        printf("%s", "Error: Can not find the file. Make sure to create the file first\n");
        exit(1);
        }
    } else {
        printf("%s", "Error: Can not find the file. Make sure to create the file first\n");
        exit(1);
    }

    // max no of strings to write
    printf("%s", "Type new user's first name: ");
    fgets(newfname, MAX_INPUT_FOR_NAME, stdin);
    if(strlen(newfname) < 20){
        newfname[strlen(newfname) - 1] = '\0';
    }
    strcpy(p_to_new_person -> firstname, newfname);

    printf("%s", "Type new user's last name: ");
    fgets(newlname, MAX_INPUT_FOR_NAME, stdin);
    if(strlen(newlname) < 20){
        newlname[strlen(newlname) - 1] = '\0';
    }
    strcpy(p_to_new_person -> famname, newlname);

    do {
        printf("%s", "Type new user's personal number (yyyymmddnnnc): ");
        fgets(newpersnum, MAX_INPUT_FOR_PERS, stdin);
        if(newpersnum[strlen(newpersnum) - 1] == '\n'){
            newpersnum[strlen(newpersnum) - 1] = '\0';
        }
        printf("\n");
        if(strlen(newpersnum) < 12){
            printf("Wrong format for personal number, please type in this format -> yyyymmddnnnc\n");
        }
    } while (strlen(newpersnum) != 12);

    strcpy(p_to_new_person -> pers_number, newpersnum);

    if(fwrite(p_to_new_person, sizeof(PERSON), 1, fileptr) == 1){
        printf("Added new user successfully!\n\n");
    } else {
        printf("Error occurred when adding user to database, please try again.\n\n");
        exit(1);
    }

    fclose(fileptr);
    
}

void printfile(){
    FILE *fileptr;
    PERSON p_to_person_in_bin;
    int n = 0;

    if((fileptr = fopen(PATH, BINARY_READ)) == NULL){
        printf("%s", "Error: Can not find the file. Make sure to create the file first\n");
        exit(1);
    }

    int c = fgetc(fileptr);
    if(c == EOF){
        printf("The file has no students in it, please add new person to the file\n");
        exit(1);
    } else {
        ungetc(c, fileptr);
    }

    while(!feof(fileptr)){
        if(fread(&p_to_person_in_bin, sizeof(PERSON), 1, fileptr)){
            printf("Student %d\n", n + 1);
            printf("First Name: %s\n", p_to_person_in_bin.firstname);
            printf("Family Name: %s\n", p_to_person_in_bin.famname);
            printf("Personal Number: ");
            for (int i = 0; i < strlen(p_to_person_in_bin.pers_number); i++){
                printf("%c", p_to_person_in_bin.pers_number[i]);
            }
            printf("\n\n");
            n++;
        }
    }

    fclose(fileptr);
}

void search_by_firstname(char *name_of_person){
    FILE *fileptr;
    PERSON p_to_person_in_bin;
    int n = 1;
    int foundUser = 0;

    if((fileptr = fopen(PATH, BINARY_READ)) == NULL){
        printf("%s", "Error: Can not find the file. Make sure to create the file first\n");
        exit(1);
    }

    int c = fgetc(fileptr);
    if(c == EOF){
        printf("The file has no students in it, please add new person to the file\n");
        exit(1);
    } else {
        ungetc(c, fileptr);
    }
    
    while(!feof(fileptr)){
        if(fread(&p_to_person_in_bin, sizeof(PERSON), 1, fileptr)){
            if(strcmp(name_of_person, p_to_person_in_bin.famname) == 0 || strcmp(name_of_person, p_to_person_in_bin.firstname) == 0) {
                printf("Student %d\n", n);
                printf("First Name: %s\n", p_to_person_in_bin.firstname);
                printf("Family Name: %s\n", p_to_person_in_bin.famname);
                printf("Personal Number: ");
                for (int i = 0; i < strlen(p_to_person_in_bin.pers_number); i++){
                    printf("%c", p_to_person_in_bin.pers_number[i]);
                }
                printf("\n\n");
                n++;
                foundUser++;
            }
        }
    }

    if(foundUser == 0){
        printf("No users with that associated name exists in the file.\n\n");
    }

    fclose(fileptr);

}

// main program

int main(void){
    PERSON ppost; // person struct to perform actions with during the main program
    PERSON pnewpost; // new person struct to add in the menu
    int user_input; // user's input for the menu
    char name[MAX_INPUT_FOR_NAME];

    do {

        // choice of menu for the user
        printf("%s", "1. Create a new and delete the old file.\n"); // print menu text template no.1  create new file and delete old contents in the file.
        printf("%s", "2. Add a new person to the file.\n"); // print menu text template no.2 add new person to the file
        printf("%s", "3. Search for a person in the file.\n"); // print menu text template no.3 search for person in the file
        printf("%s", "4. Print out all in the file.\n"); // print menu text template no.4 print out all persons in the file
        printf("%s", "5. Exit the program.\n\n"); // print menu text template no.5 Exit the program

        printf("%s", "Please type your choice from the menu: ");
        scanf("%d", &user_input); // read user input
        clearstdin();
        printf("\n");

        switch (user_input) {
            case 1:
                write_new_file(&ppost);
                break;
            case 2:
                append_file(&pnewpost);
                break;
            case 3:
                printf("%s", "Type user's first or last name: ");
                fgets(name, MAX_INPUT_FOR_NAME, stdin);
                if(strlen(name) < 20){
                    name[strlen(name) - 1] = '\0';
                }
                printf("\n");
                search_by_firstname(name);
                break;
            case 4:
                printfile();
                break;
            case 5:
                break;
            default:
                printf("Inputted out of range of 1-5, please input between 1-5\n");
        }

    } while (user_input != 5); // as long as user doesn't choose 5, which is exiting the program

    return(0); // end main program
}