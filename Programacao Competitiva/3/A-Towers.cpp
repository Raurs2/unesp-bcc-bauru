#include <bits/stdc++.h>

using namespace std;

int N, i, num, maior = 0;
set<int> elementos;
vector<int> contagem(1001, 0);

int main() {
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &num);
        contagem[num]++;
        elementos.insert(num);
    }
    for (i = 0; i < 1001; i++) {
        if (maior < contagem[i]) {
            maior = contagem[i];
        }
    }

    printf("%d %d\n", maior, elementos.size());
    
    return 0;
}