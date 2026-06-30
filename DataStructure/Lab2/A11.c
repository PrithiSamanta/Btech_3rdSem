#include <stdio.h>

int main(){
    printf("Enter a number : ");
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        if (n%i==0)
        {
            printf("%d,",i);
        }
        
    }
    
    return 0 ;
}