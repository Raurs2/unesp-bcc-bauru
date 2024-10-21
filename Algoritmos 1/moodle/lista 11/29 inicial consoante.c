#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int palavrasConso(char str[]) {
    char *c;
    int i = 0;
    c = strtok (str," .,-");
        while (c != NULL) {
            if (c[0] != 'a' && c[0] != 'e' && c[0] != 'i' && c[0] != 'o' && c[0] != 'u') i++;
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
        stringMin(str);
        i = palavrasConso(str);
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}