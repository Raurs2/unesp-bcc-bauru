#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    char str[20];
    char *c;
    int i = 0, n;
    do
    {
        i = 0;
        gets(str);
        c = strtok (str," .,-");
        while (c != NULL) {
            i++;
            c = strtok(NULL," .,-");
        }
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}