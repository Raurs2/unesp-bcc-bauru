#include <stdio.h>
#include <string.h>
#define max 30 

typedef struct {
  char nome[20], endereco[50];
  int telefone;
} ficha_pessoal;
//-------------------------------------------------------------
void lerPessoas (ficha_pessoal povo[], int n) {
  int i;
  for(i = 0 ; i < n; i++){
  	fflush (stdin);
    printf("Digite o nome: ");
    gets (povo[i].nome);
    printf("Digite o endereco: ");
    gets(povo[i].endereco);
    printf("Digite o numero: ");
    scanf("%d", &povo[i].telefone);
    printf("\n");
  }
}
//-------------------------------------------------------------
void imprimirPessoas (ficha_pessoal povo[], int n) {
  int i;
  for(i = 0 ; i < n; i++)
    printf("%20s%50s%4d\n", povo[i].nome, povo[i].endereco, povo[i].telefone);
}
//-------------------------------------------------------------
void ordenarPessoas(ficha_pessoal povo[], int n) {
  ficha_pessoal aux;
  int i, j;
  for(i = 0 ; i < n-1 ; i++) 
    for(j = i + 1 ; j < n; j++)
      if(strcmp(povo[i].nome, povo[j].nome) > 0) {
      aux = povo[i];
      povo[i] = povo[j];
      povo[j] = aux;
    }
}
//-------------------------------------------------------------
int main () {
  int totalPessoas;
  ficha_pessoal povo[max];
  do{
  	printf ("NUmero de pessoas (max %d): ",max);
    scanf("%d", &totalPessoas);
  }while (totalPessoas<0 || totalPessoas>max);
  lerPessoas(povo,totalPessoas);
  ordenarPessoas(povo, totalPessoas);
  imprimirPessoas(povo, totalPessoas);
}
