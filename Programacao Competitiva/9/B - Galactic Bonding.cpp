#include <bits/stdc++.h>

#define max 1005

using namespace std;

int n, tests, con;
double x[max], y[max], a[max][max], d;
bool livre[max];

double dis(double x1, double y1, double x2, double y2)
{
    double k1 = x1-x2;
    double k2 = y1-y2;
    return sqrt(k1*k1 + k2*k2);
}

void dfs(int u)
{
    livre[u] = false;
    for (int v=0; v<n; v++)
        if (livre[v] && a[u][v]<=d)
            dfs(v);
}

main()
{
    cin >> tests;

    for (int testN=1; testN<=tests; testN++)
    {
        cin >> n >> d;

        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];

            livre[i] = true;
        }

        for (int i = 0; i < n; i++)
        {
            a[i][i] = 0;

            for (int j=i+1; j<n; j++)
                a[i][j] = a[j][i] = dis(x[i], y[i], x[j], y[j]);
        }

        con = 0;

        for (int i=0; i<n; i++)
            if (livre[i])
            {
                con++;
                dfs(i);
            }

        printf("Case %d: %d\n", testN, con);
    }
}
