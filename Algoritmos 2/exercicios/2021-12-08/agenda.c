#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100

typedef struct 
{
    char nome[MAX], tel[MAX];
    int d, m, a;
} agenda;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - Remover\n3 - Listar\n4 - Pesquisa por nome\n5 - listar por inicial\n6 - aniversariantes\n7 - alterar telefone\n0 - Sair\n");
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
        printf("tel\n");
        gets(c.tel);
        printf("Dia, mes, ano niver\n");
        scanf("%d %d%d", &c.d, &c.m, &c.a);
        fwrite(&c, sizeof(agenda), 1, arq);
        printf("Adicionado com sucesso!");
        do
        {
            printf("Add mais contatos?\n1 - sim, 2 - nao\n");
            scanf("%d", &op);
        } while (op < 1 && op > 2);
        
    } while (op == 1);

    fclose(arq);
}

void listar(char file_name[])
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
            printf("data de nascimento %d/%d/%d\n", c.d, c.m, c.a);
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

void pesquisar(char file_name[])
{
    FILE *arq;
    agenda c;
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
            printf("NOme: %s\n", c.nome);
            printf("tel: %s\n", c.tel);
            printf("nasceu em: %d/%d/%d\n", c.d, c.m, c.a);
        }
    }

    fclose(arq);
    
    getch();
}

void listar_inicial(char file_name[])
{
    FILE *arq;
    agenda c;
    char inicial;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    printf("Qual letra quer consultar?\n");
    scanf("%s", &inicial);
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (inicial == c.nome[0])
        {
            printf("NOme: %s\n", c.nome);
            printf("tel: %s\n", c.tel);
            printf("nasceu em: %d/%d/%d\n", c.d, c.m, c.a);
        }
    }

    fclose(arq);
    
    getch();
}

void aniversariantes(char file_name[])
{
    FILE *arq;
    agenda c;
    int m;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    printf("Qual mes?\n");
    scanf("%d", &m);
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (m == c.m)
        {
            printf("NOme: %s\n", c.nome);
            printf("tel: %s\n", c.tel);
            printf("nasceu em: %d/%d/%d\n", c.d, c.m, c.a);
        }
    }

    fclose(arq);
    
    getch();
}

void alterar(char file_name[])
{
    FILE *arq;
    agenda c;
    int achou = 0;
    char tel[20];

    if ((arq = fopen(file_name, "r+b")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }
    
    printf("Infome o tel que deseja alterar\n");
    scanf("%s", &tel);

    while (fread(&c, sizeof(c), 1, arq) == 1 && !achou)
    {
        if (!strcmp(tel, c.tel))
        {
            printf("novo tel\n");
            scanf("%s", &c.tel);
            fseek(arq, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(agenda), 1, arq);
            fflush(arq);
            achou = 1;
            printf("Alterado com sucesso!\n");
        }
    }
    
    fclose(arq);

    if (!achou)
    {
        printf("contato nao registrado\n");
    }

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
        //printf("1 - Incluir\n2 - Remover\n3 - Listar\n4 - Pesquisa por nome\n5 - listar por inicial\n6 - aniversariantes\n7 - alterar telefone\n0 - Sair\n");
        if (op == 1) incluir(file_name);
        else if (op == 2) apagar(file_name);
        else if (op == 3) listar(file_name);
        else if (op == 4) pesquisar(file_name);
        else if (op == 5) listar_inicial(file_name);
        else if (op == 6) aniversariantes(file_name);
        else if (op == 7) alterar(file_name);
        system("cls");
    } while (op);
    
    return 0;
}
