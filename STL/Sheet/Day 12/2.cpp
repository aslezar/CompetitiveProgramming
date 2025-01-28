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
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        // for max-element , we created a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &num : nums)
        {
            pq.push(num);
            debug(pq);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    vi v = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(v, 2);

    cout << '\n';

    return 0;
}

#endif