#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010, mod = 360000;
int falha[maxn], a[maxn], b[maxn], c[maxn << 1], n;

void getNext()
{
	falha[0] = falha[1] = 0;
	for (int i = 1; i < n; ++i)
	{
		int j = falha[i];
		while (j && a[i] != a[j])
			j = falha[j];
		falha[i + 1] = a[i] == a[j] ? j + 1 : 0;
	}
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for (int i = 0; i < n; ++i)
			scanf("%d", b + i);

		sort(a, a + n);
		sort(b, b + n);

		c[n - 1] = (b[0] - b[n - 1] + mod) % mod;

		for (int i = 1; i < n; ++i)
		{
			a[i - 1] = (a[i] - a[i - 1] + mod) % mod;
			b[i - 1] = (b[i] - b[i - 1] + mod) % mod;
			c[i - 1] = c[i + n - 1] = b[i - 1];
		}

		getNext();
		bool flag = false;

		for (int i = 0, j = 0; i < (n << 1) - 1; ++i)
		{
			while (j && a[j] != c[i])
				j = falha[j];
			if (a[j] == c[i]) j++;
			if (j == n - 1)
			{
				flag = true;
				break;
			}
		}

		puts(flag ? "possible" : "impossible");
	}

	return 0;
}
