#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int ans = INT_MAX;
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]] = i;
        }

        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                mat[i][j] = m[mat[i][j]];
            }
        }
        for (int i = 0; i < mat.size(); i++)
        {
            int max = -1;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] > max)
                    max = mat[i][j];
            }
            if (max < ans)
                ans = max;
        }
        for (int i = 0; i < mat[0].size(); i++)
        {
            int max = -1;
            for (int j = 0; j < mat.size(); j++)
            {
                if (mat[j][i] > max)
                    max = mat[j][i];
            }
            if (max < ans)
                ans = max;
        }

        return ans;
    }
};
int main()
{
    Solution ans;
    vector<int> a = {1, 3, 4, 2};
    vector<vector<int>> b = {{1, 4}, {2, 3}};
    cout << ans.firstCompleteIndex(a, b);
    return 0;
}