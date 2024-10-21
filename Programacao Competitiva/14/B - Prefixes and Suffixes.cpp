#include <bits/stdc++.h>
using namespace std;

int main(){
    string palavra;
    int N, aux;

    cin >> palavra;

    N = palavra.length();
    aux = N;
    palavra = ' ' + palavra;

    vector<int>ne(N + 1);
    vector<int>dp(N + 1, 1);
    vector<int>resposta;

    for(int i = 2, j = 0; i <= N; i++){
        while (j && palavra[i] != palavra[j + 1]){
            j = ne[j];
        }

        if(palavra[i] == palavra[j + 1]){
            j++;
        }

        ne[i] = j;       
    }

    for (int i = N; i > 0; i--){
        dp[ne[i]] += dp[i];
    }

    while (aux){
        resposta.push_back(aux);
        aux = ne[aux];
    }
    
    reverse(resposta.begin(), resposta.end());

    cout << resposta.size() << endl;
    for (int i : resposta){
        cout << i << ' ' << dp[i] << endl;
    }

    return 0;
}