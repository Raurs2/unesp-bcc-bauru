#include <stdio.h>
#include <conio.h>
#include <malloc.h>

//Raul Alexandre Gonzalez Augusto

typedef struct no
{
    char info;
    struct no* primeiro_filho;
    struct no* irmao;
} *def_arvore;

void cria_filhos(def_arvore* arvore)
{
    int i,qt;
    char filho;
    def_arvore p,q1,q2;

    do
    {
        printf("\nQuantos filhos sao: ");
        scanf("%d",&qt);
    } while (qt<0);

    if(qt>=1)
    {
        printf("\nFilho = ");
        filho=getche();

        p = (def_arvore)malloc(sizeof(struct no));
        p->info = filho;
        p->primeiro_filho = NULL;
        p->irmao = NULL;
        (*arvore)->primeiro_filho = p;
    }

    for(i=2;i<=qt;i++)
    {
        printf("\nFilho = ",(*arvore)->info);
        filho=getche();

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
    char ok;
    def_arvore q1=NULL,q2=NULL;
    
    if((*arvore)==NULL) return;

    printf("\n\nO no %c tem filhos?(S/N)", (*arvore)->info);
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
    char dado;

    printf("\nEntre com a raiz = ");
    dado=getche();

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

    printf("%c\n",arvore->info);
    nivel1=(*nivel)+1;

    if(arvore->primeiro_filho!=NULL)
        mostra_arvore(arvore->primeiro_filho,&nivel1);

    if(arvore->irmao!=NULL)
        mostra_arvore(arvore->irmao,&nivel1);
}

void exercicio_arvore(def_arvore arvore, int *nos, int *nosFolhas, int *menor)
{
    if (arvore->info < (*menor))
        (*menor) = arvore->info;
    
    (*nos)++;

    if(arvore->primeiro_filho==NULL) (*nosFolhas)++;

    if(arvore->primeiro_filho!=NULL)
        exercicio_arvore(arvore->primeiro_filho, nos, nosFolhas, menor);

    if(arvore->irmao!=NULL)
        exercicio_arvore(arvore->irmao, nos, nosFolhas, menor);
}


int main(){
    def_arvore arvore=NULL;
    int nos = 0, nosFolhas = 0, menor, nivel=0;

    le_arvore(&arvore);
    printf("\n\n\nMostrando a arvore....\n");
    mostra_arvore(arvore,&nivel);
    menor = arvore->info;
    exercicio_arvore(arvore, &nos, &nosFolhas, &menor);
    printf("\nMenor %c\nNos %d\nNos Folha %d\n", menor, nos, nosFolhas);
    printf("\n\n\aTecle algo para encerrar ...");getch();
}
