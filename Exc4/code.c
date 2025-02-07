#include <stdio.h>
#include <stdlib.h>

/*

Improvements:-

Use shifting nigga

*/

typedef unsigned char byte;

int main(int argc, char* argv[]){
    if(argc !=  6){
        printf("%s", "Error, user has not inputted 5 arguments, please input 5 arguments in this fashion. (ex: 1 4 2 1 1)\n");
        return(0);
    }

    int number[5] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])};

    for (int i = 0; i < 5; i++) {
        if(i==1) {
            if(number[i] < 0 || number[i] > 4){
                printf("%s", "Error: Encountered faulty input value at argument 2, please input a value between 0-4 when launching the program. (ex: 1 4 2 1 1)\n");
                return(0);
            }
        } else if(i==2){
            if(number[i] < 0 || number[i] > 2){
                printf("%s", "Error: Encountered faulty input value at argument 3, please input a value between 0-2 when launching the program. (ex: 1 4 2 1 1)\n");
                return(0);
            }
        } else if (number[i] !=  0 && number[i] != 1){
            printf("%s", "Error: Encountered faulty input value on either arguments 1,4 and/or 5, please input the values between 0-1 when launching the program. (ex: 1 4 2 1 1)\n");
            return(0);
        }

    }

    byte packed_byte; 

    for(int i = 0; i < (sizeof(number)/sizeof(number[0])); i++){
        switch (i){
            case 0:
                if (number[i] == 1){
                    packed_byte = 0b10000000;
                } else {
                    packed_byte = 0b00000000;
                }
                break;
            case 1:
                switch (number[i]){
                    case 0:
                        packed_byte = packed_byte | 0b00000000;
                        break;
                    case 1:
                        packed_byte = packed_byte | 0b00010000;
                        break;
                    case 2:
                        packed_byte = packed_byte | 0b00100000;
                        break;
                    case 3:
                        packed_byte = packed_byte | 0b00110000;
                        break;
                    case 4:
                        packed_byte = packed_byte | 0b01000000;
                        break;
                }
                break;
            case 2:
                switch (number[i]) {
                    case 0:
                        packed_byte = packed_byte | 0b00000000;
                        break;
                    case 1:
                        packed_byte = packed_byte | 0b00000100;
                        break;
                    case 2:
                        packed_byte = packed_byte | 0b00001000;
                        break;                    
                }
                break;
            case 3:
                if (number[i] == 1){
                    packed_byte = packed_byte | 0b00000010;
                } else {
                    packed_byte = packed_byte | 0b00000000;
                }
                break;
            case 4:
                if (number[i] == 1){
                    packed_byte = packed_byte | 0b00000001;
                } else {
                    packed_byte = packed_byte | 0b00000000;
                }
                break;
        }
    }
    
    printf("0x%X\n", packed_byte);
    
}