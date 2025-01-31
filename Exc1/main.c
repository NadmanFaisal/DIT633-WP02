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

    struct ROBOT myRobot = {userX, userY, 1};

    printf("\n");
    printf("==================ROBOT-COMPLETE==================\n");
    printf("\n");

    printf("Robot starting x: %d\n", myRobot.xpos);
    printf("Robot starting y: %d\n", myRobot.ypos);

}