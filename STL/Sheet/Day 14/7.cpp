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
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        typedef pair<int, int> pii;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    time[i][j] = 0;
                }
                else if (grid[i][j] == 2)
                {
                    time[i][j] = 0;
                    pq.push({0, i * m + j});
                }
            }
        }

        const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto inRange = [&](int x, int y) -> bool
        { return x >= 0 && x < n && y >= 0 && y < m; };

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            if (top.first > time[top.second / m][top.second % m])
            {
                continue;
            }

            for (auto &d : directions)
            {
                int x = top.second / m + d.first;
                int y = top.second % m + d.second;
                if (inRange(x, y) && grid[x][y] == 1 && time[x][y] > 1 + top.first)
                {
                    time[x][y] = 1 + top.first;
                    pq.push({1 + top.first, x * m + y});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, time[i][j]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif