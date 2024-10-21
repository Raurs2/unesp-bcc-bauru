#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int menorPalavra(char str[], char menor[]) {
    char *c;
    int i = 0, j = 1, n = 0, d= 0;
    c = strtok (str," .,-");
    strcpy(menor, c);
        while (c != NULL) {
            if (strlen(c) < strlen(menor)) strcpy(menor, c);
            c = strtok(NULL," .,-");
        }
        
    return n;
}

int main () {
    char str[20], menor[20];
    int i, n;
    do
    {
        gets(str);
        stringMin(str);
        menorPalavra(str, menor);
        printf("%s\n", menor);
        scanf("%d", &n);
    } while (n != 0);
}