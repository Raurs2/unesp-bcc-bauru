#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int numExtenso(char str[], int n[]) {
    char *c;
    int i = 0;
    c = strtok (str," .,-");
        while (c != NULL) {
            if (!strcmp(c, "zero")) n[i] = 0;
            if (!strcmp(c, "um")) n[i] = 1;
            if (!strcmp(c, "dois")) n[i] = 2;
            if (!strcmp(c, "tres")) n[i] = 3;
            if (!strcmp(c, "quatro")) n[i] = 4;
            if (!strcmp(c, "cinco")) n[i] = 5;
            if (!strcmp(c, "seis")) n[i] = 6;
            if (!strcmp(c, "sete")) n[i] = 7;
            if (!strcmp(c, "oite")) n[i] = 8;
            if (!strcmp(c, "nove")) n[i] = 9;
            c = strtok(NULL," .,-");
            i++;
        }
        return i;
}

int main () {
    char str[20];
    int i, n, num[20], d;
    do
    {
        gets(str);
        stringMin(str);
        d = numExtenso(str, num);
        for ( i = 0; i < d; i++)
        {
            printf("%d", num[i]);
        }
        
        scanf("%d", &n);
    } while (n != 0);
}