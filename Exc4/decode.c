#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {

    if(argc < 2 || argc > 2) {
        printf("Invalid arguements.\n");
        return 0;
    }
    
    for(int i = 0; i < 2; i ++) {
        if(!isalpha(argv[1][i])) {
            printf("Invalid arguement type.\n");
            return 0;
        }
    }

    char *firstChar = argv[1];
    int decimalNumber = (int)strtol(firstChar, NULL, 16);
    int decimalCopy = decimalNumber;

    int engineDecimal = 0;
    int gearDecimal = 0;
    int keyDecimal = 0;
    int brake1Decimal = 0;
    int brake2decimal = 0;

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

    printf("%d\n", gearDecimal);
}