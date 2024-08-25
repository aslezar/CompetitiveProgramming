#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int n = nums.size();
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++)
        {
            auto top = pq.top();
            pq.pop();

            long long newNo = (top.first * multiplier);
            if (newNo > mx)
            {
            }
            pq.push({newNo, top.second});
        }
        vector<int> ans(n);
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans[top.second] = top.first % mod;
        }

        return ans;
    }
};
