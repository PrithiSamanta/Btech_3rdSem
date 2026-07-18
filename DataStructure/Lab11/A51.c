#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
void insFirst(struct Node **first, struct Node **last, int val)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = val;
    if (*first == NULL)
    {
        *first = newNode;
        *last = newNode;
        newNode->link = newNode;
    }
    else
    {
        newNode->link = *first;
        (*last)->link = newNode;
        *first = newNode;
    }
}

void delPos(struct Node **first, struct Node **last, int pos)
{
    if (*first == NULL)
    {
        printf("The linked list is empty.\n");
    }
    if (pos < 0)
    {
        printf("Index not found.\n");
    }
    if (pos == 0)
    {
        struct Node *temp = *first;
        if (*first == *last)
        {
            *first = NULL;
            *last = NULL;
        }
        else
        {
            *first = (*first)->link;
            (*last)->link = *first;
        }

        free(temp);
        return;
    }

    struct Node *save = *first;
    for (int i = 1; i < pos; i++)
    {
        save = save->link;
        if (save == *first)
        {
            printf("Index is out of range.\n");
            return;
        }
    }
    struct Node *temp = save->link;
    save->link = save->link->link;
    free(temp);
    if (save->link == *first)
    {
        *last = save;
    }
}

void insLast(struct Node **first, struct Node **last, int val)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = val;
    if (*first == NULL)
    {
        newNode->link = newNode;
        *first = newNode;
        *last = newNode;
    }
    else
    {
        newNode->link = *first;
        (*last)->link = newNode;
        *last = newNode;
    }
}

void display(struct Node *first)
{
    struct Node *save = first;
    do
    {
        printf("%d, ", save->info);
        save = save->link;
    } while (save != first);
}

int main()
{
    struct Node *first = NULL;
    struct Node *last = NULL;
    insFirst(&first, &last, 1);
    insFirst(&first, &last, 3);
    insFirst(&first, &last, 4);
    insFirst(&first, &last, 2);
    insLast(&first, &last, 6);
    display(first);
    return 0;
}