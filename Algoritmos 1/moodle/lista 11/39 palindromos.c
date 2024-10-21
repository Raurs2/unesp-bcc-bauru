#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int palindromo(char str[], char str2[], int i)
{
    if (strlen(str) == i)
    {
        str2[i] = '\0';
        if (!strcmp(str, str2)) return 1;
        else return 0;
    } else
    {
        str2[i] = str[strlen(str) - 1 - i];
        return palindromo(str, str2, i + 1);
    }
}

int main () {
    char str[50], str2[50];
    int i = 0, n;
    do
    {
        scanf("%s", &str);

        if (palindromo(str, str2, i)) printf("eh palindromo\n");
        else printf("n eh palindromo\n");
        printf("1 - %s\n2 - %s\n", str, str2);
        
        printf("Dnv?\n");
        scanf("%d", &n);
    } while (n != 0);
}