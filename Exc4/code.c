// Source: To convert decimal to hexadecimal value: https://www.geeksforgeeks.org/c-program-for-decimal-to-hexadecimal-conversion/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {
    if(argc < 6 || argc > 6) {
        printf("Invalid arguements provided.\n");
        return 0;
    }

    for(int i = 1; i < argc; i++) {
        if(!isdigit(*argv[i])) {
            printf("Invalid arguement type. Please provide valid arguements.\n");
            return 0;
        }

    }

    byte result = 0;
    byte result_copy = result;

    byte engine_on = atoi(argv[1]);
    byte gear_pos = atoi(argv[2]);
    byte key_pos = atoi(argv[3]);
    byte brake1 = atoi(argv[4]);
    byte brake2 = atoi(argv[5]);

    printf("engine_on: %d\n", engine_on);
    printf("gear_pos: %d\n", gear_pos);
    printf("key_pos: %d\n", key_pos);
    printf("brake1: %d\n", brake1);
    printf("brake2: %d\n", brake2);
    printf("\n");

    result = result | engine_on;

    result = result << 3;
    result = result | gear_pos;

    result = result << 2;
    result = result | key_pos;

    result = result << 1;
    result = result | brake1;

    result = result << 1;
    result = result | brake2;

    printf("Result: %d\n", result);
    int decimal_Number = result; 
    int i = 1, j, temp; 
    char hexa_Number[100]; 
    
    while (decimal_Number != 0) { 
        temp = decimal_Number % 16; 
        
        if (temp < 10) 
            temp = temp + 48; 
        else
            temp = temp + 55; 
        hexa_Number[i++] = temp; 
        decimal_Number = decimal_Number / 16; 
    } 
    
    printf("Hexadecimal value is: "); 
    for (j = i - 1; j > 0; j--) {
        printf("%c", hexa_Number[j]); 
    }
    printf("\n");
    return 0;
}