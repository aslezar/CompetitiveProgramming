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
    vector<int> numberOfWays(int n, vector<int> &hunger, int m, vector<int> &calories)
    {
        int maxHunger = INT_MIN;
        for (int i = 0; i < n; i++)
            maxHunger = max(maxHunger, hunger[i]);

        sorta(calories);

        vector<int> prev(maxHunger + 1, 0);
        for (int i = 0; i <= maxHunger; i++)
        {
            if (i % calories[0] == 0)
                prev[i] = 1;
        }

        for (int ind = 1; ind < int(calories.size()); ind++)
        {
            vector<int> cur(maxHunger + 1, 0);
            for (int target = 0; target <= maxHunger; target++)
            {
                long notTaken = prev[target];

                long taken = 0;
                if (calories[ind] <= target)
                    taken = cur[target - calories[ind]];

                cur[target] = (notTaken + taken) % mod;
            }
            prev = cur;
        }
        debug(prev);

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(prev[hunger[i]]);
        }
        return ans;
    }
};

#undef int

#ifdef LOCAL_RUN

int main()
{
    Solution s;
    // vector<int> hunger = {1, 2, 1, 2, 1};
    // vector<int> c = {1, 1, 1};

    vector<int> hunger = {2, 7, 11};
    vector<int> c = {2, 7, 11};

    vector<int> ans = s.numberOfWays(hunger.size(), hunger, c.size(), c);
    debug(ans);

    cout << endl;

    return 0;
}

#endif