#include <bits/stdc++.h>

using namespace std;

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

    for (i = 0, j = 0; i < bikes; i++)
    {
        
        if (personal_money[j] >= prices[i])
        {
            personal_money[j] = 999;
            prices[i] = 99;
            max_boys++;
            min_money += prices[i];
            j++;
        } 
    }

    sort(personal_money.begin(), personal_money.end());
    sort(prices.begin(), prices.end());

    int x, k = j;
    for (j = 0 ; j < boys; j++)
    {

        x = prices[k] - personal_money[j];
        if (x <= rubles)
        {
            rubles -= x;
            max_boys++;
            min_money += personal_money[j];
            k++;
        }

        if (rubles <= 0) break;
        
    }

    cout << max_boys << " " << min_money << endl;
    
    return 0;
}