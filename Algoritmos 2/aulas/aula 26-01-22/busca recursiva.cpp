#include<stdio.h>
int busca(int n, int v[], int num)
{
	if (n == 0) return -1;
	else if (v[n-1] == num) return n;
	else return busca(n-1, v, num);
}

int main(){

	return 0;
}
