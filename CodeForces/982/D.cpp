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

    ll m = 0;
    cin >> m;

    vi a(n);
    input(a, n);

    vi b(m);
    input(b, m);

    int mx_a = *max_element(all(a));
    int mx_b = *max_element(all(b));
    if (mx_a > mx_b)
    {
        cout << -1 el;
        return;
    }

    vii nxt(n, vi(m));
    for (int k = 0; k < m; k++)
    {
        int r = -1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            while (r < n && sum <= b[k])
                sum += a[++r];
            nxt[i][k] = r;
            sum -= a[i];
        }
    }
    debug(nxt);

    vii dp(n + 1, vi(m, 3e14));
    dp[0][0] = 0;
    for (int k = 0; k < m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            auto next = nxt[i][k];
            dp[next][k] = min(dp[next][k], dp[i][k] + (m - k - 1));
            if (k < m - 1)
            {
                dp[i][k + 1] = min(dp[i][k + 1], dp[i][k]);
            }
        }
    }
    debug(dp);
    cout << *min_element(all(dp[n])) el;
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