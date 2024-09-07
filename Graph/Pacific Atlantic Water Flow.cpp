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
private:
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>> &vis, const int &m, const int &n, vector<vector<int>> &h)
    {
        vis[i][j] = 1;
        for (auto &d : delta)
        {
            int x = i + d.first, y = j + d.second;
            if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y] == 0)
            {
                if (h[i][j] <= h[x][y])
                    dfs(x, y, vis, m, n, h);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        auto &h = heights;
        int m = h.size();
        int n = h[0].size();

        vector<vector<int>> visPacific(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            if (visPacific[i][0] == 0)
                dfs(i, 0, visPacific, m, n, h);
        }
        for (int j = 0; j < n; j++)
        {
            if (visPacific[0][j] == 0)
                dfs(0, j, visPacific, m, n, h);
        }

        vector<vector<int>> visAtlantic(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            if (visAtlantic[i][n - 1] == 0)
                dfs(i, n - 1, visAtlantic, m, n, h);
        }
        for (int j = 0; j < n; j++)
        {
            if (visAtlantic[m - 1][j] == 0)
                dfs(m - 1, j, visAtlantic, m, n, h);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (visPacific[i][j] == 1 && visAtlantic[i][j] == 1)
                {
                    ans.push_back({i, j});
                }
        }
        debug(ans);
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]

    vector<vector<int>> h = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    s.pacificAtlantic(h);
    cout << endl;

    return 0;
}

#endif