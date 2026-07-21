#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char info;
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

void recognize(char str[])
{
    struct Node *top = NULL;
    int i = 0;
    while (str[i] != 'c')
    {
        push(&top, str[i]);
        i++;
    }
    i++;
    while (str[i] != '\0' && top != NULL)
    {
        if (str[i] == top->info)
        {
            pop(&top);
        }
        else
        {
            printf("The given string is not of the required pattern.\n");
            return;
        }
        i++;
    }
    if (str[i] == '\0' && top == NULL)
    {
        printf("The given string is of the required pattern.\n");
    }
    else
    {
        printf("The given string is not of the required pattern.\n");
    }
}

int main()
{
    printf("Enter string : ");
    char str[100];
    scanf("%s", str);

    recognize(str);
}