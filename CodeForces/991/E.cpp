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
constexpr unsigned int mod = 1e9 + 7;

vector<vector<int>> dp;
int helper(int i, int j, string &a, string &b, string &c)
{
    if (i + j >= c.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    // pick char from a
    if (i < a.length())
    {
        int ans1 = helper(i + 1, j, a, b, c);
        if (c[i + j] != a[i])
            ans1++;

        ans = min(ans, ans1);
    }

    // pick char from b
    if (j < b.length())
    {
        int ans2 = helper(i, j + 1, a, b, c);
        if (c[i + j] != b[j])
            ans2++;
        ans = min(ans, ans2);
    }

    return dp[i][j] = ans;
}

void solve([[maybe_unused]] ll &_case_no)
{
    string a, b, c;
    cin >> a >> b >> c;

    reverse(all(a));
    reverse(all(b));
    reverse(all(c));

    dp = vector<vector<int>>(a.length() + 1, vector<int>(b.length() + 1, -1));

    helper(0, 0, a, b, c);

    // debug(dp);
    debug(dp[0][0]);
    cout << dp[0][0] el;
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