#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[20], c;
    int i = 0, n;
    do
    {
        gets(str);
        scanf("%c", &c);
        i = -(str-strchr(str,c));
        printf("%d\n", i);
        scanf("%d", &i);
        printf("%c", str[i]);
        scanf("%d", &n);
    } while (n != 0);
}