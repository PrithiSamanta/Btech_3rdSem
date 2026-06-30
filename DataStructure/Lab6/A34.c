#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a=(int*)(malloc(sizeof(int)));
    char *c=(char *)(malloc(sizeof(char)));
    float *f=(float *)(malloc(sizeof(float)));
    free(a);
    free(c);
    free(f);

    return 0;

}