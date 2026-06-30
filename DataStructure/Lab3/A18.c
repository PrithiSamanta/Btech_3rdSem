#include <stdio.h>

int main(){
    printf("Enter size of array : ");
    int n;
    scanf("%d",&n);
    int arr[n],sum=0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter array element : ");
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    printf("The average of all elements of array is %0.2f",(double)sum/n);
}