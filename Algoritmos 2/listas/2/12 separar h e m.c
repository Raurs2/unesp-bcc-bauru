#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//NOME, SEXO, COR DE OLHOS, ALTURA, PESO e DATA DE NASCIMENTO
typedef struct 
{
    char nome[20], eyes_color[20];
    int sex, alt, peso, d, m, a;
} cadastro;

typedef struct 
{
    char nome[20], eyes_color[20];
    int  alt, peso, d, m, a;
} noSex;

int main()
{
    FILE *arq, *homens, *mulheres;
    cadastro c;
    noSex p;

    if ((arq = fopen("cadastro.dat", "rb")) == NULL)
    {
        printf("Erro de abertura 1");
        exit(1);
    }
    
    if ((homens = fopen("homens.dat", "wb")) == NULL)
    {
        printf("Erro de abertura 2");
        exit(1);
    }

    if ((mulheres = fopen("mulheres.dat", "wb")) == NULL)
    {
        printf("Erro de abertura 3");
        exit(1);
    }
    
    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        strcpy(p.nome, c.nome);
        strcpy(p.eyes_color, c.eyes_color);
        p.alt = c.alt;
        p.d = c.d;
        p.m = c.m;
        p.a = c.a;
        p.alt = c.alt;
        p.peso = c.peso;

        if (c.sex == 1)
        {
            fwrite(&p, sizeof(p), 1, homens);
        } else if (c.sex == 2)
        {
            fwrite(&p, sizeof(p), 1, mulheres);
        }
    }

    remove("cadastro.dat");
    printf("copiado\n");
    fclose(arq);
    fclose(homens);
    fclose(mulheres);
    
    return 0;
}
