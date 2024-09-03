#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIndex(int x, int y, int n, int m)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int xOffset = -1; xOffset <= 1; xOffset++)
        {
            for (int yOffset = -1; yOffset <= 1; yOffset++)
            {
                if (xOffset == 0 && yOffset == 0)
                    continue;
                int x = i + xOffset, y = j + yOffset;
                if (checkIndex(x, y, n, m) && vis[x][y] == false && grid[x][y] == '1')
                {
                    vis[x][y] = true;
                    dfs(grid, vis, x, y);
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    vis[i][j] = true;
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};