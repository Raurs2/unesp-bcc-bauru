#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int tel, duracao;
    char city[20];

} telefonia;

int main()
{
    FILE *arq1, *arq2;
    telefonia tele1, tele2;
    int op;
    do
    {
        do
        {
            printf("1 - gravar arq1\n2 - gravar arq2\n3- tel em comum\n0 - sair\n");
            scanf("%d", &op);
        } while (op < 0 && op > 3);

        if (op == 1)
        {
            if ((arq1 = fopen("tel1.dat","ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("telefone\n");
                scanf("%d", &tele1.tel);
                printf("cidade\n");
                scanf("%s", &tele1.city);
                printf("saldo da conta\n");
                scanf("%d", &tele1.duracao);
                fwrite(&tele1, sizeof(tele1), 1, arq1);

                do
                {
                    printf("Add mais contas?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq1);
        }
        else if (op == 2)
        {
            if ((arq2 = fopen("tel2.dat","ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("telefone\n");
                scanf("%d", &tele2.tel);
                printf("cidade\n");
                scanf("%s", &tele2.city);
                printf("saldo da conta\n");
                scanf("%d", &tele2.duracao);
                fwrite(&tele2, sizeof(tele2), 1, arq2);

                do
                {
                    printf("Add mais contas?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq2);
        }
        else if (op == 3)
        {
            if ((arq1 = fopen("tel1.dat","rb")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }
            if ((arq2 = fopen("tel2.dat","rb")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            while (fread(&tele1, sizeof(telefonia), 1, arq1))
            {
                while (fread(&tele2, sizeof(telefonia), 1, arq2))
                {
                    if (!strcmp(tele1.city, tele2.city))
                    {
                    printf("%s\n", tele1.city);
                    printf("%d\n", tele1.tel);
                    printf("%d\n", tele2.tel);
                    }
                }
            }

            fclose(arq1);
            fclose(arq2);
        }
        
    } while (op != 0);
    
    return 0;
}
