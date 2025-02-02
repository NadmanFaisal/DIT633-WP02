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


//###### Main program #######
int main(int argc, char *argv[]) {
    
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

REGTYPE* random_list(void) {

    int nr, i=0;
    int *pNr = &nr;
    REGTYPE *top, *old, *item;

    for(i = 0; i < MAX; i++) {
        if(i == 0) {
            top = malloc(sizeof(REGTYPE));
            *pNr = rand() % 101;
            top->number = *pNr;
            top->next = NULL;
            old = top;
        } else if(i == 4) {
            item = malloc(sizeof(REGTYPE));
            *pNr = rand() % 101;
            item->number = *pNr;
            item->prev = old;
            old->next = item;
            break;
        } else {
            item = malloc(sizeof(REGTYPE));
            *pNr = rand() % 101;
            item->number = *pNr;
            item->prev = old;
            item->next = NULL;
            old->next = item;
            old = item;
        }
    }
    
    return (top);
};