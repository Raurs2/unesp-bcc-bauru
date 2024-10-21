#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int MaiorPalavra(char str[], char maior[]) {
    char *c;
    int i = 0, j = 1, n = 0, d= 0;
    c = strtok (str," .,-");
    strcpy(maior, c);
        while (c != NULL) {
            if (strlen(c) > strlen(maior)) strcpy(maior, c);
            c = strtok(NULL," .,-");
        }
        
    return n;
}

int main () {
    char str[20], maior[20];
    int i, n;
    do
    {
        gets(str);
        stringMin(str);
        MaiorPalavra(str, maior);
        printf("%s\n", maior);
        scanf("%d", &n);
    } while (n != 0);
}