
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
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

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
// --- Free the allocated memory ---
while((act_post=head)!=NULL){
head=act_post->next;
free(act_post);
}
return 0;
}
// ==== End of main ======================================

REGTYPE* random_list(void ){

int nr; //variable declaration to store random number
int *pnr = &nr;
int i=0; //index value for 'for loop'
REGTYPE *top, *old, *item; //to create REGTYPE body

for (i; i < MAX; i++) {  //the for loop is executed till the MAX value, it contains a if, else-if, else condition

    *pnr = rand()%101; //generates random number and stores it in the variable

    if (i == 0){ // if the index value equals to 0, this if condition is executed
        item = malloc(sizeof(REGTYPE)); // creates a dynamic memory allocation for the item
        item->number = *pnr; //the random number is stored in the item pointing to number
        item->next = NULL; //item pointing to next, gets a null value
        item->prev = top; //item pointing to prev, gets assigned the top/head
        top = item; //top stores the item value
        old = item; //old storees the item value

    } else if (i == MAX - 1){ //if the index value mathes the last last value, the condition is executed
        item = malloc(sizeof(REGTYPE)); // create a dynamic memory allocation for the item
        item->number = *pnr; //the random number is stored in the item pointing to number
        item->next = NULL; //item pointing to next, gets a null value
        item->prev = old; //item pointing to prev, gets assigned the old value
        old->next = item; //old pointer pointing to next, gets assigned the current item
        old = item; //the item becomes the old value;

    } else { // else this condition executed on the rest of the indexes
        item = malloc(sizeof(REGTYPE)); //create a dynamic memory allocation for the item
        item->number = *pnr; //the random number is stored in the item pointing to number
        item->next = NULL; //item pointing to next, gets a null value
        item->prev = old; //item pointing to prev, gets assigned the old value
        old->next = item; //old pointer pointing to next, gets assigned the current item
        old = item; //the item becomes the old value;

    }

}

return(top);
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
}