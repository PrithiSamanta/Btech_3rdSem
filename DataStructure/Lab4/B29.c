#include <stdio.h>
int main(){
    int size1,size2;
    printf("Enter size of array 1 and 2 :  ");
    scanf("%d %d",&size1,&size2);
    int arr1[size1],arr2[size2];
    for (int i = 0; i < size1; i++)
    {
        printf("Enter array 1 element : ");
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        printf("Enter array 2 element : ");
        scanf("%d", &arr2[i]);
    }
    int arr3[size1+size2];
    for (int i = 0; i < size1+size2; i++)
    {
        if (i<size1)
        {
            arr3[i]=arr1[i];
        }
        
        else{
            arr3[i] = arr2[i-size1];
        }
    }
    for (int i = 0; i < size1+size2; i++)
    {
        printf("%d, ", arr3[i]);
    }
    return 0;
}