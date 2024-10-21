#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX 20
//número da conta, tipo da operação (crédito ou débito), valor.
typedef struct 
{
    char sex, fumante;
    int idade;
} pesquisa;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - listar\n3 - resultados\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 3);
    return op;
}

void incluir(char file_name[])
{
    int op;
    FILE *arq;
    pesquisa c;

    if ((arq = fopen(file_name,"ab")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    do
    {
        fflush(stdin);
        printf("sexo\n");
        scanf("%c", &c.sex);
        printf("fumante\n");
        fflush(stdin);
        scanf("%c", &c.fumante);
        printf("idade\n");
        scanf("%d", &c.idade);
        fwrite(&c, sizeof(pesquisa), 1, arq);
        printf("Adicionado com sucesso!");
        do
        {
            printf("Add mais pessoas?\n1 - sim, 2 - nao\n");
            scanf("%d", &op);
        } while (op < 1 && op > 2);
        
    } while (op == 1);

    fclose(arq);
}

void listar(char file_name[])
{
    FILE *arq;
    pesquisa c;
    int i = 0;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
            printf("sexo: %c\n", c.sex);
            printf("fumante: %c\n", c.fumante);
            printf("idade: %d\n\n", c.idade);
    }
    getch();
    fclose(arq); 
}

void resultados(char file_name[])
{
    FILE *arq;
    pesquisa c;
    int i = 0;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    double men = 0, woman = 0, men_nao_fuma = 0, woman_fuma = 0, fumante = 0, tot = 0;
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (c.fumante == 'S')
        {
            fumante++;
        }
        if (c.fumante == 'N' && c.sex == 'H' && c.idade < 40)
        {
            men_nao_fuma++;
        }
        if (c.fumante == 'S' && c.sex == 'M' && c.idade > 40)
        {
            woman_fuma++;
        }
        if (c.sex == 'H')
        {
            men++;
        }
        if (c.sex == 'M')
        {
            woman++;
        }
        tot++;
    }
    double fumantes = 0, mulheres_sim = 0, homens_nao = 0;
    if (fumante) fumantes = fumante/tot*100.0;
    if (men_nao_fuma) homens_nao = men_nao_fuma/men*100.0;
    if (woman_fuma) mulheres_sim =  woman_fuma/woman*100.0;
    printf("fumantes/tot %.2lf\nhomens nao fumantes menor de %.2lf\nmulheres fumantes maior de %.2f\n", fumantes, homens_nao, mulheres_sim);
    getch();
    fclose(arq); 
}

int main()
{
    int op;
    char file_name[20] = "pesquisa.dat";
    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(file_name);
        else if (op == 2) listar(file_name);
        else if (op == 3) resultados(file_name);
        system("cls");
    } while (op);
    
    return 0;
}
