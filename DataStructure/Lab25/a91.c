#include <stdio.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    bubbleSort(arr, n);

    printf("Sorted array is : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}