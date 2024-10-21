/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>

#define max  100

typedef int def_fila[max];

int enfileira (def_fila fila, int x)
{ 
    int i;

    if (!((fila[1]-fila[0]+1)<max)) return 0;

    fila[1]++;
    if (fila[1] == max)
    {
        for(i=2;i<fila[1];i++) fila[i] = fila[fila[0]+i];

        fila[1] -= fila[0];
        fila[0] = 2;
    }

    fila[fila[1]]=x;

    if (fila[0] == 1) fila[0] = 2;
    return 1;
}

int desenfileira (def_fila fila, int* x)
{
    if (fila[0] == 1 || (fila[0] == fila[1]+1)) return 0;

    *x=fila[fila[0]];
    fila[fila[0]++]=1;

    return 1;
}

void visualiza (def_fila fila)
{ 
    int i;

    if (fila[1] >= fila[0] && fila[0] != 1 && fila[1] != 1) 
    {
        for(i=fila[0]; i<=fila[1]; i++) printf("%d\t",fila[i]);
    }
    else{
        printf("Vazio\n");
    }
    printf("\n");
}



void main()
{
    def_fila fila;
    int  elemento,op;

    fila[0]=fila[1]=1;
    
    do
    {
        do
        {
            printf("1 - incluir\n2 - Remover\n3 - ver\n4 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 4);

        if (op == 1)
        {
            printf("elemento: ");
            scanf("%d", &elemento);

            if (!enfileira(fila, elemento))
            {
                printf("Fila cheia\n");
            } else printf("Sucesso\n");
        } else if (op == 2)
        {
            if (desenfileira(fila, &elemento))
            {
                printf("elemento %d Removido\n", elemento);
            } else printf("Acabou os elementos");
        } else if (op == 3)
        {
            visualiza(fila);
        }
        
    } while (op != 4);
}
