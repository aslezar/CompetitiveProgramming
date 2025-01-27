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
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        auto isValidDistance = [&](int mxDistance) -> bool
        {
            int cows = 1;
            int last = 0;
            for (int i = 1; i < n; i++)
            {
                if (stalls[i] - stalls[last] >= mxDistance)
                {
                    cows++;
                    last = i;
                    if (cows >= k)
                        return true;
                }
            }
            return cows >= k;
        };

        int l = 0, r = INT_MAX;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValidDistance(mid))
            {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
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

    cout << '\n';

    return 0;
}

#endif