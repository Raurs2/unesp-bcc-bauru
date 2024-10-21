#include <bits/stdc++.h>

#define MAX 1000010

using namespace std;

int a = 0, p[MAX], n, queries;

void dfs(int x, int y)
{
    if (x == y) return;

    a++;
    dfs(p[x], y);
}

int main()
{
    cin >> queries;

    for (int i = 0; i < queries; i++)
    {
        cin >> n;

        for (int j = 1; j <= n; j++)
            cin >> p[j];
        
        for (int j = 1; j <= n; j++)
        {
            a = 1;

            dfs(p[j], j);

            cout << a;

            if (j != n) cout << " "; 
        }
        
        cout << endl;
    }
    
    return 0;
}
