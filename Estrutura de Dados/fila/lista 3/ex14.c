/*
   Raul Alexandre Gonzalez Augusto RA 211023698
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no* prox;
} *def_fila;

int vazia(def_fila inicio)
{
    return (inicio == NULL);
}

def_fila cria_no(int numero)
{	
    def_fila q = (def_fila) malloc(sizeof(struct no));

    q->dado=numero;
    q->prox=NULL;

    return q;
}

void enfileira(def_fila* inicio, def_fila* final, int numero)
{ 
    def_fila q = cria_no(numero);

    if (*final != NULL) (*final)->prox=q;
    else *inicio=q;
    
    *final=q;
}

int desenfileira(def_fila* inicio, def_fila* final, int* numero)
{ 
    def_fila q;

    if (*inicio == NULL) return 0;

    q = *inicio;
    *inicio = (*inicio)->prox;

    if (*inicio == NULL) *final=NULL;

    *numero = q->dado;
    free(q);

    return 1;
}

void visualiza(def_fila inicio)
{ 
    def_fila q;

    q=inicio;
    while (q != NULL)
    {
        printf("%d ", q->dado);
        q=q->prox;
    }
    printf("\n");
}

int operacao(int cod, int t[])
{
    if (cod == 0)
    {
        t[0]++;
        return 10;
    } 
    else if (cod == 1)
    {
        t[1]++;
        return 20;
    }  
    else if (cod == 2)
    {
        t[2]++;
        return 30;
    } 
    else if (cod == 3)
    {
        t[3]++;
        return 40;
    } 
    else if (cod == 4)
    {
        t[4]++;
        return 50;
    } 
    else if (cod == 5)
    {
        t[5]++;
        return 60;
    } 
    else if (cod == 6)
    {
        t[6]++;
        return 70;
    } 
    else if (cod == 7)
    {
        t[7]++;
        return 80;
    } 
}

void imprimeOperacoes()
{
    printf("Transacao                      Codigo  Tempo(seg)\n");
    printf("Saldo                            0       10\n");
    printf("Saque                            1       20\n");
    printf("Aplicacao                        2       30\n");
    printf("Extrato Semanal                  3       40\n");
    printf("Extrato Mensal                   4       50\n");
    printf("Pagamento de conta em dinheiro   5       60\n");
    printf("Pagamento de conta em cheque     6       70\n");
    printf("Pagamento de conta com saque     7       80\n");
    printf("\noperacao do cliente: ");
}

int main()
{   
    def_fila filaI, filaF, auxI, auxF;
    int cod;
    int op;

    filaI=filaF=NULL;
    auxI=auxF=NULL;

do
    {
        do
        {
            printf("\n1 - Inserir Clientes\n2 - Remover Clientes\n3 - Ver Fila\n4 - Iniciar expediente (for de 1000, cada i eh 1 seg)\n5 - Sair\n");
            scanf("%d", &op);
        } while (op < 1 && op > 5);

        if (op == 1)
        {
            imprimeOperacoes();
            
            scanf("%d", &cod);
            enfileira(&filaI, &filaF, cod);

        } else if (op == 2)
        {
            if (desenfileira(&filaI, &filaF, &cod))
            {
                printf("cliente %d Removida\n", cod);
            } else printf("Acabou os clientes\n");
        } else if (op == 3)
        {
            printf("\n");
            visualiza(filaI);
            printf("\n");
        } else if (op == 4)
        {
            int i, c1, c2, c3, free1, free2, free3;
            c1 = c2 = c3 = 0;
            free1 = free2 = free3 = 1;
            int t[8], atendidos = 0, naoAtendidos = 0;
            float totTempo = 0;

            for ( i = 0; i <= 7; i++)
                t[i] = 0;
            
            int temCliente = 1;
            i = 1000;
            while (temCliente)
            {
                if (free1)
                {
                    if (desenfileira(&filaI, &filaF, &cod))
                    {
                        c1 = operacao(cod, t);
                        atendidos++;
                        totTempo += c1;
                    } else temCliente = 0;
                }
                if (free2)
                {
                    if (desenfileira(&filaI, &filaF, &cod))
                    {
                        c2 = operacao(cod, t);
                        atendidos++;
                        totTempo += c2;
                    } else temCliente = 0;
                }
                if (free3)
                {
                    if (desenfileira(&filaI, &filaF, &cod))
                    {
                        c3 = operacao(cod, t);
                        atendidos++;
                        totTempo += c3;
                    } else temCliente = 0;
                }

                c1--;
                c2--;
                c3--;

                if (c1 > 0) free1 = 0;
                else
                {
                    free1 = 1;
                    c1 = 0;
                } 
                if (c2 > 0) free2 = 0;
                else
                {
                    free2 = 1;
                    c2 = 0;
                } 
                if (c3 > 0) free3 = 0;
                else
                {
                    free3 = 1;
                    c3 = 0;
                }

                if (i > 0)
                {
                    int entrou;
                    printf("Entrou Mais alguem? 1 - sim 0 - nao\n");
                    scanf("%d", &entrou);
                    if (entrou)
                    {
                        imprimeOperacoes();
                        scanf("%d", &cod);
                        enfileira(&filaI, &filaF, cod);
                    }
                }
                i--;
            }  
                totTempo /= (float) atendidos;

            while (desenfileira(&filaI, &filaF, &cod))
            {
                naoAtendidos++;
            }

            printf("Relatorio\n");
            printf("Tempo medio de espera %.2fseg\n", totTempo);
            printf("Atendidos: %d\nNao Atendidos: %d\n", atendidos, naoAtendidos);
            for ( i = 0; i <= 7; i++)
            {
                printf("Codigo %d quantidade: %d\n", i, t[i]);
            }
            
        }
    } while (op != 5);

    return 0;
}

