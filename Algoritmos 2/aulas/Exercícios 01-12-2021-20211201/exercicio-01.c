// Faça um programa que copie um arquivo texto convertendo 
// as letras minúsculas em maiúsculas. 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main() {
 	FILE *arqOriginal,*arqCopia;
 	char caractere, nome[20], nomeNovo[20];
 	printf("\nDigite o nome do arquivo a ser copiado: ");
 	gets(nome);
 	printf("\nDigite o nome do arquivo copia: ");
 	gets(nomeNovo);
 	if((arqOriginal = fopen(nome,"r")) == NULL){
 		printf("\nErro ao abrir o arquivo original!");
 		exit(1);
 	}
 	if ((arqCopia = fopen(nomeNovo,"w")) == NULL){
 		printf("\nErro ao abrir o arquivo copia!");
 		exit(1);
 	}
 	while(!feof(arqOriginal)){
 		caractere = toupper(getc(arqOriginal));
 		if (!feof(arqOriginal))
 			putc(caractere,arqCopia);
 	}
 	fclose(arqOriginal);
 	fclose(arqCopia);
 	printf("\n%s copiado com sucesso para %s.\n\n",nome,nomeNovo);
 	return 0;
}
