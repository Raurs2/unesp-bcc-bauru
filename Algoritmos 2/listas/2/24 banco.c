#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX 20
//número da conta, tipo da operação (crédito ou débito), valor.
typedef struct 
{
    int id;
    char nome[MAX];
    double saldo;
} cliente;

int menu()
{
    int op;
    do
    {
        printf("1 - Incluir\n2 - Remover\n3 - debito\n4 - credito\n5 - listar\n0 - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 0 && op > 5);
    return op;
}

void incluir(char file_name[])
{
    int op;
    FILE *arq;
    cliente c;

    if ((arq = fopen(file_name,"ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("id\n");
                scanf("%d", &c.id);
                printf("nome\n");
                scanf("%s", &c.nome);
                printf("saldo\n");
                scanf("%lf", &c.saldo);
                fwrite(&c, sizeof(cliente), 1, arq);
                printf("Adicionado com sucesso!");
                do
                {
                    printf("Add mais produtos?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq);
}

void apagar(char file_name[])
{
    int id;
    FILE *aux;
    FILE *arq;
    cliente c;
    if ((arq = fopen(file_name, "rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }
    
    aux = fopen("NOME.BAK", "wb");

    printf("Infome o ID do cliente que deseja remover\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
        if (id != c.id)
        {
            fwrite(&c, sizeof(c), 1, aux);
        }
    }
    
    fclose(arq);
    fclose(aux);
    
    remove(file_name);
    rename("NOME.BAK", file_name);

    printf("Removido com sucesso!");
    getch();
}

void debito_credito(char file_name[], int op)
{
    FILE *arq;
    cliente c;
    int id, achou = 0;

    if ((arq = fopen(file_name, "r+b")) == NULL)
    {
        printf ("Erro na abertura do arq.");
        exit (1);
    }
    
    if (op == 1) printf("Infome o ID do cliente que deseja creditar\n");
    if (op == 2) printf("Infome o ID do cliente que deseja debitar\n");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, arq) == 1 && !achou)
    {
        if (c.id == id)
        {
            double valor;
            printf("valor\n");
            scanf("%lf", &valor);
            c.saldo -= valor;
            fseek(arq, -sizeof(c), SEEK_CUR);
            fwrite(&c, sizeof(cliente), 1, arq);
            fflush(arq);
            achou = 1;
            printf("Alterado com sucesso!\n");
        }
    }
    
    fclose(arq);

    if (!achou)
    {
        printf("cliente nao registrado\n");
    }

    getch();
}

void listar(char file_name[])
{
    FILE *arq;
    cliente c;
    int i = 0;

    if ((arq = fopen(file_name,"rb")) == NULL)
    {
        printf ("Erro na abertura do arquivo.");
        exit (1);
    }

    while (fread(&c, sizeof(c), 1, arq) == 1)
    {
            printf("Id: %d\n", c.id);
            printf("nome: %s\n", c.nome);
            printf("Saldo: %.2lf\n\n", c.saldo);
    }
    getch();
    fclose(arq); 
}

int main()
{
    int op;
    char file_name[20] = "cliente.dat";
    do
    {
        op = menu();
        system("cls");
        if (op == 1) incluir(file_name);
        else if (op == 2) apagar(file_name);
        else if (op == 3) debito_credito(file_name, 2);
        else if (op == 4) debito_credito(file_name, 1);
        else if (op == 5) listar(file_name);
        system("cls");
    } while (op);
    
    return 0;
}
