#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[50], c;
    int i = 0, n, d = 0;
    do
    {
        d = 0;
        scanf("%c ", &c);
        gets(str);
        for ( i = 0; i < strlen(str); i++)
            if (tolower(str[i]) == tolower(c)) d++;
        printf("%d\n", d);
        scanf("%d", &n);
    } while (n != 0);
}