#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

int main () {
    char str[MAX], *txt, str2[MAX];
    int n;
    do
    {
        gets(str);
        fseek(stdin, 0, SEEK_END);
        gets(str2);
        txt = strstr(str, str2);
        if (txt != NULL) printf("Esta na cadeia de caracteres\n");
        else printf("nao esta na string\n");
        scanf("%d", &n);
    } while (n != 0);
}