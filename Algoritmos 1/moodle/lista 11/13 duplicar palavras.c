#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main () {
    char str[20], str2[20];
    char *c;
    int i = 0, n;
    do
    {
        gets(str);
        c = strtok (str," .,-");
        while (c != NULL) {
            printf("%s %s", c, c);
            c = strtok(NULL," .,-");
            printf(" ");
        }
        printf("\n");
        scanf("%d", &n);
    } while (n != 0);
}