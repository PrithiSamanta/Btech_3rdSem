#include <stdio.h>

void main(){
    int a[2][2],b[2][2],c[2][2];
    printf("Enter matrix 1 values\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter matrix element. ");
        scanf("%d",&a[i][j]);
        }
        
    }
    printf("Enter matrix 2 values\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter matrix element. ");
        scanf("%d",&b[i][j]);
        }
        
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
        
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    
    
    
}