#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int maxDistance(vector<vector<int>> &grid)
    {
        int visit[grid.size()][grid[0].size()];

        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                visit[i][j] = grid[i][j];
                if (grid[i][j])
                    q.push({i, j});
            }

        int dist = -1;
        while (!q.empty())
        {
            int qSize = q.size();

            while (qSize--)
            {
                pair<int, int> land = q.front();
                q.pop();

                for (pair<int, int> dir : direction)
                {
                    int x = land.first + dir.first;
                    int y = land.second + dir.second;

                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visit[x][y] == 0)
                    {
                        visit[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }

            dist++;
        }
        return dist == 0 ? -1 : dist;
    }
};

int main()
{

    return 0;
}