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

struct Node * sort(struct Node *first){
    int isSorted=0;
    struct Node *save=first;
    while(isSorted==0){
        isSorted=1;
        struct Node *save=first;
        while(save->link!=NULL){
            if (save->info >save->link->info)
            {
                int temp = save->link->info;
                save->link->info =save->info;
                save->info=temp;
                isSorted=0;
                
            }
            save=save->link;
        }
    }
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

    first=sort(first);

    displayList(first);
    return 0;
}