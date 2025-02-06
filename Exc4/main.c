#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc < 6 || argc > 6) {
        printf("Invalid arguements provided.\n");
        return 0;
    }
    printf("Hello world!\n");
    return 0;
}