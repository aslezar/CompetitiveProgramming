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

void helper(vi &a, int t1, int t2, vi &ans)
{

    // dist,cnt
    pii left, right;
    for (int j = 1; j < a.size(); j++)
    {
        if (a[j] == t1 || a[j] == t2)
        {
            right.first += j;
            right.second++;
        }
    }
    ans[0] = abs(right.first - ans[0]);
    for (int j = 1; j < a.size(); j++)
    {
        if (a[j - 1] == t1 || a[j - 1] == t2)
        {
            left.second++;
        }
        left.first += left.second;
        right.first -= right.second;
        if (a[j] == t1 || a[j] == t2)
        {
            right.second--;
        }
        // debug(left.first + right.first);
        ans[j] = abs(left.first + right.first - ans[j]);
    }
    debug(ans);
}

void solve([[maybe_unused]] ll &_case_no)
{
    ll n = 0;
    cin >> n;
    ll m = 0;
    cin >> m;

    vii a(n, vi(m));
    assert(n == 1);

    int i = 0;
    for (int j = 0; j < m; j++)
    {
        cin >> a[i][j];
    }

    vi ans(m);
    helper(a[0], 1, 3, ans);
    helper(a[0], 2, 3, ans);
    for (auto &i : ans)
        cout << i << ' ';
    cout << endl;
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