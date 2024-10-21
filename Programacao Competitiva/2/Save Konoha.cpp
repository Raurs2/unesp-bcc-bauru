#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, n, z, x, y = 0;
    priority_queue<int> a;

    cin >> test;

    
    for (int i = 0; i < test; i++)
    {
        cin >> n;
        cin >> z;

        for (int j = 0; j < n; j++)
        {
            cin >> x;
            a.push(x);
        }

        while (z > 0)
        {
            x = a.top();
            a.pop();
            z -= x;
            a.push(x/2);
            y++;

            if (!a.top()) break;
        }

        if (z > 0) cout << "Evacuate" << endl;
        else cout << y << endl;
        
        y = 0;

        while (!a.empty())
        {
            a.pop();
        }
        
    }
    
    return 0;
}