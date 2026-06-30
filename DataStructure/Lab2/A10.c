#include <stdio.h>

int main(){
    printf("Enter number : ");
    int n,d,ans=0;
    scanf("%d",&n);
    while (n!=0)
    {
        d = n%10;
        ans = ans*10 +d;
        n/=10;
    }
    printf("The reverse num is %d",ans);
    return 0;
}