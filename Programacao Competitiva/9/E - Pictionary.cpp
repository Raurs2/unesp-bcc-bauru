#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

int tempo, pai[MAX+1], tam[MAX+1], his[MAX+1];

void init() {
	tempo = 0;

	for (int i = 1; i < MAX; ++i)
	{
		pai[i] = i;
		tam[i] = 1;
		his[i] = 0;
	}
}

int find(int x, int t)
{
	if (pai[x] == x) return x;
	if (his[x] > t) return x;
	return find(pai[x], t);	
}

void merge(int u, int v)
{
	int a = find(u, tempo);
	int b = find(v, tempo);

	if (a == b) return;

	if (tam[a] > tam[b]) swap(a, b);

	pai[a] = b;
	his[a] = tempo;
	tam[b] += tam[a];	
}

int findT(int a, int b, int m)
{
	int esq = 1;
	int dir = m;
	int med;
	int menorT = m;

	while(esq <= dir) 
	{
		med = (esq+dir) / 2;

		if (find(a,med) == find(b,med)) {
			menorT = min(menorT, med);
			dir = med - 1;
		}
		else esq = med + 1;
	}

	return menorT;
}

int main()
{
	int n, m, q, i, j, k;
	
	cin >> n >> m >> q;
	
	init();
	
	for (i = m, tempo = 1; i > 0; i--, tempo++)
		for(j = 2*i; j <= n; j += i)
			merge(i, j);

	for(i = 0; i < q; i++)
	{
		cin >> j >> k;
		cout << findT(j, k, m) << endl;
	}
}