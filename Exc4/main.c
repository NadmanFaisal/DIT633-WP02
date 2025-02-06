#include <stdio.h>
#include <ctype.h>

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

    printf("Hello world!\n");
    return 0;
}