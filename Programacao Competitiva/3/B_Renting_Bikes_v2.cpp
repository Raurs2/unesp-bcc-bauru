#include <bits/stdc++.h>

using namespace std;

int otimizar()
{
    
}

int main()
{
    int boys, bikes, rubles, max_boys = 0, min_money = 0;
    
    int j, i;

    cin >> boys >> bikes >> rubles;

    vector<int> personal_money(boys), prices(bikes);

    for (i = 0; i < boys; i++)
        cin >> personal_money[i];

    for (i = 0; i < bikes; i++)
        cin >> prices[i];
    
    sort(personal_money.begin(), personal_money.end());
    sort(prices.begin(), prices.end());


    


    cout << max_boys << " " << min_money << endl;
    
    return 0;
}