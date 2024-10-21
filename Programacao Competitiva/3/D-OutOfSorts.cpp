#include <bits/stdc++.h>

using namespace std;

long long int M, A, C, x0, N, i, target, contagem = 0;
vector<long long int> valores;

/*int binary_search(vector<long long int> valores, int target) {
    int low = 0;
    int high = valores.size() - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        if (valores[mid] == target) {
            return 1;
        } else if (valores[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}*/

int binary_search(long long int esq, long long int dir, long long int target) {
    if (esq > dir) {
        return 0;
    } 
    long long int meio = (esq + dir) / 2;
    if (valores[meio] > target) {
        return binary_search(esq, meio - 1, target);
    }
    if (valores[meio] < target) {
        return binary_search(meio + 1, dir, target);
    }
    return 1;
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &N, &M, &A, &C, &x0);
    valores.push_back(((A * x0 + C) % M));
    for (i = 1; i < N; i++) {
        valores.push_back(((A * valores[i - 1] + C) % M));
    }
    for(i = 0; i < N; i++) {
        target = valores[i];
        int resultado = binary_search(0, N - 1, target);
        if (resultado == 1) {
            contagem++;
        }
    }
    printf("%lld\n", contagem);

    /*
    for (i = 0; i < N; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");
    */
    return 0;
}