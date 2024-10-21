#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
    char str[10];
    int i, n;
    do
    {
        gets(str);
        for ( i = 0; i < strlen(str); i++)
            printf("%c", toupper(str[i]));
        printf("\n");
        for ( i = 0; i < strlen(str); i++)
            printf("%c", tolower(str[i]));
        printf("\n");
        scanf("%d", &n);
    } while (n != 0);
    
}