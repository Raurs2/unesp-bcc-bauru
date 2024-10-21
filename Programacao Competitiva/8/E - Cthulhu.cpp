#include<bits/stdc++.h> 

using namespace std;  
  
int par[102];

int find(int x)
{  
    if ( par[x] == x) return x;  
    return par[x] = find(par[x]);  
}

 void unite(int x, int y)  
 {  
    x = find(x);
    y = find(y);

    if (x != y) par[x] = y;  
}  

int main()  
{  
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 101; i++) par[i] = i; 

    for (int i = 0; i < m; i++)  
    {  
        int x, y;
        cin >> x >> y;

        unite(x, y);  
    }  

    bool isCthulhu = true;

    for(int i = 2; i <= n; i++) if (find(1) != find(i)) isCthulhu = false;  

    if (n != m) isCthulhu = false;  

    if (isCthulhu) cout << "FHTAGN!" << endl;   
    else cout << "NO" << endl;  
    
    return 0;  
}  
