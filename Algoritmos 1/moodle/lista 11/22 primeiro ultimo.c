#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[15];
    int i = 0, n;
    do
    {
        gets(str);
        printf("%c%c\n", str[0], str[strlen(str)-1]);
        scanf("%d", &n);
    } while (n != 0);
}