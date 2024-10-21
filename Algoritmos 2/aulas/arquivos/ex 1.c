#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int dia, mes, ano;
} data;

typedef struct 
{
    int num;
    char nome[20];
    double saldo;
    data last_op;
} conta;

int main()
{
    int op;
    FILE *arq;
    conta c;
    do
    {
        do
        {
            printf("1 - gravar\n2 - ler\n0 - sair\n");
            scanf("%d", &op);
        } while (op < 0 && op > 2);

        if (op == 1)
        {
            if ((arq = fopen("contas.dat","ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("num da conta\n");
                scanf("%d", &c.num);
                printf("nome\n");
                scanf("%s", &c.nome);
                printf("saldo da conta\n");
                scanf("%lf", &c.saldo);
                printf("ultima operacao em\n");
                scanf("%d %d %d", &c.last_op.dia, &c.last_op.mes, &c.last_op.ano);
                fwrite(&c, sizeof(conta), 1, arq);

                do
                {
                    printf("Add mais contas?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq);
        }
        else if (op == 2)
        {
            if ((arq = fopen("contas.dat","rb")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            while (fread(&c, sizeof(conta), 1, arq) == 1)
            {
                printf("Num da conta: %d\n", c.num);
                printf("nome da conta: %s\n", c.nome);
                printf("saldo da conta: %lf\n", c.saldo);
                printf("ultima op da conta: %d/%d/%d\n", c.last_op.dia, c.last_op.mes, c.last_op.ano);
            }

            fclose(arq);
        }
    } while (op != 0);
    
    return 0;
}
