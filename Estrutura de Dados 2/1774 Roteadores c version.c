#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int vertice1, vertice2, preco;
} aresta;

aresta ares[201];
int vetRoteadores[61];
int i;

int componente(int vertice)
{
	if (vertice == vetRoteadores[vertice])
		return vertice;

	return componente(vetRoteadores[vertice]);
}

int kruskal(int cabos)
{

	int custo = 0, vertice1, vertice2;

	for (i = 0; i < cabos; i++)
	{
		vertice1 = componente(ares[i].vertice1);
		vertice2 = componente(ares[i].vertice2);

		if (vertice1 != vertice2)
        {
            vetRoteadores[vertice1] = vetRoteadores[vertice2];
            custo += ares[i].preco;
        } 
	}

	return custo;
}

int compara(aresta *x, aresta *y)
{
	return x->preco - y->preco;
}

int main()
{
	int roteadores, cabos;
	scanf("%d %d", &roteadores, &cabos);

	for ( i = 0; i < cabos; i++)
		scanf("%d %d %d", &ares[i].vertice1, &ares[i].vertice2, &ares[i].preco);

	qsort(ares, cabos, sizeof(aresta), compara);

	for ( i = 1; i <= roteadores; i++)
		vetRoteadores[i] = i;

	int total = kruskal(cabos);
	printf("%d\n", total);

	return 0;
}