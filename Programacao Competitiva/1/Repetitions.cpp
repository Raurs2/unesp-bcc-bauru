#include <bits/stdc++.h>

using namespace std;

int main()
{
    string dna;
   // int igual[101];
    int maior = 1, atual = 1;

    cin >> dna;

    //for (int i = 0; i < 101; i++)
    //{
     //   igual[i] = 1;
    //}
    
    
    for (int i = 1; i < dna.size(); i++)
    {
        if (dna[i] == dna[i - 1]) {
            atual++;
        } else atual = 1;

        if (maior < atual)
        {
            maior = atual;
        } 
    }

    printf("%d\n", maior);

    return 0;
}