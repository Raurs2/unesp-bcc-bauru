#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20

int main () {
    char a[MAX];
    int n, d;
    do
    {
        scanf("%d", &d);
        itoa(d, a, 2);
        printf("%s\n", a);
        scanf("%d", &n);
    } while (n != 0);
}