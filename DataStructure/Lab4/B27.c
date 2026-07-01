#include <stdio.h>
#include <string.h>
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d",&arr[i]);
    }
    
    int ele;
    printf("Enter the element to be deleted : ");
    scanf("%d",&ele);
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i]==ele)
        {
            for (int j = i; j < size-1; j++)
            {
                arr[j]=arr[j+1];
            }
            
        }
        
    }
    size--;
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",arr[i]);
    }
    
    return 0;
}