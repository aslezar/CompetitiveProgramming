#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_RUN
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
#define input(vec, n)           \
    for (int i = 0; i < n; i++) \
        std::cin >> vec[i];

#define el << endl;
#define ws << " ";

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;
constexpr unsigned int mod = 998244353;

// vii dp;

// int help(int n, int p, int b)
// {
//     if (b == n)
//     {
//         return 1;
//     }

//     int &d = dp[p][b];
//     if (d != -1)
//     {
//         return d;
//     }

//     int ans = 0;
//     for (int pp = max(1ll, p - 1); pp <= n; pp++)
//     {
//         ans = (ans + help(n, pp, b + 1)) % mod;
//     }
//     return d = ans;
// }

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    else if (n == 2)
    {
        cout << 4 << '\n';
        return;
    }
    else if (n == 3)
    {
        cout << 21 << '\n';
        return;
    }

    // dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

    // int ans = 0;
    // for (int p = 1; p <= n; p++)
    // {
    //     ans = (ans + help(n, p, 1)) % mod;
    // }

    vii dp(n + 1, vector<int>(n + 1));

    dp[n] = vector<int>(n + 1, 1);
    dp[n][0] = 0;

    for (int b = n - 1; b >= 1; b--)
    {
        dp[b][n] = (dp[b + 1][n] + dp[b + 1][n - 1]) % mod;
        for (int p = n - 1; p >= 1; p--)
        {
            dp[b][p] = (dp[b][p + 1] + dp[b + 1][p - 1]) % mod;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[1][i]) % mod;
    }

    cout << ans << '\n';
}

int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        // cout << "Case #" << i + 1 << ": ";
        solve(i);
    }
    return 0;
}