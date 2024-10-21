/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>

#define max  5

typedef int def_fila[max];

int enfileira (def_fila fila, int x)
{ 
    int i;

    if (!((fila[1]-fila[0]+1)<(max-2))) return 0;

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
        for(i=2; i<=4; i++) printf("%d\t",fila[i]);
    }
    else{
        printf("Vazio\n");
    }
    printf("\n");
}



void main()
{
def_fila f1, f2, aux1, aux2;
int placa, saiu, manobras, placaAux, espera;
char op;

f1[0]=f1[1]=1;
aux1[0]=aux1[1]=1;
f2[0]=f2[1]=1;
aux2[0]=aux2[1]=1;

printf("Placa (numeros) entrar (c) sair (p)\n");
while (scanf("%d", &placa) != EOF)
{
    getchar();
    scanf("%c", &op);
    //printf("%d %c\n", placa, op);


    if (op == 'c')
    {
        if (enfileira(f1, placa))
        {
            printf("Carro estacionado\n");
        } else
        {
            printf("Estacionamento lotado\n");
            if (enfileira(f2, placa))
            {
                printf("Carro em fila de espera\n");
            } else
            {
                printf("Fila de espera lotada\n");
            }
            
        }
    } else if (op == 'p')
    {
        espera = manobras = 0;

        while (desenfileira(f2, &placaAux))
        {
            manobras++;
            if (placaAux == placa)
            {
                printf("Carro na fila de espera saiu\n");
                espera++;
            } else
            {
                enfileira(aux2, placaAux);
            }
            
        }

        while (desenfileira(aux2, &placaAux))
        {
            enfileira(f2, placaAux);
            manobras++;
        }
        
        if (espera) manobras = 0;
        else
        {
            while (desenfileira(f1, &placaAux))
            {
                manobras++;
                if (placaAux == placa)
                {
                    printf("Carro do estacionamento saiu\n");
                } else
                {
                    enfileira(aux1, placaAux);
                }
            }

            while (desenfileira(aux1, &placaAux))
            {
                enfileira(f1, placaAux);
                manobras++;
            }
        }
        

        printf("Manobras: %d\n", manobras);
    }
    
    printf("Estacionamento: \n");
    visualiza(f1);

    printf("Fila de espera: \n");
    visualiza(f2);
}

return 1;
}
