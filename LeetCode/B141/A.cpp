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
    int modifyNumber(int num)
    {
        int mask = 1;
        while (num & mask)
        {
            mask <<= 1;
        }
        mask >>= 1;
        return num & ~mask;
    }

public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vi ans(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
            {
                ans[i] = -1;
                continue;
            }

            ans[i] = modifyNumber(nums[i]);
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // [11,13,31]
    vi nums = {11, 13, 31};
    vi ans = s.minBitwiseArray(nums);
    // [2,3,5,7]
    nums = {2, 3, 5, 7};
    ans = s.minBitwiseArray(nums);
    debug(ans);
    for (int i : ans)
    {
        cout << i << ' ';
    }

    cout << '\n';

    return 0;
}

#endif