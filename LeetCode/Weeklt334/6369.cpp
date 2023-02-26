#include <iostream>
#include <vector>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        ans[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] + nums[i - 1];
        }
        int sum = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            sum = nums[i + 1] + sum;
            ans[i] = abs(ans[i] - sum);
        }
        return ans;
    }
};

int main()
{

    return 0;
}