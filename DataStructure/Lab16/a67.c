#include <stdio.h>
#include <ctype.h>
#include <math.h>
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

int evalPostfix(char *postfix)
{
    int stack[100];
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char temp = postfix[i];
        if (isdigit(temp))
        {
            push(stack, 100, temp - '0');
        }
        else
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int val = perform_op(operand1, operand2, temp);
            push(stack, 100, val);
        }
    }
    return pop(stack);
}

int main()
{
    printf("Enter postfix expression : ");
    char postfix[100];
    scanf("%s", postfix);
    printf("%d", evalPostfix(postfix));
    return 0;
}