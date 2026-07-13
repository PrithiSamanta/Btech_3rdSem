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

int countNode(struct Node *first){
    int count=0;
    struct Node *save=first;
    while (save!=NULL)
    {
        count++;
        save=save->link;
    }
    return count;
}

struct Node * swapK(struct Node *first,int k){
    int n=countNode(first);
    struct Node *save=first;
    struct Node *save1=NULL;
    struct Node *save2=NULL;

    for (int i = 1; i <= n; i++)
    {
        save=save->link;
        if (i==n-k+1)
        {
            save1=save;
            save2=first;
        }
        save2=save2->link;
    }
    int temp=save2->info;
    save2->info=save1->info;
    save1->info=temp;

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

//  printf("%d",countNode(first));
    first=swapK(first,2);
    displayList(first);

    return 0;
}