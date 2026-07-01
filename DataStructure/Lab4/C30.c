#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter a string : ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 65 && str[i] <= 91)
        {
            str[i] = str[i] + 32;
        }
        else if (str[i] >= 97 && str[i] <= 123)
        {
            str[i] = str[i] - 32;
        }
    }
    printf("%s", str);

    return 0;
}