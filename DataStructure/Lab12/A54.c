#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lptr;
    int info;
    struct Node *rptr;
};

void insFirst(struct Node **first, int info)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = info;
    newNode->lptr = NULL;
    if (*first == NULL)
    {
        newNode->rptr = NULL;
    }
    else
    {
        newNode->rptr = *first;
    }
    *first = newNode;
}

void display(struct Node **first)
{
    struct Node *save = *first;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->rptr;
    }
}

void delPos(struct Node **first, int pos)
{
    if (*first == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    if (pos < 0)
    {
        printf("Index does not exist.\n");
    }
    if (pos == 0)
    {
        struct Node *temp = *first;
        if ((*first)->rptr == NULL)
        {
            *first = NULL;
            return;
        }

        *first = (*first)->rptr;
        (*first)->lptr = NULL;
        free(temp);
        return;
    }
    struct Node *save = *first;
    for (int i = 1; i < pos; i++)
    {
        save = save->rptr;
        if (save == NULL)
        {
            printf("Index out of range.\n");
            return;
        }
    }
    struct Node *temp = save->rptr;
    save->rptr = temp->rptr;
    if (temp->rptr != NULL)
    {
        temp->rptr->lptr = save;
    }
    free(temp);
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

int main()
{
    struct Node *first = NULL;
    insFirst(&first, 2);
    insFirst(&first, 5);
    insLast(&first, 15);
    display(&first);

    return 0;
}