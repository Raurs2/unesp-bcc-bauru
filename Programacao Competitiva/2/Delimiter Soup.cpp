#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, x = 1;
    string str;
    
    cin >> l;

    getchar();

    getline(cin, str);

    stack<char> pile;
    
    for (int i = 0; i < l; i++)
    {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
        {
            pile.push(str[i]);
        } else if (!pile.empty())
        {
            if ((str[i] == ']' && pile.top() == '[' ) || (str[i] == ')' && pile.top() == '(') || (str[i] == '}' && pile.top() == '{')){
                pile.pop();
            } else if(str[i] != 32){
                cout << str[i] << " " << i << endl;
                x = 0;
                break;
            }
        } else if (str[i] != 32)
        {
            cout << str[i] << " " << i << endl;
            x = 0;
            break;
        }
    }

    if (x) cout << "ok so far" << endl;
    
    return 0;
}