// Esta função devolve j em 0..n tal que
// v[j-1] < x <= v[j]. Ela supõe que n >= 0.
int busca2 (int x, int n, int v[]) {
if (n == 0) return 0;
if (x > v[n-1]) return n;
return busca2 (x, n-1, v);
}

/*
Discuta a seguinte versão recursiva da função busca:
    essa versão recursiva esta de acordo com a formulação do problema  v[j-1] < x <= v[j]
*/