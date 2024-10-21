//Faça um programa que conte o número de vogais e consoantes de um arquivo texto. 
// O nome do arquivo deve ser fornecido pelo teclado.

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int v=0, co=0;
	FILE *arq;
	char c, narq[20];
	printf("Digite o nome do arquivo (sem o .txt): ");
	gets(narq);
	strcat(narq, ".txt");
	if((arq = fopen(narq, "r")) == NULL)
	{
		printf("Erro na abertura do primeiro arquivo!");
		exit(1);
	}
    while(!feof(arq))arquivo
    a
	{
		c = tolower(getc(arq));
		if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && isalpha(c))
			co++;
		else if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			   v++;
	}
	fclose(arq);
	printf("Vogais: %d\nConsoantes: %d", v, co);
	return 0;
}
