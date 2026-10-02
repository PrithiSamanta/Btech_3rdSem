#include <stdio.h>

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j > 0 && arr[j] > key)
        {
            if (arr[j] > key)
            {
                arr[i] = arr[j];
            }
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    printf("Sorted array is : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
}