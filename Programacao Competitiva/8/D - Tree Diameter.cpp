#include <bits/stdc++.h>

using namespace std;

#define MAX 999999

int diametro[MAX];

int bfs(int init, vector<int> arvore[], int n)
{
	queue<int> q;
	q.push(init);

	int visitou[n+1];

	for (int i = 0; i <= n; i++)
	{
		visitou[i] = 0;
		diametro[i] = 0;
	}

	q.push(init);

	visitou[init] = 1;

	while (!q.empty())
	{
		int u = q.front();

		q.pop();

		for (int i = 0; i < arvore[u].size(); i++)
		{
			if (!visitou[arvore[u][i]])
			{
				visitou[arvore[u][i]] = 1;

				diametro[arvore[u][i]] += diametro[u] + 1;
				q.push(arvore[u][i]);
			}
		}
	}

	return int(max_element(diametro + 1, diametro + n + 1) - diametro);
}

int findDiameter(vector<int> arvore[], int n)
{
	int init = bfs(1, arvore, n);
	int val = bfs(init, arvore, n);
	return diametro[val];
}

int main()
{
    int a, b, n;
	
	cin >> n;

    vector<int> arvore[n+1];

	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		arvore[a].push_back(b);
		arvore[b].push_back(a);
	}
	
	cout << findDiameter(arvore, n) << endl;

	return 0;
}
