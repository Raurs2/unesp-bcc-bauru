#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX 20

typedef struct 
{
    int id, qtd;
    char nome[20];
    double custo_uni;
} estoque;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - Remover\n3 - Consultar por nome\n4 - Alterar registros\n5 - Gerar relatorio\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 5);
    return op;
}

void incluir(char file_name[])
{
    int op;
    FILE *arq;
    estoque c;

    if ((arq = fopen(file_name,"ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("id\n");
                scanf("%d", &c.id);
                printf("nome\n");
                scanf("%s", &c.nome);
                printf("custo unidade\n");
                scanf("%lf", &c.custo_uni);
                printf("quantidade\n");
                scanf("%d", &c.qtd);
                fwrite(&c, sizeof(estoque), 1, arq);
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
    estoque c;
    char nome[20];

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    printf("Qual nome quer consultar?\n");
    scanf("%s", &nome);
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (!strcmp(c.nome, nome))
        {
            printf("Id: %d\n", c.id);
            printf("nome: %s\n", c.nome);
            printf("custo unitario: %lf\n", c.custo_uni);
            printf("quantidade: %d\n\n", c.qtd);
        } else printf("Registro nao encontrado\n");
    }

    fclose(arq);
    
    getch();
}

void alterar(char file_name[])
{
    FILE *arq;
    estoque c;
    int id, achou = 0;

    if ((arq = fopen(file_name, "r+b")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }
    
    printf("Infome o ID do produto que deseja alterar\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1 && !achou)
    {
        if (c.id == id)
        {
            printf("id\n");
            scanf("%d", &c.id);
            printf("nome\n");
            scanf("%s", &c.nome);
            printf("custo unidade\n");
            scanf("%lf", &c.custo_uni);
            printf("quantidade\n");
            scanf("%d", &c.qtd);
            fseek(arq, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(estoque), 1, arq);
            fflush(arq);
            achou = 1;
            printf("Alterado com sucesso!\n");
        }
    }
    
    fclose(arq);

    if (!achou)
    {
        printf("Produto nao registrado\n");
    }

    getch();
}

void apagar(char file_name[])
{
    int id;
    FILE *aux;
    FILE *arq;
    estoque c;
    if ((arq = fopen(file_name, "rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }
    
    aux = fopen("NOME.BAK", "wb");

    printf("Infome o ID do produto que deseja remover\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (id != c.id)
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

void gerar_relatorio(char file_name[20])
{
    FILE *arq;
    estoque c;
    int i = 0;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }
    
    int op;
    do
    {
        printf("1 - todos, 2 - em falta\n");
        scanf("%d", &op);
    } while (op < 1 || op > 2);
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (op == 1)
        {
            printf("Id: %d\n", c.id);
            printf("nome: %s\n", c.nome);
            printf("custo unitario: %lf\n", c.custo_uni);
            printf("quantidade: %d\n\n", c.qtd);
        } else if (c.qtd == 0)
        {
            printf("Id: %d\n", c.id);
            printf("nome: %s\n", c.nome);
            printf("custo unitario: %lf\n", c.custo_uni);
            printf("quantidade: %d\n\n", c.qtd);
        }
    }
    getch();
    fclose(arq);
}

int main()
{
    int op;
    char file_name[20] = "estoque.dat";
    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(file_name);
        else if (op == 2) apagar(file_name);
        else if (op == 3) consultar(file_name);
        else if (op == 4) alterar(file_name);
        else if (op == 5) gerar_relatorio(file_name);
        system("cls");
    } while (op);
    
    return 0;
}
