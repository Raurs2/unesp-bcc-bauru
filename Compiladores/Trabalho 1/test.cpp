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