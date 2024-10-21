/*
* Nome: Raul Alexandre Gonzalez Augusto
* Sistema Operacional: Windows 11
* Compilador: mingw64 (port do gcc para windows)
* Desenvolvido em: Visual Studio Code 07/05/23
*/

#include <bits/stdc++.h>

using namespace std;

bool simbolos_especiais(char next)
{
    if (next == '.' || next == ';' || next == ',' || next == '(' 
    || next == ')' || next == ':' || next == '<' || next == '>' 
    || next == '+' || next == '-' || next == '*' || next == '=') return true;

    return false;
}

bool letras(char next)
{
	if ((next >= 'A' && next <= 'Z') || (next >= 'a' && next <= 'z')) return true;
    
    return false;
}

bool digitos(char next)
{
    if (next >= '0' && next <= '9') return true;

    return false;
}

bool letras_e_digitos(char next)
{
	if (letras(next) && digitos(next)) return true;

    return false;
}

bool palavras_reservadas(string next)
{
	if(next == "program" || next == "var" || next == "integer" || next == "procedure" || next == "begin" || 
    next == "if" || next == "div" || next == "then" || next == "else" || next == "end" || next == "read" || 
    next == "while" || next == "do" || next == "write") return true;

    return false;
}

string CODIGO(string cod)
{
    char temp_cod = cod[0];
    if(cod == "program") return"programa";
    else if(cod == "var") return"variaveis";
    else if(cod == "integer") return"inteiro";
    else if(cod == "procedure") return"procedimento";
    else if(cod == "begin") return"inicio";
    else if(cod == "if") return"se";
    else if(cod == "div") return"divisao";
    else if(cod == "then") return"entao";
    else if(cod == "else") return "senao";
    else if(cod == "end") return"fim";
    else if(cod == "read") return "ler";
    else if(cod == "while") return"enquanto";
    else if(cod == "do") return"faca";
    else if(cod == "write") return "escreva";
    else if (simbolos_especiais(temp_cod)) return cod;

}

map<string, string> ids;
int numId = 0;

string codigo_de_identificador (string cod)
{
    if (ids.count(cod)) return ids[cod];
    else ids[cod] = "id" + numId++;    
}

void ERRO(int numLinhas, bool err)
{
    if (err) printf("\nErro na linha %d, caractere invalido!\n\n");
    else printf("\nErro na linha %d, variavel comecando com digito!\n\n");
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
	

	char next;
	string linha;
	unsigned int numLinhas = 1;

	while (getline(arq, linha))
	{
		cout << numLinhas << " ";

        unsigned int nChar = 0;
        next = linha[nChar];

        while (next != '\n' && next != '\r' && nChar < linha.size())
        {
            string simbolo;
            string atomo;

            if (simbolos_especiais(next))
            {
                char temp_next = next;
                next = linha[++nChar];

                if (temp_next == ':' && next == '=')
                {
                    simbolo = CODIGO(":=");
                    next = linha[++nChar];
                } else
                {
                    simbolo = temp_next;
                    simbolo = CODIGO(simbolo);
                } 
            } else if (letras(next))
            {
                do
                {
                    atomo += next;
                    next = linha[++nChar];
                } while (letras_e_digitos(next));

                if (palavras_reservadas(atomo)) simbolo = CODIGO(atomo);
                else simbolo = codigo_de_identificador(atomo);
            } else if (digitos(next))
            {
                do
                {
                    atomo += next;
                    next = linha[++nChar];
                } while (digitos(next));

                if (letras(next))
                {
                    ERRO(numLinhas, false);
                    return 0;
                }
                simbolo = atomo;
            } else if (next == ' ')
            {
                cout << " ";
                next = linha[++nChar];
            } else if (next == '/t')
            {
                next = linha[++nChar];
            } else
            {
                ERRO(numLinhas, true);
                return 0;
            }

            cout << simbolo;
        }    
	}
	
	arq.close();
	return 0;
}