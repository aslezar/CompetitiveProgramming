#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
#include "debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define ws << ' '
#define el << '\n'
#define nl cout << '\n';
#define int long long
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define getbit(x, y) (((x) >> (y)) & 1ll)
#define turnonandupdate(x, y) x = ((x) | (1ll << y))
#define turnoffandupdate(x, y) x = (x & ~(1ll << (y)))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define setbits(x) __builtin_popcount(x)
#define sortall(x) sort(all(x))
#define sortallr(x) sort(rall(x))

const bool multipleTest = 1;
const int mod = 998244353;

int dp[25][(int)(4e6 + 10)];
int N;

void precompute()
{
    int mx = 4e6 + 1;
    // vi dp(mx,0);
    unordered_map<int, int> arr;
    vi arr2;
    int val = 4;
    while (val <= mx)
    {
        arr[val] = (val + arr[val / 2] * 2);
        arr2.push_back(val);
        val *= 2;
    }
    N = arr.size();
    for (int i = 0; i < mx; i++)
    {
        if (i % arr[arr2[0]] == 0)
            dp[0][i] = 1;
    }
    for (int ind = 1; ind < N; ind++)
    {
        for (int target = 0; target < mx; target += 4)
        {
            long notTaken = dp[ind - 1][target];
            long taken = 0;
            if (arr[arr2[ind]] <= target)
                taken = dp[ind][target - arr[arr2[ind]]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
}

void run_case(int currTest)
{
    int n;
    cin >> n;
    cout << dp[N - 1][n] el;
}

int32_t main()
{
#ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("log.txt", "w", stderr);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    if (multipleTest)
        cin >> t;
    int T = t;
    precompute();
    while (t--)
    {
        run_case(T - t);
    }
    return 0;
}