#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 30

typedef struct 
{
    int dia, mes, ano
} Data;


typedef struct 
{
    char nome[MAX], rg[MAX], sex;
    double sal;
    int idade;
    Data dataNasc;
} TipoReg;

typedef struct 
{
  TipoReg func[100];
  int qtd;  
} TipoCadastro;


leFuncionarios(TipoCadastro cad)
{
    int n;
    do
    {
        gets(cad.func->nome);
        gets(cad.func->rg);
        gets(cad.func->sex);
        scanf("%d", &cad.func->idade);
        scanf("%d %d %d", &cad.func->dataNasc.dia, &cad.func->dataNasc.mes, &cad.func->dataNasc.ano);
        scanf("%lf", &cad.func->sal);
        scanf("%d", &n);
        fflush(stdin);
        cad.qtd++;
    } while (n != 0 && cad.qtd <= 100);
    
}

int main()
{
    
    return 0;
}
