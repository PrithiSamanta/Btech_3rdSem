#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void push(struct Node **top, int val)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = val;
    newNode->link = *top;
    *top = newNode;
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("The stack is empty.\n");
        return -1;
    }
    struct Node *temp = *top;
    int poppedVal = temp->info;
    *top = (*top)->link;
    free(temp);
    return poppedVal;
}

void display(struct Node **top)
{
    if (*top == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    struct Node *save = *top;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->link;
    }
}

int main()
{
    struct Node *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 50);
    push(&top, 40);
    printf("%d\n", pop(&top));
    display(&top);
}