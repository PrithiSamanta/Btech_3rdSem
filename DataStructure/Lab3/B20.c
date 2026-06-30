#include <stdio.h>

int main()
{
    printf("Enter size of array : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : ");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("It has duplicate elements.");
                return 0;
            }
        }
    }
    printf("It has not duplicate elements");
}