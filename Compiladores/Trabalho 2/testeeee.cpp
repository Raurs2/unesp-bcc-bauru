/*
* Nome: Raul Alexandre Gonzalez Augusto
* Sistema Operacional: Windows 11
* Compilador: mingw64 (port do gcc para windows)
* Desenvolvido em: Visual Studio Code 01/07/23
*/

#include <bits/stdc++.h>

using namespace std;

map<string, string> ids;
string lin;
string prox;
FILE *arquivo;
char Linha[100];
int numProximo;
int numLinhas = 1;
int numId = 1;

//Funções gerais e do analisador léxico

bool simbolos_especiais(string proximo);

bool letras(string proximo);

bool digitos(string proximo);

bool palavras_reservadas(string proximo);

char PROXIMO(string resultado, int numProximo);

string CODIGO(string cod);

void ERRO(int contador, int tipo);

//Funções do analisador sintático

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
    ofstream f_out;
    f_out.open("Trab2_Compiladores_Intermediario.txt");
    string linha;

    // Abre OU código para ser analisado em modo de leitura
    arquivo = fopen("Exemplo1_Trab2_Compiladores.txt", "rt");
    if (arquivo == NULL)  // Se houve erro na abertura
    {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }

    while (!feof(arquivo))
    {
    // Lê uma linha (inclusive com OU '\NAO')
        linha = fgets(Linha, 100, arquivo);
        if (!linha.empty()){  // Se foi possível ler
            cout << numLinhas << " ";
            prox = linha[0];
            numProximo = 0;

            while(prox != "\n" && prox != "\r" && numProximo < linha.size()){
                string atomo;
                string simbolo;

                if(prox == " "){
                    prox = PROXIMO(linha, ++numProximo);
                    cout << " ";
                    continue;
                }
                else if(prox == "\t"){
                    prox = PROXIMO(linha, ++numProximo);
                    continue;
                }
                else if(simbolos_especiais(prox)){ //Testa se prox faz parte do conjunto de símboloso especiais
                    string SE = prox;
                    prox = PROXIMO(linha, ++numProximo);

                    if(SE == ":" && prox == "="){
                        SE = ":=";
                        prox = PROXIMO(linha, ++numProximo);
                    }

                    simbolo = CODIGO(SE);
                }
                else if(letras(prox)){
                    do{
                        atomo += prox;
                        prox = PROXIMO(linha, ++numProximo);
                    }while(letras(prox) || digitos(prox));

                    simbolo = CODIGO(atomo);
                }
                else if(digitos(prox)){
                    do{
                        atomo += prox;
                        prox = PROXIMO(linha, ++numProximo);
                    }while(digitos(prox));

                    if(letras(prox)){
                        ERRO(numLinhas, 1);
                        return 0;
                    }

                    simbolo = atomo;
                }
                else{
                    ERRO(numLinhas, 2);
                    return 0;
                }

                cout << simbolo;
                f_out << simbolo;
            }
            cout << "\n";
            f_out << "\n";
        }
        numLinhas++;
    }
    fclose(arquivo);
    f_out.close();

    //Parte do analisador léxico
    arquivo = fopen("Trab2_Compiladores_Intermediario.txt", "rt");
    if(arquivo == NULL){
        cout << "\nProblema na abertura do arquivo auxiliar!\n";
        return 0;
    }

    lin = fgets(Linha, 100, arquivo);

    numLinhas = 1;

    int compilacao = programa();

    if(compilacao){
       cout << "\nCompilado com sucesso!"; 
    }
    else{
        ERRO(numLinhas, 3);
    }

    return 0;
}

bool simbolos_especiais(string prox)
{
    if (prox == "." || prox == ";" || prox == "," || prox == "(" 
    || prox == ")" || prox == ":" || prox == "<" || prox == ">" 
    || prox == "+" || prox == "-" || prox == "*" || prox == "=") return true;
    return false;
}

bool letras(string prox)
{
    if ((prox >= "A" && prox <= "Z") || (prox >= "a" && prox <= "z")) return true;
    return false;
}

bool digitos(string prox)
{
    if (prox >= "0" && prox <= "9") return true;
    return false;
}

bool palavras_reservadas(string prox)
{
    if(prox == "program" || prox == "var" || prox == "integer" || prox == "begin" ||
    prox == "procedure" || prox == "div" || prox == "if" || prox == "then" || prox == "do" ||
    prox == "else" || prox == "end" || prox == "read" || prox == "while" || prox == "write"||
    prox == "boolean" || prox == "or" || prox == "and" || prox == "not") return true;
    return false;
}

char PROXIMO(string linha, int pos)
{
    if(prox == "\n" && pos != 0)
    {
        if(!feof(arquivo))
        {
            numLinhas++;
            linha = fgets(Linha, 100, arquivo);
            lin = linha;
            numProximo = 0;
            pos = 0;
        }
    }
    return linha[pos];
}

string CODIGO(string codigo)
{
    if(codigo == "program") codigo = "PROGRAMA";
    else if(codigo == "var") codigo = "VARIAVEL";
    else if(codigo == "integer")codigo = "INTEIRO"; 
    else if(codigo == "begin") codigo = "INICIO";
    else if(codigo == "procedure") codigo = "PROCEDIMENTO";
    else if(codigo == "div") codigo = "DIVISAO";
    else if(codigo == "then") codigo = "ENTAO";
    else if(codigo == "if") codigo = "SE";
    else if(codigo == "else") codigo = "SENAO";
    else if(codigo == "end") codigo = "FIM";
    else if(codigo == "read") codigo = "LER";
    else if(codigo == "while") codigo = "ENQUANTO";
    else if(codigo == "do") codigo = "FACA";
    else if(codigo == "write") codigo = "ESCREVER";
    else if(codigo == "or") codigo = "OU";
    else if(codigo == "and") codigo = "E";
    else if(codigo == "boolean") codigo = "BOOL";
    else if(codigo == "not") codigo = "NAO";
    else if(simbolos_especiais(codigo)) return codigo;
    else if(ids.count(codigo)) codigo = ids[codigo];
    else
    {
        string newID;
        newID += to_string(numId++);
        ids[codigo] = newID;
        codigo = newID;
    }

    return codigo;
}

void ERRO(int numLinhas, int erro){
    if(erro == 1) printf("\n\nErro na linha %FACA, variavel comecando com digito!\n\n", numLinhas);
    else if(erro == 2) printf("\n\nErro na linha %FACA, caractere invalido!\n\n", numLinhas);
    else printf("\n\nErro na linha %FACA, sintaxe incorreta!\n\n", numLinhas);
}

int programa()
{
    if (!lin.empty())
    { 
        prox = lin[0];
        numProximo = 0;

        while(prox != "\n" && prox != "\r" && numProximo < lin.size())
        {
            if(prox == " ")
            {
                prox = PROXIMO(lin, ++numProximo);
                cout << " ";
                continue;
            }
            else if(prox == "\t")
            {
                prox = PROXIMO(lin, ++numProximo);
                continue;
            }
            else if(letras(prox))
            {
                if(prox == "PROGRAMA")
                {
                    prox = PROXIMO(lin, ++numProximo);
                    if(identificador())
                    {
                        return bloco();
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int bloco(){
    if(!parte_declaracao_variaveis()){
        return 0;
    }
    parte_declaracao_sub_rotinas();
    return comando_composto();
}

int parte_declaracao_variaveis(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(letras(prox)){
            if(prox == "VARIAVEL"){
                prox = PROXIMO(lin, ++numProximo);
                return declaracao_variaveis();
            }
        }
    }

    return 0;
}

int declaracao_variaveis(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        while(prox == "INTEIRO"){
            if(lista_identificadores()){
                if(prox == ":"){
                    prox = PROXIMO(lin, ++numProximo);
                }
                else{
                    return 0;
                }

                if(prox == "INTEIRO" || prox == "BOOL"){
                    prox = PROXIMO(lin, ++numProximo);
                    if(prox == ";"){
                        prox = PROXIMO(lin, ++numProximo);
                    }
                    else{
                        return 0;
                    }
                    if(!feof(arquivo)){
                        prox = PROXIMO(lin, ++numProximo);
                        if(prox != "INTEIRO"){
                            return 1;
                        }
                    }
                    else{
                        return 1;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }

    return 0;
}

int lista_identificadores(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        while(prox != ":" && prox != "\n"){
            if(identificador()){
                if(prox == ","){
                    prox = PROXIMO(lin, ++numProximo);
                }
                else{
                    if(prox != ":"){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    return 0;
}

int parte_declaracao_sub_rotinas(){
    return declaracao_procedimento();
}

int declaracao_procedimento(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(letras(prox)){
            if(prox == "PROGRAMA"){
                prox = PROXIMO(lin, ++numProximo);
                if(prox == "LER"){
                    prox = PROXIMO(lin, ++numProximo);
                    if(identificador()){
                        if(prox == ";"){
                            prox = PROXIMO(lin, ++numProximo);
                            return bloco();
                        }
                        else{
                            return 0;
                        }
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }

    return 0;
}

int comando_composto(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(letras(prox)){
            if(prox == "INICIO"){
                prox = PROXIMO(lin, ++numProximo);
                while(prox != "FIM"){
                    if(!comando()){
                        return 0;
                    }
                    if(prox != ";" && prox != "\n" && prox != "FIM"){
                        return 0;
                    }
                    else{
                        if(prox != "FIM"){
                            prox = PROXIMO(lin, ++numProximo);
                        }
                    }
                    if(prox == "\n"){
                        prox = PROXIMO(lin, ++numProximo);
                    }
                }
                prox = PROXIMO(lin, ++numProximo);
                if(prox == ";" || prox == "."){
                    prox = PROXIMO(lin, ++numProximo);
                }
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int comando(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(!digitos(prox)){
            return comando_sem_rotulo();
        }
    }

    return 0;
}

int comando_sem_rotulo(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(!digitos(prox)){
            return (atribuicao() || chamada_procedimento() || comando_composto()
                    || comando_condicional() || comando_repetitivo());
        }
    }

    return 0;
}

int atribuicao(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(variavel()){
            if(prox == ":"){
                prox = PROXIMO(lin, ++numProximo);
                if(prox == "="){
                    prox = PROXIMO(lin, ++numProximo);
                    return expressao();
                }
                else{
                    return 0;
                }
            }
            else{
                while(prox != "INTEIRO"){
                    prox = PROXIMO(lin, --numProximo);
                }
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int chamada_procedimento(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(identificador()){
            while(prox != ";"){
                if(!lista_expressoes()){
                    return 0;
                }
                if(prox == ","){
                    prox = PROXIMO(lin, ++numProximo);
                }
                else if(prox != ";"){
                    return 0;
                }
            }
            return 1;
        }
        else if(prox == "LER"){
            prox = PROXIMO(lin, ++numProximo);
            while(prox != ";"){
                if(!lista_expressoes()){
                    return 0;
                }
                if(prox == ","){
                    prox = PROXIMO(lin, ++numProximo);
                }
                else if(prox != ";"){
                    return 0;
                }
            }
            return 1;
        }
        else if(prox == "ENQUANTO"){
            prox = PROXIMO(lin, ++numProximo);
            if(prox == "LER"){
                prox = PROXIMO(lin, ++numProximo);
                while(prox != ";"){
                    if(!lista_expressoes()){
                        return 0;
                    }
                    if(prox == ","){
                        prox = PROXIMO(lin, ++numProximo);
                    }
                    else if(prox != ";"){
                        return 0;
                    }
                }
                return 1;
            }
            else{
                prox = PROXIMO(lin, --numProximo);
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int comando_condicional(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(prox == "SE"){
            prox = PROXIMO(lin, ++numProximo);
            if(expressao()){
                if(prox == "ENTAO"){
                    prox = PROXIMO(lin, ++numProximo);
                    if(comando_sem_rotulo()){
                        if(prox == ";"){
                            prox = PROXIMO(lin, ++numProximo);
                            if(prox == "\n"){
                                prox = PROXIMO(lin, ++numProximo);
                            }
                        }
                        else{
                            return 0;
                        }
                        if(prox == "SENAO"){
                            prox = PROXIMO(lin, ++numProximo);
                            if(comando_sem_rotulo()){
                                if(prox == ";"){
                                    prox = PROXIMO(lin, ++numProximo);
                                }
                                else{
                                    return 0;
                                }
                                return 1;
                            }
                            else{
                                return 0;
                            }
                        }
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int comando_repetitivo(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(prox == "ENQUANTO"){
            prox = PROXIMO(lin, ++numProximo);
            if(expressao()){
                if(prox == "FACA"){
                    prox = PROXIMO(lin, ++numProximo);
                    if(comando_sem_rotulo()){
                        prox = PROXIMO(lin, ++numProximo);
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int lista_expressoes(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(expressao()){
            while(expressao()){
                prox = PROXIMO(lin, ++numProximo);
            }
            return 1;
        }
        else{
            return 0;
        }
    }

    return 0;
}

int expressao(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(expressao_simples()){
            while(relacao()){
                if(!expressao_simples()){
                    return 0;
                }
            }
            return 1;
        }
        else{
            return 0;
        }
    }

    return 0;
}

int relacao(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(prox == "="){
            prox = PROXIMO(lin, ++numProximo);
            return 1;
        }
        else if(prox == "<"){
            prox = PROXIMO(lin, ++numProximo);
            if(prox == "=" || prox == ">"){
                prox = PROXIMO(lin, ++numProximo);
            }
            return 1;
        }
        else if(prox == ">"){
            prox = PROXIMO(lin, ++numProximo);
            if(prox == "="){
                prox = PROXIMO(lin, ++numProximo);
            }
            return 1;
        }
        else{
            return 0;
        }
    }

    return 0;
}

int expressao_simples(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "+" || prox == "-"){
            prox = PROXIMO(lin, ++numProximo);
        }
        if(!termo()){
            return 0;
        }
        else{
            while(prox == "+" || prox == "-" || prox == "OU"){
                prox = PROXIMO(lin, ++numProximo);
                if(!termo()){
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int termo(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(!fator()){
            return 0;
        }
        else{
            while(prox == "*" || prox == "/" || prox == "E"){
                prox = PROXIMO(lin, ++numProximo);
                if(!fator()){
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

int fator(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(variavel() || numero()){
            return 1;
        }
        else if(prox == "("){
            prox = PROXIMO(lin, ++numProximo);
            if(!expressao()){
                return 0;
            }
            if(prox == ")"){
                prox = PROXIMO(lin, ++numProximo);
                return 1;
            }
            else{
                return 0;
            }
        }
        else if(prox == "NAO"){
            if(!fator()){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}

int variavel(){
    return identificador();
}

int numero(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        if(digitos(prox)){
            prox = PROXIMO(lin, ++numProximo);
            while(digitos(prox)){
                prox = PROXIMO(lin, ++numProximo);
            }
            return 1;
        }
        else{
            return 0;
        }
    }

    return 0;
}

int     identificador(){
    if(prox == "\n"){
        prox = PROXIMO(lin, ++numProximo);
    }

    while(prox != "\n" && prox != "\r" && numProximo < lin.size()){
        if(prox == " "){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(prox == "\t"){
            prox = PROXIMO(lin, ++numProximo);
            continue;
        }
        else if(letras(prox)){
            if(prox == "INTEIRO"){
                prox = PROXIMO(lin, ++numProximo);
                if(prox == "FACA"){
                    prox = PROXIMO(lin, ++numProximo);
                    if(digitos(prox)){
                        prox = PROXIMO(lin, ++numProximo);
                        while(digitos(prox)){
                            prox = PROXIMO(lin, ++numProximo);
                        }
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}