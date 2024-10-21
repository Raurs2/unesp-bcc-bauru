#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int stones, diferenca = 2147483646;

    cin >> stones;

    int bitmasks = (1 << stones) - 1; 

    vector<int> weights(stones);

    for (int i = 0; i < stones; i++)
        cin >> weights[i];

    for(int bit = 1; bit <= bitmasks; bit++)
	{
		int pile1 = 0, pile2 = 0;

		for(int i = 0; i < stones; i++)
		{
			if( (bit & (1 << i)) == 0)
				pile1 += weights[i];
			else
				pile2 += weights[i];
		}
		
		diferenca = min(diferenca, abs(pile1 - pile2));
	}
	cout << diferenca << endl;

    return 0;
}