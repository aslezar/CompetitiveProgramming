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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;

        deque<int> q;

        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            while (!q.empty() && q.front() < i - k + 1)
            {
                q.pop_front();
            }
            if (i >= k - 1)
                ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};
class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k - 1; i++)
        {
            pq.push({nums[i], i});
        }

        for (int i = k - 1; i < n; i++)
        {
            pq.push({nums[i], i});
            while (!pq.empty() && pq.top().second < i - k + 1)
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    // [1,3,-1,-3,5,3,6,7]
    Solution s;
    vi v = {1, 3, -1, -3, 5, 3, 6, 7};
    auto ans = s.maxSlidingWindow(v, 3);
    debug(ans);
    cout << '\n';

    return 0;
}

#endif