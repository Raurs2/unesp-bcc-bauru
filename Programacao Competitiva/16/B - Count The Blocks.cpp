#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

const int MAXN = 2e5+100;

long long dp[MAXN];

inline long long ksm(long long x, long long y)
{
	long long res = 1, k = x;

	for (; y; y >>= 1, k = k*MOD)
		if (y & 1) res = res * k % MOD;

	return res % MOD;
}

int main()
{

	long long n;
	cin >> n;

	dp[n] = 10;
	dp[n-1] = 180;

	for (long long i = n-2; i >= 1 ; i--)
		dp[i] = 10 * 9 * ksm(10, n-i-1) * 2 % MOD;
	
	for (long long i = n-2; i >= 1 ; i--)
		dp[i] = (dp[i] % MOD + 10 * 9 * 9 * (n - i - 1) * ksm(10, n - i - 2) % MOD) % MOD;
	
	for (long long i = 1; i <= n; i++)
		cout << dp[i] << " ";
	
	cout  << endl;

	return 0;
}