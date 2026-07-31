#include <stdio.h>

#define size 100
int stack[size];
int top = -1;

void push(int val)
{
    if (top >= size)
    {
        printf("Stack Overflow.\n");
        return;
    }
    else
    {
        stack[++top] = val;
    }
}

int pop()
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

int peek()
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

void canSorted(int a[], int n, int b[])
{
    int j=0,isSorted=1;
    for (int i = 0; i < n; i++)
    {
        if (top == -1)
        {
            push(a[i]);
        }
        else{
            if (peek() < a[i])
            {
                b[j++]=pop();
            }
            else{
                push(a[i]);
            }
        }
        if (j>1)
        {
            if (b[j]<b[j-1])
            {
                isSorted=0;
                return;
            } 
        }
    }
    if (isSorted)
    {
        printf("YES");
    }
    else{
        printf("NO");
    }
    
}

int main()
{
    int n;
    printf("Enter size : ");
    scanf("%d",&n);
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    canSorted(a,n,b);
    return 0;
}