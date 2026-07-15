#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
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
void dispList(struct Node *first)
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *save = first;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->link;
    }
    printf("\n");
}
void remDup(struct Node *first)
{
    struct Node *save = first;
    while (save->link != NULL)
    {
        if (save->info == save->link->info)
        {
            struct Node *temp = save->link->link;
            save->link->link = NULL;
            save->link = temp;
        }
        else
        {
            save = save->link;
        }
    }
    dispList(first);
}
int main()
{
    struct Node *l1 = NULL;
    printf("Enter number of nodes in the linked list.");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter value : ");
        scanf("%d", &val);
        l1 = insLast(val, l1);
    }
    remDup(l1);

    return 0;
}