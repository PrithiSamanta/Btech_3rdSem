#include <stdio.h>

int main(){
    printf("Enter size of array : ");
    int n;
    scanf("%d",&n);
    int arr[n],lar=0,sm=0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : ");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>arr[lar])    
        {
            lar = i;
        }
        if (arr[i]<arr[sm])
        {
            sm=i;
        }
        
        
    }
    printf("The index of largest is %d smallest is %d",lar,sm);
    

}