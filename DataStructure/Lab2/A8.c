#include <stdio.h>

int fact(int n){
    if (n==1)
    {
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    printf("Enter a number : ");
    int n;
    scanf("%d",&n);
    int ans=1;
    for (int i = 1; i <= n; i++)
    {
        ans*=i;
    }
    printf("The factorial of %d is %d\n",n,ans);
    printf("The factorial of %d is %d",n,fact(n));
    return 0;
}

