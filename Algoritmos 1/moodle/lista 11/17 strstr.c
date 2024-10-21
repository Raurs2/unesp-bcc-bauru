#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[20], str2[20];
    int i = 0, n;
    do
    {
        gets(str);
        gets(str2);
        i = -(str-strstr(str, str2));
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}