#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    char c, nome[30];
    int i = 0, maisc = 0;

    //printf("Nome do arq\n");
    //gets(nome);

    if ((arq = fopen("texto.txt", "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while ((c = getc(arq)) != EOF)
    {
        if (c != EOF)
        {
            if (c == '.') maisc = 1;
            if (i == 0) printf("%c", toupper(c));
            else if (maisc)
            {
                if (tolower(c) >= 'a' && tolower(c) <= 'z') maisc = 0;
                printf("%c", toupper(c));
            } else printf("%c", c);
            i++;
        }
    }

    fclose(arq);
    
    return 0;
}
