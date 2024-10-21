/*
 * Nome: Raul Alexandre Gonzalez Augusto
 * Sistema Operacional: Windows 11
 * Compilador: mingw64 (port do gcc para windows)
 * Desenvolvido em: Visual Studio Code 01/07/23
 */

#include <bits/stdc++.h>

using namespace std;

map<string, string> identificadores;
string uni = "0", dez = "0", lin, prox, atomo, simbolo;
char linha[100];
unsigned int numProx, tam;
int numLinhas = 1;
ofstream arq_out;
FILE *arq_in;

// Inicialização das funções
bool simbolos_especiais(string prox);
bool letras(string prox);
bool digitos(string prox);
bool palavras_reservadas(string prox);
char PROXIMO(string resultado, int numProx);
string CODIGO(string cod);
void ERRO(int numLinhas, int tipo);
int programa();
int bloco();
int parte_declaracao_variaveis();
int declaracao_variaveis();
int lista_identificadores();
int parte_declaracao_sub_rotinas();
int declaracao_procedimento();
int comando_composto();
int comando();
int comando_sem_rotulo();
int atribuicao();
int chamada_procedimento();
int comando_condicional();
int comando_repetitivo();
int lista_expressoes();
int expressao();
int relacao();
int expressao_simples();
int termo();
int fator();
int variavel();
int numero();
int identificador();

int main()
{
    arq_out.open("Trab2_Compiladores_Intermediario.txt");
    string resultado;

    // Abre o código para ser analisado em modo de leitura
    arq_in = fopen("Exemplo1_Trab2_Compiladores.txt", "rt");
    if (arq_in == NULL) // Se houve erro na abertura
    {
        printf("Problemas na abertura do arq_in\n");
        return 0;
    }

    while (!feof(arq_in))
    {
        // Lê uma linha (inclusive com o '\n')
        resultado = fgets(linha, 100, arq_in);

        if (!resultado.empty())
        { // Se foi possível ler
            cout << numLinhas << " ";
            prox = resultado[0];
            numProx = 0;

            tam = resultado.size();
            while (prox != "\n" && prox != "\r" && numProx < tam)
            {
                string atomo;
                string simbolo;

                if (prox == " ")
                {
                    prox = PROXIMO(resultado, ++numProx);
                    cout << " ";
                    continue;
                }
                else if (prox == "\t")
                {
                    prox = PROXIMO(resultado, ++numProx);
                    continue;
                }
                else if (simbolos_especiais(prox))
                { // Testa se prox faz parte do conjunto de símboloso especiais
                    string s = prox;
                    prox = PROXIMO(resultado, ++numProx);

                    if (s == ":" && prox == "=")
                    {
                        s = ":=";
                        prox = PROXIMO(resultado, ++numProx);
                    }

                    simbolo = CODIGO(s);
                }
                else if (letras(prox))
                {
                    do
                    {
                        atomo += prox;
                        prox = PROXIMO(resultado, ++numProx);
                    } while (letras(prox) || digitos(prox));

                    simbolo = CODIGO(atomo);
                }
                else if (digitos(prox))
                {
                    do
                    {
                        atomo += prox;
                        prox = PROXIMO(resultado, ++numProx);
                    } while (digitos(prox));

                    if (letras(prox))
                    {
                        ERRO(numLinhas, 1);
                        return 0;
                    }

                    simbolo = atomo;
                }
                else
                {
                    ERRO(numLinhas, 2);
                    return 0;
                }

                cout << simbolo;
                arq_out << simbolo;
            }
            cout << "\n";
            arq_out << "\n";
        }
        numLinhas++;
    }
    fclose(arq_in);
    arq_out.close();

    // Parte do analisador léxico
    arq_in = fopen("Trab2_Compiladores_Intermediario.txt", "rt");
    if (arq_in == NULL)
    {
        cout << "\nProblema na abertura do arq_in auxiliar!\n";
        return 0;
    }

    lin = fgets(linha, 100, arq_in);

    numLinhas = 1;

    int compilacao = programa();

    if (compilacao)
    {
        cout << "\nCompilado com sucesso!";
    }
    else
    {
        ERRO(numLinhas, 3);
    }

    return 0;
}

bool simbolos_especiais(string prox)
{
    char p = prox[0];
    if ((p >= 40 && p <= 46) || (p >= 58 && p <= 62))
    {
        return true;
    }

    return false;
}

bool letras(string prox)
{
    char p = prox[0];
    if ((p >= 65 && p <= 90) || (p >= 97 && p <= 122))
    {
        return true;
    }

    return false;
}

bool digitos(string prox)
{
    char p = prox[0];
    if (p >= 48 && p <= 57)
    {
        return true;
    }

    return false;
}

bool palavras_reservadas(string prox)
{
    if (prox == "program" || prox == "var" || prox == "integer" || prox == "begin" ||
        prox == "procedure" || prox == "div" || prox == "if" || prox == "then" || prox == "do" ||
        prox == "else" || prox == "end" || prox == "read" || prox == "while" || prox == "write" ||
        prox == "boolean" || prox == "or" || prox == "and" || prox == "not")
    {
        return true;
    }

    return false;
}

char PROXIMO(string resultado, int pos)
{
    if (prox == "\n" && pos != 0)
    {
        if (!feof(arq_in))
        {
            numLinhas++;
            resultado = fgets(linha, 100, arq_in);
            lin = resultado;
            numProx = 0;
            pos = 0;
        }
    }
    return resultado[pos];
}

string CODIGO(string cod)
{
    if (cod == "program")
    {
        cod = "p";
    }
    else if (cod == "var")
    {
        cod = "v";
    }
    else if (cod == "integer")
    {
        cod = "i";
    }
    else if (cod == "begin")
    {
        cod = "b";
    }
    else if (cod == "procedure")
    {
        cod = "pr";
    }
    else if (cod == "div")
    {
        cod = "/";
    }
    else if (cod == "then")
    {
        cod = "t";
    }
    else if (cod == "if")
    {
        cod = "s";
    }
    else if (cod == "else")
    {
        cod = "e";
    }
    else if (cod == "end")
    {
        cod = "f";
    }
    else if (cod == "read")
    {
        cod = "r";
    }
    else if (cod == "while")
    {
        cod = "w";
    }
    else if (cod == "do")
    {
        cod = "d";
    }
    else if (cod == "write")
    {
        cod = "wr";
    }
    else if (cod == "or")
    {
        cod = "o";
    }
    else if (cod == "and")
    {
        cod = "a";
    }
    else if (cod == "boolean")
    {
        cod = "z";
    }
    else if (cod == "not")
    {
        cod = "n";
    }
    else if (simbolos_especiais(cod))
    {
        return cod;
    }
    else if (identificadores.count(cod))
    {
        cod = identificadores[cod];
    }
    else
    {
        string novoId;
        if (uni == "9")
        {
            uni = "0";
            dez[0]++;
        }
        else
        {
            uni[0]++;
        }

        if (dez == "0")
        {
            novoId = "id" + uni;
        }
        else
        {
            novoId = "id" + dez + uni;
        }

        identificadores[cod] = novoId;
        cod = novoId;
    }

    return cod;
}

void ERRO(int numLinhas, int tipo)
{
    if (tipo == 1)
    {
        cout << "\n\nERRO! Numero mal formado na linha " << numLinhas << "!\n";
    }
    else if (tipo == 2)
    {
        cout << "\n\nERRO! Caractere invalido na linha " << numLinhas << "!\n";
    }
    else
    {
        cout << "\n\nERRO de sintaxe na linha " << numLinhas << "!\n";
    }
}

// Funções do analisador sintático

int programa()
{
    if (!lin.empty())
    { // Se foi possível ler
        prox = lin[0];
        numProx = 0;

        while (prox != "\n" && prox != "\r" && numProx < lin.size())
        {
            if (prox == " ")
            {
                prox = PROXIMO(lin, ++numProx);
                cout << " ";
                continue;
            }
            else if (prox == "\t")
            {
                prox = PROXIMO(lin, ++numProx);
                continue;
            }
            else if (letras(prox))
            {
                if (prox == "p")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (identificador())
                    {
                        return bloco();
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int bloco()
{
    if (!parte_declaracao_variaveis())
    {
        return 0;
    }
    parte_declaracao_sub_rotinas();
    return comando_composto();
}

int parte_declaracao_variaveis()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (letras(prox))
        {
            if (prox == "v")
            {
                prox = PROXIMO(lin, ++numProx);
                return declaracao_variaveis();
            }
        }
    }

    return 0;
}

int declaracao_variaveis()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        while (prox == "i")
        {
            if (lista_identificadores())
            {
                if (prox == ":")
                {
                    prox = PROXIMO(lin, ++numProx);
                }
                else
                {
                    return 0;
                }

                if (prox == "i" || prox == "z")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (prox == ";")
                    {
                        prox = PROXIMO(lin, ++numProx);
                    }
                    else
                    {
                        return 0;
                    }
                    if (!feof(arq_in))
                    {
                        prox = PROXIMO(lin, ++numProx);
                        if (prox != "i")
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

int lista_identificadores()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        while (prox != ":" && prox != "\n")
        {
            if (identificador())
            {
                if (prox == ",")
                {
                    prox = PROXIMO(lin, ++numProx);
                }
                else
                {
                    if (prox != ":")
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    return 0;
}

int parte_declaracao_sub_rotinas()
{
    return declaracao_procedimento();
}

int declaracao_procedimento()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (letras(prox))
        {
            if (prox == "p")
            {
                prox = PROXIMO(lin, ++numProx);
                if (prox == "r")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (identificador())
                    {
                        if (prox == ";")
                        {
                            prox = PROXIMO(lin, ++numProx);
                            return bloco();
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

int comando_composto()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (letras(prox))
        {
            if (prox == "b")
            {
                prox = PROXIMO(lin, ++numProx);
                while (prox != "f")
                {
                    if (!comando())
                    {
                        return 0;
                    }
                    if (prox != ";" && prox != "\n" && prox != "f")
                    {
                        return 0;
                    }
                    else
                    {
                        if (prox != "f")
                        {
                            prox = PROXIMO(lin, ++numProx);
                        }
                    }
                    if (prox == "\n")
                    {
                        prox = PROXIMO(lin, ++numProx);
                    }
                }
                prox = PROXIMO(lin, ++numProx);
                if (prox == ";" || prox == ".")
                {
                    prox = PROXIMO(lin, ++numProx);
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int comando()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (!digitos(prox))
        {
            return comando_sem_rotulo();
        }
    }

    return 0;
}

int comando_sem_rotulo()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (!digitos(prox))
        {
            return (atribuicao() || chamada_procedimento() || comando_composto() || comando_condicional() || comando_repetitivo());
        }
    }

    return 0;
}

int atribuicao()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (variavel())
        {
            if (prox == ":")
            {
                prox = PROXIMO(lin, ++numProx);
                if (prox == "=")
                {
                    prox = PROXIMO(lin, ++numProx);
                    return expressao();
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                while (prox != "i")
                {
                    prox = PROXIMO(lin, --numProx);
                }
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int chamada_procedimento()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (identificador())
        {
            while (prox != ";")
            {
                if (!lista_expressoes())
                {
                    return 0;
                }
                if (prox == ",")
                {
                    prox = PROXIMO(lin, ++numProx);
                }
                else if (prox != ";")
                {
                    return 0;
                }
            }
            return 1;
        }
        else if (prox == "r")
        {
            prox = PROXIMO(lin, ++numProx);
            while (prox != ";")
            {
                if (!lista_expressoes())
                {
                    return 0;
                }
                if (prox == ",")
                {
                    prox = PROXIMO(lin, ++numProx);
                }
                else if (prox != ";")
                {
                    return 0;
                }
            }
            return 1;
        }
        else if (prox == "w")
        {
            prox = PROXIMO(lin, ++numProx);
            if (prox == "r")
            {
                prox = PROXIMO(lin, ++numProx);
                while (prox != ";")
                {
                    if (!lista_expressoes())
                    {
                        return 0;
                    }
                    if (prox == ",")
                    {
                        prox = PROXIMO(lin, ++numProx);
                    }
                    else if (prox != ";")
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else
            {
                prox = PROXIMO(lin, --numProx);
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int comando_condicional()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (prox == "s")
        {
            prox = PROXIMO(lin, ++numProx);
            if (expressao())
            {
                if (prox == "t")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (comando_sem_rotulo())
                    {
                        if (prox == ";")
                        {
                            prox = PROXIMO(lin, ++numProx);
                            if (prox == "\n")
                            {
                                prox = PROXIMO(lin, ++numProx);
                            }
                        }
                        else
                        {
                            return 0;
                        }
                        if (prox == "e")
                        {
                            prox = PROXIMO(lin, ++numProx);
                            if (comando_sem_rotulo())
                            {
                                if (prox == ";")
                                {
                                    prox = PROXIMO(lin, ++numProx);
                                }
                                else
                                {
                                    return 0;
                                }
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int comando_repetitivo()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (prox == "w")
        {
            prox = PROXIMO(lin, ++numProx);
            if (expressao())
            {
                if (prox == "d")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (comando_sem_rotulo())
                    {
                        prox = PROXIMO(lin, ++numProx);
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int lista_expressoes()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (expressao())
        {
            while (expressao())
            {
                prox = PROXIMO(lin, ++numProx);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int expressao()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (expressao_simples())
        {
            while (relacao())
            {
                if (!expressao_simples())
                {
                    return 0;
                }
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int relacao()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (prox == "=")
        {
            prox = PROXIMO(lin, ++numProx);
            return 1;
        }
        else if (prox == "<")
        {
            prox = PROXIMO(lin, ++numProx);
            if (prox == "=" || prox == ">")
            {
                prox = PROXIMO(lin, ++numProx);
            }
            return 1;
        }
        else if (prox == ">")
        {
            prox = PROXIMO(lin, ++numProx);
            if (prox == "=")
            {
                prox = PROXIMO(lin, ++numProx);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int expressao_simples()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "+" || prox == "-")
        {
            prox = PROXIMO(lin, ++numProx);
        }
        if (!termo())
        {
            return 0;
        }
        else
        {
            while (prox == "+" || prox == "-" || prox == "o")
            {
                prox = PROXIMO(lin, ++numProx);
                if (!termo())
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int termo()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (!fator())
        {
            return 0;
        }
        else
        {
            while (prox == "*" || prox == "/" || prox == "a")
            {
                prox = PROXIMO(lin, ++numProx);
                if (!fator())
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int fator()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (variavel() || numero())
        {
            return 1;
        }
        else if (prox == "(")
        {
            prox = PROXIMO(lin, ++numProx);
            if (!expressao())
            {
                return 0;
            }
            if (prox == ")")
            {
                prox = PROXIMO(lin, ++numProx);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (prox == "n")
        {
            if (!fator())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int variavel()
{
    return identificador();
}

int numero()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        if (digitos(prox))
        {
            prox = PROXIMO(lin, ++numProx);
            while (digitos(prox))
            {
                prox = PROXIMO(lin, ++numProx);
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int identificador()
{
    if (prox == "\n")
    {
        prox = PROXIMO(lin, ++numProx);
    }

    while (prox != "\n" && prox != "\r" && numProx < lin.size())
    {
        if (prox == " ")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (prox == "\t")
        {
            prox = PROXIMO(lin, ++numProx);
            continue;
        }
        else if (letras(prox))
        {
            if (prox == "i")
            {
                prox = PROXIMO(lin, ++numProx);
                if (prox == "d")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (digitos(prox))
                    {
                        prox = PROXIMO(lin, ++numProx);
                        while (digitos(prox))
                        {
                            prox = PROXIMO(lin, ++numProx);
                        }
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    return 0;
}