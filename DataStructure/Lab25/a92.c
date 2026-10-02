#include <stdio.h>

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int minIndex = i;

        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

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
    selectionSort(arr, n);

    printf("Sorted array is : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}