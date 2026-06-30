#include <stdio.h>

int main()
{
    printf("Enter a number : ");
    int n, flag = 1;
    scanf("%d", &n);
    for (int i = 2; i < n/2; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("The number is prime");
    }
    else
    {
        printf("The number is not prime");
    }

    return 0;
}