#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char firstname[20];
    char famnamep[20];
    char pers_number[13];   // yyyymmddnnnc
} PERSON;

PERSON input_record(void);                      // Reads a person’s record.
void write_new_file(PERSON *inrecord);          // Creates a file and
                                                // writes the first record
void printfile(void);                           // Prints out all persons in the file
void search_by_firstname(char *name);           // Prints out the person if
                                                // in list
void append_file(PERSON *inrecord);             // appends a new person to the file
void printMenu();
void clearBuffer();

int main(int argc, char *argv[]) {
    int user_input;
    int looper = true;

    PERSON ppost = {"nadman", "faisal", "20040920461c"};
    PERSON ppost2 = {"zahid", "hasan", "20001231123c"};
    PERSON ppost3 = {"Mohd", "Taha", "20040404123c"};

    while(looper) {
        printMenu();
        printf("\n");
        printf("What would you like to do?: ");
        scanf("%d", &user_input);
        clearBuffer();

        if (user_input > 5 || user_input < 1) {
            printf("Number out of bounds. Program exited\n");
            looper = false;
        } else if(user_input == 1) {
            printf("Create a new file!\n");
            write_new_file(&ppost);
        } else if(user_input == 2) {
            printf("Write to a file!\n");
            append_file(&ppost2);
        }
    }

    return (0);
}

/*
The buffer is cleared each time an input is taken from the user.
This method functions by retrieving the charactes and discarding them
until it reaches a new-line character OR it reaches the end of file.
*/

void clearBuffer(void) {
    char input;
    while((input = getchar()) != '\n' && input != EOF);
}

void printMenu() {
    printf("1 Create a new and delete the old file.\n");
    printf("2 Add a new person to the file.\n");
    printf("3 Search for a person in the file.\n");
    printf("4 Print out all in the file.\n");
    printf("5 Exit the program.");
}

void write_new_file(PERSON *inrecord) {
    FILE *file;
    file = fopen("peoplesDb.bin", "wb");
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}

void append_file(PERSON *inrecord) {
    PERSON *temp = inrecord;
    FILE* file = fopen("peoplesDb.bin", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(temp, sizeof(PERSON), 1, file);
    fclose(file);
}