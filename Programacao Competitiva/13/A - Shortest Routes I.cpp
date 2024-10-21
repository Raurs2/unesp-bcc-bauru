#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist;

void dijkstra()
{
	for(int i = 0; i <= n; i++)
		dist[i] = 1e17;

	priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > pq;

	dist[1] = 0;
	pq.push({0,1});

	while(!pq.empty())
	{
		int a = pq.top().second;
		int d = pq.top().first;

		pq.pop();

		if(dist[a] < d) continue;

		for(auto e: g[a])
		{
			int b = e.first;
			int c = e.second;

			if(dist[b] <= c+d) continue;
			else
			{
				dist[b] = c+d;
				pq.push({dist[b], b});
			}
		}
	}
}

int32_t main()
{

	cin >> n >> m;

	g.resize(n+1);
	dist.resize(n+1);

	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a].push_back({b,c});
	}

	dijkstra();

	for(int i = 1; i <= n; i++ ) cout << dist[i] << " ";
	cout << endl;
}