#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Raul Alexandre Gonzalez Augusto

typedef struct no_pilha
{
    unsigned int n;
    struct no_pilha *prox;
} *def_pilha;

def_pilha cria_no(unsigned int n1)
{	
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));
    q->n=n1;
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* pilha, unsigned int n1)
{
    def_pilha q = (def_pilha) malloc(sizeof(struct no_pilha));

    q->n = n1;

    q->prox = *pilha;
    (*pilha) = q;
}

int desempilha(def_pilha* pilha, unsigned int* n1)
{
	def_pilha q;

    if (*pilha==NULL) return 0;

    q = (*pilha);
    *n1 = q->n;

    (*pilha) = (*pilha)->prox;
    free(q);

    return 1;
}

void visualiza(def_pilha pilha)
{
    printf("\n");
    while (pilha != NULL)
    {
          printf("%u\n", pilha->n);
          pilha=pilha->prox;
    }
    printf("\n");
}


int main()
{
   int op;
   unsigned int n1, n2;
   char cmd;

   def_pilha pilha = NULL;

    printf("\nComandos 0 1 2 3 4 5 6 7 8 9 + - * / C E\nF - Sair\nV - ver pilha\n");
    do
    {
        scanf("%c", &cmd);
        if (cmd == 'F')
        {
            break;
        } else if (cmd == 'V')
        {
            visualiza(pilha);
        } else if (cmd == 'C')
        {
            while (desempilha(&pilha, &n1)) {}
            printf("Limpo\n");
        } else if (cmd == '+')
        {
            desempilha(&pilha, &n1);
            desempilha(&pilha, &n2);
            
            n1 += n2;

            empilha(&pilha, n1);
        } else if (cmd == '-')
        {
            desempilha(&pilha, &n1);
            desempilha(&pilha, &n2);
            
            n1 -= n2;

            empilha(&pilha, n1);
        } else if (cmd == '*')
        {
            desempilha(&pilha, &n1);
            desempilha(&pilha, &n2);
            
            n1 *= n2;

            empilha(&pilha, n1);
        } else if (cmd == '/')
        {
            desempilha(&pilha, &n1);
            desempilha(&pilha, &n2);
            
            n1 /= n2;

            empilha(&pilha, n1);
        }
        else if (cmd == 'E')
        {
            empilha(&pilha, 0);
        } else if (cmd >= '0' && cmd <= '9')
        {
            desempilha(&pilha, &n1);
            n1 *= 10;

            if (cmd == '9')
            {
                n1 += 9;
            } else if (cmd == '8')
            {
                n1 += 8;
            } else if (cmd == '7')
            {
                n1 += 7;
            } else if (cmd == '6')
            {
                n1 += 6;
            } else if (cmd == '5')
            {
                n1 += 5;
            } else if (cmd == '4')
            {
                n1 += 4;
            } else if (cmd == '3')
            {
                n1 += 3;
            } else if (cmd == '2')
            {
                n1 += 2;
            } else if (cmd == '1')
            {
                n1 += 1;
            }
            empilha(&pilha, n1);
        }
    } while (cmd != 'F');

   return 1;
}
