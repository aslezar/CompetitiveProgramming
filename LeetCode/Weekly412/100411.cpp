#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++)
        {
            auto top = pq.top();
            pq.pop();
            pq.push({top.first * multiplier, top.second});
        }
        vector<int> ans(n);
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans[top.second] = top.first;
        }
        return ans;
    }
};