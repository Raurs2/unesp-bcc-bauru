#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int palavras(char str[]) {
    char *c;
    int i = 0;
    c = strtok (str," .,-");
        while (c != NULL) {
            i++;
            c = strtok(NULL," .,-");
        }
    return i;
}

int main () {
    char str[20];
    int i, n;
    do
    {
        gets(str);
        i = palavras(str);
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}