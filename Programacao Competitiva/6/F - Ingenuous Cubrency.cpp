#include <bits/stdc++.h>

using namespace std;

// This code is
unsigned long long int count(unsigned long long int cubes[], unsigned long long int n, unsigned long long int valor)
{
	// table[i] will be storing the number of solutions for
	// value i. We need valor+1 rows as the table is
	// constructed in bottom up manner using the base case
	// (valor = 0)
	unsigned long long int table[valor + 1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	table[0] = 1;

	// Pick all cubes one by one and update the table[]
	// values after the index greater than or equal to the
	// value of the picked coin
	for (unsigned long long int i = 0; i < n; i++)
		for (unsigned long long int j = cubes[i]; j <= valor; j++)
			table[j] += table[j - cubes[i]];
	return table[valor];
}

// Driver Code
int main()
{
	unsigned long long int cubes[21];
    for (int i = 1; i < 22; i++)
    {
        cubes[i] = i * i * i;
    }
    
	unsigned long long int n = sizeof(cubes) / sizeof(cubes[0]);
    unsigned long long int valor;
    cin >> valor;
	cout << count(cubes, n, valor);
	return 0;
}
