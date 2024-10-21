#include <stdio.h>
#include <string.h>
#define max 30

typedef struct{
  char nome[30],endereco[30],telefone[10];
}info;

main(){
  int i, j, total;
  info povo[max], aux;
  // Leitura da quantidade de pessoas
  do {
    printf("Qual o total de pessoas?\n");
    scanf("%d",&total);
  } while (total < 0 || total > max);
  fflush (stdin);
  // Leitura dos dados das pessoas
  for(i=0; i<total; i++){
    printf("Nome: ");
    gets(povo[i].nome);
    printf("Endereco: ");
    gets(povo[i].endereco);
    printf("telefone: ");
    gets(povo[i].telefone);
  }
  for(i=0; i<total; i++){
    printf("Nome:%s\n",povo[i].nome);
    printf("Endereco:%s\n",povo[i].endereco);
    printf("Telefone:%s\n\n",povo[i].telefone);
  }
  for(i = 0 ; i < total-1 ; i++) 
    for(j = i + 1 ; j < total; j++)
      if(strcmp(povo[i].nome, povo[j].nome) > 0) {
      aux = povo[i];
      povo[i] = povo[j];
      povo[j] = aux;
    }
  for(i=0; i<total; i++){
  	printf("%30s %30s %10s",povo[i].nome,povo[i].endereco,povo[i].telefone);
    //printf("Nome:%s\n",povo[i].nome);
    //printf("Endereco:%s\n",povo[i].endereco);
    //printf("Telefone:%s\n\n",povo[i].telefone);
  }
  return 0;
}
