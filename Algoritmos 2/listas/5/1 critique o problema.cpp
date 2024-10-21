int busca (int x, int n, int v[]) {
    int j = 0;
    while (j < n && v[j] < x) ++j;
        return j;
}

/*
Critique a seguinte formulação do problema de busca: dado x e um vetor crescente v[0..n-1],
encontrar um índice j tal que v[j-1] ≤ x ≤ v[j]. Critique a formulação construída em torno de
"v[j-1] < x < v[j]".
    no while temos v[j] < x, mas na formula dada queremos um v[j-1] < x < v[j], entao teria que ser 
    um x < v[j] && v[j-1] < x.
*/