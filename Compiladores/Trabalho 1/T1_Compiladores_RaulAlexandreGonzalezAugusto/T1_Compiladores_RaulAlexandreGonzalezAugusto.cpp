/*
* Nome: Raul Alexandre Gonzalez Augusto
* Sistema Operacional: Windows 11
* Compilador: mingw64 (port do gcc para windows)
* Desenvolvido em: Visual Studio Code 07/05/23
*/

#include <bits/stdc++.h>

using namespace std;

//verifica se é um dos simbolos especiais
bool simbolos_especiais(string next)
{
    if (next == "." || next == ";" || next == "," || next == "(" 
    || next == ")" || next == ":" || next == "<" || next == ">" 
    || next == "+" || next == "-" || next == "*" || next == "=") return true;

    return false;
}

//verifica se é uma letra de a-z maisc. ou minuscula
bool letras(string next)
{
	if ((next >= "A" && next <= "Z") || (next >= "a" && next <= "z")) return true;
    
    return false;
}

//verifica se é um digito
bool digitos(string next)
{
    if (next >= "0" && next <= "9") return true;

    return false;
}

//verifica se é uma letra ou um digito
bool letras_ou_digitos(string next)
{
	if (letras(next) || digitos(next)) return true;

    return false;
}

//verifica se é uma das palavras reservadas da linguagem
bool palavras_reservadas(string next)
{
	if(next == "program" || next == "var" || next == "integer" || next == "procedure" || next == "begin" || 
    next == "if" || next == "div" || next == "then" || next == "else" || next == "end" || next == "read" || 
    next == "while" || next == "do" || next == "write") return true;

    return false;
}

//transforma os simbolos e palavras especiais em novos para facilitar a montagem
string CODIGO(string cod)
{
    if(cod == "program") return"PROGRAMA";
    else if(cod == "var") return"VARIAVEL";
    else if(cod == "integer") return"INTEIRO";
    else if(cod == "procedure") return"PROCEDIMENTO";
    else if(cod == "begin") return"INICIO";
    else if(cod == "if") return"SE";
    else if(cod == "div") return"DIV";
    else if(cod == "then") return"ENTAO";
    else if(cod == "else") return "SENAO";
    else if(cod == "end") return"FIM";
    else if(cod == "read") return "LER";
    else if(cod == "while") return"ENQUANTO";
    else if(cod == "do") return"FACA";
    else if(cod == "write") return "ESCREVER";
    return cod;

}

//mapa para armazenar os identificadores
map<string, string> ids;
int numId = 1;


string codigo_de_identificador(string cod)
{
    if (ids.count(cod)) return ids[cod]; //retorna o id
    else //se não ter id ainda cria um novo id
    {
        string str = "ID";
        str += to_string(numId++);
        ids[cod] = str;
    }

    return ids[cod];  
}

//reporta caso ocorram erros no analisador lexico
void ERRO(int numLinhas, bool err)
{
    if (err) printf("\n\nErro na linha %d, caractere invalido!\n\n", numLinhas);
    else printf("\n\nErro na linha %d, variavel comecando com digito!\n\n", numLinhas);
}


//retorna o proximo caracter da linha
char PROXIMO(string linha, int nchar)
{
    return linha[nchar];
}


int main()
{
	ifstream  arq;

	arq.open("Trab1_Compiladores.txt"); //abre o arquivo
	if (!arq.is_open()) // caso falhe em abrir o arquivo avisa o erro e finaliza o programa
	{
		cout << "Erro ao abrir o arquivo" << endl;
		return 0;
	}
	

	string next;
	string linha;
	int numLinhas = 1;

	while (getline(arq, linha)) //le linha por linha do arquivo
	{
		cout << numLinhas << " "; // numero das linhas

        unsigned int nChar = 0;
        next = linha[nChar];

        while (next != "\n" && next != "\r" && nChar < linha.size()) // le letra por letra da linha
        {
            string simbolo;
            string atomo;

            if (simbolos_especiais(next)) //trata caso seja um simbolo especial
            {
                string temp_next = next;
                next = PROXIMO(linha, ++nChar);

                if (temp_next == ":" && next == "=") //tratamento para o simbolo especial de dois char :=
                {
                    simbolo = CODIGO(":=");
                    next = PROXIMO(linha, ++nChar);
                } else
                {
                    simbolo = CODIGO(temp_next);
                } 
            } else if (letras(next)) //trata caso for uma palavra
            {
                do
                {
                    atomo += next;
                    next = PROXIMO(linha, ++nChar);
                } while (letras_ou_digitos(next));

                //se for uma palavra reservada transforma para seu novo simbolo e se for uma variavel ou um identificador transforma em um id 
                if (palavras_reservadas(atomo)) simbolo = CODIGO(atomo);
                else simbolo = codigo_de_identificador(atomo);
            } else if (digitos(next)) //trata caso for um digito
            {
                do
                {
                    atomo += next;
                    next = PROXIMO(linha, ++nChar);
                } while (digitos(next));

                if (letras(next)) //caso venha uma letra apos ter iniciado com um digito da erro
                {
                    ERRO(numLinhas, false);
                    return 0;
                }
                simbolo = atomo;
            } else if (next == " ") //trata espacos em branco
            {
                simbolo = " ";
                next = PROXIMO(linha, ++nChar);
            } else if (next == "\t") //trata tabulações
            {
                next = PROXIMO(linha, ++nChar);
                continue;
            } else
            {
                ERRO(numLinhas, true); //erro de caracteres
                return 0;
            }

            cout << simbolo; //imprime o simbolo
        }
        cout << "\n";
        numLinhas++;  
	}
	
	arq.close(); //fecha o arquivo
	return 0;
}