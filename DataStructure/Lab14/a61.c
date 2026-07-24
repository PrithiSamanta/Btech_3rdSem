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
        return '\0';
    }
    struct Node *temp = *top;
    char poppedVal = temp->info;
    *top = (*top)->link;
    free(temp);
    return poppedVal;
}

int isValid(char str[])
{
    struct Node *top = NULL;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(&top, str[i]);
        }
        else
        {
            if (top == NULL)
            {
                return 0;
            }

            char ch = pop(&top);
            if ((str[i] != ')' && ch == '(') || (str[i] != ']' && ch == '[') || (str[i] != '}' && ch == '{'))
            {
                return 0;
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Enter number of string.");
    scanf("%d", &n);
    char strArr[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", strArr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", isValid(strArr[i]));
    }

    return 0;
}