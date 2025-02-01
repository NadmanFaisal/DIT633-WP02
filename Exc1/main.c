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

void turn (struct ROBOT *robot){
    int *px = &robot->xpos;
    printf("x-pos Data inside robot:%d\n", *px);
}

void move(struct ROBOT *robot);

void clearBuffer(void) {
    char input;
    while((input = getchar()) != '\n' && input != EOF);
}

int main(int argc, char *argv[]) {
    
    int user_x;
    int user_y;
    char movement = 'm';
    char end_char = 'x';

    printf("Type in the starting x-pos: ");
    scanf("%d", &user_x);
    clearBuffer();

    printf("Type in the starting y-pos: ");
    scanf("%d", &user_y);
    clearBuffer();
    
    enum DIRECTION direction = N;
    struct ROBOT my_robot = {user_x, user_y, direction};

    printf("\n");
    printf("=================ROBOT-CREATED=================\n");
    printf("\n");

    struct ROBOT *pMy_robot = &my_robot;

    printf("Robot x-pos: %d\n", pMy_robot->xpos);
    printf("Robot y-pos: %d\n", pMy_robot->ypos);
    printf("Robot direction: %d\n", pMy_robot->dir);
    printf("\n");

    while(movement != end_char) {
        printf("Write 'm' to move, or 't' to turn robot: ");
        scanf("%c", &movement);
        clearBuffer();

        if(movement == 't') {
            printf("Robot has been turned!\n");
            // turn(&pMy_robot);
        } else if(movement == 'm') {
            printf("Robot has been moved!\n");
            // move(&pMy_robot);
        } else if(movement == end_char) {
            printf("Program terminated!\n");
            return 0;
        } else {
            printf("Invalid input.\n");
            return 0;
        }
    }

    return 0;
}