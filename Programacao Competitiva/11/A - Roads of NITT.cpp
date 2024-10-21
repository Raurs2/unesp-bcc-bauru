#include <bits/stdc++.h>

using namespace std;

#define MAX 20001

int  pai[MAX] = {0};
int  tam[MAX] = {0};

typedef struct
{
	int v1, v2;
	bool mark;
} grafo;

grafo aresta[MAX] = { 0 };

int raiz(int x)
{
	while (x != pai[x])
	{
		pai[x] = pai[pai[x]];
		x = pai[x];
	}

	return x;
}

void merge(int x, int y)
{
	if (tam[x] > tam[y])
	{
		pai[y] = x;
		tam[x] = tam[x] + tam[y];
	}
	else
	{
		pai[x] = y;
		tam[y] = tam[y] + tam[x];
	}
}

int main()
{
	int tests;
	cin >> tests;

	for (int i = 0; i < tests; i++)    
	{
		int nos, arestas_total;

		cin >> nos;
		arestas_total = nos-1;

		for (int j = 1; j <= nos; j++)
		{
			pai[j] = j;
			tam[j] = 1;
		}

		for (int j = 1; j <= arestas_total; j++)
		{
			cin >> aresta[j].v1 >> aresta[j].v2;
			aresta[j].mark = false;
		}
        
		int queries = 0;

		cin >> queries;
		getchar();

		char caracter;
		stack<int> R;
		
		for (int j = 0; j < queries; j++)   
		{
			cin >> caracter;

			if (caracter == 'R')
			{
				int k;
				cin >> k;
				R.push(k);
				aresta[k].mark = true;
			}
			else if (caracter == 'Q')
				R.push(0);

			getchar();
		}

		unsigned long long  ConnPair = 0;

		for (int j = 1; j <= arestas_total; j++)
		{
			if (aresta[j].mark == false)
			{
				int a = raiz(aresta[j].v1);
				int b = raiz(aresta[j].v2);

				if (a != b)
				{
					ConnPair = ConnPair + (tam[a] * tam[b]);
					merge(a, b);
				}
			}
		}

		unsigned long long  DicConnPair = (nos * (nos - 1) / 2) - ConnPair;
		stack<unsigned long long> resp;

		while (!R.empty())
		{
			int popped = R.top();
			R.pop();

			if (popped > 0)
			{
				int a = raiz(aresta[popped].v1);
				int b = raiz(aresta[popped].v2);
				if (a != b)
				{
					DicConnPair = DicConnPair - (tam[a] * tam[b]);
					merge(a, b);
				}
			}
			else resp.push(DicConnPair);

		}

		while (!resp.empty())
        {
            cout << resp.top() << endl;
			resp.pop();
		}
		if (tests > 0) cout << endl;
	}

	return 0;
}