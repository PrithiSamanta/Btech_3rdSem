#include <stdio.h> 
int main(){
    printf("Enter size of array : ");
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the index of the element to be deleted : ");
    int index;
    scanf("%d",&index);
    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    for (int i = 0; i < size ; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}