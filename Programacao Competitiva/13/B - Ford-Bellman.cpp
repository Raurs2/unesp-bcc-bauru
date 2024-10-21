#include <bits/stdc++.h>

using namespace std;

#define MAX 10002
#define INF 0x3F3F3F3F

int n, m, v1[MAX], v2[MAX], peso[MAX], x[MAX];

void bellmanFord()
{
	memset(x, 0x3F, sizeof x);
	x[1] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (x[v1[j]] < INF && x[v2[j]] > x[v1[j]] + peso[j]) x[v2[j]] = x[v1[j]] + peso[j];
}

int main()
{
    cin >> n >> m;
    
	for (int i = 1; i <= m; i++) cin >> v1[i] >> v2[i] >> peso[i];

	bellmanFord();

	for (int i = 1; i <= n; i++) if (x[i] == INF) x[i] = 30000;

	for (int i = 1; i < n; i++) cout << x[i] << " ";
    cout << x[n] << endl;

	return 0;
}