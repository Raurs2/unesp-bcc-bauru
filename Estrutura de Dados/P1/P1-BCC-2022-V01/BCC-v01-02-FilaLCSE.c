/*
   Fila Din‰mica  - Lista Circular

   inicio = final->prox

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


typedef struct no {
		  int tipo;
          struct no* prox;
        } *def_fila;

int vazia(def_fila Final){
     return (Final == NULL);
}

def_fila cria_no(int tipo){	
    def_fila q = (def_fila) malloc(sizeof(struct no));
    q->tipo=tipo;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Final, int tipo){ 
     def_fila q = cria_no(tipo);
     if (vazia(*Final)) (*Final)=q;
     else q->prox = (*Final)->prox;
     (*Final)->prox = q;
     *Final=q;
}

int desenfileira(def_fila* Final, int* tipo){ 
    def_fila q;

    if (vazia(*Final)) return 0;
    q = (*Final)->prox;
    *tipo = q->tipo; 
    if (q == *Final) *Final=NULL;
    else (*Final)->prox = q->prox;
    free(q);
    return 1;
}

void imprime(def_fila Final)
{ def_fila q;

    q = Final->prox;
    do{
		printf("\ntipo = %d", q->tipo);
        q=q->prox;
    }while (q != Final->prox);
    printf("\n\n");
}

void separacao_filas(def_fila *F0, def_fila *F1, def_fila *F2, def_fila *F3){
	 int tipo;
	 while (desenfileira(F0,&tipo))
		switch (tipo){
				case 1: enfileira (F1,tipo); break;
				case 2: enfileira (F2,tipo); break;
				case 3: enfileira (F3,tipo); break;
		}
}

int conta (def_fila *fila){
	def_fila fila_aux=NULL;
	int tipo, cont=0;
	while(desenfileira(fila,&tipo)){
		 cont++;
		 enfileira(&fila_aux,tipo);
	}
	while(desenfileira(&fila_aux,&tipo)){
		 enfileira(fila,tipo);
	}
	return cont;	
}

void main(void){
 	def_fila Fila_inicial, Fila_meia_entrada, Fila_social, Fila_inteira;
 	int N,M,item,idade,i,tempo,tipo;

 	Fila_inicial = Fila_meia_entrada = Fila_social = Fila_inteira = NULL;

	do{
		printf("\nEntre com o tipo de ingresso (ou -1 para sair):"); scanf("%d",&tipo);
		if(tipo !=-1)enfileira(&Fila_inicial,tipo);
	}while (tipo !=-1);
   
   if(vazia(Fila_inicial)) printf("\nFila vazia....");
   else { printf("\n\n\nImprimindo a fila...\n");imprime(Fila_inicial);}
   
   separacao_filas(&Fila_inicial, &Fila_meia_entrada, &Fila_social, &Fila_inteira);
   
   if(vazia(Fila_inicial)) printf("\nFila vazia....");
   else { 	printf("\n\n\nImprimindo a fila...\n");
   			imprime(Fila_inicial);
   			printf("\nCom %d pessoas",conta(&Fila_inicial));
		}
   
   if(vazia(Fila_meia_entrada)) printf("\nFila_meia_entrada vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_meia_entrada...\n");
   			imprime(Fila_meia_entrada);
   			printf("\nCom %d pessoas",conta(&Fila_meia_entrada));
		}
   			
   if(vazia(Fila_social)) printf("\nFila_social vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_social...\n");
   			imprime(Fila_social);
   			printf("\nCom %d pessoas",conta(&Fila_social));
		}
   			
   if(vazia(Fila_inteira)) printf("\nFila_inteira vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_inteira...\n");
   			imprime(Fila_inteira);
   			printf("\nCom %d pessoas",conta(&Fila_inteira));
		}
   			

    printf("\n\n\aTecle algo para encerrar ...");getch();
}
