#include <stdio.h>
#include <stdlib.h>

#define MAX 2

typedef struct empregado {
    char nome[20], sobrenome[20];
    int diaNasc, mesNasc, anoNasc, diaAdm, mesAdm, anoAdm, rg;
    double sal;
} empregado;

int main()
{
    empregado empregados[MAX];
    int i;
    for ( i = 0; i < MAX; i++)
    {
        printf("nome: ");
        scanf("%s %s", empregados[i].nome, empregados[i].sobrenome);
        printf("Data de nasc: ");
        scanf("%d %d %d", &empregados[i].diaNasc,  &empregados[i].mesNasc,  &empregados[i].anoNasc);
        printf("RG: ");
        scanf("%d", &empregados[i].rg);
        printf("Data de Admissao: ");
        scanf("%d %d %d", &empregados[i].diaAdm,  &empregados[i].mesAdm,  &empregados[i].anoAdm);
        printf("Salario: ");
        scanf("%lf", &empregados[i].sal);
        system("cls");
    }
    for ( i = 0; i < MAX; i++)
    {
        printf("Nome: %s %s\n", empregados[i].nome, empregados[i].sobrenome);
        printf("Nascimento: %d/%d/%d\n", empregados[i].diaNasc,  empregados[i].mesNasc,  empregados[i].anoNasc);
        printf("RPG: %d\n", empregados[i].rg);
        printf("Admissao: %d/%d/%d\n", empregados[i].diaAdm,  empregados[i].mesAdm,  empregados[i].anoAdm);
        printf("Salario: R$%.2lf\n\n", empregados[i].sal);
    }
    return 0;
}
