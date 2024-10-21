/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>

#define max  100

typedef float def_fila[max];

int vazia(int inicio, int final)
{
    return ((inicio == -1) || (inicio == final+1));
}

int cheia(int inicio, int final)
{
    return !((final-inicio+1) < max);
}


int enfileira (def_fila fila, int *inicio, int *final, float x)
{ 
    int i;
    if (cheia(*inicio, *final)) return 0;
    (*final)++;
    if (*final == max)
    {
        for(i=0;i<*final;i++) fila[i] = fila[(*inicio)+i];
        (*final) -= (*inicio);
        (*inicio) = 0;
    }
    fila[(*final)]=x;
    if ((*inicio) == -1) (*inicio) = 0;
    return 1;
}

int desenfileira (def_fila fila, int* inicio, int *final, float* x)
{
     if (vazia(*inicio, *final)) return 0;

     *x=fila[(*inicio)];
     fila[(*inicio)++]=-1;

     return 1;
}

void visualiza (def_fila fila, int inicio, int final)
{ 
    int i;

    if (final >= inicio && inicio != -1 && final != -1) {
        for(i=inicio; i<=final; i++) printf("%.2f ",fila[i]);}
    else
    {
        printf("Vazio\n");
    }
    printf("\n");
}



void main()
{
    def_fila fila, inteiro, decimal;
    int  op, iFila, iInt, iDec, fFila, fInt, fDec;
    float inte, deci, elemento;

    iFila = iInt = iDec = -1; 
    fFila = fInt = fDec = -1;

    do
    {
        do
        {
            printf("1 - incluir\n2 - Remover\n3 - ver\n4 - Separar\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);

        if (op == 1)
        {
            printf("elemento: ");
            scanf("%f", &elemento);

            if (!enfileira(fila, &iFila, &fFila, elemento))
            {
                printf("fila cheia\n");
            } else printf("Sucesso\n");
        } else if (op == 2)
        {
            if (desenfileira(fila, &iFila, &fFila, &elemento))
            {
                printf("elemento %.2f Removido\n", elemento);
            } else printf("Acabou os elementos\n");
        } else if (op == 3)
        {
            visualiza(fila, iFila, fFila);
            printf("\n");

            visualiza(inteiro, iInt, fInt);
            printf("\n");

            visualiza(decimal, iDec, fDec);
            printf("\n");
        } else if (op == 4)
        {
            while (desenfileira(fila, &iFila, &fFila, &elemento))
            {
                inte = (int) elemento;
                deci = elemento - inte;

                if (!enfileira(inteiro, &iInt, &fInt, inte))
                {
                    printf("fila cheia\n");
                } else printf("Sucesso\n");

                if (!enfileira(decimal, &iDec, &fDec, deci))
                {
                    printf("fila cheia\n");
                } else printf("Sucesso\n");
            }
        }
    } while (op != 5);
}
