#include <bits\stdc++.h>

using namespace std;

int main()
{
    string host, guest, pile;
    int x = 1;

    cin >> guest;
    cin >> host;
    cin >> pile;

    guest += host;
    sort(guest.begin(), guest.end());
    sort(pile.begin(), pile.end());

    for (unsigned int i = 0; i < guest.size(); i++)
    {
        if (guest[i] != pile[i])
        {
            x = 0;
            break;
        }
    }
    
    if (guest.size() == pile.size() && x)
    {
        cout << "YES" << endl;
    } else
    {
        cout << "NO" << endl;
    }

    return 0;
}