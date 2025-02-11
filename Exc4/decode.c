#include <stdio.h> // stdio library for printf
#include <stdlib.h> // stdlib for use of strtol
#include <string.h> // string library for strlen

typedef unsigned char byte; // define byte type

// main program
int main(int argc, char* argv[]){ 
    
    // if arguments are less than 2
    if(argc != 2){
        // throw an error not providing hexadecimal
        printf("%s", "Error occurred: Did not provide an argument. Please provide a hexadecimal as an argument. (ex: AB)");
    }

    char* p_to_arg = argv[1]; // pointer to hexadecimal number

    // for each char in the hexadecimal number (without adding 0x)
    for (int i = 0; i < strlen(argv[1]); i++) {
        char character_in_arg = *p_to_arg; // extract character from the value of pointer
        if((character_in_arg < '0' || character_in_arg > '9') && (character_in_arg < 'A' || character_in_arg > 'F')) { // if character isnt a digit and isnt between A to F
            printf("%s","Error occurred: Did not provide a valid hexadecimal format. Please provide a hexadecimal number like stated (ex: AB)"); // print error message
            return(0); // exit program
        }
        p_to_arg++; // increase the pointer to next character
    } 

    char *hexadecimalStr = argv[1]; // assign to a string
    long val = strtol(hexadecimalStr, NULL, 16); // convert the string to base 16 number
    byte numInByte = (byte) val; // put that value as a byte
 
    byte engine_on = (numInByte >> 7) & 0x01; // shift to the first bit to the left and compare with 00000001
    byte gear_pos = (numInByte >> 4) & 0x07; // shift the second, third and fourth bith and compare with 00000111
    byte key_pos = (numInByte >> 2) & 0x03; // shift to the fifth and sixth bit and comparen with 00000011
    byte brake1 = (numInByte >> 1) & 0x01; //  shift to the seventh bit and compare wiht 000001
    byte brake2 = numInByte & 0x01; // no need to shift for the 8th bit and comapre with 000001

    // print name template
    printf("%s","Name \t\t Value\n"); // name and value template
    printf("%s","------------------------------\n"); // dashes template
    printf("engine_on\t  %d\n", engine_on); // print engine_on template
    printf("gear_pos\t  %d\n", gear_pos); // print gear_pos template
    printf("key_pos\t\t  %d\n", key_pos); // print key_pos template
    printf("brake1\t\t  %d\n", brake1); // print brake1 template
    printf("brake2\t\t  %d\n", brake2); // print brake2 template
    
}