#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void main(){
    printf("Enter number of words : ");
    int n;
    scanf("%d",&n);
    char words[n][100];
    printf("Enter words in lower case\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter word %d : ",i+1);
        scanf("%s",words[i]);
    }
    srand(time(NULL));
    int random = rand() %n;
    printf("Enter anagram of %s : ",words[random]);
    char anaWord[100];
    scanf("%s",anaWord);
    int freq1[26],freq2[26];
    for (int i = 0; i < 26; i++)
    {
        freq1[i]=0;
        freq2[i]=0;
    }
    for (int i = 0;i<strlen(words[random]); i++)
    {
        freq1[words[random][i]-'a']++;
    }
    for (int i = 0; i<strlen(anaWord); i++)
    {
        freq2[anaWord[i]-'a']++;
    }
    int flag=1;
    for (int i = 0; i < strlen(words[random]); i++)
    {
        if (freq1[i]!=freq2[i])
        {
            flag=0;
            break;
        }
        
    }
    
    if (flag)
    {
        printf("It is a anagram.");
    }
    else{
        printf("It is not a anagram.");
    }
}