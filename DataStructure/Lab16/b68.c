#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
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

int perform_op(int op1, int op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    case '^':
        return (int)pow(op1, op2);
        break;
    default:
        break;
    }
}

int evalPrefix(char *postfix)
{
    int stack[100];
    for (int i = strlen(postfix) - 1; i >= 0; i--)
    {
        char temp = postfix[i];
        if (isdigit(temp))
        {
            push(stack, 100, temp - '0');
        }
        else
        {
            int operand1 = pop(stack);
            int operand2 = pop(stack);
            int val = perform_op(operand1, operand2, temp);
            push(stack, 100, val);
        }
    }
    return pop(stack);
}

int main()
{
    printf("Enter prefix expression : ");
    char prefix[100];
    scanf("%s", prefix);
    printf("%d", evalPrefix(prefix));
    return 0;
}