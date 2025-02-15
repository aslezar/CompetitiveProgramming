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
    int sumOfGoodNumbers(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i - k < 0 || nums[i] > nums[i - k]) && (i + k >= n || nums[i] > nums[i + k]))
            {
                debug(i);
                ans += nums[i];
            }
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    vi v = {1, 3, 2, 1, 5, 4};
    int a = s.sumOfGoodNumbers(v, 2);
    debug(a);
    cout << '\n';

    return 0;
}

#endif