#include <stdio.h>


/*
N -> North
O -> East
S -> South
W -> West*/
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
    enum DIRECTION new_dir;
    enum DIRECTION *pRobot_dir = &robot->dir;

    if(*pRobot_dir == 1) {
        new_dir = O;
        *pRobot_dir = new_dir;
    } else if(*pRobot_dir == 2) {
        new_dir = S;
        *pRobot_dir = new_dir;
    } else if(*pRobot_dir == 3) {
        new_dir = W;
        *pRobot_dir = new_dir;
    } else {
        new_dir = N;
        *pRobot_dir = new_dir;
    }

}

void move(struct ROBOT *robot) {
    enum DIRECTION *robot_dir = &robot->dir;
    int *robot_x = &robot->xpos;
    int *robot_y = &robot->ypos;

    if(*robot_dir == 1) {
        ++*robot_x;
    } else if(*robot_dir == 3) {
        --*robot_x;
    } else if(*robot_dir == 2) {
        ++*robot_y;
    } else {
        --*robot_y;
    }
}

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
            turn(pMy_robot);
            printf("New robot direction: %d\n", pMy_robot->dir);
        } else if(movement == 'm') {
            printf("Robot has been moved!\n");
            move(pMy_robot);
            printf("New robot x-pos: %d\n", pMy_robot->xpos);
            printf("New robot y-pos: %d\n", pMy_robot->ypos);
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