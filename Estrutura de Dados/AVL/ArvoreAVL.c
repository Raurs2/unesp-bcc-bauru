/* 	Árvore AVL
      Inserção, Impressão e Remocao
*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct no_arvore{
         int info;
         int balanco;
         struct no_arvore* esquerdo;
         struct no_arvore* direito;
         } *def_arvore;


def_arvore inicializa(void){
    return NULL;
}

def_arvore cria_no (int valor){
 	def_arvore p = (def_arvore)malloc(sizeof(struct no_arvore));
   p->info = valor;
   p->balanco = 0;
   p->esquerdo = NULL;
   p->direito = NULL;
   return p;
}

void caso1_aumentou_esq(def_arvore* no_p, int *h){
	def_arvore no_u,no_v;

     no_u = (*no_p)->esquerdo;
     if (no_u->balanco == -1) {			   /* Rotacao a direita **/
        (*no_p)->esquerdo = no_u->direito;
        no_u->direito = *no_p;
        (*no_p)->balanco = 0;
        *no_p = no_u;}
     else {                          /* Rotacao dupla direita */
               no_v = no_u->direito;
               no_u->direito = no_v->esquerdo;
               no_v->esquerdo = no_u;
               (*no_p)->esquerdo = no_v->direito;
               no_v->direito = *no_p;
               if (no_v->balanco == -1) (*no_p)->balanco = 1;
               else (*no_p)->balanco = 0;
               if (no_v->balanco == 1) no_u->balanco = -1;
               else no_u->balanco = 0;
               *no_p = no_v;}
     (*no_p)->balanco=0;
     *h = 0;
}

void caso2_aumentou_dir(def_arvore* no_p, int *h){
	def_arvore no_u,no_v;

     no_u=(*no_p)->direito;             /* Rotacao esquerda * */
     if (no_u->balanco == 1){
        (*no_p)->direito = no_u->esquerdo;
        no_u->esquerdo = *no_p;
        (*no_p)->balanco = 0;
        *no_p = no_u;}
     else {                	 /* Rotacao dupla esquerda */
               no_v = no_u->esquerdo;
               no_u->esquerdo = no_v->direito;
               no_v->direito = no_u;
               (*no_p)->direito = no_v->esquerdo;
               no_v->esquerdo = *no_p;
               if (no_v->balanco == 1) (*no_p)->balanco = -1;
               else (*no_p)->balanco=0;
               if (no_v->balanco == -1) no_u->balanco = 1;
               else no_u->balanco = 0;
               *no_p = no_v; }
     (*no_p)->balanco = 0;
     *h = 0;
}

void insere (int nro, def_arvore *arvore, int *h){
     if ((*arvore) == NULL){
        *arvore = cria_no(nro);
        *h = 1;}
     else {
            if(nro == (*arvore)->info) printf("\nNro jah existe");
            else
                if(nro < (*arvore)->info) {
                   insere(nro, &((*arvore)->esquerdo), h);
                   if(*h)
                      switch ((*arvore)->balanco){
                         case 1: (*arvore)->balanco = 0; *h = 0; break;
                         case 0: (*arvore)->balanco = -1; break;
                         case -1: caso1_aumentou_esq(arvore,h); break; }}/* tem de rebalancear */
                   else{
                        insere(nro,&((*arvore)->direito),h);
                        if(*h)
                           switch ((*arvore)->balanco){
                              case -1: (*arvore)->balanco = 0; *h=0; break;
                              case 0: (*arvore)->balanco = 1; break;
                              case 1: caso2_aumentou_dir(arvore,h); break;}}} /* tem de rebalancear */
}


void caso1_encolheu_esq(def_arvore *no_p, int *h){
	  def_arvore no_u,no_v;			     /* o ramo esquerdo encolheu */

     switch((*no_p)->balanco){
        case -1: (*no_p)->balanco = 0; break;
        case 0: (*no_p)->balanco = 1; *h = 0; break;
        case 1: no_u = (*no_p)->direito;
                if(no_u->balanco >= 0) { /* rotacao simples RR*/
                   (*no_p)->direito = no_u->esquerdo;
                   no_u->esquerdo = *no_p;
                   if(no_u->balanco == 0){
                      (*no_p)->balanco = 1;
                      no_u->balanco = -1;
                      *h = 0;}
                   else {  (*no_p)->balanco = 0;
                           no_u->balanco = 0;}
                   (*no_p)=no_u;}
                else{ 						/* rotacao dupla RL */
                  		no_v = no_u->esquerdo;
                  		no_u->esquerdo = no_v->direito;
                  		no_v->direito = no_u;
                  		(*no_p)->direito = no_v->esquerdo;
                  		no_v->esquerdo = *no_p;
                  		if(no_v->balanco == 1)(*no_p)->balanco = 1;
                        else (*no_p)->balanco = 0;
                  		if(no_v->balanco == -1) no_u->balanco = 1;
                        else no_u->balanco = 0;
                  		(*no_p) = no_v;
                        no_v->balanco = 0;}
                break;}
}

void caso2_encolheu_dir(def_arvore *no_p, int *h){
 	def_arvore no_u,no_v;			     /* o ramo direito encolheu */

	switch((*no_p)->balanco){
      case 1: (*no_p)->balanco = 0; break;
      case 0: (*no_p)->balanco = -1; *h = 0; break;
      case -1: no_u = (*no_p)->esquerdo;
               if(no_u->balanco <= 0){  		/*rotacao direita*/
                 (*no_p)->esquerdo = no_u->direito;
                 no_u->direito = (*no_p);
                 if(no_u->balanco == 0){
                   (*no_p)->balanco = -1;
                   no_u->balanco = 1;
                   *h = 0;}
                 else{ (*no_p)->balanco = 0;
                 		no_u->balanco = 0; }
                 *no_p = no_u;}
               else{  						/* rotacao dupla Direita */
                  	no_v = no_u->direito;
                  	no_u->direito = no_v->esquerdo;
                  	no_v->esquerdo = no_u;
                  	(*no_p)->esquerdo = no_v->direito;
                  	no_v->direito = *no_p;
                  	if(no_v->balanco == -1) (*no_p)->balanco = 1;
                    else (*no_p)->balanco = 0;
                  	if(no_v->balanco == 1) no_u->balanco = 1;
                    else no_u->balanco = 0;
                  	*no_p = no_v;
                    no_v->balanco = 0;}
                break;}
}

void apaga_no (def_arvore *no_q, def_arvore *no_r, int *h){
   if((*no_r)->direito != NULL){
     apaga_no(no_q,&((*no_r)->direito),h);
     if(*h) caso2_encolheu_dir(no_r,h);}
     else{
           (*no_q)->info = (*no_r)->info;
           (*no_q) = *no_r;
           *no_r = (*no_r)->esquerdo;
           *h = 1;}
}

void Remove(int nro, def_arvore *arvore, int *h)
{	def_arvore q;

     if (arvore == NULL) printf ("Nao");
     else if ((*arvore)->info > nro){
             Remove(nro,&((*arvore)->esquerdo),h);
             if(*h) caso1_encolheu_esq(arvore,h);}
          else if ((*arvore)->info < nro){
                  Remove(nro,&((*arvore)->direito),h);
                  if(*h) caso2_encolheu_dir(arvore,h);}
               else{
                    q = *arvore;
                    if(q->direito == NULL) {
                       *arvore = q->esquerdo;
                       *h = 1;}
                    else if(q->esquerdo == NULL){
                            *arvore = q->direito;
                            *h = 1; }
                         else{
                              apaga_no(&q,&(q->esquerdo),h);
                              if(*h) caso1_encolheu_esq(arvore,h);}}
}


void mostra_arvore(def_arvore arvore, int *nivel)
{ int i,nivel1;

		if (arvore==NULL) return;
      for(i=0;i<=(*nivel)*2;i++) printf("  ");
      printf("%d(%d)\n",arvore->info,arvore->balanco);
      nivel1=(*nivel)+1;
      if(arvore->direito!=NULL)
         mostra_arvore(arvore->direito,&nivel1);
      if(arvore->esquerdo!=NULL)
         mostra_arvore(arvore->esquerdo,&nivel1);
}

int main(void){


	  def_arvore arvore;
	  int numero, nivel, h;

     arvore = inicializa();
     printf("Insercao. (-1) para encerrar\n");
     do{
           printf("nro = "); scanf("%d",&numero);
           if(numero != -1){
           		insere(numero,&arvore,&h);
               nivel=0;mostra_arvore(arvore,&nivel);}
     }while (numero != -1);
     printf("\n\aA arvore AVL formada e: \n");
     nivel=0;mostra_arvore(arvore,&nivel);

     printf("Remocao. (-1) para encerrar\n");
     do{
           printf("nro = "); scanf("%d",&numero);
           if(numero != -1){
           		Remove(numero,&arvore,&h);
               nivel=0;mostra_arvore(arvore,&nivel);}
     }while (numero != -1);
     printf("\n\aA arvore AVL formada e: \n");
     nivel=0;mostra_arvore(arvore,&nivel);

     printf("\n\n\aTecle algo para encerrar ...");getch();
     return 1;
}





