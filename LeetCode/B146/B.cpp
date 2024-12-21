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
public:
    vector<vector<vector<ll>>> dp;
    int helper(int i, int j, vector<vector<int>> &grid, int c, const int &k)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            c ^= grid[i][j];
            debug(c, k);
            return c == k;
        }
        if (i >= grid.size() || j >= grid[0].size())
        {
            return 0;
        }

        auto &d = dp[i][j][c];
        if (d != -1)
        {
            return d;
        }

        // move down
        ll down = helper(i + 1, j, grid, c ^ grid[i][j], k);

        // move right
        ll right = helper(i, j + 1, grid, c ^ grid[i][j], k);

        return d = (down + right) % mod;
    }
    int countPathsWithXorValue(vector<vector<int>> &grid, int k)
    {
        dp = vector<vector<vector<ll>>>(grid.size(), vector<vector<ll>>(grid[0].size(), vector<ll>(17, -1)));
        return helper(0, 0, grid, 0, k);
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11

    vii grid = {{2, 1, 5}, {7, 10, 0}, {12, 6, 4}};
    cout << s.countPathsWithXorValue(grid, 11) << '\n';
    cout << '\n';

    return 0;
}

#endif