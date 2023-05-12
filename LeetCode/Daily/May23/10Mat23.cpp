#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int top = 0, left = 0, bottom = n, right = n;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int no = 1;
        while (top < bottom && left < right)
        {
            for (int i = left; i < right; i++)
                ans[top][i] = no++;
            for (int i = top + 1; i < bottom; i++)
                ans[i][right - 1] = no++;

            if (top < bottom - 1 && left < right - 1)
            {

                for (int i = right - 2; i >= left; i--)
                    ans[bottom - 1][i] = no++;
                for (int i = bottom - 2; i > top; i--)
                    ans[i][left] = no++;
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