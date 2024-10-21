//Bibliotecas usadas
#include <sys/stat.h>
#include <windows.h>
#include <winbase.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

/*
    Autores: Alberto Azevedo Martinez & Raul Alexandre Gonzalez Augusto
    RA: 211023337 & 
*/

//Definindo valores que serão usados mais a frente
#define MAX 200
#define ESC 27
#define ENTER 13
#define BAIXO 80
#define CIMA 72
#define F1 59
#define BI 16

typedef struct 
{
    char titulo[MAX], autor[MAX], genero[MAX];
    int paginas, isEmprestado, isbn, existe;
} Livros;

void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int reprocessamento(){ //função que vai perguntar ao usuario se ele gostaria de usar o programa novamente
	int x, y = 2, i = 1;
	
	system("cls");
	
	gotoxy(0,0); printf("Voce deseja continuar utilizando o programa?\n");
	gotoxy(0,2); printf("-> ");
	gotoxy(5,2); printf("Sim\n");
	gotoxy(5,3); printf("Nao\n");
	
	while((x = getch()) != ESC && i){
		if(x == 0 || x == 224){
			switch(getch()){
				case CIMA:{
					if(y != 2){
						gotoxy(0,y); printf("   ");
						y--;
						gotoxy(0,y); printf("-> ");
						i--;
					}
					break;
				}
				case BAIXO:{
					if(y != 3){
						gotoxy(0,y); printf("   ");
						y++;
						gotoxy(0,y); printf("-> ");
						i++;
					}
					break;
				}
			}
		} else if(x == ENTER){
			if(i == 2){
				i = 0; break;
			} else {
				break;
			}
		}
	}
	if(x == ESC){
		i = 0;
	}
				
	system("cls");
	
	return i;
}

// confirma e retorna sim true ou nao false
int confirmar()
{
    int op;

    do
    {
        printf("\nRealmente deseja exclui-lo?\nsim - [1]\nnao - [0]\n");
        scanf("%d", &op);
        system("cls");
    } while (op > 1 && op < 0);
    
    return op;
}

int novoCad(){ //Função responsavel por perguntar se o usuario gostaria de fazer um novo cadatro
	int i;
    char resposta;
	
	system("cls");
	
	do{
		printf("Deseja adicionar um novo livro? (S/N)\n"); 
		scanf(" %c", &resposta);
		
		if(resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n'){ //IF responsavel de conferir se foi colocado uma resposta valida
			printf("Valor invalido! Por favor, digite novamente!\n");
		}
	}while(resposta != 'S' && resposta != 's' && resposta != 'N' && resposta != 'n');
	
    if(resposta == 'S' || resposta == 's'){ //If responsavel por transformar a resposta em 1 ou 0 para facilitar a leitura
        i = 1;
    } else{
        i = 0;
    }

	return i;
}

void cadastro(char nomeAq[]){ //Função responsavel por cadastrar um novo livro
    Livros livro;
    FILE *arquivo;
    char empres;


    //Abertura do arquivo
    if((arquivo = fopen(nomeAq, "a+b")) == NULL){
        printf("\n Erro de abertura de arquivo\n");
        exit(1);
    }
    do{
        system("cls");

        livro.existe = 1; //marca o livro como existente
        //A partir daqui é pedido os dados do livro para o usuario
        printf("Digite os seguintes dados do livro:\n\tISBN do livro: ");
        scanf("%d", &livro.isbn);
        printf("\tTitulo do livro: ");
        scanf("%s", livro.titulo);
        printf("\tAutor do livro: ");
        scanf("%s", livro.autor);
        printf("\tGenero do livro: ");
        scanf("%s", livro.genero);
        printf("\tQuantidade de paginas: ");
        scanf("%d", &livro.paginas);
        do{
            printf("\tO livro esta emprestado (S/N): ");
            scanf(" %c", &empres);

            //IF responsavel de conferir se foi colocado uma resposta valida
            if(empres != 'S' && empres != 's' && empres != 'N' && empres != 'n'){
                printf("\nValor invalido! Por favor, digite novamente!\n\n");
            }
        }while(empres != 'S' && empres != 's' && empres != 'N' && empres != 'n');

        //If responsavel por transformar a resposta em 1 ou 0 para facilitar a leitura
        if(empres == 'S' || empres == 's'){
            livro.isEmprestado = 1;
        } else{
            livro.isEmprestado = 0;
        }
        fwrite(&livro, sizeof(Livros), 1, arquivo); //grava no arquivo o novo cadastro
    }while(novoCad()); //Chama a função que pergunta de um novo cadrasto e repete ou não dependendo da resposta

    fclose(arquivo); //fecha o arquivo
}


void consultaIsbn(char nomeAq[]){ //Consulta os livros com o ISBN fornecido pelo usuario
    Livros livro;
    FILE *arquivo;
    int filtro, controle = 0;

    system("cls");

    if((arquivo = fopen(nomeAq, "rb")) == NULL){ //abre o arquivo
        printf("\n Erro de abertura de arquivo\n");
		exit(1);
    }

    printf("Digite qual ISBN deseja consultar: "); //parte responsavel por buscar o ID do livro que o usuario quer encontrar
    scanf("%d", &filtro);

    system("cls");

    while (fread (&livro, sizeof(Livros), 1, arquivo) == 1){ //Lê o arquivo
        if(livro.existe && filtro == livro.isbn){ //caso encontre um mesmo ISBN que o usuario digitou, ele mostrará as informações do livro
            printf("ISBN do livro: %d\n", livro.isbn);
            printf("Titulo do livro: %s\n", livro.titulo);
            printf("Nome do autor: %s\n", livro.autor);
            printf("Genero do livro: %s\n", livro.genero);
            printf("Numero de paginas: %d\n", livro.paginas);
            if(livro.isEmprestado){
                printf("O livro esta emprestado\n\n");
            } else{
                printf("O livro nao esta emprestado\n\n");
            }

            controle = 1;
        }
    }

    if(!controle){ //caso não seja achado nenhum livro com o ISBN fornecido pelo usuario, ele dá esse retorno de que o livro não está registrado
        printf ("Livro nao encontrado.\n\n");
    }

    system("pause");

    fclose(arquivo); //fecha o arquivo
}

void consultaTitulo(char nomeAq[]){ //Consulta os livros com o titulo fornecido pelo usuario
    Livros livro;
    FILE *arquivo;
    char filtro[MAX]; int controle = 0;

    system("cls");

    if((arquivo = fopen(nomeAq, "rb")) == NULL){ //abre o arquivo
        printf("\n Erro de abertura de arquivo\n");
		exit(1);
    }

    printf("Digite qual Titulo deseja consultar: "); //parte responsavel por buscar o Titulo do livro que o usuario quer encontrar
    scanf("%s", filtro);

    system("cls");

    while (fread (&livro, sizeof(Livros), 1, arquivo) == 1){ //Lê o arquivo
        if(livro.existe && strcmp(filtro, livro.titulo) == 0){ //caso encontre um mesmo Titulo que o usuario digitou, ele mostrará as informações do livro
            printf("ISBN do livro: %d\n", livro.isbn);
            printf("Titulo do livro: %s\n", livro.titulo);
            printf("Nome do autor: %s\n", livro.autor);
            printf("Genero do livro: %s\n", livro.genero);
            printf("Numero de paginas: %d\n", livro.paginas);
            if(livro.isEmprestado){
                printf("O livro esta emprestado\n\n");
            } else{
                printf("O livro nao esta emprestado\n\n");
            }

            controle = 1;
        }
    }

    if(!controle){ //caso não seja achado nenhum livro com o titulo fornecido pelo usuario, ele dá esse retorno de que o livro não está registrado
        printf ("Livro nao encontrado.\n\n");
    }

    system("pause");

    fclose(arquivo); //fecha o arquivo
}

void alterar(char nomeAq[]){ //Altera o livros com o ISBN fornecido pelo usuario
    Livros livro;
    FILE *arquivo;
    int controle = 0, filtro; char empres;

    system("cls");

    if((arquivo = fopen(nomeAq, "r+b")) == NULL){ //abre o arquivo
        printf("\n Erro de abertura de arquivo\n");
        exit(1);
    }

    printf("Digite qual ISBN deseja alterar: "); //parte responsavel por buscar o ID do livro que o usuario quer encontrar
    scanf("%d", &filtro);

    system("cls");

    while(fread (&livro, sizeof(Livros), 1, arquivo) == 1){ //Lê o arquivo
        if(livro.existe && filtro == livro.isbn){ //caso encontre um mesmo ISBN que o usuario digitou, ele pedirá as novas informações do livro
            printf("Digite os seguintes dados atualizados do livro:\n\tTitulo do livro: ");
            scanf("%s", livro.titulo);
            printf("\tNome do autor: ");
            scanf("%s", livro.autor);
            printf("\tGenero do livro: ");
            scanf("%s", livro.genero);
            printf("\tQuantidade de paginas: ");
            scanf("%d", &livro.paginas);
            do{
                printf("\tO livro esta emprestado (S/N): ");
                scanf(" %c", &empres);

                if(empres != 'S' && empres != 's' && empres != 'N' && empres != 'n'){
                    printf("\nValor invalido! Por favor, digite novamente!\n\n");
                }
            }while(empres != 'S' && empres != 's' && empres != 'N' && empres != 'n');

            if(empres == 'S' || empres == 's'){
                livro.isEmprestado = 1;
            } else{
                livro.isEmprestado = 0;
            }

            fseek (arquivo,-sizeof(Livros), SEEK_CUR);
            fwrite(&livro, sizeof(Livros), 1, arquivo);
            fflush (arquivo);

            controle = 1;
        }
    }

    if(!controle){  //caso não seja achado nenhum livro com o ISBN fornecido pelo usuario, ele dá esse retorno de que o livro não está registrado
        printf ("Livro nao encontrado.\n\n");
    }

    printf("\n");
    system("pause");
	
	fclose(arquivo); //fecha o arquivo
}

//funcao para remover logicamente
void remocao_logica(char nome_arquivo[MAX])
{
    FILE *arquivo;
    Livros livro;
    int achou = 0, isbn;

    system("cls");

    // Abertura do arquivo
    if ((arquivo = fopen(nome_arquivo, "r+b")) == NULL)
    {
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    //pega isbn que ira remover logicamente
    printf("Qual ISBN deseja excluir?\n");
    scanf("%d", &isbn);

    system("cls");

    // roda pelos livros ate achar o com mesmo isbn
    while (fread(&livro, sizeof(Livros), 1, arquivo) == 1 && !achou)
    {
        // se acha o livro vai perguntar se realmente deseja excluir se sim o livro sera excluido logicamente setando a var existe para 0
        if (livro.existe && livro.isbn == isbn)
        {
            printf("Livro: %s\nAutor: %s\n", livro.titulo, livro.autor);
            if (confirmar())
            {
                livro.existe = 0;
                fseek(arquivo, -sizeof(Livros), SEEK_CUR);
                fwrite(&livro, sizeof(Livros), 1, arquivo);
                fflush(arquivo);
                printf("Livro %s removido com sucesso!\n", livro.titulo);
            } else printf("Livro %s nao removido!\n", livro.titulo);

            achou = 1;
        }
    }

    if (!achou) printf("Livro nao registrado!\n");

    //fecha arquivo
    fclose(arquivo);
    getch();
}

//funcao para remover fisicamente
void remoca_fisica(char nome_arquivo[MAX])
{
    FILE *arquivo, *arquivo_temporario;
    Livros livro;

    system("cls");

    // Abertura do arquivo
    if ((arquivo = fopen(nome_arquivo, "rb")) == NULL)
    {
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }
    //cria arquivo temporario
    arquivo_temporario = fopen("temporario.dat", "wb");

    while (fread(&livro, sizeof(Livros), 1, arquivo) == 1)
    {
        //se o livro existir adicionara ele no arq temp
        if (livro.existe) fwrite(&livro, sizeof(Livros), 1, arquivo_temporario);
        
    }
    
    //fecha arquivo
    fclose(arquivo);
    fclose(arquivo_temporario);

    //remove o arquivo original e renomeia o arq temp com o nome do original
    remove(arquivo);
    rename("temporario.dat", nome_arquivo);
    printf("Remocao fisica realizada com sucesso!");

    getch();
}

// usa funcoes do cmd para alterar data e hora
void alterar_data_hora()
{
    system("cls");

    system("date"); printf("\n");
    system("time"); printf("\n");

    system("pause");
}

// cria uma nova pasta com o nome digitado
void criar_pasta()
{
    system("cls");

    char nomePasta[100];

    //recebe o nome da pasta
    printf("Digite o nome da pasta:\n");
    scanf("%s", &nomePasta);

    //cria a pasta
    if (!mkdir(nomePasta)) printf("Pasta criada com sucesso!\n\n");
    else printf("Pasta nao criada!\n\n");

    system("pause");
}

// renomeia arquivos e pastas
void renomear_pasta_arquivo()
{
    system("cls");

    char nome[100], novo_nome[100];

    //recebe nome do arquivo
    printf("Digite o nome do arquivo com sua extensao ou pasta que deseja renomear:\n");
    scanf("%s", &nome);

    //o novo nome
    printf("Digite o novo nome:\n");
    scanf("%s", &novo_nome);

    //renomeia o arquivo
    if (!rename(nome, novo_nome)) printf("Renomeado com sucesso!\n\n");
    else printf("Renomeado sem sucesso!\n\n");

    system("pause");
}

// remover arquivos e pastas
void remover_pasta_arquivo()
{
    system("cls");

    char nome[100];

    //recebe nome do arquivo
    printf("Digite o nome do arquivo com sua extensao ou pasta que deseja remover:\n");
    scanf("%s", &nome);

    //renomeia o arquivo
    if (!remove(nome)) printf("Removido com sucesso!\n\n");
    else printf("Removido sem sucesso!\n\n");

    system("pause");
}

//troca de diretorio
void mover_diretorio()
{
    system("cls");

    //mostra caminho atual
    char diretorio_atual[300];
	printf("Diretorio atual:\n%s\n\n", getcwd(diretorio_atual, 300));

    //pede novo caminho
    char novo_diretorio[300];
    printf("Digite o diretorio que deseja ir:\n");
    scanf("%s", &novo_diretorio);

    //troca de diretorio
    chdir(novo_diretorio);

    //mostra novo diretorio
    char novo[300];
    printf("\nDiretorio novo:\n%s\n\n", getcwd(novo, 300));

    system("pause");
}


//cria o menu
int menu() {
    int op = 1, y = 2, tecla, isRunning = 1;

    while (isRunning)
    {
        gotoxy(0, 0); printf("Menu  ------------------------ ESC -> Sair F1 -> ajuda");
        gotoxy(0, 2); printf("-> ");
        gotoxy(5, 2); printf("cadastrar\n");
        gotoxy(5, 3); printf("alterar\n");
        gotoxy(5, 4); printf("exclusao logica\n");
        gotoxy(5, 5); printf("exclusao fisica\n");
        gotoxy(5, 6); printf("consultar ISBN\n");
        gotoxy(5, 7); printf("consultar titulo\n");
        gotoxy(5, 8); printf("opcoes do sistema\n");

        while ((tecla = getch()) != ENTER)
        {
            if (tecla == CIMA && y != 2)
            {
                gotoxy(0, y); printf("   ");
                y--;
                gotoxy(0, y); printf("-> ");
                op--;
            } else if (tecla == BAIXO && y != 8)
            {
                gotoxy(0, y); printf("   ");
                y++;
                gotoxy(0, y); printf("-> ");
                op++;
            }
            if (tecla == F1)
            {
                system("cls");
                ajuda();
                system("pause");
                system("cls");
                break;
            }
            if (tecla == ESC)
            {
                op = 0;
                isRunning = 0;
                break;
            }
        }
        if (tecla == ENTER) isRunning = 0;
    }
    return op;
}

int menuOpcoes(){ //Cria o menu focado nas opções do sistema
    system("cls");

    int y = 2, op = 1, tecla, isRunning = 1;

    while (isRunning){
        gotoxy(0, 0); printf("Menu das opcoes -------------- ESC -> Sair F1 -> ajuda");
        gotoxy(0, 2); printf("-> ");
        gotoxy(5, 2); printf("alterar data e hora\n");
        gotoxy(5, 3); printf("criar pasta\n");
        gotoxy(5, 4); printf("renomear pasta ou arquivo\n");
        gotoxy(5, 5); printf("remover pasta ou arquivo\n");
        gotoxy(5, 6); printf("mover diretorio\n");

        while((tecla = getch()) != ENTER){
            if(tecla == CIMA && y != 2){
                gotoxy(0, y); printf("   ");
                y--;
                gotoxy(0, y); printf("-> ");
                op--;
            } else if(tecla == BAIXO && y != 6){
                gotoxy(0, y); printf("   ");
                y++;
                gotoxy(0, y); printf("-> ");
                op++;
            }
            if(tecla == ESC){
                op = 0;
                isRunning = 0;
                break;
            }
        }
        if(tecla == ENTER) isRunning = 0;
    }
    return op;
}

//seccao de ajuda com arq txt criptografado
void ajuda()
{
    FILE *arquivo;
    char c[MAX];

    // abre arquivo texto
    if ((arquivo = fopen("ajuda.txt", "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    //printa texto descriptografado
    while (fgets(c, MAX, arquivo) != NULL)
    {
        for (int i = 0; i < strlen(c); i++)
            printf("%c", c[i] - 4);
    }

    //fecha arquivo
    fclose(arquivo);
}

int main() //Função principal do sistema, aqui chamaremos as demais funções dependo da escolha do usuario
{ 
    char nome_arquivo[MAX]  = "teste.dat";
    int i;

    do{
        switch (menu()){
        case 0: {
            i = 0;
            break;
        }
        case 1:{
            cadastro(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 2:{
            alterar(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 3:{
            remocao_logica(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 4:{
            remoca_fisica(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 5:{
            consultaIsbn(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 6:{
            consultaTitulo(nome_arquivo);
            i = reprocessamento();
            break;
        }
        case 7:{
            switch(menuOpcoes()){
                case 0:{
                    i = 0;
                    break;
                }
                case 1:{
                    alterar_data_hora();
                    i = reprocessamento();
                    break;
                }
                case 2:{
                    criar_pasta();
                    i = reprocessamento();
                    break;
                }
                case 3:{
                    renomear_pasta_arquivo();
                    i = reprocessamento();
                    break;
                }
                case 4:{
                    remover_pasta_arquivo();
                    i = reprocessamento();
                    break;
                }
                case 5:{
                    mover_diretorio();
                    i = reprocessamento();
                    break;
                }
            }
            break;
        }
        default:
            break;
        }
    }while (i);

    system("cls");

    return 0;
}