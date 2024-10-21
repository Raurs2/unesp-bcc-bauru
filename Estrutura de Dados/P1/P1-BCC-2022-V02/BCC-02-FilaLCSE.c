/*
   Fila Din‰mica  - Lista Circular

   inicio = final->prox

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>


typedef struct no {
		  int andar;
          struct no* prox;
        } *def_fila;

int vazia(def_fila Final){
     return (Final == NULL);
}

def_fila cria_no(int andar){	
    def_fila q = (def_fila) malloc(sizeof(struct no));
    q->andar=andar;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Final, int andar){ 
     def_fila q = cria_no(andar);
     if (vazia(*Final)) (*Final)=q;
     else q->prox = (*Final)->prox;
     (*Final)->prox = q;
     *Final=q;
}

int desenfileira(def_fila* Final, int* andar){ 
    def_fila q;

    if (vazia(*Final)) return 0;
    q = (*Final)->prox;
    *andar = q->andar; 
    if (q == *Final) *Final=NULL;
    else (*Final)->prox = q->prox;
    free(q);
    return 1;
}

void imprime(def_fila Final)
{ def_fila q;

    q = Final->prox;
    do{
		printf("\nAndar = %d", q->andar);
        q=q->prox;
    }while (q != Final->prox);
    printf("\n\n");
}

void separacao_filas(def_fila *F0, def_fila *F1, def_fila *F2, def_fila *F3){
	 int andar;
	 while (desenfileira(F0,&andar))
		if((andar>=2) && (andar <=7)) enfileira (F1,andar);
		else 
			if((andar>=8) && (andar <=15)) enfileira (F2,andar);
			else
				if((andar>=16) && (andar <=21)) enfileira (F3,andar); 
}

int conta (def_fila *fila){
	def_fila fila_aux=NULL;
	int andar, cont=0;
	while(desenfileira(fila,&andar)){
		 cont++;
		 enfileira(&fila_aux,andar);
	}
	while(desenfileira(&fila_aux,&andar)){
		 enfileira(fila,andar);
	}
	return cont;	
}

void main(void){
 	def_fila Fila_inicial, Fila_elevador01, Fila_elevador02, Fila_elevador03;
 	int N,M,item,idade,i,tempo,andar;

 	Fila_inicial = Fila_elevador01 = Fila_elevador02 = Fila_elevador03 = NULL;

	do{
		printf("\nEntre com o andar (ou -1 para sair):"); scanf("%d",&andar);
		if(andar !=-1)enfileira(&Fila_inicial,andar);
	}while (andar !=-1);
   
   if(vazia(Fila_inicial)) printf("\nFila vazia....");
   else { printf("\n\n\nImprimindo a fila...\n");imprime(Fila_inicial);}
   
   separacao_filas(&Fila_inicial, &Fila_elevador01, &Fila_elevador02, &Fila_elevador03);
   
   if(vazia(Fila_inicial)) printf("\nFila vazia....");
   else { 	printf("\n\n\nImprimindo a fila...\n");
   			imprime(Fila_inicial);
   			printf("\nCom %d pessoas",conta(&Fila_inicial));
		}
   
   if(vazia(Fila_elevador01)) printf("\nFila_elevador01 vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_elevador01...\n");
   			imprime(Fila_elevador01);
   			printf("\nCom %d pessoas",conta(&Fila_elevador01));
		}
   			
   if(vazia(Fila_elevador02)) printf("\nFila_elevador02 vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_elevador02...\n");
   			imprime(Fila_elevador02);
   			printf("\nCom %d pessoas",conta(&Fila_elevador02));
		}
   			
   if(vazia(Fila_elevador03)) printf("\nFila_elevador03 vazia....");
   else { 	printf("\n\n\nImprimindo a Fila_elevador03...\n");
   			imprime(Fila_elevador03);
   			printf("\nCom %d pessoas",conta(&Fila_elevador03));
		}
   			

    printf("\n\n\aTecle algo para encerrar ...");getch();
}
