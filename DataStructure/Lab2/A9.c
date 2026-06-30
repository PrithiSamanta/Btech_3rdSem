#include <stdio.h>

int main(){
    printf("Enter base and power : ");
    int x,y,ans=1;
    scanf("%d %d",&x,&y);
    for (int i = 0; i < y; i++)
    {
        ans*=x;
    }
    printf("Ans is %d",ans);
    return 0;
}