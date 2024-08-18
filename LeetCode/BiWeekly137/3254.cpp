#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> results;
        for (int start = 0; start <= n - k; start++)
        {
            bool isSortedAndCons = true;
            for (int i = start + 1; i < start + k; i++)
            {
                if (nums[i - 1] + 1 != nums[i])
                {
                    isSortedAndCons = false;
                    break;
                }
            }
            if (isSortedAndCons)
                results.push_back(nums[start + k - 1]);
            else
                results.push_back(-1);
        }
        return results;
    }
};