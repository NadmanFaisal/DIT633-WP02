#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char *argv[]) {
    printMenu();
    printf("\n");

    PERSON ppost = {"nadman", "faisal", "20040920461c"};

    write_new_file(&ppost);
    return (0);
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

