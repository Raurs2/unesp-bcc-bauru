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
    char nome[MAX], sex;
    double sal;
    int idade, rg;
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
        gets(cad.func[i].sex);
        scanf("%d", &cad.func[i].rg);
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

void imposto(TipoCadastro cad, int id)
{
    if (cad.func[id].sal <= 1000)
    {
        printf("%s é insento de imposto", cad.func[id].nome);
    } else if (cad.func[id].sal <= 2000)
    {
        printf("%s tem %.2lf do salario retido", cad.func[id].nome, cad.func[id].sal * 0.1);
    } else if (cad.func[id].sal <= 3500)
    {
        printf("%s tem %.2lf do salario retido", cad.func[id].nome, cad.func[id].sal * 0.15);
    } else if (cad.func[id].sal > 3500)
    {
        printf("%s tem %.2lf do salario retido", cad.func[id].nome, cad.func[id].sal * 0.25);
    }
}

void AtualizaSalario(TipoCadastro cad)
{
    int rg, i;
    double sal;
    scanf("%d", &rg);
    scanf("%lf", &sal);
    for ( i = 0; i < cad.qtd; i++)
    {
        if (rg == cad.func[i].rg)
        {
            cad.func[i].sal = sal;
            break;
        }
    }
}

void RemoveFuncionario(TipoCadastro cad, int rg)
{
    int i;
    for ( i = 0; i < cad.qtd; i++)
    {
        if (rg == cad.func[i].rg)
        {
            for ( i; i < cad.qtd; i++)
            {
                cad.func[i] = cad.func[i+1];
            }
            cad.qtd--;
            break;
        }
    }
}

void ListaAniversarioSexo(TipoCadastro cad, int dia, int mes, int ano, char sex)
{
    int i;
    for ( i = 0; i < cad.qtd; i++)
    {
        int isDia = dia == cad.func[i].dataNasc.dia;
        int isMes = mes == cad.func[i].dataNasc.mes;
        int isAno = ano == cad.func[i].dataNasc.ano;
        int isSex = sex == cad.func[i].sex;
        if (isDia && isMes && isAno && isSex)
        {
            printf("%s", cad.func[i].nome);
        }
    }
}

int main()
{
    
    return 0;
}
