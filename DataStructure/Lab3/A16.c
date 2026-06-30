#include <stdio.h>

int main(){
    printf("Enter size of array : ");
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : ");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d,",arr[i]);
    }
    

    return 0;
}