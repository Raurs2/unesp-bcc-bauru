#include<bits/stdc++.h>

#define MAXN 1000

using namespace std;

int num[MAXN];
long long a, b, x, y;

int main()
{
    while(cin >> a >> b >> x >> y)
    {
        int t = __gcd(x, y);

        x /= t;
        y /= t;

        t = min(a/x, b/y);

        long long l1, l2;

        l1 = x*t;
        l2 = y*t;

        cout << l1 << " " << l2 << endl;
    }

    return 0;
}