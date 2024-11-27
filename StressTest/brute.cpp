#include <bits/stdc++.h>
using namespace std;

// #define ONLINE_JUDGE
#ifdef LOCAL_JUDGE
#include "/algo/debug.h"
#else
#define debug(...) 42
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
const int mod = 1e9 + 7;

int helper(int n, vi &a, vi &b, int i, vi &cmax, vector<unordered_map<int, unordered_map<int, int>>> &dp)
{
    if (i >= n)
    {
        return 0;
    }
    if (dp[i].count(cmax[0]) && dp[i][cmax[0]].count(cmax[1]))
        return dp[i][cmax[0]][cmax[1]];
    int prevMaxSum = cmax[0] + cmax[1];
    // take from a
    vi cmax2(cmax);
    cmax2.push_back(a[i]);
    sortallr(cmax2);
    cmax2.pop_back();
    int ans1 = ((cmax[0] + cmax[1]) >= a[i]) + helper(n, a, b, i + 1, cmax2, dp);
    // take from b
    vi cmax3(cmax);
    cmax3.push_back(b[i]);
    sortallr(cmax3);
    cmax3.pop_back();
    int ans2 = ((cmax[0] + cmax[1]) >= b[i]) + helper(n, a, b, i + 1, cmax3, dp);
    // debug(i,cmax,cmax2,cmax3, max(ans1, ans2));
    return dp[i][cmax[0]][cmax[1]] = max(ans1, ans2);
}

void run_case(int currTest)
{
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    vector<unordered_map<int, unordered_map<int, int>>> dp(n + 1);
    vi cmax={a[0],b[1]};
    sortallr(cmax);
    int ans2 = helper(n, a, b, 2, cmax, dp);
    ans = max(ans, ans2);
    cmax={b[0],a[1]};
    sortallr(cmax);
    ans2 = helper(n, a, b, 2, cmax, dp);
    ans=max(ans,ans2);
    cmax={a[0],a[1]};
    sortallr(cmax);
    ans2 = helper(n, a, b, 2, cmax, dp);
    ans=max(ans,ans2);
    cmax={b[0],b[1]};
    sortallr(cmax);
    ans2 = helper(n, a, b, 2, cmax, dp);
    ans=max(ans,ans2);
    cout << ans el;
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
    while (t--)
    {
        run_case(T - t);
    }
    return 0;
}