#include <stdio.h> // header file
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100 // defing max value for string (max 100 command at once)

// this method clears buffer after user input
void clearBuffer (void) {
    char input;
    while ( (input = getchar()) != '\n' && input != EOF );
}

// enum for Direction
enum DIRECTION{N, O, S, W}; // North, East, South, West

// record of type ROBOT, used to create the robot
typedef struct {
int xpos; // X cordinator
int ypos; // y cordinator
enum DIRECTION dir; // direction
} ROBOT;

/*This method is used to move the robot any directionit takes
three pointer argument as parameter. The movement is based on
the X, Y axis. It checks the currectDirection and moves towards
that direction, and depending on the ROBOT locationX and Y cordinator
gets incrimented and subtracted
*/
void move(char * currentDirection, int * xpos, int * ypos){ //move method taking pointer parameter argument

    if(*currentDirection == N){ // checking if the direction is North
        ++*ypos; // incriment y coordinate by 1
    } else if (*currentDirection == S) { // checking if the direction is North
        --*ypos; // subtract y coordnate by 1
    } else if (*currentDirection == O) { // checking if the direction is North
        ++*xpos; // incriment x coordinate by 1
    } else if (*currentDirection == W) { // checking if the direction is North
        --*xpos; // subtract x coordnate by 1
    }

}

/*The turn() is used to change the direction (N,O,S,W) of the ROBOT
It changes direction clock wise at 90 degree. The method has only
on poinyer parameter as argument. The if condition checks the 
currentDirection and moves the direction 90 degree cloclwise 
axxording to the user command*/
void turn(char * currentDirection){ //taking pointer parameter as argument

    if(*currentDirection == N){ // check if the direction is Noth
        *currentDirection = O; // move 90 degree clockwise we get East
        
    } else if (*currentDirection == O) { // check if the direction is East
        *currentDirection = S; // move 90 degree clockwise we get South
        
    } else if (*currentDirection == S) { // check if the direction is South
        *currentDirection = W; // move 90 degree clockwise we get West
        
    } else if (*currentDirection == W) { // check if the direction is West
        *currentDirection = N; // move 90 degree clockwise we get North
        
    }
}

/*The method is used to output the direction of the ROBOT.
it takes direction as pararmemter and we are using a switch
case to identfy the direction and print the current direction*/
void printDirection(char direction){ //takes direction as parameter
    switch (direction) { //direction to check agaist the case
        case N:
            printf("Current direction: N\n"); //if the direction is North(N) this is printed
            break; // breaks when match found
        case O:
            printf("Current direction: O\n"); //if the direction is East(O) this is printed
            break; // breaks when match found
        case S:
            printf("Current direction: S\n"); //if the direction is South(S) this is printed
            break; // breaks when match found
        case W:
            printf("Current direction: W\n"); //if the direction is West(W) this is printed
            break; // breaks when match found
    }

}

/*The main function, it holds the body of the ROBOT. Moreover, exception coditions are also checked
here. It holds the initial output for the user to enter the X and Y coordinates, and the commands
for MOVE and TURN. We are using while loop to control the program exit logic and for handling invalid
inputs. Adding to it, a for loop is used to itirate through the command string and commands are executed
based on the string input(m,t).*/
int main(int argc, char * argv[]){

    ROBOT robot; // initializing robot
    char currentDirection = robot.dir; // assinging the robot direction
    currentDirection = N; // default direction of Robot
    int  xCordinate = robot.xpos; // variable to hold the x coordinate
    int  yCordinate = robot.ypos; // variable to hold the y coordinate
    bool progRuning = true; // boolean for program exit logic

// the while loop is used to end the program, it runs till the user enters x
// once the user enters x, progRuning = false, hence the program ends
while (progRuning) { 

    int  MAX_CORDINATE = 99; // varibale to store the maximum bound for x and y coordinate
    int  MIN_CORDINATE = 0; // variable to store the minimum bound for x and y coordinate

    printf("Enter robot starting X cordinate (0-99): \n"); // prompts user to enter the X coordinate
    scanf("%d", &xCordinate); // storing the user input in for x coordinate 
    clearBuffer(); // clears buffer

        // the loop runs till user input is out of bound. Once the user input is
        // within the max and mix x-coordinate, it stores the the userinput
        while (((xCordinate < MIN_CORDINATE) || (xCordinate > MAX_CORDINATE)) || !isalpha(xCordinate)) {

            printf("Invalid X cordinate. Enter robot starting X cordinate (0-99): \n");
            scanf("%d", &xCordinate); // stores valid user input for x coordinate
            clearBuffer(); // clear buffer

        }

    printf("Enter robot starting Y cordinate (0-99): \n"); // prompts user to enter the Y coordinate
    scanf("%d", &yCordinate); // storing the user input in for y coordinate
    clearBuffer(); // clears buffer

        // the loop runs till user input is out of bound. Once the user input is
        // within the max and mix y-coordinate, it stores the the userinput
        while (((yCordinate < MIN_CORDINATE) || (yCordinate > MAX_CORDINATE) || !isalpha(yCordinate)) ) {

            printf("Invalid Y cordinate. Enter robot starting Y cordinate (0-99): \n");
            scanf("%d", &yCordinate); // stores valid user input for y coordinate
            clearBuffer(); // clear buffer
            
        }


    char robotCommand[MAX] = {0}; // variable to hold the command string (string of characters 'm' and 't')


    printf("Enter 'm' to move and 't' to turn ('x' to Exit): "); // prompts the user to enter a command
    scanf("%s", robotCommand); // the command string is stored in the variable
    clearBuffer(); // clear buffer

    
    /*The for loop is used to itirate through the string and find m,t,x as command
    It ititrataes till the command string length and keeps incrimenting till reaching
    the length. It itirates through the string and compares every char/index value with
    the command characters(m,t,x). if a match is found appropriate method is called to 
    perform that specific action*/
    for (int i = 0; i < strlen(robotCommand); i++) {

        // the loop executes till it finds valid command characters in the string, once it finds
        // a valid charcter it stores in the variable.
        while ((robotCommand[i] != 'm') && (robotCommand[i] != 't') && (robotCommand[i] != 'x' )) {
            printf("Invalid command, Enter 'm' to move and 't' to turn and 'x' to Exit(lowercase): "); // prompt for user to help them with command character
            scanf("%s", robotCommand); // stores valid command character
            clearBuffer(); // clears buffer
            i = 0; // reseting the length size to validate from the beginning again
        }

        if (robotCommand[i] == 'm') { // checks if the string charcter is equal to 'm'. If true the function is called

            move(&currentDirection, &xCordinate, &yCordinate); // calls the move function and it has the robot values as parameter
            
        } else if (robotCommand[i]== 't') { // checks if the string charcter is equal to 't'. If true the function is called

            turn(&currentDirection); // calls the turn function and it has the robot values as parameter
            
        } else if (robotCommand[i] == 'x' ){ // checks if the string charcter is equal to 'x'. If true, the boolean variable is updated to false

            printf("Successful EXIT\n"); // printline for exit behaviour
            progRuning = false; // updating the boolean to false, it stops the while loop
            return 0; // retun of success
        }
       
        
    }

    if (xCordinate > 100 || yCordinate > 100) // check  if the X or Y coordnate is out of bound
    {
        printf("OUT OF BOUND COORDINATE\n"); // printline for error behaviour
        return 0; // retun value
    }
    
    printf("\n"); // print line for spacing
    printf("######-ROBOT_LOCATION-######\n"); // header formating for output
    printDirection(currentDirection); // prints the direction the robot is facing
    printf("Cordinates: X: %d Y: %d\n", xCordinate, yCordinate); // print x and y coordinate of robot
    printf("############################\n"); // formating for ouot put
    printf("\n"); // print line for spcaing
    
    }
    return 0; // return on successfull execution


}