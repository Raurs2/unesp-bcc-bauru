/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define max  100

typedef char def_fila[max];

int vazia(int inicio, int final)
{
    return ((inicio == -1) || (inicio == final+1));
}

int cheia(int inicio, int final)
{
    return !((final-inicio+1) < max);
}


int enfileira (def_fila fila, int *inicio, int *final, char x)
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

int desenfileira (def_fila fila, int* inicio, int *final, char *x)
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
        for(i=inicio; i<=final; i++) printf("%c ",fila[i]);}
    else
    {
        printf("Vazio\n");
    }
    printf("\n");
}



void main()
{
    def_fila fila, vogal, consoante, especias;
    int  op, iFila, iVogal, iConso, fFila, fVogal, fConso, iEsp, fEsp;
    char str[max], c;
    int i = 0;
    iFila = iVogal = iConso = iEsp = -1; 
    fFila = fVogal = fConso = fEsp = -1;

    do
    {
        do
        {
            printf("1 - incluir\n2 - Remover\n3 - ver\n4 - Separar\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);

        if (op == 1)
        {
            printf("String: ");
            scanf("%s", &str);

            for ( i = 0; i < strlen(str); i++)
            {
                if (!enfileira(fila, &iFila, &fFila, str[i]))
                {
                    printf("fila cheia\n");
                } //else printf("Sucesso\n");
            }
        } else if (op == 2)
        {
            if (desenfileira(fila, &iFila, &fFila, &c))
            {
                printf("%c Removido\n", c);
            } else printf("Acabou os elementos\n");
        } else if (op == 3)
        {
            visualiza(fila, iFila, fFila);
            printf("\n");

            visualiza(vogal, iVogal, fVogal);
            printf("\n");

            visualiza(consoante, iConso, fConso);
            printf("\n");

            visualiza(especias, iEsp, fEsp);
            printf("\n");
        } else if (op == 4)
        {
            while (desenfileira(fila, &iFila, &fFila, &c))
            {
                c = tolower(c);
                if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
                {
                    if (!enfileira(vogal, &iVogal, &fVogal, c))
                    {
                        printf("fila cheia\n");
                    } //else printf("Sucesso\n");   
                } else if (c > 'a' && c <= 'z')
                {
                    if (!enfileira(consoante, &iConso, &fConso, c))
                    {
                        printf("fila cheia\n");
                    }// else printf("Sucesso\n");  
                } else
                {
                    if (!enfileira(especias, &iEsp, &fEsp, c))
                    {
                        printf("fila cheia\n");
                    }// elseprintf("Sucesso\n");  
                }
            }
        }
    } while (op != 5);
}
