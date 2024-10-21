/*
* Nome: Raul Alexandre Gonzalez Augusto
* Sistema Operacional: Windows 11
* Compilador: mingw64 (port do gcc para windows)
* Desenvolvido em: Visual Studio Code 07/05/23
*/

#include <bits/stdc++.h>

using namespace std;

bool simbolos_especiais(char proximo)
{

}

bool letras(char proximo)
{
	
}

bool digitos(char proximo)
{
	
}

bool letras_e_digitos(char proximo)
{
	
}

bool palavras_reservadas(char proximo)
{
	
}


int main()
{
	ifstream  arq;

	arq.open("Trab1_Compiladores.txt");
	if (!arq.is_open())
	{
		cout << "Erro ao abrir o arquivo" << endl;
		return 0;
	}
	

	char proximo;
	string linha;
	unsigned int numLinhas = 1;

	while (getline(arq, linha))
	{
		
	}
	

	while (!arq.eof())
	{
		if (getline(arq, linha))
		{
			cout << numLinhas << " ";

			proximo = linha[0];
			unsigned int numProximo = 0;
		}
		
	}
	

	fclose(arq);
	return 0;
}