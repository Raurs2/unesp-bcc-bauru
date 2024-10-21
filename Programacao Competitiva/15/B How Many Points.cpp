#include <bits/stdc++.h>

using namespace std;

long long Ax, Ay, Bx, By;

long long Abs(long long n)
{
    return n > 0 ? n : -n;
}

long gcd(long long a, long long b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> Ax >> Ay >> Bx >> By;
        cout << "Case " << i << ": " << gcd(Abs(Ax - Bx), Abs(Ay - By)) + 1 << endl;
    }
    
    return 0;
}