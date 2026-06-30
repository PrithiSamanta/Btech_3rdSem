#include <stdio.h>

int main()
{
    printf("Enter the interval : ");
    int n1, n2,flag=1;
    scanf("%d %d", &n1, &n2);
    for (int i = n1; i <= n2; i++)
    {
        flag=1;
        for (int j = 2; j < i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d,",i);
        }
    }

    return 0;
}