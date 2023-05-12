#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        int top = 0, left = 0, bottom = row, right = column;
        vector<int> ans;
        while (top < bottom && left < right)
        {
            for (int i = left; i < right; i++)
                ans.push_back(matrix[top][i]);
            for (int i = top + 1; i < bottom; i++)
                ans.push_back(matrix[i][right - 1]);
            if (top < bottom - 1 && left < right - 1)
            {

                for (int i = right - 2; i >= left; i--)
                    ans.push_back(matrix[bottom - 1][i]);
                for (int i = bottom - 2; i > top; i--)
                    ans.push_back(matrix[i][left]);
            }
            top++, bottom--, left++, right--;
        }
        return ans;
    }
};
int main()
{
    return 0;
}