#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lptr;
    int info;
    struct Node *rptr;
};

void insFirst(struct Node **first,int info){
    struct Node *newNode= (struct Node*)(malloc(sizeof(struct Node)));
    newNode->info=info;
    newNode->lptr=NULL;
    if (*first==NULL)
    {
        newNode->rptr=NULL;
    }
    else{
        newNode->rptr=*first; 
    }
    *first=newNode;
}

void display(struct Node **first){
    struct Node *save=*first;
    while (save!=NULL)
    {
        printf("%d, ",save->info);
        save=save->rptr;
    }
    
}

int main(){
    struct Node *first=NULL;
    insFirst(&first,2);
    insFirst(&first,5);
    insFirst(&first,15);
    
    display(&first);

    return 0;
}