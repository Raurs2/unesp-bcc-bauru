/*
 * Nome: Raul Alexandre Gonzalez Augusto
 * Sistema Operacional: Windows 11
 * Compilador: mingw64 (port do gcc para windows)
 * Desenvolvido em: Visual Studio Code 10/07/23
 */

#include <bits/stdc++.h>

#define MAX 100

using namespace std;

//variaveis globais
map<string, string> ids;
string uni = "0", dez = "0", lin, prox;
FILE *arq_in;
ofstream arq_out;
char linha[MAX];
unsigned int numProx, tam;
int numLinhas = 1, numId = 1;

//Inicialização das funções
bool simbolos_especiais(string prox);
bool letras(string prox);
bool digitos(string prox);
bool palavras_reservadas(string prox);
char PROXIMO(string lin_atual, int numProx);
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

//abre arquivos
int open_file(char filename[])
{
    arq_in = fopen(filename, "rt");
    if (arq_in == NULL) 
    {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }
    return 1;
}

int main()
{
    //cria um arquivo intermediario
    arq_out.open("intermediario.txt");
    string lin_atual;

    // Abre o arquivo pascal
    if(!open_file("Exemplo1_Trab2_Compiladores.txt")) return 0;

    //varre ate o final do arquivo
    while (!feof(arq_in))
    {
        // Lê uma linha
        lin_atual = fgets(linha, MAX, arq_in);
        if (!lin_atual.empty()) // Se foi possível ler
        { 
            //cout << numLinhas << " ";
            prox = lin_atual[0];
            numProx = 0;

            tam = lin_atual.size();
            while (prox != "\n" && prox != "\r" && numProx < tam) // le letra por letra da linha
            {
                string atomo;
                string simbolo;

                if (prox == " ")
                {
                    prox = PROXIMO(lin_atual, ++numProx);
                    //cout << " ";
                    continue;
                }
                else if (prox == "\t")
                {
                    prox = PROXIMO(lin_atual, ++numProx);
                    continue;
                }
                else if (simbolos_especiais(prox)) //trata caso seja um simbolo especial
                { 
                    string str_temp = prox;
                    prox = PROXIMO(lin_atual, ++numProx);

                    //tratamento para o simbolo especial de dois char :=
                    if (str_temp == ":" && prox == "=")
                    {
                        str_temp = ":=";
                        prox = PROXIMO(lin_atual, ++numProx);
                    }

                    simbolo = CODIGO(str_temp);
                }
                else if (letras(prox)) //trata caso for uma palavra
                {
                    do
                    {
                        atomo += prox;
                        prox = PROXIMO(lin_atual, ++numProx);
                    } while (letras(prox) || digitos(prox));

                    simbolo = CODIGO(atomo);
                }
                else if (digitos(prox)) //trata caso for um digito
                {
                    do
                    {
                        atomo += prox;
                        prox = PROXIMO(lin_atual, ++numProx);
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

                //cout << simbolo;
                arq_out << simbolo;
            }
            //cout << "\n";
            arq_out << "\n";
        }
        numLinhas++;
    }
    //fecha os arquivos
    fclose(arq_in);
    arq_out.close();

    // abre o arquivo intermediario
    if(!open_file("intermediario.txt")) return 0;

    //pega uma linha
    lin = fgets(linha, MAX, arq_in);
    numLinhas = 1;

    //se o programa compilar exibe sucesso caso contrario mostra erro
    if (programa()) cout << "\nCompilado com sucesso!";
    else ERRO(numLinhas, 3);

    return 0;
}

//tratamento de simbolos especiais
bool simbolos_especiais(string prox)
{
    if (prox == "." || prox == ";" || prox == "," || prox == "(" 
    || prox == ")" || prox == ":" || prox == "<" || prox == ">" 
    || prox == "+" || prox == "-" || prox == "*" || prox == "="
    || prox == ":=") return true;
    return false;
}

//tratamento de letras
bool letras(string prox)
{
    if ((prox >= "A" && prox <= "Z") || (prox >= "a" && prox <= "z")) return true;
    return false;
}


//tratamento de digitos
bool digitos(string prox)
{
    if (prox >= "0" && prox <= "9") return true;
    return false;
}

//tratamento de palavras reservadas
bool palavras_reservadas(string prox)
{
    if (prox == "program" || prox == "var" || prox == "integer" || prox == "begin" ||
        prox == "procedure" || prox == "div" || prox == "if" || prox == "then" || prox == "do" ||
        prox == "else" || prox == "end" || prox == "read" || prox == "while" || prox == "write" ||
        prox == "boolean" || prox == "or" || prox == "and" || prox == "not") return true;
    return false;
}

//funcao para ler proximo caracter da linha
char PROXIMO(string lin_atual, int pos)
{
    if (prox == "\n" && pos != 0)
    {
        if (!feof(arq_in))
        {
            numLinhas++;
            lin_atual = fgets(linha, MAX, arq_in);
            lin = lin_atual;
            numProx = 0;
            pos = 0;
        }
    }
    return lin_atual[pos];
}

//transforma os simbolos e palavras especiais em novos para facilitar a montagem
string CODIGO(string cod)
{
    if (cod == "program") cod = "p";
    else if (cod == "var") cod = "v";
    else if (cod == "integer") cod = "i";
    else if (cod == "begin") cod = "b";
    else if (cod == "procedure") cod = "pr";
    else if (cod == "div") cod = "/";
    else if (cod == "then") cod = "t";
    else if (cod == "if") cod = "s";
    else if (cod == "else") cod = "e";
    else if (cod == "end") cod = "f";
    else if (cod == "read") cod = "r";
    else if (cod == "while") cod = "w";
    else if (cod == "do") cod = "d";
    else if (cod == "write") cod = "wr";
    else if (cod == "or") cod = "o";
    else if (cod == "and") cod = "a";
    else if (cod == "boolean") cod = "z";
    else if (cod == "not") cod = "n";
    else if (simbolos_especiais(cod)) return cod;
    else if (ids.count(cod)) cod = ids[cod];
    else
    {
        string str = "id";
        str += to_string(numId++);
        ids[cod] = str;
        return ids[cod];
    }

    return cod;
}

//tratamento de erros
void ERRO(int numLinhas, int tipo)
{
    if (tipo == 1) printf("\n\nErro na linha %d, variavel comecando com digito!\n\n", numLinhas);
    else if (tipo == 2) printf("\n\nErro na linha %d, caractere invalido!\n\n", numLinhas);
    else printf("\n\nErro na linha %d, sintaxe incorreta!\n\n", numLinhas);
}

//funcoes para tratamento sintaxo do pascal simplificado
//trata o programa
int programa()
{
    if (!lin.empty())
    { 
        prox = lin[0];
        numProx = 0;

        tam = lin.size();
        while (prox != "\n" && prox != "\r" && numProx < tam)
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
                if (prox == "p")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (identificador()) return bloco();
                    else return 0;
                }
        }
    }
    return 0;
}

//tratamento do bloco
int bloco()
{
    if (!parte_declaracao_variaveis()) return 0;
    parte_declaracao_sub_rotinas();
    return comando_composto();
}

//trata o bloco de declaracao de variaveis
int parte_declaracao_variaveis()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
            if (prox == "v")
            {
                prox = PROXIMO(lin, ++numProx);
                return declaracao_variaveis();
            }
    }

    return 0;
}

//trata a declaracao de variaveis
int declaracao_variaveis()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
            if (lista_identificadores())
            {
                if (prox == ":") prox = PROXIMO(lin, ++numProx);
                else return 0;

                if (prox == "i" || prox == "z")
                {
                    prox = PROXIMO(lin, ++numProx);
                    if (prox == ";") prox = PROXIMO(lin, ++numProx);
                    else return 0;
                    if (!feof(arq_in))
                    {
                        prox = PROXIMO(lin, ++numProx);
                        if (prox != "i") return 1;
                    }
                    else return 1;
                }
                else return 0;

            }
            else return 0;
    }

    return 0;
}

//tratamento dos identificadores
int lista_identificadores()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);
    
    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                if (prox == ",") prox = PROXIMO(lin, ++numProx);
                else if (prox != ":") return 0;
            }
        }
        return 1;
    }

    return 0;
}

//bloco de declaracao de sub rotinas
int parte_declaracao_sub_rotinas()
{
    return declaracao_procedimento();
}

//trata declaracao de procedimentos
int declaracao_procedimento()
{
    if (prox == "\n")
        prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                        else return 0;
                    }
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
    }

    return 0;
}

//trata comandos compostos
int comando_composto()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                    if (!comando()) return 0;
                    if (prox != ";" && prox != "\n" && prox != "f") return 0;
                    else if (prox != "f") prox = PROXIMO(lin, ++numProx);
                    if (prox == "\n") prox = PROXIMO(lin, ++numProx);
                }
                prox = PROXIMO(lin, ++numProx);
                if (prox == ";" || prox == ".") prox = PROXIMO(lin, ++numProx);
                return 1;
            }
            else return 0;
        }
        else return 0;
    }

    return 0;
}

//trata comandos
int comando()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
        else if (!digitos(prox)) return comando_sem_rotulo();
    }

    return 0;
}

//trata comandos sem rotulos
int comando_sem_rotulo()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

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
            return (atribuicao() || chamada_procedimento() || comando_composto() || comando_condicional() || comando_repetitivo());
    }

    return 0;
}

//trata a atribuicao
int atribuicao()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                else return 0;
            }
            else
            {
                while (prox != "i") prox = PROXIMO(lin, --numProx);
                return 0;
            }
        }
        else return 0;
    }
    return 0;
}

//trata a chamada de procedimentos
int chamada_procedimento()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                if (!lista_expressoes()) return 0;
                if (prox == ",") prox = PROXIMO(lin, ++numProx);
                else if (prox != ";") return 0;
            }
            return 1;
        }
        else if (prox == "r")
        {
            prox = PROXIMO(lin, ++numProx);
            while (prox != ";")
            {
                if (!lista_expressoes()) return 0;
                if (prox == ",") prox = PROXIMO(lin, ++numProx);
                else if (prox != ";") return 0;
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
                    if (!lista_expressoes()) return 0;
                    if (prox == ",") prox = PROXIMO(lin, ++numProx);
                    else if (prox != ";") return 0;
                }
                return 1;
            }
            else
            {
                prox = PROXIMO(lin, --numProx);
                return 0;
            }
        }
        else return 0;
    }

    return 0;
}

//trata os comandos condicionais
int comando_condicional()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                            if (prox == "\n") prox = PROXIMO(lin, ++numProx);
                        }
                        else return 0;
                        if (prox == "e")
                        {
                            prox = PROXIMO(lin, ++numProx);
                            if (comando_sem_rotulo())
                            {
                                if (prox == ";") prox = PROXIMO(lin, ++numProx);
                                else return 0;
                                return 1;
                            }
                            else return 0;
                        }
                        return 1;
                    }
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }

    return 0;
}

//trata comandos repetitivos
int comando_repetitivo()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }

    return 0;
}

//listagem das expressoes
int lista_expressoes()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
            while (expressao()) prox = PROXIMO(lin, ++numProx);
            return 1;
        }
        else return 0;
    }

    return 0;
}

//trata as expressoes
int expressao()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                if (!expressao_simples()) return 0;
            }
            return 1;
        }
        else return 0;
    }

    return 0;
}

//trata as relacoes
int relacao()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
            if (prox == "=" || prox == ">") prox = PROXIMO(lin, ++numProx);
            return 1;
        }
        else if (prox == ">")
        {
            prox = PROXIMO(lin, ++numProx);
            if (prox == "=") prox = PROXIMO(lin, ++numProx);
            return 1;
        }
        else return 0;
    }

    return 0;
}

//trata expressoes simples
int expressao_simples()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
        else if (prox == "+" || prox == "-") prox = PROXIMO(lin, ++numProx);
        if (!termo()) return 0;
        else
        {
            while (prox == "+" || prox == "-" || prox == "o")
            {
                prox = PROXIMO(lin, ++numProx);
                if (!termo()) return 0;
            }
            return 1;
        }
    }

    return 0;
}

//trata os termos
int termo()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

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
        if (!fator()) return 0;
        else
        {
            while (prox == "*" || prox == "/" || prox == "a")
            {
                prox = PROXIMO(lin, ++numProx);
                if (!fator()) return 0;
            }
            return 1;
        }
    }

    return 0;
}

//trata o fator
int fator()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
        if (variavel() || numero()) return 1;
        else if (prox == "(")
        {
            prox = PROXIMO(lin, ++numProx);
            if (!expressao()) return 0;
            if (prox == ")")
            {
                prox = PROXIMO(lin, ++numProx);
                return 1;
            }
            else return 0;
        }
        else if (prox == "n")
        {
            if (!fator()) return 0;
            else return 1;
        }
        else return 0;
    }

    return 0;
}

//trata as variaveis
int variavel()
{
    return identificador();
}

//trata os numeros
int numero()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
            while (digitos(prox)) prox = PROXIMO(lin, ++numProx);
            return 1;
        }
        else return 0;
    }

    return 0;
}


//trata os identificadoes
int identificador()
{
    if (prox == "\n") prox = PROXIMO(lin, ++numProx);

    tam = lin.size();
    while (prox != "\n" && prox != "\r" && numProx < tam)
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
                        while (digitos(prox)) prox = PROXIMO(lin, ++numProx);
                        return 1;
                    }
                    else return 0;
                }
                else return 0;
            }
            else return 0;
        }
        else return 0;
    }

    return 0;
}