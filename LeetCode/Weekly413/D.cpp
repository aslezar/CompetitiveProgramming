#ifdef LOCAL_RUN

#include <bits/stdc++.h>
using namespace std;
#include "debug.cpp"

#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sorta(a) sort(all(a))
#define sortd(a) sort(rall(a))
#define set_bits __builtin_popcount

#define F first
#define S second
#define PB push_back
#define gcd __gcd
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

constexpr unsigned int mod = 1e9 + 7;
constexpr unsigned int maxn = 1e5 + 4;
constexpr float EPS = numeric_limits<float>::epsilon();
constexpr ll INF = numeric_limits<ll>::max();

class Solution
{
public:
    vector<int> maximumSubarrayXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<vector<int>> dp2(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp2[i][i] = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                dp2[i][j] = dp2[i][j - 1] ^ nums[j];
            }
        }
        debug(dp2);

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];

        for (int len = 2; len <= n; len++)
        {
            for (int st = 0; st + len - 1 < n; st++)
            {
                int end = st + len - 1;
                dp[st][end] = dp[st][end - 1] ^ dp[st + 1][end];
            }
        }
        debug(dp);

        return {};
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // nums = [2,8,4,32,16,1], queries = [[0,2],[1,4],[0,5]]
    vector<ll> nums = {2, 8, 4, 32, 16, 1};
    // vector<ll> nums = {1, 2, 3, 4, 5};
    vector<vector<ll>> queries = {{0, 2}, {1, 4}, {0, 5}};

    vector<ll> ans = s.maximumSubarrayXor(nums, queries);
    debug(ans);

    return 0;
}

#endif