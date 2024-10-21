/*
   Fila Din‰mica  - Lista Circular

   inicio = final->prox

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct dados{
       int tipo;
       int caminho;
       };
typedef struct no {
		       struct dados info;
               struct no* prox;
               } *def_avenida;
typedef def_avenida rotatoria[5];

int vazia(def_avenida Fila){
     return (Fila == NULL);
}

def_avenida cria_no(struct dados dado){	
    def_avenida q = (def_avenida) malloc(sizeof(struct no));
    q->info=dado;
    q->prox=NULL;
    return q;
}

void enfileira(def_avenida* Fila, struct dados dado){ 
     def_avenida q = cria_no(dado);
     if (vazia(*Fila)) (*Fila)=q;
     else q->prox = (*Fila)->prox;
     (*Fila)->prox = q;
     *Fila=q;
}

int desenfileira(def_avenida* Fila, struct dados* dado){ 
    def_avenida q;

    if (vazia(*Fila)) return 0;
    q = (*Fila)->prox;
    *dado = q->info;
    if (q == *Fila) *Fila=NULL;
    else (*Fila)->prox = q->prox;
    free(q);
    return 1;
}
int policial (def_avenida *Avenida, rotatoria R){
    struct dados veiculo;
    while(desenfileira(Avenida, &veiculo)){
        switch(veiculo.tipo){
          case 1: if (veiculo.caminho == 4)  // carro quer ir para onde não pode
                     enfileira(&(R[4]),veiculo);
                  else enfileira(&(R[veiculo.caminho-1]),veiculo);
                  break; 
          case 2: if (veiculo.caminho == 1)  // caminhão quer ir para onde não pode
                      enfileira(&(R[1]),veiculo); 
                  else enfileira(&(R[veiculo.caminho-1]),veiculo);
                  break; 
          case 3: enfileira(&(R[veiculo.caminho-1]),veiculo); // ônibus
                  break; 
          case 4: if (veiculo.caminho == 2)  // moto quer ir para onde não pode
                      enfileira(&(R[2]),veiculo); 
                  else enfileira(&(R[veiculo.caminho-1]),veiculo);
                  break; 
          case 5: if (veiculo.caminho == 3)  // bicicletas quer ir para onde não pode
                      enfileira(&(R[3]),veiculo);    
                  else enfileira(&(R[veiculo.caminho-1]),veiculo);
                  break; 
          case 6: if (veiculo.caminho == 5)  // vans quer ir para onde não pode
                      enfileira(&(R[0]),veiculo);   
                  else enfileira(&(R[veiculo.caminho-1]),veiculo);
                  break;     
          } }
}

void imprime(def_avenida Fila)
{ def_avenida q;
  struct dados p;

    q = Fila->prox;
    do{  p = q->info; 
         printf("tipo=%d; \tcaminho=%d\n", p.tipo, p.caminho);
         q=q->prox;
    }while (q != Fila->prox);
    printf("\n\n");
}


int main(void)
{  def_avenida final;
	struct dados dado;
	rotatoria R;
   char op;
   int i;

    final=NULL;
    printf("Insercao de valores na fila... \n");
    do{
         printf("Inserir carro na Avenida (s/n)?...");op=getche();
         if (op=='s' || op=='S'){
            printf("\tTipo do carro (1..6) = ");scanf("%d",&(dado.tipo));
            printf("\tCaminho do carro (1..5) = ");scanf("%d",&(dado.caminho));
            enfileira(&final,dado); }
    }while (op=='s' || op=='S');
    if(!vazia(final)){ printf("\n\n\nImprimindo a fila na Avenida...\n");imprime(final);}
      
    
    for(i=0;i<5;i++) R[i]=NULL;
    policial(&final, R);
    for(i=0;i<5;i++){
        if(!vazia(R[i])){ printf("\n\n\nImprimindo a fila da R[%d]...\n",i+1);imprime(R[i]);}
        else printf("\n\n\nImprimindo a fila da R[%d]... Vazia\n",i+1);}
    
     printf("\n\n\aTecle algo para encerrar ...");getch();
}
