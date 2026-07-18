#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *twoHalves(struct Node **first, struct Node **last)
{
    if (*first == NULL || *first == (*first)->link)
    {
        return NULL;
    }

    struct Node *slow = *first;
    struct Node *fast = *first;

    while (fast->link != *first && fast->link->link != *first)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    struct Node *first2 = slow->link;
    slow->link = *first;
    (*last)->link = first2;
    *last = slow;
    return first2;
}

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

void display(struct Node *first)
{
    struct Node *save = first;
    do
    {
        printf("%d, ", save->info);
        save = save->link;
    } while (save != first);
    printf("\n");
}

int main()
{
    struct Node *first = NULL;
    struct Node *last = NULL;
    insFirst(&first, &last, 1);
    insFirst(&first, &last, 3);
    insFirst(&first, &last, 4);
    insFirst(&first, &last, 2);
    insFirst(&first, &last, 6);

    struct Node *first2 = twoHalves(&first, &last);

    display(first);
    display(first2);
    return 0;
}