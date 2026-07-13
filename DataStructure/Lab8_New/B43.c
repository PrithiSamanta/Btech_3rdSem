#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};

struct Node* insLast(int x, struct Node *first)
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
    free(save);
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

void isSame(struct Node* l1,struct Node *l2){
    struct Node * save1=l1;
    struct Node * save2=l2;
    while (save1 !=NULL && save2 !=NULL)
    {
        if (save1->info !=save2->info)
        {
            printf("The linked list is not same.");
            return;
        }
        save1=save1->link;
        save2=save2->link;
    }
    if (save1==NULL && save2 ==NULL)
    {
        printf("The linked list is same.");
        return;
    }
    printf("The linked list is not same.");
    
}

int main()
{
    struct Node *l1 = NULL;
    struct Node *l2 = NULL;
    l1 = insLast(2, l1);
    l2 = insLast(2,l2);


    isSame(l1,l2);

    return 0;
}