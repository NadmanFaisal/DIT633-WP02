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

    printf("%d\n", decimalNumber);

    decimalNumber = decimalNumber >> 4;

    printf("%d\n", decimalNumber);


    printf("\n");
}