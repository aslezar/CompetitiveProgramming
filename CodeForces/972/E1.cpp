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

void solve([[maybe_unused]] ll &_case_no)
{
    ll l, n, m;
    cin >> l >> n >> m;

    vi a(l);
    for (size_t i = 0; i < l; i++)
    {
        cin >> a[i];
    }

    vii mat(n, vi(m));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    // unordered_set<int> vis;
    // for (int i = 0; i < l; i++)
    // {
    //     if (vis.count(a[i]))
    //     {
    //         l = i;
    //         break;
    //     }
    //     vis.insert(a[i]);
    // }

    vector<vii> dp(n, vii(m, vi(l)));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (int k = 0; k < l; k++)
            {
                // dp[i][j][k] = 1;
                if (i + 1 < n && dp[i + 1][j][k] == 1)
                {
                    dp[i][j][k] = 1;
                    continue;
                }
                if (j + 1 < m && dp[i][j + 1][k] == 1)
                {
                    dp[i][j][k] = 1;
                    continue;
                }
                if (i + 1 < n && j + 1 < m && dp[i + 1][j + 1][k] == 1)
                {
                    dp[i][j][k] = 1;
                    continue;
                }
                if (mat[i][j] == a[k])
                {
                    if (k == l - 1 || i == n - 1 || j == m - 1)
                    {
                        dp[i][j][k] = 1;
                    }
                    else
                    {
                        dp[i][j][k] = !dp[i + 1][j + 1][k + 1];
                    }
                }
                else
                {
                    dp[i][j][k] = 0;
                }
            }
        }
    }
    cout << (dp[0][0][0] == 1 ? 'T' : 'N') << '\n';
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