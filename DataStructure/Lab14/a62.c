#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
char *display(struct Node **top)
{
    char str[100];
    struct Node *curr = *top;
    for (int i = 0; curr != NULL; i++)
    {
        str[i] = curr->info;
        curr = curr->link;
    }
    return str;
}
char *rev(char *str)
{
    char revstr[100];
    for (int i = 0; i < strlen(str); i++)
    {
        revstr[i] = str[strlen(str) - 1 - i];
    }
    return revstr;
}
char *removeStar(char *str)
{
    struct Node *top = NULL;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '*')
        {
            push(&top, str[i]);
        }
        else
        {
            pop(&top);
        }
    }
    return rev(display(&top));
}
 
int main()
{
    char str[100];
    printf("Enter string : ");
    scanf("%s", str);
    printf("%s", removeStar(str));
    return 0;
}
