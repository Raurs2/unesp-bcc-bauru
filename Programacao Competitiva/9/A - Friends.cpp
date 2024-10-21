#include <bits/stdc++.h>

using namespace std;

#define MAX 30001

int tests, n, m, a, b, tam[MAX], pai[MAX], maior;

void init()
{
    for (int i = 1; i <= MAX; i++)
    {
        pai[i] = i;
        tam[i] = 1;
    }
}

int find(int x)
{
    if (pai[x] == x) return x;

    return find(pai[x]);
}

void merge(int u, int v)
{
    int a = find(u), b = find(v);

    if (tam[a] > tam[b]) swap(a, b);
	
    if (a != b)
    {
        pai[a] = b;
        tam[b] += tam[a];
    }

    if (maior < tam[b]) maior = tam[b];
}

int main()
{
	cin	>> tests;

    for (int i = 0; i < tests; i++)
    {
        init();
		
        maior = 1;
		
		cin	>> n >> m;

        for (int j = 0; j < m; j++)
        {
			cin	>> a >> b;

            if (find(a) != find(b)) merge(a, b);
        }

		cout << maior << endl;
    }

    return 0;
}