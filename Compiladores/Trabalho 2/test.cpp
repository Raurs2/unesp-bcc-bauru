/*
* Nome: Raul Alexandre Gonzalez Augusto
* Sistema Operacional: Windows 11
* Compilador: mingw64 (port do gcc para windows)
* Desenvolvido em: Visual Studio Code 01/07/23
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

	ifstream  arq;

	arq.open("Trab1_Compiladores.txt");
	if (!arq.is_open())
	{
		cout << "Erro ao abrir o arquivo" << endl;
		return 0;
	}
    
    string linha;
    while (getline(arq, linha))
    cout << linha << endl;

	return 0;
}