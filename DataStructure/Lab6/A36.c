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
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i);
    }
    printf("The sum of all elements in the array is %d\n", sum);
    return 0;
}