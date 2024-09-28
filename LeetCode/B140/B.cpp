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
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        sortd(maximumHeight);
        int n = maximumHeight.size();
        long long heightSum = 0;

        long long lastHeight = maximumHeight[0];
        heightSum += lastHeight;
        for (int i = 1; i < n; i++)
        {
            ll canTakeHeight = min(lastHeight - 1, (ll)maximumHeight[i]);
            if (canTakeHeight <= 0)
                return -1;
            heightSum += canTakeHeight;
            lastHeight = canTakeHeight;
        }
        return heightSum;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // [2,3,4,3]
    vi v = {2, 3, 4, 3};
    cout << s.maximumTotalSum(v) << '\n';
    cout << '\n';

    return 0;
}

#endif