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
constexpr unsigned int mod = 1e9 + 7;

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;

    vi v(n);
    input(v, n);

    auto f = [&](int a, int x)
    {
        return a + (a < x) - (a > x);
    };

    vii dp(n + 1, vi(3));
    dp[0] = {0, -n, -n};
    for (int i = 0; i < n; i++)
    {
        dp[i + 1][0] = f(dp[i][0], v[i]);
        dp[i + 1][1] = max(dp[i][0], dp[i][1]);
        dp[i + 1][2] = max(f(dp[i][1], v[i]), f(dp[i][2], v[i]));
    }

    cout << max(dp[n][1], dp[n][2]) el;
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