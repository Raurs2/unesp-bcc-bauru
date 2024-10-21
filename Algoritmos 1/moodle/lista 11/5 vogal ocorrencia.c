#include <stdio.h>
#include <string.h>
#include <ctype.h>

void stringMin(char str[]) {
    int i;
    for ( i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int contaVog(char str[], char vogal) {
    int i, j, n = 0;
    for ( i = 0; i < strlen(str); i++)
            if (vogal == str[i]) n++;
    return n;
}

int main () {
    char str[20];
    int i, n;
    do
    {
        gets(str);
        stringMin(str);
        printf("a: %d\n", contaVog(str, 'a'));
        printf("i: %d\n", contaVog(str, 'i'));
        printf("e: %d\n", contaVog(str, 'e'));
        printf("o: %d\n", contaVog(str, 'o'));
        printf("u: %d\n", contaVog(str, 'u'));
        printf("\n");
        scanf("%d", &n);
    } while (n != 0);
    
}