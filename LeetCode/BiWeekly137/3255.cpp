#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 1 || k == 1)
            return vector<int>(nums);

        vector<int> result;
        int l = 0, r = 1; // r-> 0 to n-1
        int failedIndex = -1;

        // r-> 0 to k - 1
        while (r < k - 1)
        {
            if (nums[r - 1] + 1 != nums[r])
                failedIndex = r - 1;
            r++;
        }

        // r-> k to n
        while (r < n)
        {
            if (nums[r - 1] + 1 != nums[r])
                failedIndex = r - 1;

            if (failedIndex == -1 || failedIndex < l)
                result.push_back(nums[r]);
            else
                result.push_back(-1);

            l++;
            r++;
        }
        return result;
    }
};