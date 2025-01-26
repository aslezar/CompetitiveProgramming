#ifdef LOCAL_RUN
#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

// #define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

class Solution
{
public:
    int binary_search(vector<int> &nums, int target, int l, int r)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        // edge case
        if (n == 1)
            return nums[0] == target ? 0 : -1;

        // if whole array is sorted, binary search
        if (nums[0] <= nums[n - 1])
            return binary_search(nums, target, l, r);
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[l] <= nums[mid])
            {
                // Left part is sorted
                if (nums[l] <= target && target <= nums[mid])
                {
                    // if element is in sorted part, search and return
                    return binary_search(nums, target, l, mid);
                }
                l = mid + 1;
            }
            else
            {
                // Right part is sorted
                if (nums[mid] <= target && target <= nums[r])
                {
                    // if element is in sorted part, search and return
                    return binary_search(nums, target, mid, r);
                }
                r = mid - 1;
            }
        }
        return -1;
    }
};

class Solution2
{
    // with duplicates
    // https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547
    bool binary_search(vector<int> &nums, int target, int l, int r)
    {
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[l] == nums[mid] && nums[mid] == nums[r])
            {
                l++;
                r--;
                continue;
            }

            if (nums[l] <= nums[mid])
            {
                // Left part is sorted
                if (nums[l] <= target && target <= nums[mid])
                {
                    // if element is in sorted part, search and return
                    return binary_search(nums, target, l, mid);
                }
                l = mid + 1;
            }
            else
            {
                // Right part is sorted
                if (nums[mid] <= target && target <= nums[r])
                {
                    // if element is in sorted part, search and return
                    return binary_search(nums, target, mid, r);
                }
                r = mid - 1;
            }
        }
        return false;
    }
};
#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;

    cout << '\n';

    return 0;
}

#endif