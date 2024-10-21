#include <stdio.h>
#include <conio.h>

//Raul Alexandre Gonzalez Augusto 

#define Max 30
#define Grau 3

typedef int vetor_filhos[Grau];

typedef struct
{
    int info;
    vetor_filhos filhos;
}elemento;

typedef elemento def_arvore[Max];

void inicializa_arvore(def_arvore arvore)
{
    int i,j;
    for(i=0;i<Max;i++)
    {
        arvore[i].info=-1;
        for(j=0;j<Grau;j++) arvore[i].filhos[j]=0;
    }

}

void le_arvore(def_arvore arvore)
{
    int posicao=1,i,j,pai=0,qt;
    int filho, tem_filhos;

    printf("Raiz: ");arvore[pai].info=getche();

    for(j=1;j<Max;j++)
    {
        if(arvore[pai].info!=-1)
        {
            printf("\n\nO no %d tem filhos(1(s)/0(n))?", arvore[pai].info);
            scanf("%d", &tem_filhos);

            if(tem_filhos =='s' || tem_filhos =='S')
            {
                printf("\nLeitura dos filhos de: %d", arvore[pai].info);
                printf("\nQuantos filhos: ");
                scanf("%d", &qt);

                for(i=0; i<qt; i++)
                {
                    printf("\nFilho = ");
                    scanf("%d", &filho);

                    if (filho!=0)
                    {
                        arvore[posicao].info=filho;
                        arvore[pai].filhos[i]=posicao;
                    }
                    posicao++;
                }
                
            }
            
        }
        pai++;
    }
}

void escreve_arvore(def_arvore arvore)
{
    int posicao,i,pai=0,cont;

    if(arvore[0].info== -1)
    {
        printf("\n\n\aArvore vazia...");
        return;
    }

    printf("\n\n\aImpressao da arvore: \n");
    printf("Raiz: %d",arvore[pai].info);
    for (posicao=1; posicao<Max; posicao++)
    {
        if(arvore[pai].info!= -1)
        {
            printf("\nFilhos de %d: ", arvore[pai].info);
            cont=0;
            for(i=1; i<=Grau; i++)
            {
                if(arvore[posicao].info != -1)
                {
                    printf("\t%d",arvore[posicao].info);
                    cont++;
                }
                posicao++;
            }
            if (cont==0) printf("....sem filhos");
            posicao--;
        }
        pai++;
    }
}

void menor_arvore(def_arvore arvore)
{
    int posicao,i,pai=0,cont;
    int menor, nos = 1, nosFolha = 0;

    if(arvore[0].info== -1)
    {
        printf("\n\n\aArvore vazia...");
        return;
    }
    
    menor = arvore[pai].info;

    for (posicao=1; posicao<Max; posicao++)
    {
        if(arvore[posicao].info != -1)
        {
            nos++;
        }
        
        if(arvore[pai].info!= -1)
        {
            if (arvore[pai].info < menor)
            {
                menor++;
            }

            for(i=1; i<=Grau; i++)
            {
                if (arvore[posicao+1].info == -1 && i != Grau)
                {
                    nosFolha++;
                }
                
                if(arvore[posicao].info != -1)
                {
                    if (arvore[posicao].info < menor)
                    {
                        menor++;
                    }
                    if (i == Grau)
                    {
                        nosFolha++;
                    }
                    
                }
                posicao++;
            }
            posicao--;
        }
        pai++;
    }
}

void mostra_vetor(def_arvore arvore)
{
    int i,j;
    printf("\n\n");
    for (i=0; i<Max; i++)
    {
        printf("\narvore[%d] = %d",i,arvore[i].info);
        for(j=0;j<Grau;j++) printf("\t %d", arvore[i].filhos[j]);
    }
}

int main(){
	def_arvore arvore;

   inicializa_arvore(arvore);
   le_arvore(arvore);
   escreve_arvore(arvore);
   mostra_vetor(arvore);
   printf("\n\n\aTecle algo para encerrar ...");getch();

}


