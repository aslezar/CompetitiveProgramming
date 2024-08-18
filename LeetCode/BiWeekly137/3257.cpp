#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &board)
    {
        // select top 3 values
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int, ll>>> b(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                b[i].push_back({board[i][j], j});
            sort(b[i].rbegin(), b[i].rend());
            b[i].resize(3);
        }

        ll ans = -3e9;
        for (int row1 = 0; row1 < n; row1++)
        {
            for (int i1 = 0; i1 < 3; i1++)
            {
                ll val1 = b[row1][i1].first;
                int col1 = b[row1][i1].second;

                for (int row2 = row1 + 1; row2 < n; row2++)
                {
                    for (int i2 = 0; i2 < 3; i2++)
                    {
                        ll val2 = b[row2][i2].first;
                        int col2 = b[row2][i2].second;

                        for (int row3 = row2 + 1; row3 < n; row3++)
                        {
                            for (int i3 = 0; i3 < 3; i3++)
                            {
                                ll val3 = b[row3][i3].first;
                                int col3 = b[row3][i3].second;

                                if (col1 != col2 && col2 != col3 &&
                                    col1 != col3)
                                {
                                    ans = max(ans, val1 + val2 + val3);
                                }
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};