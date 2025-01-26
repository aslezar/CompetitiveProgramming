#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
    bool isValid(vector<vector<int>> &g, vi &colors, int color, int currentVertex)  // O(V-1)
    {
        for (auto v : g[currentVertex])
        {
            if (colors[v] == color)
                return false;
        }
        return true;
    }
    bool graphColoringHelper(int v, vector<vector<int>> &g, int m, int index, vi &colors)
    {
        if (index >= v)
        {
            return true;
        }

        for (int color = 0; color < m; color++)
        {
            if (isValid(g, colors, color, index))
            {
                colors[index] = color;
                if (graphColoringHelper(v, g, m, index + 1, colors))
                {
                    return true;
                }
                colors[index] = -1;
            }
        }
        return false;
    }

public:
    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        vector<vector<int>> g(v);

        for (auto &edge : edges)
        {
            g[edge.first].push_back(edge.second);
            g[edge.second].push_back(edge.first);
        }

        vi colors(v, -1);
        return graphColoringHelper(v, g, m, 0, colors);
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif