#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001

int main() 
{
    int n; 
    double res[MAX];
    res[0] = res[1] = 1; 

    for (int i = 2; i < MAX; i++) 
        res[i] = log10(i) + res[i - 1]; 
    
    while (cin >> n) 
        cout << (int)floor(res[n]) << endl;
    
    return 0;
}