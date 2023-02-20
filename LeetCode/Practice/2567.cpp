#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int minimizeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ans = nums[size - 1] - nums[2];
        ans = min(ans, nums[size - 3] - nums[0]);
        ans = min(ans, nums[size - 2] - nums[1]);
        return ans;
    }
};
int main()
{

    return 0;
}