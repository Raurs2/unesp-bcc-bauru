#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define MOD 1000000007

typedef long long ll;

int n, k, v[MAXN];
ll factorial[MAXN], inv_factorial[MAXN];

int pot_mod(ll a, int b)
{
    ll r = 1;
    
    while (b) 
    {
        if (b & 1) r = r * a % MOD;
        
        a = a * a % MOD;
        b >>= 1;
    }
    
    return r;
}

ll comb(int n, int m)
{
    return factorial[n] * inv_factorial[m] % MOD * inv_factorial[n - m] % MOD;
}

int main() 
{
    cin >> n >> k;
    
    if (k == 1) 
    {
        cout << "0" << endl;
        return 0;
    }
    
    for (int i = 0; i < n; ++i) cin >> v[i]; 
    
    sort(v, v + n);
    
    factorial[0] = inv_factorial[0] = 1;
    
    for (int i = 1; i <= n; ++i) 
    {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv_factorial[i] = pot_mod(factorial[i], MOD - 2);
    }
    
    int resp = 0;
    
    for (int i = 0; i < n;) 
    {
        int end = i;
        
        while (end < n && v[end] == v[i]) ++end;
        
        if (end >= k) resp = (resp + (comb(end, k) - comb(i, k)) * v[i]) % MOD;
        
        i = end;
    }
    
    for (int i = n - 1; i >= 0;) 
    {
        int end = i;
        
        while (end >= 0 && v[end] == v[i]) --end;
        
        if (n - 1 - end >= k) resp = (resp - (comb(n - 1 - end, k) - comb(n - 1 - i, k)) * v[i]) % MOD;
        
        i = end;
    }
    
    if (resp < 0) resp += MOD;
    cout << resp << endl;
    
    return 0;
}