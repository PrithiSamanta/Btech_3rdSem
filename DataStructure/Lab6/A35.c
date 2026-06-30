#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter size of array : ");
    int size;
    scanf("%d",&size);
    int *arr=malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d",arr+i);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",*(arr+i));
    }
    return 0;
}