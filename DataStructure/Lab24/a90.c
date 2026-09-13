#include <stdio.h>

int binarySearch(int *arr,int x,int n){
    int left=0,right=n-1;

    while (left<=right)
    {
        int middle = (left+right)/2;

        if (arr[middle]==x)
        {
            return middle;
        }
        else if (x<arr[middle])
        {
            right=middle-1;
        }
        else{
            left=middle+1;
        }
    }
    return -1;
}

int main(){
    int n, x;
    printf("Enter length of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter array elements.");
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search : ");
    scanf("%d", &x);

    int res = binarySearch(arr, x, n);

    if (res != -1)
    {
        printf("Element found at index %d\n", res);
    }
    else
    {
        printf("Elemet not found.\n");
    }
}