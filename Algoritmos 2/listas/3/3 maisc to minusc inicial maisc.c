#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    char c[401], nome[30];
    int i = 0, maisc = 0, j;

    //printf("Nome do arq\n");
    //gets(nome);

    if ((arq = fopen("texto.txt", "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
   while (fgets(c, 400, arq) != NULL)
    {
        for ( j = 0; j < strlen(c); j++)
        {
            if (c[j] != EOF)
            {
            if (c[j] == '.' || c[j] == '!' || c[j] == '?') maisc = 1;
            if (i == 0) printf("%c", toupper(c[j]));
            else if (maisc)
            {
                if (tolower(c[j]) >= 'a' && tolower(c[j]) <= 'z') maisc = 0;
                printf("%c", toupper(c[j]));
            } else printf("%c", tolower(c[j]));
            i++;
            }
        }
        
    }

    fclose(arq);
    return 0;
}
