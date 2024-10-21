#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX 20
//número da conta, tipo da operação (crédito ou débito), valor.
typedef struct 
{
    char sex, civil;
    int idade, instrucao, depende;
    double sal, patrimonio, kcal;
} pesquisa;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - listar\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 2);
    return op;
}

void incluir(char f1[], char f2[], char f3[])
{
    int op;
    FILE *arq1, *arq2, *arq3;
    pesquisa c;

    if ((arq1 = fopen(f1,"ab")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    if ((arq2 = fopen(f2,"ab")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    if ((arq3 = fopen(f3,"ab")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    do
    {
        fflush(stdin);
        printf("sexo\n");
        scanf("%c", &c.sex);
        printf("estado civil\n");
        fflush(stdin);
        scanf("%c", &c.civil);
        printf("idade\n");
        scanf("%d", &c.idade);
        printf("nivel de instrucao\n");
        scanf("%d", &c.instrucao);
        printf("dependentes\n");
        scanf("%d", &c.depende);
        printf("salario\n");
        scanf("%lf", &c.sal);
        printf("patrimonio\n");
        scanf("%lf", &c.patrimonio);
        printf("kcal\n");
        scanf("%lf", &c.kcal);

        do
        {
            printf("Add para regiao 1, 2 ou 3?\n");
            scanf("%d", &op);
        } while (op < 1 && op > 3);

        if (op == 1) fwrite(&c, sizeof(pesquisa), 1, arq1);
        if (op == 2) fwrite(&c, sizeof(pesquisa), 1, arq2);
        if (op == 3) fwrite(&c, sizeof(pesquisa), 1, arq3);
        printf("Adicionado com sucesso!");

        do
        {
            printf("Add mais pessoas?\n1 - sim, 2 - nao\n");
            scanf("%d", &op);
        } while (op < 1 && op > 2);
        
    } while (op == 1);

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
}

void listar(char f1[], char f2[], char f3[])
{
    FILE *arq1, *arq2, *arq3, *arqf;
    pesquisa c1, c2, c3;
    int i = 0;
    int tem1 = 1, tem2 = 1, tem3 = 1;

    if ((arq1 = fopen(f1,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    if ((arq2 = fopen(f2,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    if ((arq3 = fopen(f3,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    if ((arqf = fopen("todasRegioes.dat","w+b")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    
    fread(&c1, sizeof(c1), 1, arq1);
    fread(&c2, sizeof(c2), 1, arq2);
    fread(&c3, sizeof(c3), 1, arq3);
    
    while (tem1 || tem2 || tem3)
    {
        if (c1.idade < c2.idade && c1.idade < c3.idade)
        {
            fwrite(&c1, sizeof(pesquisa), 1, arqf);
            if (fread(&c1, sizeof(c1), 1, arq1) == 0)
            {
                tem1 = 0;
            }
        } else if (c2.idade < c1.idade && c2.idade < c3.idade)
        {
            fwrite(&c2, sizeof(pesquisa), 1, arqf);
            if (fread(&c2, sizeof(c2), 1, arq1) == 0)
            {
                tem2 = 0;
            }
        } else if (c3.idade < c1.idade && c3.idade < c2.idade)
        {
            fwrite(&c3, sizeof(pesquisa), 1, arqf);
            if (fread(&c3, sizeof(c3), 1, arq1) == 0)
            {
                tem3 = 0;
            }
        }
    }

    while (fread(&c1, sizeof(c1), 1, arqf) == 1)
    {
        printf("%d\n", c1.idade);
    }

    getch();

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
}

int main()
{
    int op;
    char f1[20] = "regiao1.dat", f2[20] = "regiao2.dat", f3[20] = "regiao3.dat";
    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(f1, f2, f3);
        else if (op == 2) listar(f1, f2, f3);
        system("cls");
    } while (op);
    
    return 0;
}
