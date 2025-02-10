#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;

/*
This method takes the pointer to the destination, the value to be shifted, 
the shifting value, and the numberOfBits to extract. The method starts off 
by declaring a decimalCopy which is equal to the valueToShift. It is then 
used to shift its value by the shifting value to bring the relevant bits 
to the absolute end. 

Then, the last bits are extracted, and masked to the destination, while 
shifting the destination to the left to keep accomodating for more of the
required btis
*/
void unpackBits(int *destination, int *valueToShift, int shiftingValue, int numberOfBits) {
    *valueToShift = *valueToShift >> shiftingValue;         // Value shifted to the right by the shifting value specified
    int decimalCopy = *valueToShift;                        // copy of the valueToShift made to back track at the end    

    for(int i = numberOfBits; i > 0; i--) {                 // Looped through as many times as specified to extract bits
        decimalCopy = decimalCopy >> (i - 1);               // The first relevant bit shifted to the absolute end
        int extractedBit = decimalCopy & 1;                 // The bit is then extracted
        *destination = *destination | extractedBit;         // The destination is then masked by the extracted bit
        if(i != 1) {                                        // destination bits keep shifting untill the last bit is extracted
            *destination = *destination << 1;               // destination bits keep shifting to accomodate for new bits
            decimalCopy = *valueToShift;                    // decimalCopy reinitialized to valueToShift.
        }
    }

    printf("NUMBER: %d\n", *destination);                   // The number printed to ensure expected results
}

int main(int argc, char *argv[]) {

    // If arguements less than 2 or more than 2 are provided, it indicates invalid arguements
    if(argc < 2 || argc > 2) {
        printf("Invalid arguements.\n");        // Respective prompt is printed.
        return 0;                               // Program exits.
    }
    

    char *firstChar = argv[1];                                      // The second arguement is stored in a pointer to a char, indicating a string.
    int decimalNumber = (int)strtol(firstChar, NULL, 16);           // The hexadecimal string is converted to integer.
    int decimalCopy = decimalNumber;                                // Copy of the decimalNumber variable declared, for bitshifting operations.

    int engineDecimal = 0;              // The variable which will store the int value for engine_on
    int gearDecimal = 0;                // The variable which will store the int value for gear_pos
    int keyDecimal = 0;                 // The variable which will store the int value for key_pos
    int brake1Decimal = 0;              // The variable which will store the int value for brake1
    int brake2Decimal = 0;              // The variable which will store the int value for brake2

    printf("%d\n", decimalNumber);      // The decimal number is printed to ensure expected conversion

    // Extract engine_on
    engineDecimal = decimalCopy >> 7;                   // The bits for engine is extracted. Since it is the left most bit, the bits are shifted
                                                        // all the way to the right by 7

    printf("Engine: %d\n", engineDecimal);              // The decimal number of engine_pos printed to ensure expected conversion

    // Extract gears_pos
    decimalCopy = decimalNumber;                        // The decimalCopy is reinitialized to decimalNumber for further bitshifting operations
    unpackBits(&gearDecimal, &decimalCopy, 4, 3);

    // Extract key_pos
    decimalCopy = decimalNumber;                        // DecimalCopy reinitialized to decimalNumber
    unpackBits(&keyDecimal, &decimalCopy, 2, 2);         // Method called to shift bits and mask keyDecimal to shifted bits

    // Extract brake1
    decimalCopy = decimalNumber;                        // DecimalCopy reinitialized to decimalNumber
    unpackBits(&brake1Decimal, &decimalCopy, 1, 1);      // Method called to shift bits and mask brake1Decimal to shifted bits

    // Extract brake2
    decimalCopy = decimalNumber;                        // DecimalCopy reinitialized to decimalNumber
    unpackBits(&brake2Decimal, &decimalCopy, 1, 1);      // Method called to shift bits and mask brake2Decimal to shifted bits

    printf("Name                   Value\n");
    printf("===================================================\n");
    printf("engine_on              ");
    printf("%d\n", engineDecimal);                      // The unpacked engine_on value printed
    printf("gear_pos               ");
    printf("%d\n", gearDecimal);                        // The unpacked gear_pos value printed
    printf("key_pos                ");
    printf("%d\n", keyDecimal);                         // The unpacked key_pos value printed
    printf("brake1                 ");
    printf("%d\n", brake1Decimal);                      // The unpacked brake1 value printed
    printf("brake2                 ");
    printf("%d\n", brake2Decimal);                      // The unpacked brake2 value printed

}