#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strrev(char* str){
    char temp;
    for (int i = 0; i < strlen(str)/2; i++)
    {
        temp = *(str+i);
        *(str+i)=*(str + strlen(str)-i-1);
        *(str+strlen(str)-i-1)=temp;
    }
    
}
int main(){
    char *str = malloc(sizeof(char)*100);
    char *revstr=malloc(sizeof(char)*100);
    printf("Enter string : ");
    scanf("%s",str);
    strcpy(revstr,str);
    strrev(revstr);
    if (strcmp(str,revstr)==0)
    {
        printf("The string is palindrome.");
    }
    else{
        printf("String is not palindrome");
    }
    
    return 0;
}