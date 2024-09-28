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
#define set_bits __builtin_popcount

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define input(vec, n) FOR(i, 0, n - 1) std::cin >> vec[i];

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

constexpr unsigned int mod = 1e9 + 7;

// int helper(int index, vi &v, vii &dp, int mx = 0)
// {
//     if (index >= v.size())
//     {
//         return mx;
//     }
//     if (dp[index][mx] != -1)
//         return dp[index][mx];
//     // don;t take this value
//     ll ans = helper(index + 1, v, dp, mx);

//     // take this value if prev value not taken
//     mx = max(mx, v[index]);
//     ans = max(ans, 1 + helper(index + 2, v, dp, mx));

//     return dp[index][mx] = ans;
// }

// void solve([[maybe_unused]] ll &_case_no)
// {
//     ll n = 0;
//     cin >> n;

//     vi v(n);
//     input(v, n);

//     vii dp(n, vi(1002, -1));

//     cout << helper(0, v, dp) << endl;
// }

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    if (n & 1)
    {
        int mx = *max_element(all(v));

        // found at odd index
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == mx && i % 2 == 0)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << mx + (n + 1) / 2;
        }
        else
        {
            cout << mx + (n) / 2;
        }
    }
    else
    {
        int ans = *max_element(all(v)) + n / 2;
        cout << ans;
    }
    cout << '\n';
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