#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

long long modBiExp(int x, int y)
{
	if (y == 0) return 1;

	long long res = modBiExp(x, y/2);
	res = (res * res) % mod; 

	if (y % 2 == 1) return (res * x) % mod;
	else return res;
}

int main()
{

	int a, b;
	cin >> a >> b;

	vector<long long> factorial(a+b);
	factorial[0] = 1;

	for (int i = 1; i < a+b; i++) factorial[i] = (factorial[i-1] * i) % mod;
	
	cout << (((factorial[a+b-1] * modBiExp(factorial[b], mod-2)) % mod) 
	* modBiExp(factorial[a-1], mod-2)) % mod << endl;

	return 0;
}