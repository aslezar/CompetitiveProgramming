#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
typedef long long ll;
typedef vector<int> vi;

class Solution
{
    void build(const vector<int> &nums, vector<int> &seg, int index, int range_low, int range_high)
    {
        if (range_low == range_high)
        {
            seg[index] = nums[range_low];
            return;
        }
        int range_mid = range_low + (range_high - range_low) / 2;
        build(nums, seg, 2 * index + 1, range_low, range_mid);
        build(nums, seg, 2 * index + 2, range_mid + 1, range_high);

        seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
    }

    int query(const vector<int> &seg, int index, int range_low, int range_high, const int &l, const int &r)
    {
        if (range_low >= l && range_high <= r)
        {
            // completely inside the range
            return seg[index];
        }
        if (r < range_low || range_high < l)
        {
            // lies completly outside
            return 0;
        }
        // overlaps
        int range_mid = range_low + (range_high - range_low) / 2;
        return query(seg, 2 * index + 1, range_low, range_mid, l, r) ^ query(seg, 2 * index + 2, range_mid + 1, range_high, l, r);
    }

public:
    vector<int> maximumSubarrayXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> seg(4 * n);
        build(nums, seg, 0, 0, n - 1);

        vi ans;
        for (auto &&i : queries)
        {
            int l = i[0];
            int r = i[1];
            ans.push_back(query(seg, 0, 0, n - 1, l, r));
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // vector<ll> nums = {1, 2, 3, 4, 5};

    // nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]
    vector<ll> nums = {2, 8, 4, 32, 16, 1};
    vector<vector<ll>> queries = {{0, 2}, {1, 4}, {0, 5}};

    vector<ll> ans = s.maximumSubarrayXor(nums, queries);
    debug(ans);

    return 0;
}

#endif