#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000010

ll r[MAX];
ll pi[MAX];

ll LCM_Sum(long long n)
{
	for (ll i = 1; i <= n; ++i)
		pi[i] = i;

	for (ll i = 2; i <= n; ++i)
		if (pi[i] == i)
			for (int j = i; j <= n; j += i)
			{
				pi[j] /= i;
				pi[j] *= i - 1;
			}

	for (ll i = 1; i < n; ++i)
		for (int j = i; j <= n; j += i)
			r[j] += (i * pi[i]);
}

int main()
{
	LCM_Sum(1000000);

	int n, T;
	ll r_final;
    cin >> T;

    while (T--)
    {
        cin >> n;

		r_final = r[n] + 1;
		r_final *= n;
		r_final /= 2;

        cout << r_final << endl;
    }
    
	return 0;
}
