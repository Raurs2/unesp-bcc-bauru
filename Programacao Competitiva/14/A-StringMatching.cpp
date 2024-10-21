#include <bits/stdc++.h>

using namespace std;

string text, pattern, concat;
int tamanho;

void zArray(int Z[])
{
    int L, R, k, i;
    L = R = 0;

    for (i = 1; i < tamanho; i++)
    {
        if (i > R)
        {
            L = R = i;

            while ((R < tamanho) && (concat[R - L] == concat[R]))
                R++;

            Z[i] = R-L;
            R--;
        } else
        {
            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;

                while ((R < tamanho) && (concat[R - L] == concat[R]))
                    R++;

                Z[i] = R - L;
                R--;
            }
        }
    }
}

int main()
{
    int N, M, i, repet = 0;

    cin >> text;
    cin >> pattern;

    N = text.length(); M = pattern.length();
    concat = pattern + "$" + text;
    tamanho = concat.length();

    int Z[tamanho];
    zArray(Z);

    for (i = 0; i < tamanho; i++) 
        if (Z[i] == pattern.length())
            repet++;

    cout << repet << endl;
    
    return 0;
}