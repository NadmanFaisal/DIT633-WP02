
// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 2
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h> // include I/O library
#include <stdlib.h> // include library for srand & rand.
#include <time.h> // include library for time function to randomize seed

/*

Improvements:-

Questions:-

*/


//#### Constants #####
#define MAX 5 // define max amount of nodes to create when first creating a linked_list

//##### typedefs ####

// define a type REGTYPE, which is a struct containing:-
typedef struct q{
    int number; // a number, between 0-100
    struct q *next; // the next REGTYPE struct
    struct q *prev; // the previous REGTYPE struct
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void); // function declaration for creating a linked_list that has random numbers as its data

REGTYPE* add_first(REGTYPE* temp, int data); // function declaration for adding a new head to the linked list


//###### Main program #######
int main(int argc, char *argv[]) {

    int nr=0; // index of struct in a linked list, starting from zero.
    // actual position of the linked list 
    REGTYPE *act_post , *head=NULL; // the head position of the  linked lsit

    srand(time(0)); // create random seed to make new number based on time

    head=random_list(); // make head equal to the generated linked list
    // since head will contain a recursive next
    // where the next struct will point to the next struct containing the member next which will also contain the next struct and so on


    act_post=head;// we make act_post equal to the head, so that we can modify it for ex: printing
    
    // as long as the act_post isn't NULL, meaning it isn't in the end of the linked list
    while( act_post!=NULL){ 
        printf("\n Post nr %d : %d" , nr++, act_post->number); // print the struct with where it is in linked list and the data it contains
        act_post=act_post->next; // now we make act post the next struct by accessing the value of its member next.
    }

    head=add_first(head, rand() % 101); // head now equals to the new head in our linked list with a random data between 0-100
    act_post = head; // we make act_post equal to the head, so that we can modify it for ex: printing
    nr = 0; // reset number so that we accurately show the index of the linked list

    printf("\n"); // print new line


    // similar to the while loop above.

    // as long as the act_post isn't NULL, meaning it isn't in the end of the linked list
    while( act_post!=NULL){ 
        printf("\n Post nr %d : %d" , nr++, act_post->number); // print the struct with where it is in linked list and the data it contains
        act_post=act_post->next; // now we make act post the next struct by accessing the value of its member next.
    }


    // --- Free the allocated memory ---

    // as long as the act_post isn't NULL, meaning it isn't in the end of the linked list
    while((act_post=head)!=NULL){ 
        head=act_post->next; // make head equal to the next struct in act_post until it reaches NULL
        free(act_post); // free up the memory on the current struct up until it frees up the last struct
    }
    
    return 0; // end program
}

// ==== End of main ======================================

// function for creating a linked_list that has random numbers as its data
REGTYPE* random_list(void ){

    // nr is the data for the struct which is a random number 
    int nr, i=0; // index for the for loop

    /*
    
    *top = the head of the linked list
    *old = the previous struct of linked list
    *item = the current struct of linked list

    */
    REGTYPE *top, *old, *item; 
    
    item = (REGTYPE*) malloc(sizeof(REGTYPE)); // allocate memory to the first struct in the linked list and assign it to item

    // for each struct in the linked list up to MAX - 1th struct 
    for(i = 0; i < MAX; i++){ 
        nr = rand() % 101; // generate random num for the struct's member number in range 0-100.
        item -> number = nr; // assign struct member number to the random number
        if(i == 0){ // if this is the first struct
            item -> prev = NULL; // assign prev to NULL since there is no previous when you are the first struct in the linked list
            top = item; // assign it to the top struct of the linked list
            old = item; // assign it to be the old, since nearly all field's of the current struct is filled
            item = (REGTYPE*) malloc(sizeof(REGTYPE)); // allocate memory to a new struct and assign it to item, to be the new current
            old -> next = item; // point the current struct's member next to the new struct we made.
        } else if(i == (MAX - 1)) { // if this is the last struct we will add
            item -> prev = old; // we assign the last struct's member previous to the previous struct we stored in old
            item -> next = NULL; // we make the next of this last struct to be NULL since this is the last struct in the linked list
        } else { // otherwise for all other structs in between the first & the last
            item -> prev = old; //  we assign the current struct's member previous to the previous struct we stored in old
            old = item; // we assign this current struct to be the old
            item = (REGTYPE*) malloc(sizeof(REGTYPE)); // we allocate memory to the new struct and assign it to item, to be the new current
            old -> next = item; // we make the newly assigned old struct's member next to the newly assigned item's struct (which will be the next struct we will work on the next for loop iteration)
        }
    }
    return(top); // return the head of the linked list
}

//==========================================================

// function for adding a new head to the linked list
REGTYPE* add_first(REGTYPE* temp, int data){ // takes in the current head we have and the data for the new head (which is a random number in range 0-100)

    REGTYPE *new_head = (REGTYPE*) malloc(sizeof(REGTYPE)); // allocate memory for the new head

    new_head -> number = data; // assign new head's member number to the data argument we were provided
    new_head -> next = temp; // assign new head's member next to the temp argument we were provided, which is the address of the old head for the linked list 
    new_head -> prev = NULL; // assign new head's member prev to the NULL argument since it will be the new head of our linked list

    temp -> prev = new_head; // we must also update the old head's member prev & assign it to the new head's of the linked list.

    return(new_head); // return the new head of the linked list
}