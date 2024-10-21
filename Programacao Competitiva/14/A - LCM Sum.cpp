#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll LCM_Sum(long long n)
{
	ll sum = 0;

	for (long long int i = 1; i <= n; i++) 
    {

		long long int gcd = __gcd(i, n);
		long long int lcm = (i * n) / gcd;

		sum = sum + lcm;
	}

	return sum;
}

int main()
{
	int n, T;
    cin >> T;

    while (T--)
    {
        cin >> n;
        cout << LCM_Sum(n) << endl;
    }
    
	return 0;
}
