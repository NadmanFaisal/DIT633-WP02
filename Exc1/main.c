#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 100

/*
Enumerated values of direction, where the constants
are given names, representing directions.
*/
enum DIRECTION {
    N = 1,      // North
    O = 2,      // East
    S = 3,      // South
    W = 4       // West
};

/*
Different variables od different data types packaged into one,
representing a ROBOT. The type name of ROBOT is ROBOT, indicating
that ROBOT is a data type.

Here, ROBOT has different types of variables packaged together in a
bundle. The relevant data for ROBOT are xpos (x-coordinate), 
ypos (y-coordinatae), and an enum dir, indicating direction.
*/
typedef struct ROBOT {
    int xpos;               // x-coordinate
    int ypos;               // y-coordinate
    enum DIRECTION dir;     // facing direction
};

/*
This method is used to turn the ROBOT by 90 degrees to it's right.
This method works by taking the pointer to the ROBOT, and changind
its direction by changing the values of the member variablse.
For this case, the only member variable that is changed is the
'dir' variable of the robot. If the robot is facing North, its
'dir' changes to 'East'. If it is facing 'East', the direction 
changes to 'South'.

This is done by taking the pointer to the robot, and then accessing
the pointer to the direction with the help of arrow operators,
and changing the value. This works by accessing the memory address
of the dir through the arrow operator, and changing the value of the
dir in that particular memory address.
*/

void turn (struct ROBOT *robot) {

    if(robot->dir == N) {           // If the pointer to the dir of robot is North,
        robot->dir = O;             // Changes the value of dir to East
    } else if(robot->dir == O) {    // If the pointer to the dir of robot is East,
        robot->dir = S;             // Changes the value of dir to South
    } else if(robot->dir == S) {    // If the pointer to the dir of robot is South,
        robot->dir = W;             // Changes the value of dir to West
    } else {
        robot->dir = N;             // Else, changes the value of dir to North again.
    }

}

/*
This method works my taking the pointer to the robot as parameter, and
Accessing the member variables such as 'dir', 'xpos', and 'ypos'. Depending
on the direction of the robot, the pointers to the 'xpos' and 'ypos' are
incremented or decremented.

This is done by the help of arrow opereator (->), where the pointers 
to the xpos and ypos points towards their respective memory addresses,
and reasigns new values.
*/

void move(struct ROBOT *robot) {

    if(robot->dir == N) {           // If the robot is facing north,
        ++robot->xpos;              // the xpos is incremented (robot moves forward)
    } else if(robot->dir == S) {    // If the robot is facing south,
        --robot->xpos;              // xpos is decremented (robot moves backwards)
    } else if(robot->dir == O) {    // If the robot is facing east,
        ++robot->ypos;              // ypos is incremented (robot moves towards right direction)
    } else {                        
        --robot->ypos;              // Else, the robot moves left
    }
}

/*
Calculates the length of the entered string by taking the pointer to the array as a parameter
and keeps incrementing the counter until the null-terminator is found in the array.
*/

int calculateLen(char *string) {
    int counter = 0;                    // Variable to keep track of the length of the string

    while(string[counter] != '\0') {    // Loop keeps incrementing counter until null-terminator
        counter++;                      // Counter incremented
    }

    return counter;                     // Returns the counter
}

/*
The buffer is cleared each time an input is taken from the user.
This method functions by retrieving the charactes and discarding them
until it reaches a new-line character OR it reaches the end of file.
*/

void clearBuffer(void) {
    char input;
    while((input = getchar()) != '\n' && input != EOF);
}

int main(int argc, char *argv[]) {
    
    int user_x;                     // Variable to store x-coordinate from user
    int user_y;                     // Variable to store y-coordinate from user
    bool program_loop = true;          // Boolean to keep taking user input
    char movement[MAX_LENGTH];      // Array of characters as string taken from user input
    char end_char = 'x';            // Character that denotes the end of program

    printf("Type in the starting x-pos: ");
    scanf("%d", &user_x);           // Stores the user input as integer for robot's x-coordinate
    clearBuffer();                  // Clears buffer to prevent '\n' from skipping user input

    printf("Type in the starting y-pos: ");
    scanf("%d", &user_y);           // Stores the user input as integer for robot's y-coordinate
    clearBuffer();                  // Clears buffer to prevent '\n' from skipping user input
    
    enum DIRECTION direction = N;                           // Starting direction of robot set as NORTH
    struct ROBOT my_robot = {user_x, user_y, direction};    // Creating my_robot from ROBOT structure
    struct ROBOT *pMy_robot = &my_robot;                    // Pointer which stores the memory address of my_robot variable

    /*
    The loop is responsible for taking user inputs repeatedly.
    The while loop breaks once it has detected 'end_char', or 
    an invalid character. 
    */

    while(program_loop) {
        // The program prompts the user for movement strings
        printf("Put in a string of movements: ");
        scanf("%s", movement);      // String of characters stored in 'movement' variable
        clearBuffer();              // Buffer is cleared so that no '\n' is stored which might result in missed user input
        printf("\n");               // Enough spacing printed for readability of the console

        /*
        The length of the string is calculated and stored in 'string_len' variable which is used in the
        for-loop so that the loop does not reach an index of the array where there are no characters.

        The calculation is done by passing the memory adddress of the array.
        */

        int string_len = calculateLen(&movement);

        // The loop continues untill the length of the string 'movement'
        for(int i = 0; i < string_len; i++) {
            if(movement[i] == 'm') {        // If the character 'm' has been discovered,
                move(pMy_robot);            // the robot will be moved with the method 'move'
                // If the position of the robot is beyond 0-99, the loop will be exited.
                if(pMy_robot->xpos > 99 || pMy_robot->xpos < 0 || pMy_robot->ypos > 99 || pMy_robot->ypos < 0) {
                    printf("Robot out of bounds. Program exited.\n");
                    break;      // Exits the for-loop
                }
            } else if(movement[i] == 't') {             // If the character 't' has been discovered,
                turn(pMy_robot);                        // the robot will be turned with the method 'turn'
            } else if(movement[i] == end_char) {        // If the end_char is discovered, the program will be exited
                printf("Program terminated!\n");
                program_loop = false;                   // The program condition is set to false.
                return 0;                               // Program ends with zero-value
            } else {                                    // Else if an invalid character is discovered, the program also ends.
                printf("Invalid characted encountered. Program exited.\n");
                program_loop = false;                   // The program condition is set to false.
                return 0;                               // Program ends with zero-value
            }
        }

        printf("New robot x-pos: %d\n", pMy_robot->xpos);
        printf("New robot y-pos: %d\n", pMy_robot->ypos);
        printf("\n");

        /*
        The program prompts the user for new movement starting positions
        */

        printf("Type in the starting x-pos: ");
        scanf("%d", &user_x);           // Stores the user input as integer for robot's x-coordinate
        clearBuffer();                  // Clears buffer to prevent '\n' from skipping user input

        printf("Type in the starting y-pos: ");
        scanf("%d", &user_y);           // Stores the user input as integer for robot's y-coordinate
        clearBuffer();                  // Clears buffer to prevent '\n' from skipping user input
        printf("\n");                   // Enough spacing printed for readability of the console

        // Reinitializer the values for the robot as the new stored user inputs
        pMy_robot->xpos = user_x;
        pMy_robot->ypos = user_y;
        pMy_robot->dir = N;         // Resets the direction of the robot to NORTH
    }

    return 0;
}