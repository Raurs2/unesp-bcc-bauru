#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct 
{
    char nome[20], curso[20];
    double p1, p2, mt, freq;
    int num;
} aluno;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - Remover\n3 - Consultar por num\n4 - Alterar registros\n5 - listar\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 5);
    return op;
}

void incluir(char file_name[])
{
    int op;
    FILE *arq;
    aluno c;

    if ((arq = fopen(file_name,"ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                //NOME, NUMERO, CURSO, P1,
//P2, MT e FREQUÊNCIA
                printf("num\n");
                scanf("%d", &c.num);
                printf("nome\n");
                scanf("%s", &c.nome);
                printf("curso\n");
                scanf("%s", &c.curso);
                printf("p1\n");
                scanf("%lf", &c.p1);
                printf("p2\n");
                scanf("%lf", &c.p2);
                printf("frequencia\n");
                scanf("%lf", &c.freq);
                printf("mt\n");
                scanf("%lf", &c.mt);
                fwrite(&c, sizeof(aluno), 1, arq);
                printf("Adicionado com sucesso!");
                do
                {
                    printf("Add mais aluno?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq);
}

void consultar(char file_name[])
{
    FILE *arq;
    aluno c;
    int num;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    printf("Qual num quer consultar?\n");
    scanf("%d", &num);
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (num == c.num)
        {
            double m = (c.p1+c.p2)/2*0.8 + 0.2*c.mt;
            printf("Id: %d\n", c.num);
            printf("nome: %s\n", c.nome);
            printf("mf: %.2lf\n", m);
            printf("frequencia: %.2lf\n", c.freq);
            if (c.freq >= 70 && m >= 4.95) printf("Aprovado\n");
            else printf("Reprovado");
            
        } else printf("Registro nao encontrado\n");
    }

    fclose(arq);
    
    getch();
}

void listar(char file_name[])
{
    FILE *arq;
    aluno c;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
            double m = (c.p1+c.p2)/2*0.8 + 0.2*c.mt;
            printf("Id: %d\n", c.num);
            printf("nome: %s\n", c.nome);
            printf("mf: %.2lf\n", m);
            printf("frequencia: %.2lf\n", c.freq);
            if (c.freq >= 70 && m >= 4.95) printf("Aprovado\n");
            else printf("Reprovado");
    }

    fclose(arq);
    
    getch();
}

void alterar(char file_name[])
{
    FILE *arq;
    aluno c;
    int id, achou = 0;

    if ((arq = fopen(file_name, "r+b")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }
    
    printf("Infome o ID do aluno que deseja alterar\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1 && !achou)
    {
        if (c.num == id)
        {
            printf("num\n");
            scanf("%d", &c.num);
            printf("nome\n");
            scanf("%s", &c.nome);
            printf("curso\n");
            scanf("%s", &c.curso);
            printf("p1\n");
            scanf("%lf", &c.p1);
            printf("p2\n");
            scanf("%lf", &c.p2);
            printf("frequencia\n");
            scanf("%lf", &c.freq);
            printf("mt\n");
            scanf("%lf", &c.mt);
            fseek(arq, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(aluno), 1, arq);
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
    aluno c;
    if ((arq = fopen(file_name, "rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }
    
    aux = fopen("NOME.BAK", "wb");

    printf("Infome o ID do aluno que deseja remover\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (id != c.num)
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
    char file_name[20] = "estoque.dat";
    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(file_name);
        else if (op == 2) apagar(file_name);
        else if (op == 3) consultar(file_name);
        else if (op == 4) alterar(file_name);
        else if (op == 5) listar(file_name);
        system("cls");
    } while (op);

    return 0;
}
