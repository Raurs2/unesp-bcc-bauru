#include <bits/stdc++.h>

using namespace std;

#define MAXN 760

int x[MAXN], y[MAXN];
int S[MAXN];

struct Aresta
{
    int v1,v2;
    double peso;
} aresta[MAXN * MAXN];

bool compara_peso(Aresta a, Aresta b)
{
    return a.peso < b.peso; 
}

int find(int x)
{
    if(x != S[x]) S[x] = find(S[x]);
    return S[x];
}

int merge(int x,int y)
{
    x = find(x);
    y = find(y);

    if(x != y) S[x] = S[y];
    else return 0;
    return 1;
}


int n, cont;

void kruskal()
{
    for(int i = 1; i <= cont; i++)
        if(merge(aresta[i].v1, aresta[i].v2))
            cout << aresta[i].v1 << aresta[i].v2 << endl;
} 

int main()
{
    cont = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            double peso_temp = sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
            cont++;
            aresta[cont].v1 = i, aresta[cont].v2 = j, aresta[cont].peso = peso_temp;
        }
    }

    for(int i = 1; i <= MAXN; i++)
        S[i] = i;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    
    sort(aresta + 1, aresta + 1 + cont, compara_peso);
    kruskal();
    
    return 0;
}