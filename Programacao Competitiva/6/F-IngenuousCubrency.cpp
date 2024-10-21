#include <bits/stdc++.h>
using namespace std;

long long int count(long long int cubes[], long long int n, long long int valor)
{
    long long int j, x, y, i, table[valor + 1][n];

	for (i = 0; i < n; i++) {
        table[0][i] = 1;
    }

	for (i = 1; i < valor + 1; i++) {
		for (j = 0; j < n; j++) {

			x = (i - cubes[j] >= 0) ? table[i - cubes[j]][j] : 0;

			y = (j >= 1) ? table[i][j - 1] : 0;

			table[i][j] = x + y;
		}
	}
	return table[valor][n - 1];
}

int main()
{
	long long int cubes[22], valor;

    for (int i = 0; i < 21; i++) {
        int j = i + 1;
        cubes[i] = j * j * j;
    }

    long long int n = sizeof(cubes) / sizeof(cubes[0]);
    while (cin >> valor) {
        cout << count(cubes, n, valor) << endl;
    }
	return 0;
}