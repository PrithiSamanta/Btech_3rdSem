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

struct Node * revLinkedList(struct Node *first){
    if (first==NULL)
    {
        return 0;
    }
    struct Node *save=first;
    struct Node *pre = NULL;
    
    while (save!=NULL)
    {
        struct Node *temp=save->link;
        save->link=pre;
        pre=save;
        save=temp;
    }
    first=pre;
    return first;
}

int main(){
     struct Node *first = NULL;

    for (int i = 0; i < 5; i++)
    {
        printf("Enter the value to insert : ");
        int val;
        scanf("%d", &val);
        first = insLast(val, first);
    }

    first = revLinkedList(first);

    displayList(first);
    return 0;
}