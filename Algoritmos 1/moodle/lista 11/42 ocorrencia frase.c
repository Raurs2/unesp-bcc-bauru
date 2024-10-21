#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int frase(char str[], char str2[]) {
    char *c, *txt;
    int d = 0;
    c = strtok (str," .,-");
    while (c != NULL) {
        txt = strstr(c, str2);
        if (txt != NULL) d++;
        c = strtok(NULL," .,-");
    }
}

int main () {
    char str[50], c[50];
    int i = 0, n, d = 0;
    do
    {
        scanf("%s ", &c);
        gets(str);
        printf("%d\n", frase(str, c));
        scanf("%d", &n);
    } while (n != 0);
}