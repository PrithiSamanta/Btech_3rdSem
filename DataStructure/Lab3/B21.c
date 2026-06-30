#include <stdio.h>

int main(){
    printf("Enter size of array : ");
    int n;
    scanf("%d", &n);
    int arr[n],n1,n2;
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : ");
        scanf("%d", &arr[i]);
    }
    printf("Enter a number you want to replace and another number you want to replace with : ");
    scanf("%d %d",&n1,&n2);
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==n1)
        {
            arr[i]=n2;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d,",arr[i]);
    }

    return 0;
    
}