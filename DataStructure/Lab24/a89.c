#include <stdio.h>

int search(int *arr,int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter length of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array elements.");
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search : ");
    scanf("%d", &x);

    int res = search(arr, x, n);

    if (res != -1)
    {
        printf("Element found at index %d\n", res);
    }
    else
    {
        printf("Elemet not found.\n");
    }
}