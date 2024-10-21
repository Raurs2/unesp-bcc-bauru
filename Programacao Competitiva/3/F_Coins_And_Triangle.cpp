#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests, coins, height, x;

    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        cin >> coins;

        height = 0;
        x = 1;
        while (1)
        {
            if ((coins - x) >= 0)
            {
                coins -= x;
                height++;
                x++;
            } else break;
        }
        
        cout << height << endl;
    }
    
    return 0;
}