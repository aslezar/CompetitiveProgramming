#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

class Solution
{
    bool check(const pair<int, int> &p, const int &m, const int &n)
    {
        const int &i = p.first, &j = p.second;
        return i >= 0 && j >= 0 && i < m && j < n;
    }

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int time = 0;
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int size = q.size();
            bool pushed = 0;
            for (int i = 0; i < size; i++)
            {
                auto front = q.front();
                q.pop();
                int &x = front.first, &y = front.second;
                if (check({x, y - 1}, m, n) && grid[x][y - 1] == 1)
                {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    pushed = 1;
                }
                if (check({x, y + 1}, m, n) && grid[x][y + 1] == 1)
                {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    pushed = 1;
                }
                if (check({x - 1, y}, m, n) && grid[x - 1][y] == 1)
                {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    pushed = 1;
                }
                if (check({x + 1, y}, m, n) && grid[x + 1][y] == 1)
                {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    pushed = 1;
                }
            }
            if (pushed)
                time++;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};