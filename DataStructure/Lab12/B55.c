#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lptr;
    int info;
    struct Node *rptr;
};

void display(struct Node **first)
{
    struct Node *save = *first;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->rptr;
    }
}

void insLast(struct Node **first, int info)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = info;
    newNode->rptr = NULL;
    if (*first == NULL)
    {
        newNode->lptr = NULL;
        *first = newNode;
    }
    else
    {
        struct Node *save = *first;
        while (save->rptr != NULL)
        {
            save = save->rptr;
        }
        newNode->lptr = save;
        save->rptr=newNode;
    }
}

void delAlternate(struct Node **first){
    struct Node *save=*first;

    while (save!=NULL && save->rptr!=NULL)
    {
        struct Node *next = save->rptr;
        save->rptr=next->rptr;
        if (next->rptr !=NULL)
        {
            next->rptr->lptr=save;
        }
        free(next);
        save=save->rptr;
    }
    
}

int main()
{
    struct Node *first = NULL;
    insLast(&first, 2);
    insLast(&first, 5);
    insLast(&first, 15);
    insLast(&first,10);
    delAlternate(&first);
    display(&first);

    return 0;
}
