#include <stdio.h>

int main()
{
    printf("Enter number of rows : ");
    int n;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}