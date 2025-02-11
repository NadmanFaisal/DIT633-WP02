#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;         // Unsigned char can be used using the typedef 'byte'

int main(int argc, char *argv[]) {

    /*
    If arguements more or less than than 5 are provided (not counting file path), 
    then the program is stopped. 
    */
    if(argc < 6 || argc > 6) {                          // If more or less than 6 arguements provided, then 
        printf("Invalid arguements provided.\n");       // the program prints the prompt highlighting the issue and
        return 0;                                       // stops the program.
    }

    /*
    The provided arguements are also checked whether they are of the correct data 
    type. The provided arguements (besides the file path) needs to be a number. 
    */
    for(int i = 1; i < argc; i++) {                     // Each arguement (except the file path) are checked,
        if(!isdigit(*argv[i])) {                        // and ensured they are numbers and not alphabets.
            printf("Invalid arguement type. Please provide valid arguements.\n");       // If not numbers, prompt is printed and
            return 0;                                                                   // program is stopped.
        }

    }

    byte result = 0;                            // Result of type byte (unsignsd char) declared.
    byte result_copy = result;                  // A copy of result is kept for bitshifting.

    byte engine_on = atoi(argv[1]);             // The first arguement converted to integer and stored in engine_on.
    byte gear_pos = atoi(argv[2]);              // The second arguement converted to integer and stored in gear_pos.
    byte key_pos = atoi(argv[3]);               // The third arguement converted to integer and stored in key_pos.
    byte brake1 = atoi(argv[4]);                // The forth arguement converted to integer and stored in brake1.
    byte brake2 = atoi(argv[5]);                // The fifth arguement converted to integer and stored in brake2.

    if (engine_on < 0 || engine_on > 1) {       // Checks if engine_on is out of bound 
        printf("Invalid engine arguement.\n");    
        return(0);
    } else if (gear_pos > 4 || gear_pos < 0) {  // Checks if gear_pos is out of bound
        printf("Invalid gear arguement.\n");       
        return(0);   
    } else if (key_pos > 2 || key_pos < 0) {    // Checks if key_pos is out of bound
        printf("Invalid key arguement.\n");       
        return(0);
    } else if (brake1 > 1 || brake1 < 0) {      // Checks if brake1 is out of bound
        printf("Invalid brake1 arguement.\n");
        return(0);
    } else if (brake2 > 1 || brake2 < 0) {      // Checks if brake2 is out of bound
        printf("Invalid brake2 arguement.\n");
        return(0);
    }

    printf("engine_on: %d\n", engine_on);       // The number for engine_on printed
    printf("gear_pos: %d\n", gear_pos);         // The number for gear_pos printed
    printf("key_pos: %d\n", key_pos);           // The number for key_pos printed
    printf("brake1: %d\n", brake1);             // The number for brake1 printed
    printf("brake2: %d\n", brake2);             // The number for brake2 printed
    printf("\n");

    result = result | engine_on;        // Since result is initially 0, bitmasking is used to insert engine bits into result variable

    result = result << 3;               // Result bits are shifted left 3 times to accomodate for gear bits
    result = result | gear_pos;         // Bit masking used to insert gear bits into result

    result = result << 2;               // Result bits are shifted left twice to accomodate for key pos bits
    result = result | key_pos;          // Bit masking used to insert key_pos bits into result

    result = result << 1;               // Result bits are shifted left once to accomodate for brake1 bits
    result = result | brake1;           // Bit masking used to insert brake1 bits into result

    result = result << 1;               // Result bits are shifted left once to accomodate for brake2 bits
    result = result | brake2;           // Bit masking used to insert brake2 bits into result

    printf("Result: %d\n", result);     // The resulting integer printed
    byte decimal_Number = result;       // Declaring a variable 'decimal_number' to 'result' value
    byte temp;
    byte hexa_Number[100];              // Array of characters representing string, to store hexadecimal values
    int i = 1, j; 
    
    while (decimal_Number != 0) { 
        temp = decimal_Number % 16;     // The decimal number keeps dividing by 16 untill 0
        
        if (temp < 10) {                // If the remainder is less than 10, 
            temp = temp + 48;           // Added with 48, as the ASCII values of numbers starts from 48. 48 represents 0 as char.
        }
        else {                          // else if remainer is greater than 10, 
            temp = temp + 55;           // numbers greater than 10 have alphabetical values in hexadecimal. Numbers greater than 10
                                        // are added with 55 as alphabet's ASCII values start from 65. 10-15 are A-F.
        }
        hexa_Number[i++] = temp;                        // temp values stored in the array
        decimal_Number = decimal_Number / 16;           // The quotient is then divided, untill final quotient reaches 0.
    } 
    
    printf("Hexadecimal value is: ");               // Prompt to indicate printing of hexadecimal values
    for (j = i - 1; j > 0; j--) {                   // The array is printed from backwards, as the last remainder is in the first place
                                                    // of a dexadecimal value
        printf("%c", hexa_Number[j]);               // The characters stored in the array are printed.
    }
    printf("\n");                       // Extra line to accomodate space for readability.
    return 0;                           // Program returns 0.
}
// Source: To convert decimal to hexadecimal value: https://www.geeksforgeeks.org/c-program-for-decimal-to-hexadecimal-conversion/