#include <bits/stdc++.h>

#define MAX 10010
#define INF 0x3F3F3F3F

using namespace std;

int testes, i, j, d, n, m, s, k, t, b, e, w, resposta;
int usado[MAX], distancia[MAX], distanciaR[MAX];

struct aresta
{
  int no, distancia;
  aresta(int no, int distancia) : no(no), distancia(distancia) {}
};

bool operator< (aresta a, aresta b)
{
  return a.distancia > b.distancia;
}

int min(int i, int j)
{
  return (i < j) ? i : j;
}

vector<vector<aresta> > g, gr;

void dijkstra(vector<vector<aresta> > &g, int *d, int start)
{
  int v, para, custo;

  memset(usado,0,sizeof(usado));
  priority_queue<aresta> pq;
  pq.push(aresta(start,0));

  while(!pq.empty())
  {

    aresta e = pq.top(); pq.pop();
    v = e.no;

    if (e.distancia > d[v]) continue;

    for(j = 0; j < g[v].size(); j++)
    {
      para = g[v][j].no;
      custo = g[v][j].distancia;

      if (!usado[para] && (d[para] > d[v] + custo))
      {
        d[para] = d[v] + custo;
        pq.push(aresta(para,d[para]));
      }
    }
  }
}

int main()
{

  cin >> testes;

  while(testes--)
  {
    cin >> n >> m >> k >> s >> t;

    g.clear(); 
    g.resize(n+1);

    gr.clear();
    gr.resize(n+1);

    for(i = 0; i < m; i++)
    {
      cin >> b >> e >> w;

      g[b].push_back(aresta(e,w));
      gr[e].push_back(aresta(b,w));
    }

    memset(distancia,0x3F,sizeof(distancia));
    distancia[s] = 0;

    memset(distanciaR,0x3F,sizeof(distanciaR));
    distanciaR[t] = 0;

    dijkstra(g,distancia,s);
    dijkstra(gr,distanciaR,t);

    resposta = distancia[t];

    for(i = 0; i < k; i++)
    {
      cin >> b >> e >> w;

      resposta = min(resposta, distancia[b] + w + distanciaR[e]);
      resposta = min(resposta, distancia[e] + w + distanciaR[b]);
    }

    if (resposta == INF) cout << "-1" << endl;
    else cout << resposta << endl;
  }

  return 0;
}