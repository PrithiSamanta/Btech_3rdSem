#include <stdio.h>
#include <stdlib.h>
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *arr = malloc(sizeof(int)*(size));
    for (int i = 0; i < size; i++)
    {
        printf("Enter array element : ");
        scanf("%d",arr+i);
    }
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
         if (*(arr+i)>*(arr+j))
         {
            int temp = *(arr+i);
            *(arr+i)=*(arr+j);
            *(arr+j)=temp;
         }
            
        }  
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",*(arr+i));
    }
    
    
    return 0;

}