#include<stdio.h>
#include<string.h>
#define MAX 31

typedef struct{
char nome[20];
char endereco[20];
int telefone;
}registro;

void inserir(registro pessoa[MAX], int i){
  scanf("%s", &pessoa[i].nome);
  scanf("%s", &pessoa[i].endereco);
  scanf("%d", &pessoa[i].telefone);
}

void mostra(registro pessoa[MAX], int i){
  printf("\n%s\n", pessoa[i].nome);
  printf("%s\n", pessoa[i].endereco);
  printf("%d\n", pessoa[i].telefone);
}

int main(){

  registro pessoa[MAX];
  int i, j;

  for(i=1; i<MAX; i++){
    inserir(pessoa, i);
  }

  for(i=1; i<MAX; i++){
    for(j=i+1; j<MAX; j++){
       if(strcoll(pessoa[i].nome, pessoa[j].nome) > 0 ){
                pessoa[0] = pessoa[i];
                pessoa[i] = pessoa[j];
                pessoa[j] = pessoa[0];
       }
    }
  }

  for(i=1; i<MAX; i++){
    mostra(pessoa, i);
  }
  return 0;
}
