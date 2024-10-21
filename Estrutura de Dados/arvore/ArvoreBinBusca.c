#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct no_arvore{
		 int info;
         struct no_arvore* esq;
         struct no_arvore* dir;
         } *def_arvore;


void mostra_arvore(def_arvore arvore, int *nivel){
 int i,nivel1;

		if (arvore==NULL) return;
      for(i=0;i<=(*nivel)*2;i++) printf("  ");
      printf("%d\n",arvore->info);
      nivel1=(*nivel)+1;
      if(arvore->dir!=NULL)
         mostra_arvore(arvore->dir,&nivel1);
      if(arvore->esq!=NULL)
         mostra_arvore(arvore->esq,&nivel1);
}

void mostra_em_ordem(def_arvore arvore){

    if (arvore != NULL){
        mostra_em_ordem(arvore->esq);
        printf("%d  ",arvore->info);
        mostra_em_ordem(arvore->dir);}
}

long int mostra_pre_ordem(def_arvore arvore){
	long int aux=1;
    if (arvore != NULL){
        printf("%d  ",arvore->info); aux=arvore->info;
		mostra_em_ordem(arvore->esq); 
        mostra_em_ordem(arvore->dir);
		}
    else return 1;
}

void insere_arvore(def_arvore *arvore, int valor){

     if(*arvore!=NULL){
        if ((*arvore)->info > valor) insere_arvore(&((*arvore)->esq),valor);
        else if ((*arvore)->info < valor) insere_arvore(&((*arvore)->dir),valor);
        else printf("O numero ja existe\n");}
     else{
          *arvore=(def_arvore)malloc(sizeof(struct no_arvore));
          (*arvore)->info = valor;
          (*arvore)->esq = NULL;
          (*arvore)->dir = NULL;}
}

int busca(def_arvore arvore, int valor){
     if (arvore==NULL) return 0;
     if (arvore->info == valor) return 1;
     if (valor < arvore->info)
     		return busca(arvore->esq,valor);
     if (valor > arvore->info)
     		return busca(arvore->dir,valor);
}

void remocao_tipo01 (def_arvore *arvore, int dado){
	 def_arvore p,q,rp,f,s;

     p = *arvore;
     q = NULL;
     while (p!=NULL && p->info!=dado){
           q = p;
           if (dado < p->info) p=p->esq;
           else p = p->dir;}
     if (p != NULL){
        if (p->esq == NULL)  rp=p->dir;
        else if (p->dir == NULL)  rp = p->esq;
             else {
                       f = p;
                       rp= p->dir;
                       s= rp->esq;
                       while (s != NULL){
                             f=rp;
                             rp=s;
                             s=rp->esq;}
                       if (f != p) {
                          f->esq = rp->dir;
                          rp->dir = p->dir;}
                       rp->esq = p->esq;}
        if (q == NULL)  *arvore = rp;
        else{
                  if (p == q->esq) q->esq=rp;
                  else q->dir=rp; }
        free(p);}
}

void remocao_tipo02 (def_arvore *arvore, int dado){
	  def_arvore p,q,rp,f,s;

     p = *arvore;
     q = NULL;
     while (p!=NULL && p->info!=dado){
           q = p;
           if (dado < p->info) p=p->esq;
           else p = p->dir;}
     if (p != NULL){
        if (p->esq == NULL)  rp=p->dir;
        else if (p->dir == NULL)  rp = p->esq;
             else {    f = p;
                       rp= p->esq;
                       s= rp->dir;
                       while (s != NULL){
                             f=rp;
                             rp=s;
                             s=rp->dir;}
                       if (f != p) {
                          f->dir = rp->esq;
                          rp->esq = p->esq;}
                       rp->dir = p->dir;}
        if (q == NULL)  *arvore = rp;
        else{     if (p == q->esq) q->esq=rp;
                  else q->dir=rp; }
        free(p);}
}

int main(){
	  def_arvore arvore;
	  int numero, nivel=0;
     char resp;

     arvore = NULL;
     printf("Insercao. (-1) para encerrar\n");
     do{
           printf("nro = ");scanf("%d",&numero);
           if(numero != -1) insere_arvore(&arvore,numero);
     }while (numero != -1);
     printf("\n\aA arvore binaria formada e: \n");
     mostra_arvore(arvore,&nivel);

     printf("\n\aA arvore binaria formada em_ordem: \n");
     mostra_em_ordem(arvore);
	  printf("\nRemocao de elementos -  Tipo01\n");
     do{
           printf("\nNumero = "); scanf("%d",&numero);
           remocao_tipo01(&arvore,numero);
           printf("\n\aA arvore binaria formada e: \n");
           nivel=0;mostra_arvore(arvore,&nivel);
           printf("Continuar?(s/n) ");resp=getche();
     }while (resp !='n');
     printf("\nRemocao de elementos -  Tipo02\n");
     do{
           printf("\nNumero = "); scanf("%d",&numero);
           remocao_tipo02(&arvore,numero);
           printf("\n\aA arvore binaria formada e: \n");
           nivel=0;mostra_arvore(arvore,&nivel);
           printf("Continuar?(s/n) ");resp=getche();
     }while (resp !='n');

     printf("\n\n\aTecle algo para encerrar ...");getch();
}
