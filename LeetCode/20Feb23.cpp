#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        auto ans = lower_bound(nums.begin(), nums.end(), target);
        if (ans == nums.end())
            return nums.size();
        return (ans - nums.begin());
    }
};
class Solution2
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
class Solution3
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size();
        int mid = 0;
        if (nums[high - 1] < target)
            return high;
        while (low <= high)
        {
            mid = low + high;
            // mid/=2;
            mid >>= 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
int main()
{

    return 0;
}