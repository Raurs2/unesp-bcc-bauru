#include<bits/stdc++.h>

int main()
{
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int m;
        cin >> m;

        vector<int> l[100000], r[100000];
        bool begin = false, end = false;
        int segments = 0;
        for (segments = 0; l[segments] != 0 && r[segments] != 0; segments++)
        {
            scanf("%d %d", &l[segments], &r[segments]);

            if (l[segments] == 0) begin = true;
            if (r[segments] == m) end = true;
            
        }
        
        int dist_min = 0;

        if (!begin || !end)
        {
            cout << "0" << endl;
        } else
        {
            vector<int> vec_seg[segments];

            do
            {
                if ()
                {
                    
                }
                
            } while (next_permutation(vec_seg, vec_seg+segments));
            
        }
        
    }
    
    return 0;
}
