#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int letrasMaisc(char str[]) {
    int i, n = 0;
    for ( i = 0; i < strlen(str); i++)
        if (isupper(str[i])) n++;
    return n;
}

int main () {
    char str[20];
    char *c;
    int i = 0, n;
    do
    {
        gets(str);
        printf("%d\n", letrasMaisc(str));
        scanf("%d", &n);
    } while (n != 0);
}