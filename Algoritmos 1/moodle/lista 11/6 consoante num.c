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
    int i, n, vogal;
    do
    {
        gets(str);
        stringMin(str);
        vogal = contaVog(str, 'a') + contaVog(str, 'i') + contaVog(str, 'e') + contaVog(str, 'o') + contaVog(str, 'u');
        printf("consoantes: %d\n", strlen(str) - vogal);
        printf("\n");
        scanf("%d", &n);
    } while (n != 0);
    
}