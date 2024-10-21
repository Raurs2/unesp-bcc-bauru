int busca (int x, int n, int v[]) {
    int j = 0;
    while (v[j] < x && j < n) ++j;
        return j;
}

/*
Critique a seguinte versão da função:
    a unica coisa que mudou em relação ao 1 é a ordem das comparações logicas.
*/