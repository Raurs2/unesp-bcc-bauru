#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[20];
    int i, n, num[20], d;
    do
    {
        gets(str);
        if (!strcmp(str, "ALGI")) printf("Acesso Permitido\n");
        else printf("Acesso negado\n");
        scanf("%d", &n);
    } while (n != 0);
}