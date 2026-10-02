#include <stdio.h>

void merge(int *arr, int low, int mid, int high)
{
    int h, i, j, k, b[high - low + 1];

    h = low;
    i = low;
    j = mid + 1;

    while (h <= mid && j <= high)
    {
        if (arr[h] <= arr[j])
        {
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (k = j; k < high; k++)
        {
            b[i] = arr[k];
            i++;
            ;
        }
    }
    else
    {
        for (k = h; k < mid; k++)
        {
            b[i] = arr[k];
            i++;
            ;
        }
    }

    for (k = low; k < high; k++)
    {
        arr[k] = b[k];
    }
}

void mergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n+1);

    printf("Sorted array is : ");

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i])
    }
}