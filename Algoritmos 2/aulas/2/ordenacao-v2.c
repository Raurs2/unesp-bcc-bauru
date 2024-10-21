#include <stdio.h>
#include <string.h>
#define max 30 

typedef struct {
  char nome[20], endereco[50];
  int telefone;
} ficha_pessoal;

void lerPessoa (ficha_pessoal povo[], int i) {
  fflush (stdin);
  printf("Digite o nome: ");
  gets (povo[i].nome);
  printf("Digite o endereco: ");
  gets(povo[i].endereco);
  printf("Digite o numero: ");
  scanf("%d", &povo[i].telefone);
  printf("\n");
}

void imprimirPessoa (ficha_pessoal povo[], int i) {
  printf("\tNome: %s\n\tEndereco: %s\n\tNumero: %d\n\n", povo[i].nome, povo[i].endereco, povo[i].telefone);
}

void imprimirPessoa2 (ficha_pessoal povo) {
  printf("\tNome: %s\n\tEndereco: %s\n\tNumero: %d\n\n", povo.nome, povo.endereco, povo.telefone);
}

void ordenarPessoa(ficha_pessoal povo[], int i, int j) {
  ficha_pessoal aux;
  if(strcmp(povo[i].nome, povo[j].nome) > 0) {
    aux = povo[i];
    povo[i] = povo[j];
    povo[j] = aux;
  }
}

int main () {
  int i, j, totalPessoas;
  ficha_pessoal povo[max], aux;
  do{
  	printf ("NUmero de pessoas (max %d): ",max);
    scanf("%d", &totalPessoas);
  }while (totalPessoas<0 || totalPessoas>max);
  for(i = 0 ; i < totalPessoas ; i++)
    lerPessoa(povo, i);
  for(i = 0 ; i < totalPessoas - 1 ; i++) {
    for(j = i + 1 ; j < totalPessoas ; j++)
      ordenarPessoa(povo, i, j);
  }
  for(i = 0 ; i < totalPessoas ; i++)
    imprimirPessoa2(povo[i]);  // imprimirPessoa(povo,i);
}
