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


void leFuncionarios(TipoCadastro cad)
{
    int n, i = 0;
    do
    {
        gets(cad.func[i].nome);
        gets(cad.func[i].rg);
        gets(cad.func[i].sex);
        scanf("%d", &cad.func[i].idade);
        scanf("%d %d %d", &cad.func[i].dataNasc.dia, &cad.func[i].dataNasc.mes, &cad.func[i].dataNasc.ano);
        scanf("%lf", &cad.func[i].sal);
        scanf("%d", &n);
        fflush(stdin);
        cad.qtd++;
    } while (n != 0 && cad.qtd <= 100);
    
}

void ordenaNome(TipoCadastro cad)
{
    int i, j;
    TipoCadastro aux;
    for(i = 0 ; i < cad.qtd-1 ; i++)
    {
        for(j = i + 1 ; j < cad.qtd; j++)
        {
            if(strcmp(cad.func[i].nome, cad.func[j].nome) > 0) 
            {
                aux.func[i] = cad.func[i];
                cad.func[i] = cad.func[j];
                cad.func[j] = aux.func[i];
            }
        }
    }
}

void ordenaSalario(TipoCadastro cad)
{
    int i, j;
    TipoCadastro aux;
    for(i = 0 ; i < cad.qtd-1 ; i++)
    {
        for(j = i + 1 ; j < cad.qtd; j++)
        {
            if(cad.func[i].sal < cad.func[j].sal) 
            {
                aux.func[i] = cad.func[i];
                cad.func[i] = cad.func[j];
                cad.func[j] = aux.func[i];
            }
        }
    }
}

int main()
{
    
    return 0;
}
