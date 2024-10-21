#include "bits/stdc++.h"

using namespace std;

void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if ((int)name.size())
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	setIO("censor");

	string s, t, censurado;

	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) 
    {
		censurado += s[i];

		if (censurado.size() > t.size() && censurado.substr(censurado.size() - t.size()) == t)
			censurado.resize(censurado.size() - t.size());
	}
    
	cout << censurado << endl;
}