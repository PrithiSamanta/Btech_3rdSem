#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char info;
    struct Node *link;
};

void push(struct Node **top, char info)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = info;
    if (*top == NULL)
    {
        newNode->link = NULL;
    }
    else
    {
        newNode->link = *top;
    }
    *top = newNode;
}

char pop(struct Node **top)
{
    if (*top == NULL)
    {
        return '\0';
    }

    struct Node *temp = *top;
    char poppedVal = temp->info;
    *top = (*top)->link;
    free(temp);
    return poppedVal;
}

int stackPre(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if (c == '(')
        return 0;
    else if ((c >= 65 || c <= 91) && (c >= 97 || c <= 123))
        return 8;
}

int inputPre(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 9;
    else if (c == ')')
        return 0;
    else if ((c >= 65 || c <= 91) && (c >= 97 || c <= 123))
        return 7;
}

int rnk(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return -1;
    }
    else if ((c >= 65 || c <= 91) && (c >= 97 || c <= 123))
    {
        return 1;
    }
}

// char nextChar(int curr, char*infix){
//     return infix[curr++];
// }

void revPol(char *infix)
{
    struct Node *top = NULL;
    push(&top, '(');

    char polish[100] = ' ';
    int rank = 0;
    int curr = 0;
    int next = infix[curr++];

    while (next != '\0')
    {
        if (top = NULL)
        {
            printf("Invalid");
            return;
        }

        while (stackPre(top->info) > inputPre(next))
        {
            char temp = pop(&top);
            strcat(polish, temp);
            rank += rnk(temp);

            if (rank < 1)
            {
                printf("Invalid");
                return;
            }
        }
        if (stackPre(top->info) != inputPre(next))
        {
            push(&top, next);
        }
        else
        {
            pop(&top);
        }

        next = infix[curr++];
    }
    if (top != NULL || rank != 1)
    {
        printf("Invalid");
    }
    else
    {
        printf("Polish");
    }
}

int main()
{
    return 0;
}