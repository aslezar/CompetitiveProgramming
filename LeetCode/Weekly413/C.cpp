#include <bits/stdc++.h>
using namespace std;

#include <debug.cpp>

// bitmask

// class Solution
// {
// public:
//     int helper(vector<pair<int, int>> &v, int i, string r)
//     {
//         if (i == v.size())
//         {
//             return 0;
//         }
//         if (r[v[i].second] == '1')
//         {
//             // row already selected
//         }
//         else
//         {
//             // row not selected
//         }
//     }
//     int maxScore(vector<vector<int>> &grid)
//     {
//         int ans = 0;
//         string r = "0000000000";

//         vector<pair<int, int>> v;
//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[i].size(); j++)
//             {
//                 v.push_back({grid[i][j], i});
//             }
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, pair<int, int>>> v;
        // push all values in vector
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                v.push_back({grid[i][j], {i, j}});
            }
        }

        auto comp = [&](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
        {
            if(a.first==b.first){
                int row1=a.second.first;
                int row2=b.second.first;
                int col1=a.second.second+1;
                int col2=b.second.second+1;
                if(col1==n)return true;
                if(col2==n)return false;
                return grid[row1][col1] < grid[row2][col1];
            }
            return a.first > b.first; };

        sort(v.begin(), v.end(), comp);
        debug(v);

        set<int> visRow;
        set<int> visValue;
        for (int i = 0; i < v.size(); i++)
        {
            int val = v[i].first;
            int row = v[i].second.first;
            int col = v[i].second.second;
            if (visValue.find(val) == visValue.end() && visRow.find(row) == visRow.end())
            {
                visRow.insert(row);
                visValue.insert(val);
                ans += val;
                debug(val);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {};

    // [[1,2,3],[4,3,2],[1,1,1]]
    grid = {{1, 2, 3}, {4, 3, 2}, {1, 1, 1}};
    // cout << s.maxScore(grid)<<endl;

    //  [[8,7,6],[8,3,2]]
    grid = {{8, 7, 6}, {8, 3, 2}};
    // cout << s.maxScore(grid)<<endl;

    // [[19,18],[1,14],[4,14]]
    grid = {{19, 18}, {1, 14}, {4, 14}};
    cout << s.maxScore(grid) << endl;
    return 0;
}