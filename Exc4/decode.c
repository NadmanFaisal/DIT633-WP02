
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int main(int argc, char* argv[]){
    
    if(argc != 2){
        printf("%s", "Error occurred: Did not provide an argument. Please provide a hexadecimal as an argument.");
    }

    char* p_to_arg = argv[1];

    for (int i = 0; i < strlen(argv[1]); i++) {
        char character_in_arg = *p_to_arg;
        if((character_in_arg < '0' || character_in_arg > '9') && (character_in_arg < 'A' || character_in_arg > 'F')) {
            printf("%s","Error occurred: Did not provide a valid hexadecimal format. Please provide a hexadecimal number like stated (ex: AB)");
            return(0);
        }
        p_to_arg++;
    }

    char *hexadecimalStr = argv[1];
    long val = strtol(hexadecimalStr, NULL, 16);
    byte numInByte = (byte) val;
 
    byte engine_on = (numInByte >> 7) & 0x01;
    byte gear_pos = (numInByte >> 4) & 0x07;
    byte key_pos = (numInByte >> 2) & 0x03;
    byte brake1 = (numInByte >> 1) & 0x01;
    byte brake2 = numInByte & 0x01;

    printf("%s","Name \t\t Value\n");
    printf("%s","------------------------------\n");
    printf("engine_on\t  %d\n", engine_on);
    printf("gear_pos\t  %d\n", gear_pos);
    printf("key_pos\t\t  %d\n", key_pos);
    printf("brake1\t\t  %d\n", brake1);
    printf("brake2\t\t  %d\n", brake2);
    
}