#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter size of array : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d", arr + i);
    }
    int lar = *arr;
    for (int i = 1; i < size; i++)
    {
        if (lar < *(arr + i))
        {
            lar = *(arr + i);
        }
    }
    printf("The largest element in the array is %d\n", lar);
    return 0;
}