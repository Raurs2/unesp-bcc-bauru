#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char nome[20];
    double sal;
} empregado;

int main()
{
    int op;
    FILE *arq, *arq2;
    empregado e1, e2;
    do
    {
        do
        {
            printf("1 - gravar\n2 - copiar\n0 - sair\n");
            scanf("%d", &op);
        } while (op < 0 && op > 2);

        if (op == 1)
        {
            if ((arq = fopen("a.dat","ab")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            do
            {
                printf("NOme\n");
                scanf("%s", &e1.nome);
                printf("salario\n");
                scanf("%lf", &e1.sal);
                fwrite(&e1, sizeof(empregado), 1, arq);

                do
                {
                    printf("Add mais empregados?\n1 - sim, 2 - nao\n");
                    scanf("%d", &op);
                } while (op < 1 && op > 2);
                
            } while (op == 1);

            fclose(arq);
        }
        else if (op == 2)
        {
            if ((arq2 = fopen("b.dat","wb")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }

            if ((arq = fopen("a.dat","rb")) == NULL)
            {
                printf ("Erro na abertura do arquivo.");
                exit (1);
            }
            
            while (fread(&e1, sizeof(empregado), 1, arq) == 1)
            {
                fwrite(&e1, sizeof(empregado), 1, arq2);
            }

            fclose(arq);
            fclose(arq2);
        }
    } while (op != 0);
    
    return 0;
}
