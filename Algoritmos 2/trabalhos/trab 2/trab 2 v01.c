#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

/*
    Autores: Alberto & Raul
*/

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

// confirma e retorna sim true ou nao false
int confirmar()
{
    int op;

    do
    {
        printf("\nRealmente deseja exclui-lo?\nsim - [1]\nnao - [0]");
        scanf("%d", &op);
        system("cls");
    } while (op > 1 && op < 0);
    
    return op;
}

//funcao para remover logicamente
void remocao_logica(char nome_arquivo[MAX])
{
    FILE *arquivo;
    Livros livro;
    int achou = 0, isbn;

    // Abertura do arquivo
    if ((arquivo = fopen(nome_arquivo, "r+b")) == NULL)
    {
        printf ("\n Erro de abertura de arquivo.\n\n");
        getch();
        return;
    }

    //pega isbn que ira remover logicamente
    printf("Qual ISBN deseja excluir?");
    scanf("%d", &isbn);

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
        gotoxy(5, 6); printf("consultar\n");

        while ((tecla = getch()) != ENTER)
        {
            if (tecla == CIMA && y != 2)
            {
                gotoxy(0, y); printf("   ");
                y--;
                gotoxy(0, y); printf("-> ");
                op--;
            } else if (tecla == BAIXO && y != 6)
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
                op = -1;
                isRunning = 0;
                break;
            }
        }
        if (tecla == ENTER) isRunning = 0;
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
        for ( i = 0; i < strlen(c); i++)
            printf("%c", c[i] - 4);
    }

    //fecha arquivo
    fclose(arquivo);
}

int main()
{
    char nome_arquivo[MAX]  = "teste.dat";
    int op = menu();
    return 0;
}
