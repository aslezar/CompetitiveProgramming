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

bool canIndexWin(vi &a, vii &mat, int index, int row, int col, vector<vector<vector<int>>> &dp)
{
    ll n = mat.size();
    ll m = mat[0].size();

    if (row >= n || col >= m || index >= a.size())
    {
        //"Lose"
        return false;
    }
    if (dp[index][row][col] != -1)
        return dp[index][row][col];

    for (size_t i = n - 1; i >= row; i--)
    {
        for (size_t j = m - 1; j >= col; j--)
        {
            if (a[index] == mat[i][j])
            {
                if (canIndexWin(a, mat, index + 1, i + 1, j + 1, dp) == false)
                {
                    debug(index, i, j);
                    return dp[index][row][col] = 1;
                }
            }
        }
    }
    return dp[index][row][col] = false;
}
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
    vector<vector<vector<int>>> dp(l + 1, vii(n + 1, vi(m + 1, -1)));
    bool ans = canIndexWin(a, mat, 0, 0, 0, dp);
    cout << (ans == true ? 'T' : 'N') << '\n';
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