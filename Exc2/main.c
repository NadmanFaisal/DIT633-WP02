#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####

/*
Functions are declared at the top to allow the compiler to compile properly. 
Without declaring the function before the main, calling these functions will 
cause the compiler to face error since the functions are defined at the bottom. 
*/

REGTYPE* random_list(void);                     // Creates a linked list of 5 REGTYPE elements of random numbers
REGTYPE* add_first(REGTYPE* temp, int data);    // Adds a REGTYPE element to the first position of a linked list


//###### Main program #######
int main(int argc, char *argv[])
{
int nr=0;
REGTYPE *act_post , *head=NULL;
srand(time(0)); // Random seed
head=random_list();
act_post=head;
while( act_post!=NULL){
printf("\n Post nr %d : %d" , nr++, act_post->number);
act_post=act_post->next;
}
printf(" \n");

int newNum = 7; //new number stores the number for add first method
nr = 0; //nr count to 0, fo new value print
head = add_first(head, newNum); // assigning add_first() method to head regtype.
act_post=head;
printf("After adding new value at first: \n"); // print line to differentiate the new values printed
while( act_post!=NULL){
printf("\n Post nr %d : %d" , nr++, act_post->number);
act_post=act_post->next;
}
printf("\n");

// --- Free the allocated memory ---
while((act_post=head)!=NULL){
head=act_post->next;
free(act_post);
}
return 0;
}
// ==== End of main ======================================

/*
random_list creates a linked list of REGTYPE with random data values. 
Method does not take any parameters. 

This method functions by allocating memories for each elements, and then
setting their 'number' member variable to a random number with the help of 
pointers. Then, arrow operators are used to access member variables of the 
REGTYPE structs, and values are assigned/reassigned. 

If the it is the first element of the linked list, then 'next' pointer points 
to null, as no other elements have been created for the linked list yet. It also 
does not need the 'prev' pointer to point to anything, as there are no elements 
before it. 

If it is the last element, then the element does not need 'next' pointer to 
point to anything, as it is the last element. 

If it is any element in between, then the 'prev' pointer points to the element before it 
in the linked list. And the 'next' pointer points to the element after it.
*/

REGTYPE* random_list(void) {

    int nr, i=0;
    int *pI = &i;                                   // Pointer to the index i, which is incremented in the for loop
    int *pNr = &nr;                                 // Pointer to the nr, to reassign values to it
    REGTYPE *top, *old, *item;                      // Pointers to the REGTYPE elements

    for(*pI = 0; i < MAX; ++*pI) {                  // Loops untill MAX, indicating the length of the list
        if(i == 0) {                                // If the first element,
            top = malloc(sizeof(REGTYPE));          // Memory allocated for the 'top' element
            *pNr = rand() % 101;                    // Value of nr is reassigned
            top->number = *pNr;                     // 'top' element's 'number' variable is set to a random number
            top->next = NULL;                       // 'top' element's 'next' pointer points to NULL
            old = top;                              // old pointer of type REGTYPE points to the 'top' element
        } else if(i == MAX) {                       // If the last element
            item = malloc(sizeof(REGTYPE));         // Memory allocated for 'item' element
            *pNr = rand() % 101;                    // Random number generated
            item->number = *pNr;                    // 'number' variable value set to random number
            item->prev = old;                       // 'prev' pointer points to 'old' element
        } else {                                    // If it is any element in between,
            item = malloc(sizeof(REGTYPE));         // Memory allocated for the 'item' element
            *pNr = rand() % 101;                    // Random number assigned to 'nr' variable
            item->number = *pNr;                    // 'number' value is set to a random number
            item->prev = old;                       // 'prev' pointer points to 'old' element
            item->next = NULL;                      // 'next' pointer points to NULL as the next element is yet to be created
            old->next = item;                       // 'next' pointer of the old element points to the 'item' just now created
            old = item;
        }
    }
    
    return (top);               // Returns the first element of the linked list
}

//========================================================== 

/*
The method below creates a new element of REGTYPE, and sets the first
linked list element to the new element created. 

Method takes two parameters - the current first elemet of the linked list, 
and the data that the new element will have
*/

REGTYPE *add_first(REGTYPE *temp, int data) {
    REGTYPE *newNode = malloc(sizeof(REGTYPE));             // Allocates memory for the new element
    newNode->number = data;                                 // New element's 'number' is set to the value of the second parameter
    newNode->next = temp;                                   // 'next' pointer points to the 'temp', which is the previous first element
    temp->prev = newNode;                                   // The previous first element's 'prev' points to the new first element

    return newNode;             // Returns the new element
}