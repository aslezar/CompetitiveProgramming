#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define el << '\n'
#define ws << ' '

class Solution
{
    int M = 1e7;

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            auto it = upper_bound(i, nums.end(), target - *nums.begin());
            if (it == nums.end())
                break;
            int length = it - i;
            length = it - nums.begin();
            ans = (ans + length) % M;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    int binarySearchRightmost(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int answer = 0;

        // Iterate over each left pointer.
        for (int left = 0; left < n; left++)
        {
            // Find the insertion position for `target - nums[left]`
            // 'right' equals the insertion index minus 1.
            int right = binarySearchRightmost(nums, target - nums[left]) - 1;
            if (right >= left)
            {
                answer += power[right - left];
                answer %= mod;
            }
        }

        return answer;
    }
};

int main()
{
    return 0;
}