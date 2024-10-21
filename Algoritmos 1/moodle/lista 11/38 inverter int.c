#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void inverter(char str[]) {
    int i, j;
    for ( i = 0, j = strlen(str)-1; i < strlen(str); i++, j--)
        printf("%c", str[j]);
}

int main () {
    char str[20];
    int i = 0, n;
    do
    {
        gets(str);
        inverter(str);
        printf("\n");
        scanf("%d", &n);
    } while (n != 0);
}