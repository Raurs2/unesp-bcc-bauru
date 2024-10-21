//Manipulação de pastas -- Anselmo R. -- RA211020508
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <winbase.h>
#include <unistd.h> 
#include <sys/stat.h>



void ExecutaCMD(char comando[300])
{
    system(comando);
}

void MostraCaminho()
{
	char FuncLouca[300];
	printf("%s\n", getcwd(FuncLouca, 300));
}


void MoveDir(char caminho[296])
{
	chdir(caminho);
}

void RenomearArquivo(char nome1[], char nome2[])
{
	 
    int ok;
    ok = rename(nome1, nome2);
    if(!ok)
    {
        printf("%s", "Arquivo renomeado com sucesso");
    }
    else
    {
        perror("Error");
    }
   
}

void RemoverArquivo(char nome1[])
{
	 
    int ok;
    ok = remove(nome1);
    if(!ok)
    {
        printf("%s", "Arquivo removido com sucesso");
    }
    else
    {
        perror("Error");
    }
   
}

void CriarPasta(char nome1[])
{
	int ok;
	ok = mkdir(nome1);
	if(!ok)
    {
        printf("%s", "Pasta criada com sucesso");
    }
    else
    {
        perror("Ihh, Deu Erro");
    }
}

void RenomearPasta(char nome1[], char nome2[])
{
	 
    int ok;
    ok = rename(nome1, nome2);
    if(!ok)
    {
        printf("%s", "Pasta renomeada com sucesso");
    }
    else
    {
        perror("Error");
    }
   
}

void AlterarData()
{
	system("date");
}

void AlterarHora()
{
	system("time");
}
