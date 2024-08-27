#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIndex(int x, int y, int n, int m)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int x, int y, int original_x, int original_y, vector<pair<int, int>> &island)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[x][y] = true;
        island.push_back({x - original_x, y - original_y});

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        for (int index = 0; index < 4; index++)
        {
            int i = x + delRow[index], j = y + delCol[index];
            if (checkIndex(i, j, n, m) && vis[i][j] == false && grid[i][j] == 1)
            {
                dfs(grid, vis, i, j, original_x, original_y, island);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> islands;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (vis[i][j] == false && grid[i][j] == 1)
                {
                    vector<pair<int, int>> island;
                    dfs(grid, vis, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    cout << s.countDistinctIslands(grid) << endl;
    return 0;
}
