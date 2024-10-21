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

typedef struct no
{
    int info;
    struct no* primeiro_filho;
    struct no* irmao;
} *def_arvore;

void cria_filhos(def_arvore* arvore)
{
    int i,qt;
    int filho;
    def_arvore p,q1,q2;

    do
    {
        printf("\nQuantos filhos sao: ");
        scanf("%d",&qt);
    } while (qt<0);

    if(qt>=1)
    {
        printf("\nFilho = ");
        scanf("%d",&filho);

        p = (def_arvore)malloc(sizeof(struct no));
        p->info = filho;
        p->primeiro_filho = NULL;
        p->irmao = NULL;
        (*arvore)->primeiro_filho = p;
    }

    for(i=2;i<=qt;i++)
    {
        printf("\nFilho = ",(*arvore)->info);
        scanf("%d",&filho);

            p=(def_arvore)malloc(sizeof(struct no));
            p->info=filho;
            p->primeiro_filho=NULL;
            p->irmao=NULL;
            
            q1 = (*arvore)->primeiro_filho;
            while (q1 != NULL)
            {
                q2=q1; 
                q1=q1->irmao;
            }

            q2->irmao=p;
    }
}              
 

void cria_arvore(def_arvore* arvore)
{
    int ok;
    def_arvore q1=NULL,q2=NULL;
    
    if((*arvore)==NULL) return;

    printf("\n\nO no %d tem filhos?(S/N)", (*arvore)->info);
    ok=getche();

    if(ok=='S' || ok=='s')
    {
        cria_filhos(arvore);

        if((*arvore)->primeiro_filho!=NULL)
        {
            cria_arvore(&((*arvore)->primeiro_filho));
            q1 = (*arvore)->primeiro_filho;  
            while (q1 != NULL)
            {
                q2=q1; 
                if(q2->irmao!=NULL) cria_arvore(&(q2->irmao));
                q1=q1->irmao;
            }  
        }
    }
}


void le_arvore (def_arvore* arvore)
{
    int dado;

    printf("\nEntre com a raiz = ");
    scanf("%d",&dado);


    (*arvore)=(def_arvore)malloc(sizeof(struct no));;
    (*arvore)->info=dado;
    (*arvore)->primeiro_filho=NULL;
    (*arvore)->irmao=NULL;
    cria_arvore(arvore);
}

void mostra_arvore(def_arvore arvore, int *nivel)
{
    int i,nivel1;

    for(i=0;i<=(*nivel)*2;i++) printf("  ");

    printf("%d\n",arvore->info);
    nivel1=(*nivel)+1;

    if(arvore->primeiro_filho!=NULL)
        mostra_arvore(arvore->primeiro_filho,&nivel1);

    if(arvore->irmao!=NULL)
        mostra_arvore(arvore->irmao,&nivel1);
}

int converter(def_arvore arv, def_arvoreBi* bi)
{
    insere_arvoreBi(bi, arv->info);

    if(arv->primeiro_filho!=NULL)
        converter(arv->primeiro_filho, bi);

    if(arv->irmao!=NULL)
        converter(arv->irmao, bi);
}

int main()
{
    def_arvoreBi bi = NULL;
    def_arvore arv = NULL;
    int dado, op, nivel = 0;

    le_arvore(&arv);
    printf("\n\n\nMostrando a arvore....\n");
    mostra_arvore(arv,&nivel);
    converter(arv, &bi);
    printf("\n\n\nMostrando a arvore binaria....\n");
    nivel = 0;
    mostra_arvoreBi(bi, &nivel);
    printf("\n\n\nMostrando a arvore binaria em ordem....\n");
    mostra_em_ordemBi(bi);
    printf("\n\n\nMostrando a arvore binaria em pre ordem....\n");
    mostra_pre_ordemBi(bi);
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
