#include <stdio.h>
int main()
{
    int size;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d", &i[arr]);
    }
    size++;
    int n;
    printf("Enter the element to be inserted : ");
    scanf("%d", &n);
    for (int i = 0; i < size; i++)
    {
        if (n < arr[i])
        {
            for (int j = size - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[i] = n;
            break;
        }
        if (i == size - 1)
        {
            arr[i] = n;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}