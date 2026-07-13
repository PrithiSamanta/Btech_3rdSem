#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

void displayList(struct Node *first)
{
    if (first == NULL)
    {
        printf("The linked list is empty.");
        return;
    }
    struct Node *save = first;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->link;
    }
}
struct Node *insLast(int x, struct Node *first)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        first = newNode;
        return first;
    }
    struct Node *save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
    return first;
}

struct Node *copyList(struct Node *first1, struct Node *first2)
{
    if (first1 == NULL)
    {
        printf("The linked list is empty.");
        return 0;
    }
    struct Node *save1 = first1;
    struct Node *save2 = first2;
    while (save1 != NULL)
    {
        struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
        newNode->info = save1->info;
        newNode->link = NULL;
        if (first2 == NULL)
        {
            first2 = newNode;
            save1 = save1->link;
            continue;
        }
        struct Node *save = first2;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;

        save1 = save1->link;
    }
    return first2;
}

int main()
{
    struct Node *first1 = NULL;
    struct Node *first2 = NULL;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the value to insert : ");
        int val;
        scanf("%d", &val);
        first1 = insLast(val, first1);
    }

    first2 = copyList(first1, first2);

    displayList(first2);
    return 0;
}