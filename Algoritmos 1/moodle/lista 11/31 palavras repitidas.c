#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int palavraRept(char str[]) {
    char *c[20];
    int i = 0, j = 1, n = 0, d= 0;
    c[0] = strtok (str," .,-");
        while (c != NULL) {
            d++;
            c[d] = strtok(NULL," .,-");
        }
        for ( i = 0; i < d; i++)
        {
            for ( j = 0; j < d; j++)
            {
                if (c[j] == c[i]) n++;
            }
            
        }
        
    return n;
}

int main () {
    char str[20];
    int i, n;
    do
    {
        gets(str);
        stringMin(str);
        i = palavraRept(str);
        printf("%d\n", i);
        scanf("%d", &n);
    } while (n != 0);
}