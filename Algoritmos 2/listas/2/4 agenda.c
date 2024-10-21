#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100

typedef struct 
{
    char nome[MAX], rua[MAX], city[MAX], state[MAX], tel[MAX];
    int num;
} agenda;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - Remover\n3 - Listar\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 3);
    return op;
}

void incluir(char file_name[])
{
    int op;
    FILE *arq;
    agenda c;

    if ((arq = fopen(file_name,"ab")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    } else fseek (arq, 0, SEEK_END);

    do
    {
        fflush(stdin);
        printf("nome\n");
        gets(c.nome);
        printf("rua\n");
        gets(c.rua);
        printf("cidade\n");
        gets(c.city);
        printf("estado\n");
        gets(c.state);
        printf("tel\n");
        gets(c.tel);
        printf("numero\n");
        scanf("%d", &c.num);
        fwrite(&c, sizeof(agenda), 1, arq);
        printf("Adicionado com sucesso!");
        do
        {
            printf("Add mais produtos?\n1 - sim, 2 - nao\n");
            scanf("%d", &op);
        } while (op < 1 && op > 2);
        
    } while (op == 1);

    fclose(arq);
}

void consultar(char file_name[])
{
    FILE *arq;
    agenda c;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
            printf("nome: %s\n", c.nome);
            printf("tel: %s\n", c.tel);
            printf("Rua %s %d, %s, %s\n\n", c.rua, c.num, c.city, c.state);
    }

    fclose(arq);
    
    getch();
}


void apagar(char file_name[])
{
    char tel[MAX];
    FILE *aux, *arq;
    agenda c;

    if ((arq = fopen(file_name, "rb")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }
    
    aux = fopen("NOME.BAK", "wb");

    printf("Infome o tel da pessoa que deseja remover\n");
    scanf("%s", &tel);

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (strcmp(tel, c.tel))
        {
            fwrite(&c, sizeof(c), 1, aux);
        }
    }
    
    fclose(arq);
    fclose(aux);
    
    remove(file_name);
    rename("NOME.BAK", file_name);

    printf("Removido com sucesso!");
    getch();
}

int main()
{
    int op;
    char file_name[20] = "agenda.dat";

    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(file_name);
        else if (op == 2) apagar(file_name);
        else if (op == 3) consultar(file_name);
        system("cls");
    } while (op);
    
    return 0;
}
