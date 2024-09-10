#ifdef LOCAL_RUN

// https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
    int helper(vector<pair<int, pii>> &g, int index, string &mask, vector<unordered_map<string, int>> &dp)
    {
        if (index >= g.size())
        {
            return 0;
        }

        if (dp[index].find(mask) != dp[index].end())
        {
            return dp[index][mask];
        }
        // skip this index
        int sum = helper(g, index + 1, mask, dp);

        // if row not taken take this element in ans
        int row = g[index].second.first;
        if (mask[row] == '0')
        {
            mask[row] = '1';
            int j = index + 1;
            while (j < g.size() && g[index].first == g[j].first)
                j++;
            sum = max(sum, helper(g, j, mask, dp) + g[index].first);
            mask[row] = '0';
        }
        return dp[index][mask] = sum;
    }

public:
    int maxScore(vector<vector<int>> &grid)
    {
        vector<pair<int, pii>> g;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                g.PB({grid[i][j], {i, j}});
            }
        }
        sortd(g);
        debug(g);
        vector<unordered_map<string, int>> dp(g.size());
        string mask(grid.size(), '0');

        return helper(g, 0, mask, dp);
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    // [[1,2,3],[4,3,2],[1,1,1]]
    vector<vector<int>> grid = {{1, 2, 3}, {4, 3, 2}, {1, 1, 1}};
    cout << s.maxScore(grid) << endl;

    // [[8,7,6],[8,3,2]]
    grid = {{8, 7, 6}, {8, 3, 2}};
    cout << s.maxScore(grid) << endl;

    return 0;
}

#endif