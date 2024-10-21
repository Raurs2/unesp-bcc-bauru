/*
		�rvore Heap Maxima
      Inser��o, Remo��o e altera��o de valores.
*/

#include <stdio.h>
#include <conio.h>

#define Max 30
#define Grau 2

typedef int def_heap[Max];

/* ------  INICIALIZA��O DA �RVORE HEAP M�XIMA --------------------*/
void inicializa(def_heap arvore){
   int i;
   for (i=0; i<Max; i++) arvore[i]=-1;
}

/* ------  MOSTRANDO A �RVORE HEAP M�XIMA -------------------------*/
void escreve_arvore(def_heap arvore){
   int posicao,i,pai=0,cont;

   if((arvore)[0]== -1){
     printf("\n\n\aArvore vazia...");
     return;}
   printf("\n\n\aImpressao da arvore: \nRaiz: %d\n",(arvore)[pai]);
   for (posicao=1; (posicao<Max)&&(arvore[posicao]!=-1); posicao++){
        if((arvore)[pai]!= -1){
       	   printf("%d:", (arvore)[pai]);
       	   cont=0;
       	   for(i=1; i<=Grau; i++){
              if((arvore)[posicao] != -1){
                printf("\t%d",(arvore)[posicao]);
                cont++;}
           posicao++;}
        if (cont==0) printf("....sem filhos");
        posicao--;}
	pai++;
	printf("\n");}
}



void escreve_heap(def_heap arvore){
   int i;
   printf("\n O vetor ... \n");
   for(i=0;i<Max;i++)
    	if(arvore[i] != -1)
      	   printf("\t%d",arvore[i]);
}

int verifica_HEAP(def_heap arvore, int valor)
{
   int i;
   for(i=0;i<Max;i++)
    	if(arvore[i] == valor) return 1;
   return 0;
}

/* ------  ALGUMAS ROTINAS DE �RVORE HEAP M�XIMA -------------------------*/
int qtidade(def_heap arvore){
    int cont;
    for(cont=0;arvore[cont]!=-1;cont++);
    return cont;
}

int cheia(def_heap arvore){
 	return(qtidade(arvore)==Max);
}

int vazia(def_heap arvore){
 	return(qtidade(arvore)==0);
}

int maior_filho(int p, int m, def_heap arvore){
   int s = 2*p+1;

   if((s+1)<= m && arvore[s]<arvore[s+1]) s = s+1;
   if (s>m) return (-1);
   else return s;
}

void subir(int i, def_heap arvore){
   int troca, j = (i-1)/2;

   if(j>=0 && arvore[i]>arvore[j]){
      troca = arvore[i];
      arvore[i] = arvore[j];
      arvore[j] = troca;
      subir(j,arvore);}
}

void ajusta_heap(int R, int K, def_heap arvore){
   int f = R;
   int s = maior_filho(f,K-1,arvore);
   if(s >= 0 && arvore[K] < arvore[s]){
      arvore[f] = arvore[s];
      ajusta_heap(s,K,arvore);
      }
   else arvore[f] = arvore[K];
}

void descer(int posicao, def_heap arvore){
   int pos,troca, n = qtidade(arvore);;
   pos = posicao*2+1; /* filho esquerdo */
   if(pos < n)
   	if(arvore[pos+1]>arvore[pos]) pos++; /* pega maior filho - direito*/
        if(arvore[posicao]<arvore[pos]){
     	     troca = arvore[pos];
           arvore[pos]=arvore[posicao];
           arvore[posicao]=troca;
           descer(pos,arvore);}
}


/* ------  INSER��O DE ITENS NA �RVORE HEAP M�XIMA -------------------------*/

int Insere01(int nro, def_heap arvore){
   int n;

   if(cheia(arvore)) return 0;
   n = qtidade(arvore);
   arvore[n]=nro;
   subir(n,arvore);
   return 1;
}

int Insere02(int valor, def_heap arvore){
   int s = qtidade(arvore);
   int f = (s - 1)/2;

   if (cheia(arvore)) return 0;
   while (s>0 && arvore[f]< valor){
          arvore[s]=arvore[f];
          s=f;
          f = (s-1)/2;}
   arvore[s]=valor;
   return 1;
}

/* ------  REMO��O DE ITENS DA �RVORE HEAP M�XIMA -------------------------*/
int Remove_heap01(int *valor, def_heap arvore){
   int k = qtidade(arvore);

   if(vazia(arvore))return 0;
   *valor = arvore[0];
   ajusta_heap(0,k-1,arvore);
   arvore[k-1]=-1;
   return 1;
}

int Remove_heap02(int *valor, def_heap arvore){
   int n = qtidade(arvore);

   if(vazia(arvore))return 0;
   *valor = arvore[0];
   arvore[0]= arvore[n-1];
   descer(0,arvore);
   arvore[n-1]=-1;
   return 1;
}

/* ------  ALTERA��O DE PRIORIDADES NA �RVORE HEAP M�XIMA ------------------*/
int altera_prioridade(int nro1, int nro2, def_heap arvore){
   int x,i,n = qtidade(arvore)+1;

   if(vazia(arvore)) return 0;
   for(i=0;(i<n && arvore[i]!=nro1);i++);
   if(arvore[i]==nro1) arvore[i]=nro2;
   else return 0;
   x =maior_filho(i,n,arvore);
   if (arvore[i]< arvore[x]) descer(i,arvore);
   else subir(i,arvore);
   return 1;
}

/* ------  ROTINA HEAPSORT  -----------------------------------------------*/
void heapsort01(def_heap arvore, int R[]){
   int valor, i, n=qtidade(arvore);

   for(i=n-1; i>0; i--){
      Remove_heap01(&valor,arvore);
      R[i]=valor;}
   R[0]=arvore[0];
}

void heapsort02(def_heap arvore, int R[]){
   int valor, i, n=qtidade(arvore);

   for(i=n-1; i>0; i--){
   	Remove_heap02(&valor,arvore);
      R[i]=valor;}
   R[0]=arvore[0];
}



/* ------  ROTINA PRINCIPAL DA �RVORE HEAP M�XIMA -------------------------*/
void main(void){
   int nro,nro1;
   def_heap arvore;
   char resp;
   int i,n;
   int R[Max];

   inicializa(arvore); escreve_heap(arvore);
   printf("\n\nInsercao no heap (-1 para encerrar)\n");
   do{
   	printf("Entre com um valor: ");scanf("%d",&nro);
   	if(nro!=-1){
      	 if(Insere02(nro,arvore)){
   		 	escreve_heap(arvore);
   		 	escreve_arvore(arvore);}
          else printf("\nNao foi possivel inserir item...\n");}
   }while (nro!=-1);
   printf("\n\nAlteracao de prioridades no heap\n");
   do{
   	printf("Deseja alterar prioridade ...(s/n) ");resp=getche();
   	if(resp=='s'){
   	   printf("Entre com o original: ");scanf("%d",&nro);
        	printf("Entre com a troca: ");scanf("%d",&nro1);
      	if(altera_prioridade(nro,nro1,arvore)){
		   	escreve_heap(arvore);
		   	escreve_arvore(arvore);}
         else printf("\nNao foi possivel alterar item...\n");}
   }while (resp=='s');

   printf("\n\nRemocao no heap\n");
   do{
   	printf("Deseja remover...(s/n) ");resp=getche();
   	if(resp=='s'){
      	if(Remove_heap01(&nro,arvore)){
         	printf("\n o numero removido foi %d",nro);
		   	escreve_heap(arvore);
		   	escreve_arvore(arvore);}
         else printf("\nNao foi possivel remover item...\n");}
   }while (resp=='s');
   n=qtidade(arvore);
   heapsort02(arvore,R);
	printf("\nO vetor ordenado em ordem crescente ... \n");
   for(i=0;i<n;i++)printf("\t%d",R[i]);

   printf("\n\n\aTecle algo para encerrar ...");getch();
}   


