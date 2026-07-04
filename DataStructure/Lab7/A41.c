#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *link;
    
};
int main(){

    struct Node *first = (struct Node*)(malloc(sizeof(struct Node)));
    
    printf("Enter element of the node.");
    int x;
    scanf("%d",&x);
    first->info = x;
    first->link=NULL;
    printf("%d",first->info);
    free(first);
    return 0;
}
