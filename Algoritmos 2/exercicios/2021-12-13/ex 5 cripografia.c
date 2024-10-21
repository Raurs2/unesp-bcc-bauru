#include <stdio.h>
#include <ctype.h>
#include <string.h>

void criptografar(char name[])
{
    FILE *arq, *arq2;
    char tex[101];
    int i;
    
    if ((arq = fopen(name, "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    if ((arq2 = fopen("novo.txt", "wt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    while (strlen(gets(tex)) > 0)
    {
        for ( i = 0; i < strlen(tex); i++)
        {
            tex[i] = tex[i] + 2;
        }
        
        fputs(tex, arq2);
        putc('\n', arq2);
    }

    fclose(arq);
    fclose(arq2);
    getch();
}

void descriptografar(char name[])
{
    FILE *arq;
    char tex[101];
    int i;

    if ((arq = fopen(name, "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    while (fgets(tex, 100, arq) != NULL)
    {
        for ( i = 0; i < strlen(tex); i++)
        {
            printf("%c", tex[i] - 2);
        }
        printf("\n");
    }
    
    fclose(arq);
    getch();
}

int main()
{
    int op, i, j;
    char name[30] = "cripto.txt";

    do
    {
        do
        {
            printf("1 - cripto\n2 - descripto\n3 - sair\n");
            scanf("%d", &op);
            fflush(stdin);
        } while (op < 1 || op > 3);
        
        if (op == 3) break;
        else if (op == 1) criptografar(name);
        else if (op == 2) descriptografar(name);
        
    } while (1);
    
    return 0;
}
