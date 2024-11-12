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
    ll n, m, v;
    cin >> n >> m >> v;

    vi a(n);
    input(a, n);

    vi dp1(n + 1, 0);
    vi dp2(n + 1, 0);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // dp[i+1]
        sum += a[i];
        if (sum >= v)
        {
            dp1[i + 1] = dp1[i] + 1;
            sum = 0;
        }
        else
        {
            dp1[i + 1] = dp1[i];
        }
    }
    // debug(dp1);

    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += a[i];
        if (sum >= v)
        {
            dp2[i] = dp2[i + 1] + 1;
            sum = 0;
        }
        else
        {
            dp2[i] = dp2[i + 1];
        }
    }
    // debug(dp2);

    if (dp1[n] < m && dp2[0] < m)
    {
        cout << -1 el;
        return;
    }

    vi pa(n + 1);
    for (int i = 0; i < n; i++)
    {
        pa[i + 1] = pa[i] + a[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (dp2[i + 1] > m)
        {
            // ans
            break;
        }
        int f = m - dp2[i + 1];
        int it = lower_bound(all(dp1), f) - dp1.begin();
        if (it == dp1.size())
            continue;

        ans = max(ans, pa[i + 1] - pa[it]);
    }
    cout << ans el;
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