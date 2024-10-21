#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct no_arvoreBi
{
    int info;
    struct no_arvoreBi* esq;
    struct no_arvoreBi* dir;
} *def_arvoreBi;


void mostra_arvoreBi(def_arvoreBi arvore, int *nivel)
{
    int i,nivel1;

    if (arvore==NULL) return;

    for(i=0;i<=(*nivel)*2;i++) printf("  ");
    printf("%d\n",arvore->info);

    nivel1=(*nivel)+1;

    if(arvore->dir!=NULL)
        mostra_arvoreBi(arvore->dir,&nivel1);

    if(arvore->esq!=NULL)
        mostra_arvoreBi(arvore->esq,&nivel1);
}

void mostra_em_ordemBi(def_arvoreBi arvore)
{

    if (arvore != NULL)
    {
        mostra_em_ordemBi(arvore->esq);
        printf("%d  ",arvore->info);
        mostra_em_ordemBi(arvore->dir);
    }
}

long int mostra_pre_ordemBi(def_arvoreBi arvore)
{
    long int aux=1;
    if (arvore != NULL)
    {
        printf("%d  ",arvore->info); 
        aux=arvore->info;
        mostra_pre_ordemBi(arvore->esq); 
        mostra_pre_ordemBi(arvore->dir);
    }
    else return 1;
}

void insere_arvoreBi(def_arvoreBi *arvore, int valor)
{

    if(*arvore!=NULL)
    {
        if ((*arvore)->info > valor) insere_arvoreBi(&((*arvore)->esq),valor);
        else if ((*arvore)->info < valor) insere_arvoreBi(&((*arvore)->dir),valor);
        else printf("O numero ja existe\n");
    }
    else
    {
        *arvore=(def_arvoreBi)malloc(sizeof(struct no_arvoreBi));
        (*arvore)->info = valor;
        (*arvore)->esq = NULL;
        (*arvore)->dir = NULL;
    }
}

int buscaBi(def_arvoreBi arvore, int valor)
{
    if (arvore==NULL) return 0;
    if (arvore->info == valor) return 1;
    if (valor < arvore->info) return buscaBi(arvore->esq,valor);
    if (valor > arvore->info) return buscaBi(arvore->dir,valor);
}

void remocao_tipo01Bi(def_arvoreBi *arvore, int dado)
{
    def_arvoreBi p,q,rp,f,s;

    p = *arvore;
    q = NULL;

    while (p!=NULL && p->info!=dado)
    {
        q = p;
        if (dado < p->info) p=p->esq;
        else p = p->dir;
    }
    if (p != NULL)
    {
        if (p->esq == NULL)  rp=p->dir;
        else if (p->dir == NULL)  rp = p->esq;
                else
                {
                    f = p;
                    rp= p->dir;
                    s= rp->esq;
                    while (s != NULL)
                    {
                        f=rp;
                        rp=s;
                        s=rp->esq;
                    }
                    if (f != p) 
                    {
                        f->esq = rp->dir;
                        rp->dir = p->dir;
                    }
                    rp->esq = p->esq;
                }
        if (q == NULL)  *arvore = rp;
        else
        {
            if (p == q->esq) q->esq=rp;
            else q->dir=rp; 
        }
        free(p);
    }
}

void remocao_tipo02Bi (def_arvoreBi *arvore, int dado)
{
    def_arvoreBi p,q,rp,f,s;

    p = *arvore;
    q = NULL;

    while (p!=NULL && p->info!=dado)
    {
        q = p;
        if (dado < p->info) p=p->esq;
        else p = p->dir;
    }
    if (p != NULL)
    {
        if (p->esq == NULL)  rp=p->dir;
        else if (p->dir == NULL)  rp = p->esq;
                else 
                {    
                    f = p;
                        rp= p->esq;
                        s= rp->dir;
                        while (s != NULL){
                                f=rp;
                                rp=s;
                                s=rp->dir;}
                        if (f != p) {
                            f->dir = rp->esq;
                            rp->esq = p->esq;}
                        rp->dir = p->dir;
                }
        if (q == NULL)  *arvore = rp;
        else
        {     
            if (p == q->esq) q->esq=rp;
            else q->dir=rp; 
        }
        free(p);
    }
}

void NivelAtual(def_arvoreBi  arvore, int nivel);
int altura(def_arvoreBi arvore);

void mostraPorNivel(def_arvoreBi  arvore)
{
    int h = altura(arvore);
    int i;
    for (i = 1; i <= h; i++)
        NivelAtual(arvore, i);
}
 
void NivelAtual(def_arvoreBi  arvore, int nivel)
{
    if (arvore == NULL) return; 
    if (nivel == 1) printf("%d ", arvore->info);
    else if (nivel > 1)
    {
        NivelAtual(arvore->esq, nivel - 1);
        NivelAtual(arvore->dir, nivel - 1);
    }
}
 

int altura(def_arvoreBi arvore)
{
    if (arvore == NULL) return 0;
    else 
    {
        int hL = altura(arvore->esq);
        int hR = altura(arvore->dir);
 
        if (hL > hR) return (hL + 1);
        else return (hR + 1);
    }
}

int main()
{
    def_arvoreBi arvore;
    int numero, nivel=0;
    char resp;
    arvore = NULL;

    printf("Insercao. (-1) para encerrar\n");
    do{
        printf("nro = ");scanf("%d",&numero);
        if(numero != -1) insere_arvoreBi(&arvore,numero);
    }while (numero != -1);
    
    printf("\n\aA arvore binaria formada e: \n");
    mostra_arvoreBi(arvore,&nivel);

    printf("\n\aA arvore binaria formada em_ordem: \n");
    mostra_em_ordemBi(arvore);

    printf("\n\nSequencia por nivel:\n");
    mostraPorNivel(arvore);


    printf("\n\n\aTecle algo para encerrar ...");getch();
}
