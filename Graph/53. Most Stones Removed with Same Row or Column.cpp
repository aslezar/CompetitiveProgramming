#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Code here
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int i = 0; i < 2; ++i)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}

#endif