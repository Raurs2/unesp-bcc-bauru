#include <bits/stdc++.h>
using namespace std;

int sumDice(int n, int dp[])
{
	if (n == 0) return 1;

	if (dp[n] != -1) return dp[n];

	int nOfWays = 0;

	for (int i = 1; i <= 6; i++)
		if (n - i >= 0)
		{
			nOfWays += sumDice(n - i, dp);
			nOfWays %= 1000000007;
		}	
	
	return dp[n] = nOfWays;
}

int main()
{
    int n;
    cin >> n;

	int dp[n+1];
	for (int i = 0; i < n+1; i++)
		dp[i] = -1;
	
	cout << sumDice(n, dp) << endl;
	
    return 0;
}
