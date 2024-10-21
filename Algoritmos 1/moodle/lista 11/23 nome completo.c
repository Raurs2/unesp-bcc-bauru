#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

int main () {
    char first[MAX], last[MAX], name[40];
    int n;
    do
    {
        scanf("%s %s", &first, &last);
        strcpy(name, "");
        strcat(name, first);
        strcat(name, " ");
        strcat(name, last);
        printf("%s\n", name);
        scanf("%d", &n);
    } while (n != 0);
}