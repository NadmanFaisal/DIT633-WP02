#include <stdio.h>

enum DIRECTION {
    N = 1,
    O = 2,
    S = 3,
    W = 4
};

typedef struct ROBOT {
    int xpos;
    int ypos;
    enum DIRECTION dir;
};

void turn (char *turn);

void move(char *move);

void clearBuffer(void) {
    char input;
    while((input = getchar()) != '\n' && input != EOF);
}

int main(int argc, char *argv[]) {
    
    int userX;
    int userY;

    printf("Provide starting x-coordinate: ");
    scanf("%d", &userX);
    clearBuffer();

    printf("Provide starting y-coordinate: ");
    scanf("%d", &userY);
    clearBuffer();

    enum DIRECTION direction = N;
    struct ROBOT myRobot = {userX, userY, direction};

    printf("\n");
    printf("==================ROBOT-COMPLETE==================\n");
    printf("\n");

    printf("Robot starting x: %d\n", myRobot.xpos);
    printf("Robot starting y: %d\n", myRobot.ypos);
    printf("Robot directionx: %d\n", myRobot.dir);

    printf("==================MANIPULATING-ROBOT-DATA==================\n");

    int *pXpos = &myRobot.xpos;
    int *pYpos = &myRobot.ypos;

    *pXpos = 14;
    *pYpos = 15;

    printf("Robot x-pos address: %p\n", pXpos);
    printf("Robot y-pos address: %p\n", pYpos);

    printf("Robot x-pos new value: %d\n", *pXpos);
    printf("Robot y-pos new value: %d\n", *pYpos);

}