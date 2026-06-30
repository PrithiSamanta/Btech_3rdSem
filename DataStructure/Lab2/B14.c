#include <stdio.h>

int main(){
    printf("Enter n : ");
    int n,ans=0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        ans+= i*(i+1)/2;
    }
    printf("Ans is %d",ans);

    return 0;
}