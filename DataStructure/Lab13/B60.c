#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char info;
    struct Node *link;
};

void push(struct Node **top, char val)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = val;
    newNode->link = *top;
    *top = newNode;
}

char pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("The stack is empty.\n");
        return -1;
    }
    struct Node *temp = *top;
    char poppedVal = temp->info;
    *top = (*top)->link;
    free(temp);
    return poppedVal;
}

int countNodes(struct Node *top)
{
    struct Node *save = top;
    int count = 0;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
    return count;
}

void recognize(char str[])
{
    struct Node *top = NULL;

    int i = 0;
    char pushVal;
    while (str[i] != '\0')
    {
        if (str[i] == 'a' || str[i] == 'b')
        {
            if (top == NULL)
            {
                pushVal = str[i];
            }
            if (str[i] == pushVal)
            {
                push(&top, pushVal);
            }
            else
            {
                pop(&top);
            }
        }
        else
        {
            printf("Invalid.\n");
            return;
        }
        i++;
    }
    if (top == NULL)
    {
        printf("Valid.\n");
    }
    else
    {
        printf("Invalid.\n");
    }
}

int main()
{
    printf("Enter string : ");
    char str[100];
    scanf("%s", str);

    recognize(str);
}