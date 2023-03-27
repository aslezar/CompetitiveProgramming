#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int lenx = grid.size(), leny = grid[0].size();
        for (auto &&i : grid)
            i.push_back(INT_MAX);

        vector<int> row(leny + 1, INT_MAX);
        row[leny - 1] = 0;

        int i = lenx;
        while (i > 0)
        {
            i--;
            int j = leny;
            while (j > 0)
            {
                j--;
                int cost = grid[i][j] + min(grid[i][j + 1], row[j]);
                row[j] = cost;
                grid[i][j] = cost;
            }
        }
        return row[0];
    }
};

int main()
{
    vector<vector<int>> a = {{1, 3, 1},
                             {1, 5, 1},
                             {4, 2, 1}};
    Solution ans;
    cout << ans.minPathSum(a);
    return 0;
}