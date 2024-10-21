#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <winbase.h>
#include <unistd.h> 
#include <sys/stat.h>

// usa funcoes do cmd para alterar data e hora
void alterar_data_hora()
{
    system("date");
    system("time");
}

// cria uma nova pasta com o nome digitado
void criar_pasta()
{
    char nomePasta[100];

    //recebe o nome da pasta
    printf("Digite o nome da pasta\n");
    scanf("%s", &nomePasta);

    //cria a pasta
    if (!mkdir(nomePasta)) printf("Pasta criada com sucesso!\n");
    else printf("Pasta não criada!");
}

// renomeia arquivos e pastas
void renomear_pasta_arquivo()
{
    char nome[100], novo_nome[100];

    //recebe nome do arquivo
    printf("Digite o nome do arquivo com sua extensao ou pasta que deseja renomear\n");
    scanf("%s", &nome);

    //o novo nome
    printf("Digite o novo nome\n");
    scanf("%s", &novo_nome);

    //renomeia o arquivo
    if (!rename(nome, novo_nome)) printf("Renomeado com sucesso!\n");
    else printf("Renomeado sem sucesso!\n");
}

// remover arquivos e pastas
void remover_pasta_arquivo()
{
    char nome[100];

    //recebe nome do arquivo
    printf("Digite o nome do arquivo com sua extensao ou pasta que deseja remover\n");
    scanf("%s", &nome);

    //renomeia o arquivo
    if (!remove(nome)) printf("Removido com sucesso!\n");
    else printf("Removido sem sucesso!\n");
}

//troca de diretorio
void mover_diretorio()
{
    //mostra caminho atual
    char diretorio_atual[300];
	printf("Diretorio atual:\n%s\n", getcwd(diretorio_atual, 300));

    //pede novo caminho
    char novo_diretorio[300];
    printf("Digite o diretorio que deseja ir\n");
    scanf("%s", &novo_diretorio);

    //troca de diretorio
    chdir(novo_diretorio);

    //mostra novo diretorio
    char novo[300];
    printf("\nDiretorio novo:\n%s\n", getcwd(novo, 300));
}
