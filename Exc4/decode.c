#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {

    if(argc < 2 || argc > 2) {
        printf("Invalid arguements.\n");
        return 0;
    }
    

    char *firstChar = argv[1];
    int decimalNumber = (int)strtol(firstChar, NULL, 16);
    int decimalCopy = decimalNumber;

    int engineDecimal = 0;
    int gearDecimal = 0;
    int keyDecimal = 0;
    int brake1Decimal = 0;
    int brake2Decimal = 0;

    printf("%d\n", decimalNumber);

    // Extract engine_on
    engineDecimal = decimalCopy >> 7;

    printf("Engine: %d\n", engineDecimal);

    // Extract gears_pos
    decimalCopy = decimalNumber;
    decimalCopy = decimalCopy >> 4;
    int decimalCopy2 = decimalCopy;
    
    for(int i = 3; i > 0; i--) {
        decimalCopy2 = decimalCopy2 >> (i - 1);
        int extractedBit = decimalCopy2 & 1;
        gearDecimal = gearDecimal | extractedBit;
        if(i != 1) {
            gearDecimal = gearDecimal << 1;
            decimalCopy2 = decimalCopy;
        }
    }

    printf("Gear: %d\n", gearDecimal);

    // Extract key_pos
    decimalCopy = decimalNumber;
    decimalCopy = decimalCopy >> 2;
    decimalCopy2 = decimalCopy;
    
    for(int i = 2; i > 0; i--) {
        decimalCopy2 = decimalCopy2 >> (i - 1);
        int extractedBit = decimalCopy2 & 1;
        keyDecimal = keyDecimal | extractedBit;
        if(i != 1) {
            keyDecimal = keyDecimal << 1;
            decimalCopy2 = decimalCopy;
        }
    }

    printf("Key: %d\n", keyDecimal);

    // Extract brake1
    decimalCopy = decimalNumber;
    decimalCopy = decimalCopy >> 1;
    decimalCopy2 = decimalCopy;
    
    for(int i = 1; i > 0; i--) {
        decimalCopy2 = decimalCopy2 >> (i - 1);
        int extractedBit = decimalCopy2 & 1;
        brake1Decimal = brake1Decimal | extractedBit;
        if(i != 1) {
            brake1Decimal = brake1Decimal << 1;
            decimalCopy2 = decimalCopy;
        }
    }

    printf("Brake 1: %d\n", brake1Decimal);

    // Extract brake2
    decimalCopy = decimalNumber;
    decimalCopy = decimalCopy >> 1;
    decimalCopy2 = decimalCopy;
    
    for(int i = 1; i > 0; i--) {
        decimalCopy2 = decimalCopy2 >> (i - 1);
        int extractedBit = decimalCopy2 & 1;
        brake2Decimal = brake2Decimal | extractedBit;
        if(i != 1) {
            brake2Decimal = brake2Decimal << 1;
            decimalCopy2 = decimalCopy;
        }
    }

    printf("Name                   Value\n");
    printf("===================================================\n");
    printf("engine_on              ");
    printf("%d\n", engineDecimal);
    printf("gear_pos               ");
    printf("%d\n", gearDecimal);
    printf("key_pos                ");
    printf("%d\n", keyDecimal);
    printf("brake1                 ");
    printf("%d\n", brake1Decimal);
    printf("brake2                 ");
    printf("%d\n", brake2Decimal);

}