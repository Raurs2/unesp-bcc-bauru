#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n[10], a[10], k, k_temp;
    bool tem;
    
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> n[j];

        cin >> k;

        tem = false;

        for(int j = 0; j < 10; j++) a[j] = j;

        do
        {
            k_temp = 0;

            for (int j = 0; j < 10; j++)
                k_temp += n[j]*a[j];

            if (k_temp <= k)
            {
                tem = true;
                break;
            }
        } while (next_permutation(a, a+10));
        
        if (tem) 
            for (int j = 0; j < 10; j++)
                cout << a[j] << " ";
        else cout << "-1";

        cout << endl;
    }
    
    return 0;
}