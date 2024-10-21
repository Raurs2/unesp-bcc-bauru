#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
	int src, dest;
};


class Graph {
public:
	int V, E;

	Edge* edge;
};

Graph* createGraph(int V, int E)
{
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];

	return graph;
}

int find(int parent[], int i)
{
	if (parent[i] == i)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
	 parent[x] = y; 
	 
	 }

int isCycle(Graph* graph)
{
	int* parent = new int[graph->V];

	for(int i = 0; i < graph->V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < graph->E; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if (x == y)
			return 1;

		Union(parent, x, y);
	}
	return 0;
}

int daTam(Graph* graph, int count)
{
	int* parent = new int[graph->V];

	for(int i = 0; i < graph->V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < graph->E; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if (x > count)
			return x;
		if (y > count)
			return y;

		Union(parent, x, y);
	}
	return 0;
}
int main()
{

	int test;
	cin >> test;

	int n, m, a, b, count = 0, maiorCount = 0;
	Graph* graph;

	for (int i = 0; i < test; i++)
	{
		cin >> n >> m;
		
		graph = createGraph(n, m);
		
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;

			graph->edge[j].src = a;
    		graph->edge[j].dest = b;
		}
		count = 0, maiorCount = 0;
		count = daTam(graph, count);
		if ( count > maiorCount)
		{
			maiorCount = count;
		}

		cout << maiorCount << endl;
		
	}

	return 0;
}