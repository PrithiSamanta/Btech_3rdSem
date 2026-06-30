#include <stdio.h>

int main()
{
    printf("Enter size of array : ");
    int size;
    scanf("%d", &size);
    int arr[size + 1];
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to inserted and its index : ");
    int val, index;
    scanf("%d %d", &val, &index);
    for (int i = size; i < index; i++)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = val;
    for (int i = 0; i < size + 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}