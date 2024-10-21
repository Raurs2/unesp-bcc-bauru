/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>

#define max  3

typedef int def_fila[max];

int vazia(int Inicio, int Final){
    return ((Inicio == -1) || (Inicio == Final+1));
}

int cheia(int Inicio, int Final){
     return !((Final-Inicio+1) < max);
}


int enfileira (def_fila Fila, int *Inicio, int *Final, int x){ 
     int i;
     if (cheia(*Inicio, *Final)) return 0;
     (*Final)++;
     if (*Final == max){
         for(i=0;i<*Final;i++) Fila[i] = Fila[(*Inicio)+i];
         (*Final) -= (*Inicio);
    	 (*Inicio) = 0;}
    Fila[(*Final)]=x;
    if ((*Inicio) == -1) {
(*Inicio) = 0; }
    return 1;
}

int desenfileira (def_fila Fila, int* Inicio, int *Final, int* x){
     if (vazia(*Inicio,*Final)) return 0;
     *x=Fila[(*Inicio)];
     Fila[(*Inicio)++]=-1;
     return 1;
}

void visualiza (def_fila Fila, int Inicio, int Final){ 
     int i;

     if (Final >= Inicio && Final != -1 && Inicio != -1) {
	     for(i=Inicio; i<=Final; i++) printf("%d\t",Fila[i]);}
     else{
	     printf("Vazio");
		 }
     printf("\n");
}



void main()
{
def_fila f1, f2, aux1, aux2;
int placa, saiu, manobras, placaAux, espera;
char op;
int f1I, f1F, f2I, f2F, aux1I, aux1F, aux2I, aux2F; 
int isThere;
f1I = f1F = f2I = f2F = aux1I = aux1F = aux2I = aux2F = -1;

printf("Placa (numeros) entrar (c) sair (p)\n Executa enquanto entrada != EOF\n");
while (scanf("%d", &placa) != EOF)
{
    getchar();
    scanf("%c", &op);

    if (op == 'c')
    {
        if (enfileira(f1, &f1I, &f1F, placa))
        {
            printf("Carro estacionado\n");
        } else
        {
            printf("Estacionamento lotado\n");
            if (enfileira(f2, &f2I, &f2F, placa))
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

        while (desenfileira(f2, &f2I, &f2F, &placaAux))
        {
            if (placaAux == placa)
            {
                printf("Carro na fila de espera saiu\n");
                espera++;
            } else
            {
                enfileira(aux2, &aux2I, &aux2F, placaAux);
            }
            
        }

        while (desenfileira(aux2, &aux2I, &aux2F, &placaAux))
        {
            enfileira(f2, &f2I, &f2F, placaAux);
        }
        
        if (espera) manobras = 0;
        else
        {
            isThere = 0;
            while (desenfileira(f1, &f1I, &f1F, &placaAux))
            {
                if (!isThere)
                {
                    manobras++;
                }
                
                if (placaAux == placa)
                {
                    printf("Carro do estacionamento saiu\n");
                    isThere = 1;
                } else
                {
                    enfileira(aux1, &aux1I, &aux1F, placaAux);
                }
            }

            while (desenfileira(aux1, &aux1I, &aux1F, &placaAux))
            {
                enfileira(f1, &f1I, &f1F, placaAux);
            }

            while (!cheia(f1I, f1F) && !vazia(f2I, f2F))
            {
                desenfileira(f2, &f2I, &f2F, &placaAux);
                enfileira(f1, &f1I, &f1F, placaAux);
            }
        }
        
        printf("Manobras do carro: %d\n", manobras);

    }
    
    printf("Estacionamento: \n");
    visualiza(f1, f1I, f1F);

    printf("Fila de espera: \n");
    visualiza(f2, f2I, f2F);

    printf("\n\n");
}

return 1;
}
