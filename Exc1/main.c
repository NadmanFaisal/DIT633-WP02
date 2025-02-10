// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 2
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h> // library for I/O files
#include <string.h> // library for string functions
#include <stdlib.h> // library for exit function to exit program when encountering an end character
#include <ctype.h> // library to include isdigit function, that checks if a number is a digit

#define MAX_INPUT 100 // max is 100 char

/*

Improvements:-

Questions:-

*/

// Enum of robot direction where N = 0, O = 1, S = 2, W = 3
enum DIRECTION {N,O,S,W};

// structure of a robot with:-
typedef struct {
    int xpos; // robot's x-axis position
    int ypos; // robot's  y-axis position
    enum DIRECTION dir; // robot's direction in relation to the enum
} ROBOT; // of type robot

// clear input buffer function
void clearstdin(){ 
    char temp; // temp character
    while((temp = getchar()) != '\n' && temp != EOF){} //while we get the char from buffer and its not an EOF (CTRL+Z) or an \n (Enter button)
}

// turn function that turns robot direction 90 degrees clockwise
void turn(enum DIRECTION *p_to_robotdir){ // takes in pointer to robot direction argument to permanently change the robot's direction from main
    switch (*p_to_robotdir){ // we check the direction
        case N: // if it's North
            *p_to_robotdir = O;  // we change it to East 
            break; // and thats it we do not want it to check all cases
        case O: // if its East
            *p_to_robotdir = S; // we change it to south
            break; // and thats it we do not want it to check all cases
        case S: // if its south
            *p_to_robotdir = W; // we change it to west
            break; // and thats it we do not want it to check all cases
        case W: // if its west
            *p_to_robotdir = N; // we change it back to north
            break; // and thats it we do not want it to check all cases
    }
}

// function to move the robot (based on a x and y coordinate diagram) or to end the program based on the string of characters provided
void move(char* chars_of_robots_movement, ROBOT *p_to_user_robot){ // takes in pointer to the robot as argument to permanently change the robot's x and y position in main, as well as pass the pointer to robot direction to the turn function

    for (int i = 0; i < strlen(chars_of_robots_movement); i++) { // for each character in the length of string
        if(chars_of_robots_movement[i] != 'e' && chars_of_robots_movement[i] != 'm' && chars_of_robots_movement[i] != 't') { // if it doesnt equal to either e, m or t
            printf("Invalid characters inputted! Please make sure your string of characters include characters between 'm' (move the robot) or 't' (turn the robot)\n"); // print error message
            exit(0); // end program
        } else if(chars_of_robots_movement[i] == 'e'){ // if it contains an e
            printf("Encountered an end of program character. Ending program...\n"); // print end message
            exit(0); // end program
        } else if(chars_of_robots_movement[i] == 't') { // if the char is t
            turn(&(p_to_user_robot -> dir)); // enter turn function passing in the address of the robot's direction
        } else if (chars_of_robots_movement[i] == 'm'){ // if the char is m
            switch (p_to_user_robot -> dir){ //we check the direction
                case N: // if the robot direction is facing North
                    p_to_user_robot -> ypos++; // increase y-axis position
                    p_to_user_robot -> ypos % 100; // wrap around in case we go to 101
                    break; // and thats it we do not want it to check all cases
                case O: // if the robot direction is facing East
                    p_to_user_robot -> xpos++; // increase x-axis position
                    p_to_user_robot -> xpos % 100; // wrap around in case we go to 101
                    break; // and thats it we do not want it to check all cases
                case S: // if the robot direction is facing South
                    p_to_user_robot -> ypos--; // decrease y-axis position
                    p_to_user_robot -> ypos % 100; // wrap around in case we go to -1
                    break; // and thats it we do not want it to check all cases
                case W: // if the robot direction is facing West
                    p_to_user_robot -> xpos--; // decrease x-axis position
                    p_to_user_robot -> xpos % 100; // wrap around in case we go to -1
                    break; // and thats it we do not want it to check all cases
            }
        }
    }

}

// main function
int main(int argc, char* argv[]){

    ROBOT user_robot; // we create the robot for the user
    user_robot.dir = N; // we assign his direction to always face north at the start of the program
    char* robots_movement = malloc(MAX_INPUT*sizeof(char)); // we create list of characters to store list of characters for robot's movement
    char robot_pos[MAX_INPUT]; // robot position in char to check for 'e'
    int validNum; // valid num to check if num valid (1) or not valid (0)

    while(argc) { // while true, we keep looping so that the program continues to run until we encounter the end character 'e'
        printf("Welcome to the robot moving game!\nTo move the robot you move by typing m or turn by typing t\nIf you ever want to end the game you type e\nYou wil now be prompted to type the robot's starting position.\n\n"); // print intro message
        do { // do the below while the user does not input the X above 99 or below 0 sinnce the X cannot be be above 99 or below 0
            printf("Please input robot's starting position in X-axis (0-99): "); //print message template to input X-axis
            fgets(robot_pos, MAX_INPUT, stdin); // get X-pos in char since we need to figure out if there is the 'e' character there
            robot_pos[strlen(robot_pos) - 1] = '\0'; // add the end line character 
            validNum = 1; // so long its valid until
            for(int i = 0; i < strlen(robot_pos); i++){ // check each character
                if(!isdigit(robot_pos[i])){ // if its not a digit
                    if(robot_pos[i] == 'e'){ // check if its an 'e' if it is
                        printf("Encountered an end of program character. Ending program...\n"); // print end message
                        exit(0); // exit program
                    }
                    validNum = 0; // since it is not a digit, user must retype so it is not a valid num
                }
            }

            if(!validNum){ // if it is not a valid num
                printf("Error character inputted: Please input a valid number between 0-99.\n"); // print error message
                continue; //do another loop in this loop
            }

            user_robot.xpos = atoi(robot_pos); //update x-pos
            if(user_robot.xpos < 0 || user_robot.xpos > 99){ // if its not in range of 0-99
                printf("Invalid range of numbers. Please input the number between 0-99.\n"); // print not in range error message
                validNum = 0; // not valid num
            }
        } while (!validNum);  // while the user is not inputting a valid num


        do { // do the below while the user does not input the Y above 99 or below 0 sinnce the Y cannot be be above 99 or below 0
            printf("Please input robot's starting position in Y-axis (0-99): "); //print message template to input Y-axis
            fgets(robot_pos, MAX_INPUT, stdin); // get Y-pos in char since we need to figure out if there is the 'e' character there
            robot_pos[strlen(robot_pos) - 1] = '\0'; // add the end line character 
            validNum = 1; // so long its valid until
            for(int i = 0; i < strlen(robot_pos); i++){ // check each character
                if(!isdigit(robot_pos[i])){ // if its not a digit
                    if(robot_pos[i] == 'e'){ // check if its an 'e' if it is
                        printf("Encountered an end of program character. Ending program...\n"); // print end message
                        exit(0); // exit program
                    }
                    validNum = 0; // since it is not a digit, user must retype so it is not a valid num
                }
            }

            if(!validNum){ // if it is not a valid num
                printf("Error character inputted: Please input a valid number between 0-99.\n"); // print error message
                continue; //do another loop in this loop
            }

            user_robot.ypos = atoi(robot_pos); //update y-pos
            if(user_robot.ypos < 0 || user_robot.ypos > 99){ // if its not in range of 0-99
                printf("Invalid range of numbers. Please input the number between 0-99.\n"); // print not in range error message
                validNum = 0; // not valid num
            }
        } while (!validNum);  // while the user is not inputting a valid num

        printf("Please input robot's movement: "); // print message template to input list of robot movement character
        fgets(robots_movement, MAX_INPUT, stdin); // read robot movement where MAX_INPUT here is the max number for 100 char
        robots_movement[strlen(robots_movement) - 1] = '\0'; // put null terminator after last char
        printf("\n"); // print next line

        move(robots_movement, &user_robot); // call move function where it takes in the robot's movement and the address of user_robot

        printf("Robot's new position at X-axis: %d\nRobot's new position at Y-axis: %d\n\n", user_robot.xpos, user_robot.ypos); // print out robot's new position at X pos and Y pos

    }

    free(robots_movement); // free memory for robot_movement string

}