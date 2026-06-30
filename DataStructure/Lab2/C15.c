#include <stdio.h>
#include <math.h>

int main(){

    int digits,digit,n;
    double ans;

    for (int i = 1; i <= 1000; i++)
    {
        digits=0;
        ans=0;
        n=i;
        while (n!=0)
        {
            n/=10;
            digits++;
        }
        n=i;
        while (n!=0)
        {
            digit =n%10;
            ans+= pow((double)digit,(double)digits);
            n/=10;
        }
        if (ans==i)
        {
            printf("%d,",i);
        }
        
        
    }
    

    return 0;
}