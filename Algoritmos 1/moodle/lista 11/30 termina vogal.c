#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int palavrasVog(char str[]) {
    char *c;
    int i = 0;
    c = strtok (str," .,-");
        while (c != NULL) {
            if (c[strlen(c)-1] == 'a' || c[strlen(c)-1] == 'e' || c[strlen(c)-1] == 'i' || c[strlen(c)-1] == 'o' || c[strlen(c)-1] == 'u') i++;
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
        i = palavrasVog(str);
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}