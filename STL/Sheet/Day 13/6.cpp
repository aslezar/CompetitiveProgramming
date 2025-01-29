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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }
            m[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for (auto &num : nums1)
        {
            ans.push_back(m[num]);
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    cout << '\n';

    return 0;
}

#endif