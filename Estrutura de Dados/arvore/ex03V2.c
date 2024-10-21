#include <stdio.h>
#include <conio.h>

//Raul Alexandre Gonzalez Augusto

#define Max 30
#define Grau 3

typedef int vetor_filhos[Grau];

typedef struct
{
    char info;
    vetor_filhos filhos;
}elemento;

typedef elemento def_arvore[Max];

void inicializa_arvore(def_arvore arvore)
{
    int i,j;
    for(i=0;i<Max;i++)
    {
        arvore[i].info='-';
        for(j=0;j<Grau;j++) arvore[i].filhos[j]=0;
    }

}

void le_arvore(def_arvore arvore)
{
    int posicao=1,i,j,pai=0,qt;
    char filho, tem_filhos;

    printf("Raiz: ");arvore[pai].info=getche();

    for(j=1;j<Max;j++)
    {
        if(arvore[pai].info!='-')
        {
            printf("\n\nO no %c tem filhos(s/n)?",arvore[pai].info);
            tem_filhos=getche();

            if(tem_filhos =='s' || tem_filhos =='S')
            {
                printf("\nLeitura dos filhos de: %c", arvore[pai].info);
                printf("\nQuantos filhos: ");
                qt=getche()-48;

                for(i=0; i<qt; i++)
                {
                    printf("\nFilho = ");
                    filho=getche();

                    if (filho!='0')
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
    if(arvore[0].info== '-')
    {
        printf("\n\n\aArvore vazia...");
        return;
    }

    printf("\n\n\aImpressao da arvore: \n");
    printf("Raiz: %c",arvore[pai].info);
    for (posicao=1; posicao<Max; posicao++)
    {
        if(arvore[pai].info!= '-')
        {
            printf("\nFilhos de %c: ", arvore[pai].info);
            cont=0;
            for(i=1; i<=Grau; i++)
            {
                if(arvore[posicao].info != '-')
                {
                    printf("\t%c",arvore[posicao].info);
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

void exercicio_arvore(def_arvore arvore)
{
    int posicao,i,pai=0,cont;
    char menor, nos, nosFolha = 0;

    if(arvore[0].info== '-')
    {
        printf("\n\n\aArvore vazia...");
        return;
    }

    nos = 1;
    menor = arvore[pai].info;

    for (posicao=1; posicao<Max; posicao++)
    {

        if(arvore[pai].info!= '-')
        {
            if (arvore[pai].info < menor)
            {
                menor = arvore[pai].info;
            }
            for(i=1; i<=Grau; i++)
            {
                if(arvore[posicao].info != '-')
                {
                    nos++;
                    if (arvore[posicao].info < menor)
                    {
                        menor++;
                    }
                    if (!filhos(arvore, posicao))
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

    printf("\nMenor elemento da arvore: %c\n", menor);
    printf("Nos: %d\nNos folha: %d\n", nos, nosFolha);
}

int filhos(def_arvore arvore, int pos)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (arvore[pos].filhos[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

void mostra_vetor(def_arvore arvore)
{
    int i,j;
    printf("\n\n");
    for (i=0; i<Max; i++)
    {
        printf("\narvore[%d] = %c",i,arvore[i].info);
        for(j=0;j<Grau;j++) printf("\t %d", arvore[i].filhos[j]);
    }
}

int main(){
	def_arvore arvore;

   inicializa_arvore(arvore);
   le_arvore(arvore);
   //escreve_arvore(arvore);
   mostra_vetor(arvore);
   exercicio_arvore(arvore);
   printf("\n\n\aTecle algo para encerrar ...");getch();

}


