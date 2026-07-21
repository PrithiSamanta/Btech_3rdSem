#include <stdio.h>
int top = -1;
void push(int stack[], int size, int val)
{
    if (top >= size - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    else
    {
        stack[++top] = val;
    }
}

int pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        return stack[top--];
    }
}

void dispStack(int stack[])
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d, ", stack[i]);
    }
}

int peep(int stack[])
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        return stack[top];
    }
}

void change(int stack[], int idx, int val)
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
    }
    else if (idx > top || idx < 0)
    {
        printf("The index does not exist.\n");
    }
    else
    {
        stack[idx] = val;
    }
}

int main()
{
    printf("Enter size of stack : ");
    int size;
    scanf("%d", &size);
    int stack[size];
    push(stack, size, 10);
    push(stack, size, 20);
    push(stack, size, 30);
    push(stack, size, 40);
    push(stack, size, 50);
    change(stack, 6, 99);
    // printf("%d",pop(stack));
    dispStack(stack);
    return 0;
}