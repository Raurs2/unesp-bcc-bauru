/*
   Fila Din‰mica  - Lista Linear Simplesmente Encadeada
   						com Descritor 
   Filas com elementos diferentes: figuras geometricas
   Uso de void*

*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define RET 1
#define TRI 2
#define CIR 3

typedef struct retangulo{
		    float base;
            float altura;
            } Retangulo;
typedef struct triangulo{
		    float base;
            float altura;
            } Triangulo;
typedef struct circulo{
		    float raio;
            } Circulo;

typedef struct lista {
		    int tipo;
            void *info;
            struct lista* prox;
            } lista_generica;

typedef struct no {
		    int tipo;
            void *info;
            } *No;

typedef struct descritor{
		    lista_generica* inicio;
            lista_generica* final;
            } *def_fila;

def_fila inicializa(void) { 	
   def_fila Fila;

   Fila = (def_fila)malloc(sizeof(struct descritor));
   Fila->inicio = Fila->final = NULL;
   return Fila;
}

int vazia(def_fila Fila){
     return (Fila->inicio == NULL);
}

lista_generica* cria_retangulo(float base, float altura){	
   Retangulo* R;
   lista_generica* p;

   R = (Retangulo*)malloc(sizeof(Retangulo));
   R->base = base;
   R->altura = altura;

   p = (lista_generica*)malloc(sizeof(lista_generica));
   p->tipo = RET;
   p->info = R;
   p->prox = NULL;

   return p;
}

lista_generica* cria_triangulo(float base, float altura){
   Triangulo* T;
   lista_generica* p;

   T = (Triangulo*)malloc(sizeof(Triangulo));
   T->base = base;
   T->altura = altura;

   p = (lista_generica*)malloc(sizeof(lista_generica));
   p->tipo = TRI;
   p->info = T;
   p->prox = NULL;

   return p;
}

lista_generica* cria_circulo(float raio){	
   Circulo* C;
   lista_generica* p;

   C = (Circulo*)malloc(sizeof(Circulo));
   C->raio = raio;

   p = (lista_generica*)malloc(sizeof(lista_generica));
   p->tipo = CIR;
   p->info = C;
   p->prox = NULL;

   return p;
}

void enfileira(def_fila* Fila, lista_generica* dado) {
     if (vazia(*Fila)) (*Fila)->inicio = dado;
     else (*Fila)->final->prox = dado;
     (*Fila)->final=dado;
}

int desenfileira(def_fila* Fila, No* dado){  
    lista_generica* q;
    No informe = (No)malloc(sizeof(struct no));

    if (vazia(*Fila)) return 0;
    q = (*Fila)->inicio;
    informe->tipo = q->tipo;
    switch (q->tipo){
          	case RET:   informe->info = (Retangulo*)q->info;
            				break;
          	case TRI:   informe->info = (Triangulo*)q->info;
            				break;
          	case CIR:   informe->info = (Circulo*)q->info;
            				break;
            }
    *dado=informe;
    if ((*Fila)->inicio == (*Fila)->final)
         	(*Fila)->final=NULL;
    (*Fila)->inicio = q->prox;
    free(q);
    return 1;
}

void imprime(def_fila Fila){  
   lista_generica* q;
   Retangulo *R;
   Triangulo *T;
   Circulo *C;

    q = Fila->inicio;
    while (q != NULL){
    		 switch (q->tipo){
          	case RET:   R = (Retangulo*)q->info;
            		    printf("A base do retangulo e: %.2f\t e a altura:%.2f\n", R->base,R->altura);
            		    break;
          	case TRI:   T = (Triangulo*)q->info;
            		    printf("A base do triangulo e: %.2f\t e a altura:%.2f\n", T->base,T->altura);
            		    break;
          	case CIR:   C = (Circulo*)q->info;
            		    printf("O raio do circulo e: %.2f\n", C->raio);
            		    break;
            }
          q=q->prox;}
    printf("\n\n");
}

void imprime_no(No Info){
   Retangulo *R;
   Triangulo *T;
   Circulo *C;

   printf("\nImprimindo o no removido:\t");
   switch (Info->tipo){
          	case RET:   R = (Retangulo*)Info->info;
            				printf("A base do retangulo e: %.2f\t e a altura:%.2f\n", R->base,R->altura);
            				break;
          	case TRI:   T = (Triangulo*)Info->info;
            				printf("A base do triangulo e: %.2f\t e a altura:%.2f\n", T->base,T->altura);
            				break;
          	case CIR:   C = (Circulo*)Info->info;
            				printf("O raio do circulo e: %.2f\n", C->raio);
            				break;
            }
}

int main(void){
    def_fila fila;
    int tipo;
    float base,altura,raio;
    lista_generica* dado;
    No info;
    char op;

    fila = inicializa();
    printf("Insercao de valores na fila... \n");
    do{
         printf("\n\nInserir elementos (s/n)?...");op=getche();
         if (op=='s' || op=='S'){
            printf("\nInserir (1)RET\t(2)TRI\t(3)CIR ");tipo=getche()-48;
            switch (tipo){
            	case RET: printf("\nInserir um retangulo\n");
               		  printf("Base = ");scanf("%f",&base);
                          printf("Altura = ");scanf("%f",&altura);
                          dado=cria_retangulo(base,altura);
                          break;
            	case TRI: printf("\nInserir um triangulo\n");
               		  printf("Base = ");scanf("%f",&base);
                          printf("Altura = ");scanf("%f",&altura);
                          dado=cria_triangulo(base,altura);
                          break;
            	case CIR: printf("\nInserir um circulo\n");
               		  printf("Raio = ");scanf("%f",&raio);
                          dado=cria_circulo(raio);
                          break;}
            enfileira(&fila,dado); }
    }while (op=='s' || op=='S');
    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");imprime(fila);}
    do{
        printf("\nRetirar elementos (s/n)?...");op=getche();
        if (op=='s' || op=='S') {
           if (!desenfileira(&fila,&info)) printf("Remocao sem sucesso\n");
           else imprime_no(info);}
    }while (op=='s' || op=='S');

    if(!vazia(fila)) {printf("\n\n\nImprimindo a fila...\n");imprime(fila);}
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
