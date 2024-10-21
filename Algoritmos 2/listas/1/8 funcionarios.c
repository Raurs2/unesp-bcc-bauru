#include <stdio.h>
#include <math.h>

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
    Data dataNascimento;
} TipoReg;

typedef struct 
{
  TipoReg funci[100];
  int qtd;  
} TipoCadastro;


int main()
{
    
    return 0;
}
