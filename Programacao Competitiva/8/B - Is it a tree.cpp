#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int nosVisitados;

void dfs(int s, int visitou[MAX], vector<int> arvore[MAX])
{
    if (!visitou[s]) visitou[s] = 1;

    for (vector<int>::iterator i = arvore[s].begin(); i != arvore[s].end(); i++)
        if (visitou[*i] == 0)  
        {
            nosVisitados++;
            dfs(*i,visitou,arvore);
        } 
}

int main()
{
    int nos, vertices, x, y;
    cin >> nos >> vertices;
    
    vector<int> arvore[nos+1];
    int visitou[nos+1];

    for (int i = 0; i < vertices; i++)
    {
        cin >> x >> y;
        arvore[x].push_back(y);
        arvore[y].push_back(x);
    }
    
    for (int i = 1; i <= nos; i++) visitou[i] = 0;

    if (nos == 1) cout << "YES" << endl;             
    else if (vertices != nos-1) cout << "NO" << endl;
    else
    {
        nosVisitados = 1; 
        dfs(1, visitou, arvore);

        if (nosVisitados == nos) cout<<"YES";
        else cout<<"NO";
    }

    return 0;
}
